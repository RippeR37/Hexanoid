#include "Wall.h"
#include "Ball.h"

#include <glm/geometric.hpp>

namespace Model {

    Wall::Wall(const Line& line, bool collisionCheck) {
        setLine(line);
        computeNormal();
        _collisionCheck = collisionCheck;
    }

    Wall::Wall(const Line& line, const glm::vec2& surfaceNormal, bool collisionCheck) {
        setLine(line);
        _normal = surfaceNormal;
        _collisionCheck = collisionCheck;
    }

    bool Wall::checkCollision(const Ball& ball) const {
        static glm::vec2 zeroOffset = glm::vec2(0.0f);

        return checkCollision(ball, zeroOffset);
    }

    bool Wall::checkCollision(const Ball& ball, const glm::vec2& offset) const {
        float ballRadius = static_cast<float>(ball.getRadius());
        glm::vec2 ballCenter = ball.getPosition() + glm::vec2(ballRadius) - offset;

        if(_collisionCheck == false)
            return false;

        if(distance(Util::Point(ballCenter)) <= ballRadius)
            return true;

        return false;
    }

    double Wall::getCollisionDistance(const Ball& ball) const {
        static glm::vec2 zeroOffset = glm::vec2(0.0f);

        return getCollisionDistance(ball, zeroOffset);
    }

    double Wall::getCollisionDistance(const Ball& ball, const glm::vec2& offset) const {
        float ballRadius = static_cast<float>(ball.getRadius());
        glm::vec2 ballCenter = ball.getPosition() + glm::vec2(ballRadius) - offset;

        return distance(Util::Point(ballCenter));
    }


    const glm::vec2& Wall::getNormal() const {
        return _normal;
    }

    void Wall::computeNormal() {
        _normal = Line::getNormal();
    }
    
}