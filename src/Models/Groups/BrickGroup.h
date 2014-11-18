#ifndef MODEL_GROUP_BRICKGROUP_H_INCLUDED
#define MODEL_GROUP_BRICKGROUP_H_INCLUDED

#include "../Brick.h"
#include "ItemGroup.h"

#include <glm/vec2.hpp>

#include <vector>

namespace Model {

    class BrickGroup {
        public:
            void init();
            void update(ItemGroup& items);
            void insertBrick(const Brick& brick);

            unsigned int getBricksLeft() const;
            const std::vector<Brick>& getBricks() const;

        private:
            std::vector<Brick>& getBricks();

            std::vector<Brick> _bricks;

        public:
            friend class Ball;
    };

}

#endif