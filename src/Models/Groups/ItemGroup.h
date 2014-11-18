#ifndef MODEL_GROUP_ITEMGROUP_H_INCLUDED
#define MODEL_GROUP_ITEMGROUP_H_INCLUDED

#include "../Item.h"
#include "../Paddle.h"

#include <vector>

namespace Model {
    
    class Ball;

    class ItemGroup {
        public:
            void update(double deltaTime, Model::Paddle& paddle, Ball& ball);
            void insert(const Item& item);

            const std::vector<Item>& getItems() const;

        private:
            std::vector<Item> _items;
    };

}

#endif