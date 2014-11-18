#include "VertexArray.h"

namespace GL {

    VertexArray::VertexArray() {
        create();
    }

    VertexArray::~VertexArray() {
        destroy();
    }

    void VertexArray::bind() {
        glBindVertexArray(_vaoID);
    }

    void VertexArray::unbind() {
        glBindVertexArray(0);
    }

    void VertexArray::enableAttrib(GLuint index) {
        glEnableVertexAttribArray(index);
    }

    void VertexArray::disableAttrib(GLuint index) {
        glDisableVertexAttribArray(index);
    }

    void VertexArray::setAttribPointer(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const GLvoid* pointer) {
        glVertexAttribPointer(index, size, type, normalized, stride, pointer);
    }

    GLuint VertexArray::getID() const {
        return _vaoID;
    }

    void VertexArray::create() {
        glGenVertexArrays(1, &_vaoID);
    }

    void VertexArray::destroy() {
        glDeleteVertexArrays(1, &_vaoID);
    }

}