#include "KiShader.h"


ShaderNode KiShader::ParseShader(const std::string &file_name)
{
    std::ifstream fin(file_name.c_str(), std::ios::in);
    if (!fin.is_open())
    {
        std::cout << "shader file not found" << std::endl;
        return {"", ""};
    }

    std::string line;
    std::stringstream ss[2];
    int state = -1;
    while (getline(fin, line))
    {
        if (line.find("vertex") != line.npos)
        {
            state = 0;
        }
        else if (line.find("fragment") != line.npos)
        {
            state = 1;
        }
        else if (state != -1)
        {
            ss[state] << line << '\n';
        }        
    }
    return { ss[0].str(), ss[1].str() };
}

unsigned int KiShader::CompileShader(GLuint type, const std::string& source)
{
    unsigned int id = glCreateShader(type);
    int slen = source.length();
    glShaderSource(id, 1, (char **)&(source), &slen);
    glCompileShader(id);

    int result;
    glGetShaderiv(id, GL_COMPILE_STATUS, &result);
    if(result == GL_FALSE)
    {
        int length;
        glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);
        char *msg = (char*)alloca(length*sizeof(char));
        glGetShaderInfoLog(id, length, &length, msg);
        std::cout << "compile " << (type == GL_VERTEX_SHADER ? "vertex" : "fragment") << " shader wrong" << std::endl;
        std::cout << msg << std::endl;
    }
    return id;
}

unsigned int KiShader::CreateShader(const std::string &vertex_shader, const std::string &fragment_shader)
{
    unsigned int program = glCreateProgram();
    unsigned int vs = CompileShader(GL_VERTEX_SHADER, vertex_shader);
    unsigned int fs = CompileShader(GL_FRAGMENT_SHADER, fragment_shader);

    glAttachShader(program, vs);
    glAttachShader(program, fs);
    glLinkProgram(program);
    glValidateProgram(program);

    glDeleteShader(vs);
    glDeleteShader(fs);
    return program;
}

void KiShader::Compile()
{
    sn = ParseShader(std::string("res/shaders/shader.hlsl"));
    shader_id = CreateShader(sn.vertex_shader, sn.fragment_shader);
}

void KiShader::Bind()
{
    KICALL(glUseProgram(shader_id));
}

void KiShader::Unbind()
{
    KICALL(glUseProgram(0));
}

