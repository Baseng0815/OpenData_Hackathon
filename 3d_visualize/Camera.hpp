#pragma once

#include <glm/glm.hpp>

class Camera {
    public:
        Camera(float fov, int width, int height);

        void update(int dt); /* in ms */

        void handleKey(int, int, int, int);
        void handleCursor(double, double);

        const glm::mat4 &getProjection() const;
        const glm::mat4 &getView() const;

    private:
        glm::mat4 m_perspectiveProjection, m_viewMatrix;

        float m_yaw = -90.f, m_pitch = 0.f, m_fov;
        int m_width, m_height;

        glm::vec3 m_front, m_right;
        glm::vec3 m_position;
        glm::vec3 m_move;

        void updateVectors();
        void updateViewMatrix();
        void updateProjectionMatrix();
};
