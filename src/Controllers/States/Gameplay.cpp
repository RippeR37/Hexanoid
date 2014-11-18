#include "Gameplay.h"
#include "../../Models/States.h"
#include "../../Game.h"
#include "../../Utils/TimeLoop.h"

#include <GLFW/glfw3.h>

namespace Controller {

    State::Gameplay::Gameplay() : _ball(&_paddle), _paddle(&_viewPaddle) {
        
    }

    void State::Gameplay::update(double frameTime) {
        static const double timeStep = 0.001;

        if(shouldSkip())
            return;

        Util::TimeLoop::semiFixed(frameTime, timeStep, [&, this](double deltaTime) { 
            _paddle.update(deltaTime);
            _ball.update(deltaTime, _walls, _bricks);
            _items.update(deltaTime, _paddle, _ball);
            _bricks.update(_items);
        });

        if(isEnd() == true)
            State::changeTo(Model::States::get().gameplayEnd);
    }

    void State::Gameplay::render() {
        if(shouldSkip())
            return;

        Game::get().getWindow().getContext().clearBuffers(GL::Context::BufferMask::Color);
        
        _viewBackground.render();
        _viewBall.render(_ball);
        _viewWalls.render(_walls);
        _viewPaddle.render(_paddle);
        _viewBricks.render(_bricks);
        _viewItems.render(_items);
    }

    void State::Gameplay::onLoad() {
        changeTo(this);
        glfwSetKeyCallback(Game::get().getWindow().getHandle(), handleKeyboard);
        Game::get().getWindow().getContext().setClearColor(glm::vec4(0.1f, 0.1f, 0.1f, 1.0f));

        _paddle.reset();
        _ball.reset();
        _walls.init();
        _bricks.init();
        
        _viewBackground.init();
        _viewPaddle.init(_paddle);
        _viewBall.init(_ball);
        _viewWalls.init(_walls);
        _viewBricks.init(_bricks);
        _viewItems.init(_items);

        _paddle.updateLives();
    }

    void State::Gameplay::onUnload() {
        glfwSetKeyCallback(Game::get().getWindow().getHandle(), nullptr);
    }

    void State::Gameplay::handleKeyboard(GLFWwindow* window, int key, int scancode, int action, int mods) {
        static State::Gameplay& thisState = *Model::States::get().gameplay;

        if(action == GLFW_PRESS) {
            switch(key) {
                case GLFW_KEY_ESCAPE:
                    thisState.changeTo(Model::States::get().shutdown);
                    break;

                case GLFW_KEY_LEFT:
                    thisState._paddle.setDirection(Model::Direction::Left);
                    thisState._paddle.setMoving(true);
                    break;

                case GLFW_KEY_RIGHT:
                    thisState._paddle.setDirection(Model::Direction::Right);
                    thisState._paddle.setMoving(true);
                    break;

                case GLFW_KEY_SPACE:
                    thisState._ball.shoot();
                    break;
            }

        } else if(action == GLFW_RELEASE) {
            switch(key) {
                case GLFW_KEY_LEFT:
                    if(thisState._paddle.getDirection() == Model::Direction::Left)
                        thisState._paddle.setMoving(false);
                    break;

                case GLFW_KEY_RIGHT:
                    if(thisState._paddle.getDirection() == Model::Direction::Right)
                        thisState._paddle.setMoving(false);
                    break;
            }
        }
    }

    bool State::Gameplay::isEnd() {
        if(_paddle.getLives() == 0) {
            Game::get().getWindow().appendTitle(" | You have lost!");
            return true;
        }

        if(_bricks.getBricksLeft() == 0) {
            Game::get().getWindow().appendTitle(" | You have won!");
            return true;
        }

        return false;
    };

}
