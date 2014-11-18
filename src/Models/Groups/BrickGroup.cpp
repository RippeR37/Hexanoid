#include "BrickGroup.h"

namespace Model {

    void BrickGroup::init() {
        glm::vec3 red    = glm::vec3(1.0f, 0.0f, 0.0f);
        glm::vec3 blue   = glm::vec3(0.0f, 0.0f, 1.0f);
        glm::vec3 orange = glm::vec3(1.0f, 0.5f, 0.0f);
        glm::vec3 pink   = glm::vec3(1.0f, 0.4f, 0.7f);
        glm::vec3 green  = glm::vec3(0.0f, 1.0f, 0.0f);
        glm::vec3 aquamarine = glm::vec3(0.5f, 1.0f, 0.8f);

        glm::vec3 colors[] = { red, blue, orange, pink, green, aquamarine };

        int colorID = 0;
        for(int y = 350; y < 440; y += 15) {
            for(int x = 250; x < 550; x += 30)
                insertBrick(Brick(glm::vec2(x, y), colors[colorID], glm::vec2(30.0f, 14.0f)));
            colorID++;
        }
    }

    void BrickGroup::update(ItemGroup& items) {
        for(std::vector<Brick>::iterator brick = _bricks.begin(); brick != _bricks.end(); ) {
            if(brick->isHit()) {
                brick->spawnItem(items);
                brick = _bricks.erase(brick);
            } else
                ++brick;
        }
    }

    void BrickGroup::insertBrick(const Brick& brick) {
        _bricks.push_back(brick);
    }

    unsigned int BrickGroup::getBricksLeft() const {
        return _bricks.size();
    }

    const std::vector<Brick>& BrickGroup::getBricks() const {
        return _bricks;
    }

    std::vector<Brick>& BrickGroup::getBricks() {
        return _bricks;
    }
    
}