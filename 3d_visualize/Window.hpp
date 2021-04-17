#pragma once

#include <queue>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

class App;

class Window {
public:
    Window(App *app, int width, int height);

    void clear(glm::vec3 clearColor = glm::vec3(0, 0, 0));
    void display();

    int getWidth() const;
    int getHeight() const;

    bool isOpen();
    void close();

private:
    GLFWwindow *m_window = nullptr;
    GLFWmonitor *m_primaryMonitor = nullptr;
    int m_width, m_height;

    static void glfwErrorCallback(int code, const char *str);
};
