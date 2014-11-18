#ifndef MODEL_GROUP_WALLGROUP_H_INCLUDED
#define MODEL_GROUP_WALLGROUP_H_INCLUDED

#include "../Wall.h"

#include <glm/vec2.hpp>

#include <vector>

namespace Model {

    class WallGroup {
        public:
            void init();
            void insertWall(const Wall& wall);
            const std::vector<Wall>& getWalls() const;

        private:
            std::vector<Wall> _walls;
    };

}

#endif