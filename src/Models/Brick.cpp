#include "Brick.h"
#include "Ball.h"
#include "../Utils/Line.h"

#include <cstdlib>

namespace Model {

    Brick::Brick(const glm::vec2& position, const glm::vec3& color, const glm::vec2& size) {
        setPosition(position);
        setColor(color);
        setSize(size);
        setHit(false);
        setWalls();
        setHasItem((0 == (rand() % 19)));
    }

    void Brick::hit() {
        _isHit = true;
    }

    void Brick::spawnItem(ItemGroup& items) const {
        if(hasItem())
            items.insert(Item(Item::Type::Random, getPosition()));
    }

    bool Brick::isHit() const {
        return _isHit;
    }

    bool Brick::hasItem() const {
        return _hasItem;
    }

    const glm::vec2& Brick::getSize() const {
        return _size;
    }

    const glm::vec3& Brick::getColor() const {
        return _color;
    }

    const glm::vec2& Brick::getPosition() const {
        return _position;
    }
    
    const std::vector<Wall>& Brick::getWalls() const {
        return _walls;
    }

    void Brick::setHit(bool value) {
        _isHit = value;
    }
    
    void Brick::setSize(const glm::vec2& size) {
        _size = size;
    }

    void Brick::setColor(const glm::vec3& color) {
        _color = color;
    }

    void Brick::setPosition(const glm::vec2& position) {
        _position = position;
    }

    void Brick::setWalls() {
        _walls.push_back(Wall(Util::Line(glm::vec2(0.0f, 0.0f),         glm::vec2(getSize().x, 0.0f)),  glm::vec2( 0.0f, -1.0f)));
        _walls.push_back(Wall(Util::Line(glm::vec2(0.0f, 0.0f),         glm::vec2(0.0f, getSize().y)),  glm::vec2(-1.0f,  0.0f)));
        _walls.push_back(Wall(Util::Line(glm::vec2(0.0f, getSize().y),  getSize()),                     glm::vec2( 0.0f,  1.0f)));
        _walls.push_back(Wall(Util::Line(glm::vec2(getSize().x, 0.0f),  getSize()),                     glm::vec2( 1.0f,  0.0f)));
    }

    void Brick::setHasItem(bool value) {
        _hasItem = value;
    }

}