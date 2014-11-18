#include "ItemGroup.h"
#include "../Paddle.h"

namespace Model {

    void ItemGroup::update(double deltaTime, Paddle& paddle, Ball& ball) {
        for(std::vector<Item>::iterator item = _items.begin(); item != _items.end(); ) {
            item->update(deltaTime);

            if(item->getPosition().x <= paddle.getPosition().x + paddle.getWidth() &&
               item->getPosition().x + 30.0f >= paddle.getPosition().x) {

                   if(item->getPosition().y < 50.0f && item->getPosition().y > 25) {
                       paddle.aquire(*item, ball);
                       item = _items.erase(item);
                       continue;
                   }
            }
            
            if(item->getPosition().y < 20) {
                item = _items.erase(item);
                continue;
            }
            
            ++item;
        }
    }

    void ItemGroup::insert(const Item& item) {
        _items.push_back(item);
    }

    const std::vector<Item>& ItemGroup::getItems() const {
        return _items;
    }

}