#include "ViewBall.h"
#include "../Game.h"

#include <glm/vec3.hpp>

#include <vector>

namespace View {

    ViewBall::ViewBall() {
        _program.load(
            GL::Shader("assets/shaders/simple.vs", GL::Shader::Type::VertexShader),
            GL::Shader("assets/shaders/simple.fs", GL::Shader::Type::FragmentShader)
        );
    }

    ViewBall::~ViewBall() {

    }

    void ViewBall::init(const Model::Ball& ball) {
        initVBO(ball);
        initVAO();
    }

    void ViewBall::render(const Model::Ball& ball) {
        _program.use();
        _program["uWindow"].setVec(static_cast<glm::vec2>(Game::get().getWindow().getSize()));
            _vao.bind();
            
        // Shadow
        _program["uColor"].setVec(glm::vec3(0.08f));
        _program["uTranslation"].setVec(ball.getPosition() + glm::vec2(15.0f, -10.0f));
                glDrawArrays(GL_TRIANGLE_FAN, 0, 16);
        
        // Ball
        _program["uColor"].setVec(glm::vec3(1.0f, 1.0f, 1.0f));
        _program["uTranslation"].setVec(ball.getPosition());
                glDrawArrays(GL_TRIANGLE_FAN, 0, 16);

            _vao.unbind();
        _program.unbind();
    }

    void ViewBall::initVAO() {
        _vao.bind();
            _vbo.bind();
                _vao.enableAttrib(0);
                _vao.setAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, (const GLvoid*)0);
            _vbo.unbind();
        _vao.unbind();
    }

    void ViewBall::initVBO(const Model::Ball& ball) {
        std::vector<glm::vec2> vertices = getVertices(ball);

        _vbo.setUsage(GL::VertexBuffer::Usage::StaticDraw);
        _vbo.setTarget(GL::VertexBuffer::Target::Array);

        _vbo.bind();
        _vbo.setData(vertices);
        _vbo.unbind();
    }

    std::vector<glm::vec2> ViewBall::getVertices(const Model::Ball& ball) {
        std::vector<glm::vec2> vertices;
        glm::vec2 center;

        float radius;
        float step;
        int steps;

        steps = 14;
        radius = static_cast<float>(ball.getRadius());
        center = glm::vec2(radius, radius);
        
        vertices.push_back(center);
        for(int i = 0; i <= steps; ++i) {
            step = (static_cast<float>(i) * 2 * 3.14f) / static_cast<float>(steps);
            vertices.push_back(center + glm::vec2(std::cos(step), std::sin(step)) * radius);
        }

        return vertices;
    }

}