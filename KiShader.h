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
    int shader_id;
    ShaderNode ParseShader(const std::string &file_name);
    unsigned int CompileShader(GLuint type, const std::string& source);
    unsigned int CreateShader(const std::string &vertex_shader, const std::string &fragment_shader);
public:
    KiShader(const std::string& _file_name): file_name(_file_name) {};
    // ~KiShader();
    void Compile();
    void Bind();
    void Unbind();
    
    void SetUniform4f(std::string name, float v1, float v2,  float v3,  float v4)
    {
        GLint loc = glGetUniformLocation(shader_id, name.c_str());
        KICALL(glUniform4f(loc, v1, v2, v3, v4));
    }
    
    void SetUniform1i(std::string name, int v1)
    {
        GLint loc = glGetUniformLocation(shader_id, name.c_str());
        KICALL(glUniform1i(loc, v1));
    }
};



#endif
