#include "WallGroup.h"

#include <glm/geometric.hpp>

namespace Model {

    void WallGroup::init() {
        // Boundries
        insertWall(Wall(Util::Line(glm::vec2(255.0f, 550.0f), glm::vec2(544.0f, 550.0f)))); /*   -   */
        insertWall(Wall(Util::Line(glm::vec2(110.5f, 300.0f), glm::vec2(255.0f, 550.0f)))); /*  /    */
        insertWall(Wall(Util::Line(glm::vec2(110.5f, 300.0f), glm::vec2(255.0f,  50.0f)))); /*  \    */
        insertWall(Wall(Util::Line(glm::vec2(544.0f, 550.0f), glm::vec2(688.0f, 300.0f)))); /*    \  */
        insertWall(Wall(Util::Line(glm::vec2(544.0f,  50.0f), glm::vec2(688.0f, 300.0f)))); /*    /  */

        if(true) {
            // 2nd walls
            insertWall(Wall(Util::Line(glm::vec2(253.0f, 552.0f), glm::vec2(546.0f, 552.0f)), false));
            insertWall(Wall(Util::Line(glm::vec2(107.5f, 300.0f), glm::vec2(253.0f, 552.0f)), false));
            insertWall(Wall(Util::Line(glm::vec2(107.5f, 300.0f), glm::vec2(253.0f,  48.0f)), false));
            insertWall(Wall(Util::Line(glm::vec2(546.0f, 552.0f), glm::vec2(691.0f, 300.0f)), false));
            insertWall(Wall(Util::Line(glm::vec2(546.0f,  48.0f), glm::vec2(691.0f, 300.0f)), false));
        
            // Borders
            insertWall(Wall(Util::Line(glm::vec2(107.5f,  48.0f), glm::vec2(253.0f,  48.0f)), false));
            insertWall(Wall(Util::Line(glm::vec2(108.0f,  48.0f), glm::vec2(108.0f, 552.0f)), false));
            insertWall(Wall(Util::Line(glm::vec2(108.0f, 552.0f), glm::vec2(691.0f, 552.0f)), false));
            insertWall(Wall(Util::Line(glm::vec2(691.0f, 552.0f), glm::vec2(691.0f,  48.0f)), false));
            insertWall(Wall(Util::Line(glm::vec2(546.0f,  48.0f), glm::vec2(691.0f,  48.0f)), false));
            
            insertWall(Wall(Util::Line(glm::vec2(253.0f,  50.0f), glm::vec2(546.0f,  50.0f)), false));
        }

    }

    void WallGroup::insertWall(const Wall& wall) {
        _walls.push_back(wall);
    }

    const std::vector<Wall>& WallGroup::getWalls() const {
        return _walls;
    }

}