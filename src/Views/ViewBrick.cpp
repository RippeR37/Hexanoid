#include "ViewBrick.h"
#include "../Game.h"

#include <glm/vec3.hpp>

#include <vector>

namespace View {

    ViewBrick::ViewBrick() {
        _program.load(
            GL::Shader("assets/shaders/simple.vs", GL::Shader::Type::VertexShader),
            GL::Shader("assets/shaders/simple.fs", GL::Shader::Type::FragmentShader)
        );
    }

    ViewBrick::~ViewBrick() {

    }

    void ViewBrick::init(const Model::Brick& brick) {
        initVBO(brick);
        initVAO();
    }

    void ViewBrick::render(const Model::Brick& brick) {
        _program.use();
        _program["uWindow"].setVec(static_cast<glm::vec2>(Game::get().getWindow().getSize()));
        _program["uTranslation"].setVec(brick.getPosition());

        
        _program["uColor"].setVec(brick.getColor() * 0.4f);
            _vao[0].bind();
                glDrawArrays(GL_TRIANGLES, 0, _vertexCount[0]);
            _vao[0].unbind();

            
        _program["uColor"].setVec(brick.getColor());
            _vao[1].bind();
                glDrawArrays(GL_LINES, 0, _vertexCount[1]);
            _vao[1].unbind();

        _program.unbind();
    }

    void ViewBrick::initVAO() {
        for(int i = 0; i < 2; ++i) {
            _vao[i].bind();
                _vbo[i].bind();
                    _vao[i].enableAttrib(0);
                    _vao[i].setAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, (const GLvoid*)0);
                _vbo[i].unbind();
            _vao[i].unbind();
        }
    }

    void ViewBrick::initVBO(const Model::Brick& brick) {
        std::vector<glm::vec2> vertices[2];

        vertices[0] = getVertices1(brick);
        vertices[1] = getVertices2(brick);

        for(int i = 0; i < 2; ++i) {
            _vbo[i].setUsage(GL::VertexBuffer::Usage::StaticDraw);
            _vbo[i].setTarget(GL::VertexBuffer::Target::Array);

            _vbo[i].bind();
            _vbo[i].setData(vertices[i]);
            _vbo[i].unbind();
        }
    }

    std::vector<glm::vec2> ViewBrick::getVertices1(const Model::Brick& brick) {
        std::vector<glm::vec2> vertices;

        for(const Model::Wall& wall : brick.getWalls()) {
            vertices.push_back(glm::vec2(0.0f, 0.0f));
            vertices.push_back(wall.getPosition1());
            vertices.push_back(wall.getPosition2());
        }

        _vertexCount[0] = vertices.size();
        return vertices;
    }

    std::vector<glm::vec2> ViewBrick::getVertices2(const Model::Brick& brick) {
        std::vector<glm::vec2> vertices;

        for(const Model::Wall& wall : brick.getWalls()) {
            vertices.push_back(wall.getPosition1());
            vertices.push_back(wall.getPosition2());
        }

        _vertexCount[1] = vertices.size();
        return vertices;
    }

}