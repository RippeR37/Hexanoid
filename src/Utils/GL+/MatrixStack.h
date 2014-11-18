#ifndef UTILS_GL_MATRIXSTACK_H_INCLUDED
#define UTILS_GL_MATRIXSTACK_H_INCLUDED

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/matrix.hpp>

#include <stack>

namespace GL {

    class MatrixStack {
        public:
            MatrixStack();
            ~MatrixStack();

            void loadID();
            void loadMatrix(glm::mat4& matrix);
            void multiplyMatrix(glm::mat4& matrix);

            void popMatrix();
            void pushMatrix();
            void pushMatrix(glm::mat4& matrix);

            void rotate(float angle, float x, float y, float z);
            void rotate(float angle, glm::vec3& vector);

            void translate(float x, float y, float z);
            void translate(glm::vec3& vector);

            void scale(float x, float y, float z);
            void scale(glm::vec3& vector);

            const glm::mat4& getMatrix() const;

        private:
            std::stack<glm::mat4> _stack;
            
    };

}

#endif