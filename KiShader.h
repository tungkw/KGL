#ifndef __KI_SHADER_H
#define __KI_SHADER_H
#include <string>
#include <fstream>
#include <sstream>
#include <malloc.h>
#include <vector>
#include <initializer_list>
#include "KiLogger.h"


struct ShaderNode
{
    std::string vertex_shader;
    std::string fragment_shader; 
    ShaderNode() = default;
    ShaderNode(std::string vs, std::string fs): vertex_shader(vs), fragment_shader(fs) {}
};


class KiShader
{
private:
    ShaderNode sn;
    std::string file_name;
    unsigned int shader_id;
    ShaderNode ParseShader(const std::string &file_name);
    unsigned int CompileShader(GLuint type, const std::string& source);
    unsigned int CreateShader(const std::string &vertex_shader, const std::string &fragment_shader);
public:
    KiShader(const std::string& _file_name): file_name(_file_name) {};
    // ~KiShader();
    void Compile();
    void Bind();
    void Unbind();
    
    template<typename T>
    void SetUniform(GLsizei size, GLenum type, std::string uname, std::vector<T> values)
    {
        if(size == 4 && type == GL_FLOAT)
        {
            GLint loc = glGetUniformLocation(shader_id, uname.c_str());
            // auto iter = values.begin();
            KICALL(glUniform4f(loc, values[0], values[1], values[2], values[3]));
        }
    }
};



#endif
