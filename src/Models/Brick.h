#ifndef MODEL_BRICK_H_INCLUDED
#define MODEL_BRICK_H_INCLUDED

#include "Wall.h"
#include "Groups/ItemGroup.h"

#include <glm/vec2.hpp>
#include <glm/vec3.hpp>

#include <vector>

namespace Model {

    class Ball;

    class Brick {
        public:
            Brick(const glm::vec2& position, const glm::vec3& color, const glm::vec2& size);

            void hit();
            void spawnItem(ItemGroup& items) const;

            bool isHit() const;
            bool hasItem() const;
            const glm::vec2& getSize() const;
            const glm::vec3& getColor() const;
            const glm::vec2& getPosition() const;
            const std::vector<Wall>& getWalls() const;

        private:
            void setHit(bool value);
            void setSize(const glm::vec2& size);
            void setColor(const glm::vec3& color);
            void setPosition(const glm::vec2& position);
            void setWalls();
            void setHasItem(bool value);

            bool _isHit;
            bool _hasItem;
            glm::vec2 _size;
            glm::vec3 _color;
            glm::vec2 _position;
            std::vector<Wall> _walls;
    };

}

#endif