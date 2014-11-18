#ifndef MODEL_WALL_H_INCLUDED
#define MODEL_WALL_H_INCLUDED

#include "../Utils/Line.h"

#include <glm/vec2.hpp>

namespace Model {

    class Ball;
    class Brick;

    class Wall : public Util::Line {
        public: 
            Wall(const Line& line, bool collisionCheck = true);
            Wall(const Line& line, const glm::vec2& surfaceNormal, bool collisionCheck = true);

            bool checkCollision(const Ball& ball) const;
            bool checkCollision(const Ball& ball, const glm::vec2& offset) const;

            double getCollisionDistance(const Ball& ball) const;
            double getCollisionDistance(const Ball& ball, const glm::vec2& offset) const;

            const glm::vec2& getNormal() const;

        private:
            void computeNormal();

            bool _collisionCheck;
            glm::vec2 _normal;

    };

}

#endif