#ifndef MODEL_PADDLE_H_INCLUDED
#define MODEL_PADDLE_H_INCLUDED

#include "Direction.h"
#include "Item.h"

#include <glm/vec2.hpp>

namespace View { 
    class ViewPaddle; 
}

namespace Model {

    class Ball;

    class Paddle {
        public:
            Paddle(View::ViewPaddle* view);

            void update(double deltaTime);
            void reset();
            void aquire(const Item& item, Ball& ball);
            void die();
            void updateLives() const;

            void setMoving(bool value);
            void setDirection(Model::Direction direction);

            bool isMoving() const;
            unsigned int getLives() const;
            unsigned int getWidth() const;
            unsigned int getHeight() const;
            const glm::vec2& getPosition() const;
            Direction getDirection() const;

        private:
            void bindView(View::ViewPaddle* view);
            void updateView(View::ViewPaddle* view);
            void updatePosition(double deltaTime);
            void setLives(unsigned int lives);
            void setWidth(unsigned int width);
            void setHeight(unsigned int height);
            void setPosition(const glm::vec2& position);
            void setSpeedFactor(double factor);
            void setPositionRange(double left, double right);

            double getSpeedFactor() const;

            bool _isMoving;
            double _speedFactor;
            unsigned int _width;
            unsigned int _height;
            unsigned int _lives;

            glm::vec2 _position;
            glm::vec2 _positionRange;
            Direction _direction;
            View::ViewPaddle* _view;
    };

}

#endif