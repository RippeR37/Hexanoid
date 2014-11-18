#ifndef CONTROLLER_STATE_GAMEPLAY_H_INCLUDED
#define CONTROLLER_STATE_GAMEPLAY_H_INCLUDED

#include "../State.h"

#include "../../Models/Ball.h"
#include "../../Models/Paddle.h"
#include "../../Models/Groups/WallGroup.h"
#include "../../Models/Groups/BrickGroup.h"
#include "../../Models/Groups/ItemGroup.h"

#include "../../Views/ViewBall.h"
#include "../../Views/ViewPaddle.h"
#include "../../Views/Groups/ViewWallGroup.h"
#include "../../Views/Groups/ViewBrickGroup.h"
#include "../../Views/ViewBackground.h"
#include "../../Views/Groups/ViewItemGroup.h"

namespace Controller {

    class State::Gameplay : public State {
        public:
            Gameplay();

            void update(const double frameTime);
            void render();

            void onLoad();
            void onUnload();

            static void handleKeyboard(GLFWwindow* window, int key, int scancode, int action, int mods);

        private:
            bool isEnd();

        private:
            Model::Ball _ball;
            Model::Paddle _paddle;
            Model::WallGroup _walls;
            Model::BrickGroup _bricks;
            Model::ItemGroup _items;

        private:
            View::ViewBall _viewBall;
            View::ViewPaddle _viewPaddle;
            View::ViewWallGroup _viewWalls;
            View::ViewBrickGroup _viewBricks;
            View::ViewBackground _viewBackground;
            View::ViewItemGroup _viewItems;
    };

}

#endif