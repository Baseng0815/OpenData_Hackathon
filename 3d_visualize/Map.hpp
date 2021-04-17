#pragma once

#include <GL/glew.h>
#include <string>

#include "Shader.hpp"
#include "Camera.hpp"

struct Vertex {
    glm::vec3 position;
    glm::vec3 normal;
};

class Map {
    public:
        Map(const std::string &hgtFile);
        ~Map();

        void render(const Shader &shader, const Camera &camera);

    private:
        GLuint m_vao, m_vbo, m_ebo;
        unsigned int m_drawCount;
};
