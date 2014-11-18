#ifndef VIEW_BACKGROUND_H_INCLUDED
#define VIEW_BACKGROUND_H_INCLUDED

#include "View.h"
#include "../Utils/GL+/Program.h"
#include "../Utils/GL+/VertexArray.h"
#include "../Utils/GL+/VertexBuffer.h"

#include <glm/vec2.hpp>

namespace View {

    class ViewBackground : View<void> {
        public:
            ViewBackground();
            ~ViewBackground();
            
            void init();
            void render();

        private:
            void initVAO();
            void initVBO();
            std::vector<glm::vec2> getVertices();

            unsigned int _vertexCount;
            GL::Program _program;
            GL::VertexArray _vao;
            GL::VertexBuffer _vbo;
    };

}

#endif