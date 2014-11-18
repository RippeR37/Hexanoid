#include "Ball.h"
#include "Wall.h"

#include <glm/geometric.hpp>

#include <cmath>
#include <cstdlib>

namespace Model {

    Ball::Ball(Paddle* paddle) {
        if(paddle == nullptr)
            throw Util::Exception::FatalError("Can't construct ball without valid paddle pointer");

        bindPaddle(paddle);
        setVelocity(glm::vec2(1.0f, 1.0f));
        setRadius(5);

        _speedFactorIncrement = 1.0f;
    }

    void Ball::update(double deltaTime, const WallGroup& walls, BrickGroup& bricks) {
        if(getPaddle().getLives() > 0) {
            updatePosition(deltaTime);

            if(isMoving()) {
                handleCollision(deltaTime, walls, bricks);
                setSpeedFactor(getSpeedFactor() + _speedFactorIncrement * static_cast<float>(deltaTime));
            }
        }
    }

    void Ball::reset() {
        resetSpeedFactor();
        attachToPaddle();
    }

    void Ball::resetSpeedFactor() {
        setSpeedFactor(300.0f);
    }
    
    void Ball::shoot() {
        float angle;

        if(isMoving() == false && getPaddle().getLives() > 0) {
            angle = 3.14f * (90.0f + static_cast<float>((rand() % 90) - 45.0f)) / 180.0f;

            setMoving(true);
            setVelocity(glm::vec2(std::cos(angle), std::sin(angle)));
        }
    }
    
    void Ball::die() {
        getPaddle().die();

        if(getPaddle().getLives() > 0)
            reset();
    }

    void Ball::setMoving(bool value) {
        _isMoving = value;
    }

    void Ball::setSpeedFactor(float factor) {
        _speedFactor = factor;
    }

    bool Ball::isMoving() const {
        return _isMoving;
    }

    float Ball::getSpeedFactor() const {
        return _speedFactor;
    }

    unsigned int Ball::getRadius() const {
        return _radius;
    }

    const glm::vec2& Ball::getPosition() const {
        return _position;
    }

    const glm::vec2& Ball::getVelocity() const {
        return _velocity;
    }
    
    const glm::vec2& Ball::getPaddleOffset() const {
        return _paddleOffset;
    }

    void Ball::attachToPaddle() {
        setMoving(false);
        setPaddleOffset(glm::vec2(
            (getPaddle().getWidth() -  getRadius()) / 2, 
             getPaddle().getHeight() + getRadius()  / 2)
        );
        setPosition(getPaddle().getPosition() + getPaddleOffset());
    }

    void Ball::updatePosition(double deltaTime) {
        if(isMoving())
            _position += getVelocity() * getSpeedFactor() * static_cast<float>(deltaTime);
        else
            setPosition(getPaddle().getPosition() + getPaddleOffset());
    }

    void Ball::handleCollision(double deltaTime, const WallGroup& walls, BrickGroup& bricks) {
        handleCollisionWithPaddle();
        handleCollisionWithWalls(deltaTime, walls);
        handleCollisionWithBricks(deltaTime, bricks);
    }

    void Ball::handleCollisionWithPaddle() {
        if(getPosition().y < 20)
            die();

        if(getPosition().y < 50 && getPosition().y > 30) {
            if(getPosition().x > getPaddle().getPosition().x) {
                if(getPosition().x + getRadius() < getPaddle().getPosition().x + getPaddle().getWidth() - getRadius()) {
                    setVelocity(getPaddleBounceVector());
                }
            }
        }
    }

    void Ball::handleCollisionWithWalls(double deltaTime, const WallGroup& walls) {
        static glm::vec2 newVelocity;

        for(const Wall& wall : walls.getWalls()) {
            if(wall.checkCollision(*this)) {
                newVelocity = Util::Line::getReflectedVector(getVelocity(), wall.getNormal());

                setVelocity(glm::normalize(newVelocity));
                setPosition(getPosition() + getVelocity() * getSpeedFactor() * static_cast<float>(deltaTime));
                break;
            }
        }
    }

    void Ball::handleCollisionWithBricks(double deltaTime, BrickGroup& bricks) {
        static double epsilon = 0.01;

        glm::vec2 newVelocity;
        glm::vec2 closestWallNormal;
        std::vector<Brick*> bricksHitted;
        double minDistance, currentDistance; 
        bool hitDetected = false;
        bool newBrick;

        minDistance = getRadius() * 2.0f;
        hitDetected = false;

        for(Brick& brick : bricks.getBricks()) {
            newBrick = true;

            for(const Wall& wall : brick.getWalls()) {
                if(wall.checkCollision(*this, brick.getPosition())) {
                    newBrick = false;
                    hitDetected = true;
                    currentDistance = wall.getCollisionDistance(*this, brick.getPosition());

                    if(currentDistance < minDistance) {
                        minDistance = currentDistance;
                        closestWallNormal = wall.getNormal();

                        bricksHitted.clear();
                        bricksHitted.push_back(&brick);

                    } else if(currentDistance <= minDistance + epsilon) {
                        closestWallNormal += wall.getNormal();

                        if(newBrick)
                            bricksHitted.push_back(&brick);
                    }
                }
            }
        }

        if(hitDetected) {
            for(Brick* brick : bricksHitted)
                brick->hit();

            newVelocity = Util::Line::getReflectedVector(getVelocity(), glm::normalize(closestWallNormal));
            setVelocity(glm::normalize(newVelocity));
        }
    }
    
    void Ball::bindPaddle(Paddle* paddle) {
        _paddle = paddle;
    }

    void Ball::setRadius(unsigned int radius) {
        _radius = radius;
    }

    void Ball::setPosition(const glm::vec2& position) {
        _position = position;
    }

    void Ball::setVelocity(const glm::vec2& velocity) {
        _velocity = glm::normalize(velocity);
    }

    void Ball::setPaddleOffset(const glm::vec2& offset) {
        _paddleOffset = offset;
    }

    glm::vec2 Ball::getPaddleBounceVector() const {
        glm::vec2 bounceVector;
        float offset;
        float paddleHalfWidth;
        float scaledOffset;

        paddleHalfWidth = static_cast<float>(getPaddle().getWidth()) * 0.5f;
        offset = (getPosition().x + getRadius()) - (getPaddle().getPosition().x + paddleHalfWidth);
        offset = offset / (paddleHalfWidth);
        offset = offset * 0.5f;
        scaledOffset = 0.5f * 3.14f * (1.0f - offset);

        bounceVector = glm::vec2(std::cos(scaledOffset), std::sin(scaledOffset));

        return bounceVector;
    }

    Paddle& Ball::getPaddle() const {
        if(_paddle == nullptr)
            throw Util::Exception::FatalError("Dereferencing of nullptr (Model::Ball::getPaddle())");

        return *_paddle;
    }

}