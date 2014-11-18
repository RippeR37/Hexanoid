#ifndef VIEW_ITEM_H_INCLUDED
#define VIEW_ITEM_H_INCLUDED

#include "View.h"
#include "../Models/Item.h"
#include "../Utils/GL+/Program.h"
#include "../Utils/GL+/VertexArray.h"
#include "../Utils/GL+/VertexBuffer.h"

namespace View {

    class ViewItem : View<Model::Item> {
        public:
            ViewItem();
            ~ViewItem();
            
            void init(const Model::Item& item);
            void render(const Model::Item& item);

        private:
            void initVAO();
            void initVBO(const Model::Item& item);

            std::vector<glm::vec2> getVertices(const Model::Item& item);
            std::vector<glm::vec4> getColors(Model::Item::Type type);

            GL::Program _program;
            GL::VertexArray _vao[3];
            GL::VertexBuffer _vbo[4];
    };

}


#endif
