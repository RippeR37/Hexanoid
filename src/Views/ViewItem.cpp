#include "ViewItem.h"
#include "../Game.h"

#include <glm/vec3.hpp>

namespace View {

    ViewItem::ViewItem() {
        _program.load(
            GL::Shader("assets/shaders/item.vs", GL::Shader::Type::VertexShader),
            GL::Shader("assets/shaders/item.fs", GL::Shader::Type::FragmentShader)
        );
    }

    ViewItem::~ViewItem() {

    }
            
    void ViewItem::init(const Model::Item& item) {
        initVBO(item);
        initVAO();
    }

    void ViewItem::render(const Model::Item& item) {
        _program.use();
        _program["uWindow"].setVec(static_cast<glm::vec2>(Game::get().getWindow().getSize()));
        _program["uTranslation"].setVec(item.getPosition());

            _vao[item.getType()].bind();
                glDrawArrays(GL_TRIANGLES, 0, 24);
            _vao[item.getType()].unbind();

        _program.unbind();
    }

    void ViewItem::initVAO() {
        for(int i = 0; i < 3; ++i) {
            _vao[i].bind();
                _vbo[0].bind();
                    _vao[i].enableAttrib(0);
                    _vao[i].setAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, (const GLvoid*)0);
                _vbo[0].unbind();

                _vbo[i + 1].bind();
                    _vao[i].enableAttrib(1);
                    _vao[i].setAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 0, (const GLvoid*)0);
                _vbo[i + 1].unbind();
            _vao[i].unbind();
        }
    }

    void ViewItem::initVBO(const Model::Item& item) {
        std::vector<glm::vec2> vertices = getVertices(item);
        std::vector<glm::vec4> colors;

        for(int i = 0; i < 4; ++i) {
            _vbo[i].setUsage(GL::VertexBuffer::Usage::StaticDraw);
            _vbo[i].setTarget(GL::VertexBuffer::Target::Array);
        }

        _vbo[0].bind();
        _vbo[0].setData(vertices);
        _vbo[1].unbind();

        for(int i = 0; i < 3; ++i) {
            colors = getColors(static_cast<Model::Item::Type>(i));

            _vbo[i + 1].bind();
            _vbo[i + 1].setData(colors);
            _vbo[i + 1].unbind();
        }
    }

    std::vector<glm::vec2> ViewItem::getVertices(const Model::Item& item) {
        std::vector<glm::vec2> vertices;

        float width = 30.0f;
        float height = 15.0f;

        // <
        vertices.push_back(glm::vec2( 0.0f, height / 2.0f));
        vertices.push_back(glm::vec2(width / 5.0f, 0.0f));
        vertices.push_back(glm::vec2(width / 5.0f, height));
        
        // <   >
        vertices.push_back(glm::vec2(4.0f * width / 5.0f, height));
        vertices.push_back(glm::vec2(4.0f * width / 5.0f, 0.0f));
        vertices.push_back(glm::vec2(width, height / 2.0f));

        // < # >
        vertices.push_back(glm::vec2(width / 5.0f, 0.0f));
        vertices.push_back(glm::vec2(4.0f * width / 5.0f, 0.0f));
        vertices.push_back(glm::vec2(width / 5.0f, height));
        vertices.push_back(glm::vec2(width / 5.0f, height));
        vertices.push_back(glm::vec2(4.0f * width / 5.0f, 0.0f));
        vertices.push_back(glm::vec2(4.0f * width / 5.0f, height));

        // <|# >
        vertices.push_back(glm::vec2(width / 5.0f, 0.0f));
        vertices.push_back(glm::vec2(width / 5.0f + 2.0f, 0.0f));
        vertices.push_back(glm::vec2(width / 5.0f, height));
        vertices.push_back(glm::vec2(width / 5.0f, height));
        vertices.push_back(glm::vec2(width / 5.0f + 2.0f, 0.0f));
        vertices.push_back(glm::vec2(width / 5.0f + 2.0f, height));

        // <|#|>
        vertices.push_back(glm::vec2(4.0f *width / 5.0f - 2.0f, 0.0f));
        vertices.push_back(glm::vec2(4.0f *width / 5.0f, 0.0f));
        vertices.push_back(glm::vec2(4.0f *width / 5.0f - 2.0f, height));
        vertices.push_back(glm::vec2(4.0f *width / 5.0f - 2.0f, height));
        vertices.push_back(glm::vec2(4.0f *width / 5.0f, 0.0f));
        vertices.push_back(glm::vec2(4.0f *width / 5.0f, height));


        return vertices;
    }

    std::vector<glm::vec4> ViewItem::getColors(Model::Item::Type type) {
        std::vector<glm::vec4> colors;

        float width = 30.0f;
        float height = 15.0f;
        
        glm::vec4 colorRED   = glm::vec4(0.7f, 0.0f, 0.0f, 1.0f);
        glm::vec4 colorBLUE  = glm::vec4(0.0f, 0.0f, 0.7f, 1.0f);
        glm::vec4 colorROSE  = glm::vec4(1.0f, 0.4f, 0.7f, 1.0f);
        glm::vec4 colorWHITE = glm::vec4(1.0f);

        glm::vec4 mainColor[4] = {
            colorBLUE, colorRED, colorROSE, colorWHITE
        };

        // <
        colors.push_back(mainColor[type]);
        colors.push_back(mainColor[type]);
        colors.push_back(mainColor[type]);
        
        // <   >
        colors.push_back(mainColor[type]);
        colors.push_back(mainColor[type]);
        colors.push_back(mainColor[type]);
        
        // < # >
        colors.push_back(mainColor[type] * 0.95f);
        colors.push_back(mainColor[type] * 0.95f);
        colors.push_back(mainColor[type] * 0.95f);
        colors.push_back(mainColor[type] * 0.95f);
        colors.push_back(mainColor[type] * 0.95f);
        colors.push_back(mainColor[type] * 0.95f);

        // <|#|>
        colors.push_back(mainColor[type] * 1.3f);
        colors.push_back(mainColor[type] * 1.3f);
        colors.push_back(mainColor[type] * 1.3f);
        colors.push_back(mainColor[type] * 1.3f);
        colors.push_back(mainColor[type] * 1.3f);
        colors.push_back(mainColor[type] * 1.3f);
        colors.push_back(mainColor[type] * 1.3f);
        colors.push_back(mainColor[type] * 1.3f);
        colors.push_back(mainColor[type] * 1.3f);
        colors.push_back(mainColor[type] * 1.3f);
        colors.push_back(mainColor[type] * 1.3f);
        colors.push_back(mainColor[type] * 1.3f);

        return colors;
    }

}