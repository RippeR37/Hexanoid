#ifndef CONTROLLER_STATE_GAMEPLAY_END_H_INCLUDED
#define CONTROLLER_STATE_GAMEPLAY_END_H_INCLUDED

#include "../State.h"

#include <GL/glew.h>
#include <GLFW/glfw3.h>

namespace Controller {

    class State::GameplayEnd : public State {
        public:
            GameplayEnd();

            void update(const double frameTime);
            void render();

            void onLoad();
            void onUnload();

            static void handleKeyboard(GLFWwindow* window, int key, int scancode, int action, int mods);

        private:

    };

}

#endif