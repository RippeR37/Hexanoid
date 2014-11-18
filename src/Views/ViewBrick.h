#ifndef VIEW_BRICK_H_INCLUDED
#define VIEW_BRICK_H_INCLUDED

#include "View.h"
#include "../Models/Brick.h"
#include "../Utils/GL+/Program.h"
#include "../Utils/GL+/VertexArray.h"
#include "../Utils/GL+/VertexBuffer.h"

namespace View {

    class ViewBrick : public View<Model::Brick> {
        public:
            ViewBrick();
            ~ViewBrick();
            
            void init(const Model::Brick& brick);
            void render(const Model::Brick& brick);

        private:
            void initVAO();
            void initVBO(const Model::Brick& brick);

            std::vector<glm::vec2> getVertices1(const Model::Brick& brick);
            std::vector<glm::vec2> getVertices2(const Model::Brick& brick);

            unsigned int _vertexCount[2];
            GL::Program _program;
            GL::VertexArray _vao[2];
            GL::VertexBuffer _vbo[2];
    };

}

#endif