#include "ViewBackground.h"
#include "../Game.h"

#include <glm/vec3.hpp>

namespace View {

    ViewBackground::ViewBackground() {
        _program.load(
            GL::Shader("assets/shaders/simple.vs", GL::Shader::Type::VertexShader),
            GL::Shader("assets/shaders/simple.fs", GL::Shader::Type::FragmentShader)
        );
    }

    ViewBackground::~ViewBackground() {

    }
            
    void ViewBackground::init() {
        initVBO();
        initVAO();
    }

    void ViewBackground::render() {
        _program.use();
        _program["uColor"].setVec(glm::vec3(0.106f));
        _program["uWindow"].setVec(static_cast<glm::vec2>(Game::get().getWindow().getSize()));
        _program["uTranslation"].setVec(glm::vec2(0.0f));

            _vao.bind();
                glDrawArrays(GL_TRIANGLES, 0, _vertexCount);
            _vao.unbind();

        _program.unbind();
    }

    void ViewBackground::initVAO() {
        _vao.bind();
            _vbo.bind();
                _vao.enableAttrib(0);
                _vao.setAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, (const GLvoid*)0);
            _vbo.unbind();
        _vao.unbind();
    }

    void ViewBackground::initVBO() {
        std::vector<glm::vec2> vertices = getVertices();

        _vbo.setUsage(GL::VertexBuffer::Usage::StaticDraw);
        _vbo.setTarget(GL::VertexBuffer::Target::Array);

        _vbo.bind();
        _vbo.setData(vertices);
        _vbo.unbind();
    }

    std::vector<glm::vec2> ViewBackground::getVertices() {
        std::vector<glm::vec2> vertices;
        glm::vec2 center;
        float angle, angle2;

        for(int y = 36; y < 560; y += 22) {
            for(int x = 108; x < 720; x += 34) {
                center = glm::vec2(x, y);

                for(int i = 0; i <= 6; ++i) {
                    angle  = 2 * 3.14f * static_cast<float>(i) * (1.0f / 6.0f);
                    angle2 = 2 * 3.14f * static_cast<float>(i + 1) * (1.0f / 6.0f);
                    
                    vertices.push_back(center);
                    vertices.push_back(center + (glm::vec2(std::cos(angle),  std::sin(angle))  * 10.0f));
                    vertices.push_back(center + (glm::vec2(std::cos(angle2), std::sin(angle2)) * 10.0f));
                }
            }
        }

        for(int y = 47; y < 571; y += 22) {
            for(int x = 125; x < 720; x += 34) {
                center = glm::vec2(x, y);

                for(int i = 0; i <= 6; ++i) {
                    angle  = 2 * 3.14f * static_cast<float>(i) * (1.0f / 6.0f);
                    angle2 = 2 * 3.14f * static_cast<float>(i + 1) * (1.0f / 6.0f);
                    
                    vertices.push_back(center);
                    vertices.push_back(center + (glm::vec2(std::cos(angle),  std::sin(angle))  * 10.0f));
                    vertices.push_back(center + (glm::vec2(std::cos(angle2), std::sin(angle2)) * 10.0f));
                }
            }
        }

        // Clipping
        for(glm::vec2& vec : vertices) {
            if(vec.x < 108) vec.x = 108;
            if(vec.x > 691) vec.x = 691;

            if(vec.y <  48) vec.y =  48;
            if(vec.y > 550) vec.y = 550;
        }

        _vertexCount = vertices.size();
        return vertices;
    }



}