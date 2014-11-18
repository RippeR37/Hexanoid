#version 330 core

layout(location = 0) in vec2 vPos;

out vec3 vCol;

uniform vec3 uColor;
uniform vec2 uWindow;
uniform vec2 uTranslation;

void main() {
    // Transform coords from [-1, 1][-1, 1] to [0, windowWidth][0, windowHeight]
    vec2 position = ((vPos + uTranslation) / uWindow) * 2.0f - vec2(1.0f);
    
    // Assing position
    gl_Position = vec4(position, 0.0, 1.0);

    // Assing color
    vCol = uColor;
}
