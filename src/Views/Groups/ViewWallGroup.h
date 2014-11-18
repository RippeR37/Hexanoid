#ifndef VIEW_GROUP_WALLGROUP_H_INCLUDED
#define VIEW_GROUP_WALLGROUP_H_INCLUDED

#include "../View.h"
#include "../../Models/Groups/WallGroup.h"
#include "../../Utils/GL+/Program.h"
#include "../../Utils/GL+/VertexArray.h"
#include "../../Utils/GL+/VertexBuffer.h"

namespace View {

    class ViewWallGroup : public View<Model::WallGroup> {
        public:
            ViewWallGroup();
            ~ViewWallGroup();
            
            void init(const Model::WallGroup& walls);
            void render(const Model::WallGroup& walls);

        private:
            void initVAO();
            void initVBO(const Model::WallGroup& walls);
            std::vector<glm::vec2> getVertices(const Model::WallGroup& walls);

            unsigned int _vertexCount;
            GL::Program _program;
            GL::VertexArray _vao;
            GL::VertexBuffer _vbo;
    };

}

#endif