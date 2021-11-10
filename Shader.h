#ifndef __KGL_SHADER_H
#define __KGL_SHADER_H
#include <string>
#include <fstream>
#include <sstream>
#include <malloc.h>
#include <vector>
#include <initializer_list>
#include "Logger.h"

namespace kgl
{

struct ShaderNode
{
    std::string vertex_shader;
    std::string fragment_shader; 
    ShaderNode() = default;
    ShaderNode(std::string vs, std::string fs): vertex_shader(vs), fragment_shader(fs) {}
};


class Shader
{
private:
    ShaderNode sn;
    std::string file_name;
    int shader_id;
    ShaderNode ParseShader(const std::string &file_name);
    unsigned int CompileShader(GLuint type, const std::string& source);
    unsigned int CreateShader(const std::string &vertex_shader, const std::string &fragment_shader);
public:
    Shader(const std::string& _file_name): file_name(_file_name) {};
    // ~Shader();
    void Compile();
    void Bind();
    void Unbind();
    
    void FloatVector(std::string name, std::vector<float> vals);
    void Matrix4f(std::string name, Eigen::Matrix4f mat);
    void Int(std::string name, int v1);

};


    
} // namespace kgl

#endif
