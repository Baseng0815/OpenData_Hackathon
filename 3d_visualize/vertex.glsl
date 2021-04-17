#version 420

layout (location = 0) in vec3 position;
layout (location = 1) in vec3 normal;

out vec3 pass_Normal;
out float pass_Height;

uniform mat4 viewMatrix;
uniform mat4 projectionMatrix;
uniform mat4 modelMatrix;

void main()
{
    vec4 worldPos = modelMatrix * vec4(position, 1.f);
    pass_Height = worldPos.y;

    pass_Normal = transpose(inverse(mat3(modelMatrix))) * normal;

    gl_Position = projectionMatrix * viewMatrix * worldPos;
}
