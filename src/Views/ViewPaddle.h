#ifndef VIEW_PADDLE_H_INCLUDED
#define VIEW_PADDLE_H_INCLUDED

#include "View.h"
#include "../Models/Paddle.h"
#include "../Utils/GL+/Program.h"
#include "../Utils/GL+/VertexArray.h"
#include "../Utils/GL+/VertexBuffer.h"

namespace View {

    class ViewPaddle : public View<Model::Paddle> {
        public:
            ViewPaddle();
            ~ViewPaddle();
            
            void init(const Model::Paddle& paddle);
            void render(const Model::Paddle& paddle);

        private:
            void initVAO();
            void initVBO(const Model::Paddle& paddle);
            std::vector<glm::vec2> getVertices(const Model::Paddle& paddle);

            GL::Program _program;
            GL::VertexArray _vao;
            GL::VertexBuffer _vbo;

        public:
            friend class Model::Paddle;
    };

}

#endif