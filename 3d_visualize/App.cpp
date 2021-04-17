#include "App.hpp"

App::App()
    : m_window(this, 1920, 1080),
    m_shader("vertex.glsl", "fragment.glsl"),
    m_camera(110.f, m_window.getWidth(), m_window.getHeight()),
    m_map("map.hgt")
{

    glDisable(GL_CULL_FACE);

    double prevTime = glfwGetTime();
    while (m_window.isOpen()) {
        /* updating */
        double ct = glfwGetTime();
        double dt = ct - prevTime;
        prevTime = ct;

        m_camera.update(dt * 1000.0);

        glfwPollEvents();

        /* rendering */
        m_window.clear();

        m_map.render(m_shader, m_camera);

        m_window.display();
    }
}

void App::keyCallback(GLFWwindow *wnd,
                      int key,
                      int scancode,
                      int action,
                      int mods)
{
    App *app = reinterpret_cast<App*>(glfwGetWindowUserPointer(wnd));

    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
        app->m_window.close();
        return;
    }

    app->m_camera.handleKey(key, scancode, action, mods);
}

void App::cursorCallback(GLFWwindow *wnd, double x, double y)
{
    App *app = reinterpret_cast<App*>(glfwGetWindowUserPointer(wnd));
    if (app->firstMouse) {
        app->firstMouse = false;
        app->m_prevCursX = x;
        app->m_prevCursY = y;
        return;
    }

    double dx = x - app->m_prevCursX;
    double dy = y - app->m_prevCursY;
    app->m_prevCursX = x;
    app->m_prevCursY = y;

    app->m_camera.handleCursor(dx, dy);
}
