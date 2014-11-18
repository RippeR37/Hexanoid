#include "Paddle.h"
#include "Ball.h"
#include "../Views/ViewPaddle.h"
#include "../Game.h"

namespace Model {

    Paddle::Paddle(View::ViewPaddle* view) {
        bindView(view);
        reset();
        setLives(3);
        setSpeedFactor(250.0f);
    }

    void Paddle::update(double deltaTime) {
        if(getLives() > 0)
            updatePosition(deltaTime);
    }

    void Paddle::reset() {
        setWidth(60);
        setHeight(10);

        setMoving(false);
        setDirection(Model::Direction::Right);
        setPositionRange(255, 544 - getWidth());
        setPosition(glm::vec2((_positionRange.y + _positionRange.x) / 2.0f, 50.0f - _height));
    }
    
    void Paddle::aquire(const Item& item, Ball& ball) {
        switch(item.getType()) {
            case Item::Type::PaddleSize:
                if(getWidth() < 90) {
                    setWidth(getWidth() + 10);
                    setPositionRange(255, 544 - getWidth());

                    if(_position.x - 5 > _positionRange.x)
                        _position.x -= 5;

                    updateView(_view);
                }
                break;

            case Item::Type::ExtraLive:
                setLives(getLives() + 1);
                updateLives();
                break;

            case Item::Type::BallSpeedReduction:
                ball.resetSpeedFactor();
                break;
        }
    }

    void Paddle::die() {
        setLives(getLives() - 1);
        updateLives();

        if(getLives() > 0) {
            reset();
            updateView(_view);
        }
    }

    void Paddle::updateLives() const {
        Game::get().getWindow().appendTitle(std::string(" | Lives left: ") + std::to_string(getLives()));
    }

    void Paddle::setMoving(bool value) {
        _isMoving = value;
    }

    void Paddle::setDirection(Model::Direction direction) {
        _direction = direction;
    }

    bool Paddle::isMoving() const {
        return _isMoving;
    }

    unsigned int Paddle::getLives() const {
        return _lives;
    }

    unsigned int Paddle::getWidth() const {
        return _width;
    }

    unsigned int Paddle::getHeight() const {
        return _height;
    }

    const glm::vec2& Paddle::getPosition() const {
        return _position;
    }

    Direction Paddle::getDirection() const {
        return _direction;
    }

    void Paddle::bindView(View::ViewPaddle* view) {
        _view = view;
    }

    void Paddle::updateView(View::ViewPaddle* view) {
        view->initVBO(*this);
    }

    void Paddle::updatePosition(double deltaTime) {
        if(isMoving()) {
            switch(getDirection()) {
                case Model::Direction::Left:
                    _position.x -= static_cast<float>(_speedFactor * deltaTime);
                    if(_position.x < _positionRange.x)
                        _position.x = _positionRange.x;

                    break;

                case Model::Direction::Right:
                    _position.x += static_cast<float>(_speedFactor * deltaTime);
                    if(_position.x > _positionRange.y)
                        _position.x = _positionRange.y;

                    break;
            }
        }
    }

    void Paddle::setLives(unsigned int lives) {
        if(lives < 0)
            lives = 0;

        _lives = lives;
    }

    void Paddle::setWidth(unsigned int width) {
        _width = width;
    }

    void Paddle::setHeight(unsigned int height) {
        _height = height;
    }

    void Paddle::setPosition(const glm::vec2& position) {
        _position = position;

        if(_position.x < _positionRange.x)
            _position.x = _positionRange.x;

        else if(_position.x > _positionRange.y)
            _position.x = _positionRange.y;
    }

    void Paddle::setSpeedFactor(double factor) {
        _speedFactor = factor;
    }

    void Paddle::setPositionRange(double left, double right) {
        _positionRange = glm::vec2(left, right);
    }
    
    double Paddle::getSpeedFactor() const {
        return _speedFactor;
    }

}