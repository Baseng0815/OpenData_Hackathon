#include "Window.hpp"

#include "App.hpp"

#include <glm/gtc/matrix_transform.hpp>

#include <iostream>

Window::Window(App *app, int width, int height)
{
    glfwSetErrorCallback(glfwErrorCallback);

    if (!glfwInit()) {
        std::cerr << "failed to initialize GLFW\n";
        exit(1);
    }

    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
    m_window = glfwCreateWindow(width, height, "hgt visualizer",
                                nullptr, nullptr);
    if (!m_window) {
        std::cerr << "failed to create GLFW window\n";
        exit(1);
    }

    m_primaryMonitor = glfwGetPrimaryMonitor();

    glfwSetInputMode(m_window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
    if (glfwRawMouseMotionSupported()) {
        glfwSetInputMode(m_window, GLFW_RAW_MOUSE_MOTION, GLFW_TRUE);
    }

    glfwSetWindowUserPointer(m_window, app);

    glfwMakeContextCurrent(m_window);

    /* init glew and load function pointers */
    glewInit();
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glfwGetWindowSize(m_window, &m_width, &m_height);

    /* callbacks */
    glfwSetKeyCallback(m_window, App::keyCallback);
    glfwSetCursorPosCallback(m_window, App::cursorCallback);
}

void Window::clear(glm::vec3 clearColor) {
    glClearColor(clearColor.r, clearColor.g, clearColor.b, 1);
    glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
}

void Window::display()
{
    glfwSwapBuffers(m_window);
}

int Window::getWidth() const
{
    return m_width;
}
int Window::getHeight() const
{
    return m_height;
}
bool Window::isOpen()
{
    return !glfwWindowShouldClose(m_window);
}

void Window::close()
{
    glfwDestroyWindow(m_window);
}

void Window::glfwErrorCallback(int code, const char *str)
{
    std::cerr << "GLFW error with code " << code << ": " << str << "\n";
}
