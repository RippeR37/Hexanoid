#include "ViewPaddle.h"
#include "../Game.h"

#include <glm/vec3.hpp>

#include <vector>

namespace View {

    ViewPaddle::ViewPaddle() {
        _program.load(
            GL::Shader("assets/shaders/simple.vs", GL::Shader::Type::VertexShader),
            GL::Shader("assets/shaders/simple.fs", GL::Shader::Type::FragmentShader)
        );
    }

    ViewPaddle::~ViewPaddle() {

    }

    void ViewPaddle::init(const Model::Paddle& paddle) {
        initVBO(paddle);
        initVAO();
    }

    void ViewPaddle::render(const Model::Paddle& paddle) {
        _program.use();
        _program["uWindow"].setVec(static_cast<glm::vec2>(Game::get().getWindow().getSize()));
        _program["uTranslation"].setVec(paddle.getPosition());
            _vao.bind();
        
        // Shadow
        _program["uColor"].setVec(glm::vec3(0.08f));
        _program["uTranslation"].setVec(paddle.getPosition() + glm::vec2(15.0f, -10.0f));
                glDrawArrays(GL_TRIANGLE_FAN, 0, 16);
        
        // Paddle
        _program["uColor"].setVec(glm::vec3(1.0f, 0.0f, 0.0f));
        _program["uTranslation"].setVec(paddle.getPosition());
                glDrawArrays(GL_TRIANGLE_FAN, 0, 16);

            _vao.unbind();
        _program.unbind();
    }

    void ViewPaddle::initVAO() {
        _vao.bind();
            _vbo.bind();
                _vao.enableAttrib(0);
                _vao.setAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, (const GLvoid*)0);
            _vbo.unbind();
        _vao.unbind();
    }

    void ViewPaddle::initVBO(const Model::Paddle& paddle) {
        std::vector<glm::vec2> vertices = getVertices(paddle);

        _vbo.setUsage(GL::VertexBuffer::Usage::StaticDraw);
        _vbo.setTarget(GL::VertexBuffer::Target::Array);

        _vbo.bind();
        _vbo.setData(vertices);
        _vbo.unbind();
    }

    std::vector<glm::vec2> ViewPaddle::getVertices(const Model::Paddle& paddle) {
        std::vector<glm::vec2> vertices;
        glm::vec2 center;
        float halfWidth;
        float angle;
        
        halfWidth = paddle.getWidth() / 2.0f;
        center = glm::vec2(halfWidth, 0.0f);

        vertices.push_back(center);
        for(int i = 0; i < 15; ++i) {
            angle = 3.14f * (i / 14.0f);
            vertices.push_back(center + glm::vec2(cos(angle) * halfWidth, sin(angle) * paddle.getHeight()));
        }

        return vertices;
    }

}