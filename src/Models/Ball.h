#ifndef MODEL_BALL_H_INCLUDED
#define MODEL_BALL_H_INCLUDED

#include "Groups/BrickGroup.h"
#include "Paddle.h"
#include "Groups/WallGroup.h"
#include "../Utils/Exception.h"

#include <glm/vec2.hpp>

namespace Model {

    class Ball {
        public:
            Ball(Paddle* paddle) throw(Util::Exception::FatalError);

            void update(double deltaTime, const WallGroup& walls, BrickGroup& bricks);
            void reset();
            void resetSpeedFactor();
            void shoot();
            void die();
            
            void setMoving(bool value);
            void setSpeedFactor(float factor);

            bool isMoving() const;
            float getSpeedFactor() const;
            unsigned int getRadius() const;
            const glm::vec2& getPosition() const;
            const glm::vec2& getVelocity() const;
            const glm::vec2& getPaddleOffset() const;

        private:
            void attachToPaddle();
            void updatePosition(double deltaTime);
            void handleCollision(double deltaTime, const WallGroup& walls, BrickGroup& bricks);
            
            void handleCollisionWithPaddle();
            void handleCollisionWithWalls(double deltaTime, const WallGroup& walls);
            void handleCollisionWithBricks(double deltaTime, BrickGroup& bricks);

            void bindPaddle(Paddle* paddle);
            void setRadius(unsigned int width);
            void setPosition(const glm::vec2& position);
            void setVelocity(const glm::vec2& velocity);
            void setPaddleOffset(const glm::vec2& offset);

            glm::vec2 getPaddleBounceVector() const;
            Paddle& getPaddle() const throw(Util::Exception::FatalError);

            bool _isMoving;
            float _speedFactor;
            float _speedFactorIncrement;
            unsigned int _radius;

            glm::vec2 _position;
            glm::vec2 _velocity;
            glm::vec2 _paddleOffset;
            Paddle* _paddle;
    };

}

#endif