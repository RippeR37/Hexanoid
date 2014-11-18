#ifndef VIEW_GROUP_BRICKGROUP_H_INCLUDED
#define VIEW_GROUP_BRICKGROUP_H_INCLUDED

#include "../View.h"
#include "../ViewBrick.h"
#include "../../Models/Groups/BrickGroup.h"
#include "../../Utils/GL+/Program.h"
#include "../../Utils/GL+/VertexArray.h"
#include "../../Utils/GL+/VertexBuffer.h"

namespace View {

    class ViewBrickGroup : public View<Model::BrickGroup> {
        public:
            ViewBrickGroup();
            ~ViewBrickGroup();
            
            void init(const Model::BrickGroup& bricks);
            void render(const Model::BrickGroup& bricks);

        private:
            ViewBrick _viewBrick;
    };

}

#endif