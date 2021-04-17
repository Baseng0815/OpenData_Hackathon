#pragma once

#include <map>
#include <string>
#include <vector>
#include <GL/glew.h>
#include <glm/glm.hpp>

class Shader {
    public:
        Shader(const std::string& vertex, const std::string& fragment);
        ~Shader();

        // bind attribute arrays to shader locations
        void setAttributes(const std::vector<std::string>& attribs) const;

        void bind() const;

        // upload stuff
        void upload(const std::string &location, const glm::mat4 &value) const;
        void upload(const std::string &location, const glm::vec3 &value) const;
        void upload(const std::string &location, const glm::vec4 &value) const;
        void upload(const std::string &location, float value) const;
        void upload(const std::string &location, int value) const;

    protected:
        GLuint m_program;

        mutable bool m_uniformsSet = false;

        static std::string loadShader(const std::string& fileName);
        static void checkShaderError(GLuint shader, GLuint flag, bool isProgram, std::string errorMessage);
        static GLuint createShader(const std::string& text, GLenum type);

        mutable std::map<std::string, GLint> m_locations;

        GLint getLocation(const std::string& location) const;

        void release();
};
