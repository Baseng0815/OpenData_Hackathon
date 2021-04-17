#include "Map.hpp"

#include <fstream>

#include <iostream>

Map::Map(const std::string &hgtFile)
{
    glGenVertexArrays(1, &m_vao);
    glBindVertexArray(m_vao);
    glGenBuffers(1, &m_vbo);
    glGenBuffers(1, &m_ebo);
    glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ebo);

    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE,
                          sizeof(Vertex), (void*)(0));
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE,
                          sizeof(Vertex), (void*)(12));

    std::ifstream file(hgtFile, std::ios::binary);
    std::vector<unsigned char> buf(std::istreambuf_iterator<char>(file), {});

    std::vector<int> heights(buf.size() / 2);
    int max_height = 0;
    for (size_t i = 0; i < buf.size(); i += 2) {
        int higher  = (int)buf[i + 0];
        int lower   = (int)buf[i + 1];

        heights[i / 2] = (lower | (higher << 8));
        if (heights[i / 2] > max_height)
            max_height = heights[i / 2];
    }

    std::vector<Vertex> vertices;
    std::vector<unsigned int> indices;

    float scale = 255.f / max_height;

    /* vertices */
    for (int x = 0; x < 3601; x++) {
        for (int y = 0; y < 3601; y++) {
            float hgt = heights[y * 3601 + x] * scale;
            Vertex vertex;
            vertex.position = glm::vec3(x, hgt, y);
            /* calculate normal
               (https://stackoverflow.com/questions/49640250/calculate-normals-from-heightmap)
               */

            float l, t, r, b;
            if (x == 0) l = 0;
            else l = heights[y * 3601 + x - 1] * scale;

            if (x == 3600) r = 0;
            else r = heights[y * 3601 + x + 1] * scale;

            if (y == 0) t = 0;
            else t = heights[(y - 1) * 3601 + x] * scale;

            if (y == 3600) b = 0;
            else b = heights[(y + 1) * 3601 + x] * scale;

            vertex.normal = glm::normalize(glm::vec3(2.f * (r - l),
                                                     -4.f,
                                                     2.f * (b - t)));
            vertices.emplace_back(vertex);
        }
    }

    /* indices */
    for (int y = 0; y < 3601 - 1; y++) {
        for (int x = 0; x < 3601 - 1; x++) {
            indices.emplace_back(y * 3601 + x);
            indices.emplace_back((y + 1) * 3601 + x);
            indices.emplace_back((y + 1) * 3601 + x + 1);
            indices.emplace_back((y + 1) * 3601 + x + 1);
            indices.emplace_back(y * 3601 + x + 1);
            indices.emplace_back(y * 3601 + x);
        }
    }

    m_drawCount = indices.size();

    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices[0]) * vertices.size(),
                 vertices.data(), GL_STATIC_DRAW);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices[0]) * indices.size(),
                 indices.data(), GL_STATIC_DRAW);
}

Map::~Map()
{
    glDeleteBuffers(1, &m_vbo);
    glDeleteBuffers(1, &m_ebo);
    glDeleteVertexArrays(1, &m_vao);
}

void Map::render(const Shader &shader, const Camera &camera)
{
    shader.bind();
    shader.upload("viewMatrix", camera.getView());
    shader.upload("projectionMatrix", camera.getProjection());
    shader.upload("modelMatrix", glm::mat4(1.f));

    glBindVertexArray(m_vao);
    glDrawElements(GL_TRIANGLES, m_drawCount, GL_UNSIGNED_INT, nullptr);
}
