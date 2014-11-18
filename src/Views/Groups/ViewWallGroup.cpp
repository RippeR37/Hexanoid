#include "ViewWallGroup.h"
#include "../../Game.h"

#include <glm/vec3.hpp>

#include <vector>

namespace View {

    ViewWallGroup::ViewWallGroup() {
        _program.load(
            GL::Shader("assets/shaders/simple.vs", GL::Shader::Type::VertexShader),
            GL::Shader("assets/shaders/simple.fs", GL::Shader::Type::FragmentShader)
        );
    }

    ViewWallGroup::~ViewWallGroup() {

    }

    void ViewWallGroup::init(const Model::WallGroup& walls) {
        initVBO(walls);
        initVAO();
    }

    void ViewWallGroup::render(const Model::WallGroup& walls) {
        _program.use();
        _program["uColor"].setVec(glm::vec3(0.2f, 0.3f, 1.0f));
        _program["uWindow"].setVec(static_cast<glm::vec2>(Game::get().getWindow().getSize()));
        _program["uTranslation"].setVec(glm::vec2(0.0));

            _vao.bind();
                glDrawArrays(GL_LINES, 0, _vertexCount);
            _vao.unbind();

        _program.unbind();
    }

    void ViewWallGroup::initVAO() {
        _vao.bind();
            _vbo.bind();
                _vao.enableAttrib(0);
                _vao.setAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, (const GLvoid*)0);
            _vbo.unbind();
        _vao.unbind();
    }

    void ViewWallGroup::initVBO(const Model::WallGroup& walls) {
        std::vector<glm::vec2> vertices = getVertices(walls);

        _vbo.setUsage(GL::VertexBuffer::Usage::StaticDraw);
        _vbo.setTarget(GL::VertexBuffer::Target::Array);

        _vbo.bind();
        _vbo.setData(vertices);
        _vbo.unbind();
    }

    std::vector<glm::vec2> ViewWallGroup::getVertices(const Model::WallGroup& walls) {
        std::vector<glm::vec2> vertices;

        for(const Model::Wall& wall : walls.getWalls()) {
            vertices.push_back(wall.getPosition1());
            vertices.push_back(wall.getPosition2());
        }

        _vertexCount = vertices.size();

        return vertices;
    }

}