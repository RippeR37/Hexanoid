#include "Item.h"

#include <cstdlib>

namespace Model {

    Item::Item() {
        setType(Type::Random);
        setSpeedFactor(100.0);
    }

    Item::Item(Type type) {
        setType(type);
        setSpeedFactor(100.0);
    }

    Item::Item(Type type, const glm::vec2& position) {
        setType(type);
        setPosition(position);
        setSpeedFactor(100.0);
    }

    void Item::update(double deltaTime) {
        _position.y -= static_cast<float>(deltaTime * getSpeedFactor());
    }

    void Item::setType(Type type) {
        if(type == Type::Random)
            type = (Type)(rand() % Type::Random);

        switch(type) {
            case Type::PaddleSize: 
                setColor(glm::vec3(0.0f, 0.0f, 0.7f)); break;
            case Type::ExtraLive: 
                setColor(glm::vec3(0.7f, 0.0f, 0.0f)); break;
            case Type::BallSpeedReduction: 
                setColor(glm::vec3(1.0f, 0.4f, 0.7f)); break;
        }

        _type = type;
    }

    void Item::setPosition(const glm::vec2& position) {
        _position = position;
    }

    Item::Type Item::getType() const {
        return _type;
    }
    
    const glm::vec3& Item::getColor() const {
        return _color;
    }

    const glm::vec2& Item::getPosition() const {
        return _position;
    }
    
    void Item::setColor(const glm::vec3& color) {
        _color = color;
    }

    void Item::setSpeedFactor(double speedFactor) {
        _speedFactor = speedFactor;
    }

    double Item::getSpeedFactor() const {
        return _speedFactor;
    }

}