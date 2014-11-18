#include "ViewBorder.h"
#include "../Game.h"

#include <glm/vec3.hpp>

namespace View {

    ViewBorder::ViewBorder() {
        _program.load(
            GL::Shader("assets/shaders/simple.vs", GL::Shader::Type::VertexShader),
            GL::Shader("assets/shaders/simple.fs", GL::Shader::Type::FragmentShader)
        );
    }

    ViewBorder::~ViewBorder() {

    }

    void ViewBorder::init() {
        initVBO();
        initVAO();
    }

    void ViewBorder::render() {
        _program.use();
        _program["uColor"].setVec(glm::vec3(0.0f, 0.0f, 0.0f));
        _program["uWindow"].setVec(static_cast<glm::vec2>(Game::get().getWindow().getSize()));
        _program["uTranslation"].setVec(glm::vec2(0.0f));

            _vao.bind();
                glLineWidth(3.0f);
                glDrawArrays(GL_LINES, 0, 8);
                glLineWidth(1.0f);
            _vao.unbind();

        _program.unbind();
    }

    void ViewBorder::initVAO() {
        _vao.bind();
            _vbo.bind();
                _vao.enableAttrib(0);
                _vao.setAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, (const GLvoid*)0);
            _vbo.unbind();
        _vao.unbind();
    }

    void ViewBorder::initVBO() {
        std::vector<glm::vec2> vertices = getVertices();

        _vbo.setUsage(GL::VertexBuffer::Usage::StaticDraw);
        _vbo.setTarget(GL::VertexBuffer::Target::Array);

        _vbo.bind();
        _vbo.setData(vertices);
        _vbo.unbind();
    }

    std::vector<glm::vec2> ViewBorder::getVertices() {
        std::vector<glm::vec2> vertices;
        
        vertices.push_back(glm::vec2(198.0f,  40.0f));
        vertices.push_back(glm::vec2(198.0f, 552.0f));

        vertices.push_back(glm::vec2(198.0f, 552.0f));
        vertices.push_back(glm::vec2(600.0f, 552.0f));

        vertices.push_back(glm::vec2(600.0f, 552.0f));
        vertices.push_back(glm::vec2(600.0f,  40.0f));

        vertices.push_back(glm::vec2(600.0f,  40.0f));
        vertices.push_back(glm::vec2(198.0f,  40.0f));


        return vertices;
    }

}