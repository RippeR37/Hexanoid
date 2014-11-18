#ifndef VIEW_BORDER_H_INCLUDED
#define VIEW_BORDER_H_INCLUDED

#include "View.h"
#include "../Utils/GL+/Program.h"
#include "../Utils/GL+/VertexArray.h"
#include "../Utils/GL+/VertexBuffer.h"

#include <glm/vec2.hpp>

#include <vector>

namespace View {

    class ViewBorder {
        public:
            ViewBorder();
            ~ViewBorder();
            
            void init();
            void render();

        private:
            void initVAO();
            void initVBO();
            std::vector<glm::vec2> getVertices();

            GL::Program _program;
            GL::VertexArray _vao;
            GL::VertexBuffer _vbo;
    };

}

#endif