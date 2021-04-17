#include "Camera.hpp"

#include <GLFW/glfw3.h>
#include <iostream>
#include <glm/gtc/matrix_transform.hpp>

Camera::Camera(float fov, int width, int height)
    : m_fov(fov), m_width(width), m_height(height),
    m_position(0.f, 0.f, 0.f), m_move(0.f, 0.f, 0.f)
{
    updateVectors();
    updateViewMatrix();
    updateProjectionMatrix();
}

void Camera::update(int dt)
{
    glm::vec3 prev_pos = m_position;
    m_position += (m_move.x * m_right +
                   m_move.y * glm::vec3(0.f, 1.f, 0.f) +
                   m_move.z * m_front) * (dt / 1.f);

    if (m_position != prev_pos) {
        updateVectors();
        updateViewMatrix();
    }
}

void Camera::handleKey(int key, int scancode, int action, int mods)
{
    switch (key) {
        case GLFW_KEY_LEFT_SHIFT:
            if (action == GLFW_PRESS)
                m_move.y -= 1;
            else if (action == GLFW_RELEASE)
                m_move.y += 1;
            break;
        case GLFW_KEY_SPACE:
            if (action == GLFW_PRESS)
                m_move.y += 1;
            else if (action == GLFW_RELEASE)
                m_move.y -= 1;
            break;
        case GLFW_KEY_W:
            if (action == GLFW_PRESS)
                m_move.z += 1;
            else if (action == GLFW_RELEASE)
                m_move.z -= 1;
            break;
        case GLFW_KEY_S:
            if (action == GLFW_PRESS)
                m_move.z -= 1;
            else if (action == GLFW_RELEASE)
                m_move.z += 1;
            break;
        case GLFW_KEY_D:
            if (action == GLFW_PRESS)
                m_move.x += 1;
            else if (action == GLFW_RELEASE)
                m_move.x -= 1;
            break;
        case GLFW_KEY_A:
            if (action == GLFW_PRESS)
                m_move.x -= 1;
            else if (action == GLFW_RELEASE)
                m_move.x += 1;
            break;

        default:
            break;
    }
}

void Camera::handleCursor(double dx, double dy)
{
    m_yaw   += dx * 0.1f;
    m_pitch -= dy * 0.1f;

    if (m_pitch > 89.0)
        m_pitch = 89.0;
    else if (m_pitch < -89.0)
        m_pitch = -89.0;

    updateVectors();
    updateViewMatrix();
}

const glm::mat4 &Camera::getProjection() const
{
    return m_perspectiveProjection;
}

const glm::mat4 &Camera::getView() const
{
    return m_viewMatrix;
}

void Camera::updateVectors()
{
    m_front.x = cos(glm::radians(m_yaw)) * cos(glm::radians(m_pitch));
    m_front.y = sin(glm::radians(m_pitch));
    m_front.z = sin(glm::radians(m_yaw)) * cos(glm::radians(m_pitch));
    m_front = glm::normalize(m_front);
    m_right = glm::normalize(glm::cross(m_front, glm::vec3(0.f, 1.f, 0.f)));
}

void Camera::updateViewMatrix()
{
    m_viewMatrix = glm::lookAt(m_position,
                               m_position + m_front,
                               glm::vec3(0.f, 1.f, 0.f));
}

void Camera::updateProjectionMatrix()
{
    float aspect = m_width / m_height;
    m_perspectiveProjection = glm::perspective(glm::radians(m_fov), aspect,
                                               .1f, 7000.f);
}
