#ifndef MODEL_ITEM_H_INCLUDED
#define MODEL_ITEM_H_INCLUDED

#include <glm/vec2.hpp>
#include <glm/vec3.hpp>

namespace Model {

    class Item {
        public:
            enum Type {
                PaddleSize = 0,
                ExtraLive = 1,
                BallSpeedReduction = 2,
                Random
            };

        public:
            Item();
            Item(Type type);
            Item(Type type, const glm::vec2& position);

            void update(double deltaTime);

            void setType(Type type);
            void setPosition(const glm::vec2& position);

            Type getType() const;
            const glm::vec3& getColor() const;
            const glm::vec2& getPosition() const;

        private:
            void setColor(const glm::vec3& color);
            void setSpeedFactor(double speedFactor);

            double getSpeedFactor() const;

            Type _type;
            glm::vec3 _color;
            glm::vec2 _position;
            double _speedFactor;
    };

}

#endif
