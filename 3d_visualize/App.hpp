#pragma once

#include "Window.hpp"
#include "Shader.hpp"
#include "Camera.hpp"
#include "Map.hpp"

class App {
    public:
        App();

        static void keyCallback(GLFWwindow*, int, int, int, int);
        static void cursorCallback(GLFWwindow*, double, double);

    private:
        Window  m_window;
        Shader  m_shader;
        Camera  m_camera;
        Map     m_map;

        double m_prevCursX, m_prevCursY;
        bool firstMouse = true;
};
