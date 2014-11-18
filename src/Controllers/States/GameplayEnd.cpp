#include "GameplayEnd.h"
#include "../../Models/States.h"
#include "../../Game.h"

namespace Controller {

    State::GameplayEnd::GameplayEnd() {
        
    }

    void State::GameplayEnd::update(double frameTime) {
        
    }

    void State::GameplayEnd::render() {
        Model::States::get().gameplay->render();
    }

    void State::GameplayEnd::onLoad() {
        glfwSetKeyCallback(Game::get().getWindow().getHandle(), handleKeyboard);
    }

    void State::GameplayEnd::onUnload() {
        glfwSetKeyCallback(Game::get().getWindow().getHandle(), nullptr);
    }

    void State::GameplayEnd::handleKeyboard(GLFWwindow* window, int key, int scancode, int action, int mods) {
        static State::GameplayEnd& thisState = *Model::States::get().gameplayEnd;

        if(action == GLFW_PRESS) {
            switch(key) {
                case GLFW_KEY_ESCAPE:
                    thisState.changeTo(Model::States::get().shutdown);
                    break;
            }
        }
    }

}
