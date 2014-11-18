#ifndef VIEW_BALL_H_INCLUDED
#define VIEW_BALL_H_INCLUDED

#include "View.h"
#include "../Models/Ball.h"
#include "../Utils/GL+/Program.h"
#include "../Utils/GL+/VertexArray.h"
#include "../Utils/GL+/VertexBuffer.h"

namespace View {

    class ViewBall : public View<Model::Ball> {
        public:
            ViewBall();
            ~ViewBall();
            
            void init(const Model::Ball& ball);
            void render(const Model::Ball& ball);

        private:
            void initVAO();
            void initVBO(const Model::Ball& ball);
            std::vector<glm::vec2> getVertices(const Model::Ball& ball);

            GL::Program _program;
            GL::VertexArray _vao;
            GL::VertexBuffer _vbo;
    };

}

#endif