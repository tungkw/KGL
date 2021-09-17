#include "KiHeader.h"
#include "KiLogger.h"
#include "KiVertexBuffer.h"
#include "KiIndexBuffer.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <malloc.h>

struct ShaderNode
{
    std::string vertex_shader;
    std::string fragment_shader; 
};

static ShaderNode ParseShader(const std::string &file_name)
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

static unsigned int CompileShader(GLuint type, const std::string& source)
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

static unsigned int CreateShader(const std::string &vertex_shader, const std::string &fragment_shader)
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

int main(void)
{
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }


    /* Make the window's context current */
    glfwMakeContextCurrent(window);
    if(glewInit() != GLEW_OK) std::cout << "error" << std::endl;
    else std::cout << glGetString(GL_VERSION) << std::endl;

    float data[] = {
        -0.5f,  0.5f,
        0.5f, 0.5f,
        0.5f,  -0.5f,
        -0.5f,  -0.5f,
    };
    KiVertexBuffer vb(data, 4*2*sizeof(float));


    unsigned int indices[6] = {
        0, 3, 1,
        3, 2, 1,
    };
    KiIndexBuffer ib(indices, 6);
    

    // glVertexAttribPointer(index, num_of_elements_of_one_attrubute, type_of_element_of_one_attribute, need_normalized, stride_byte, start_byte);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2*sizeof(float), (const void*)0);
    glEnableVertexAttribArray(0); //index

    ShaderNode sn = ParseShader(std::string("res/shaders/shader.hlsl"));
    unsigned int shader = CreateShader(sn.vertex_shader, sn.fragment_shader);
    glUseProgram(shader);

    GLint loc = glGetUniformLocation(shader, "u_Color");
    GLfloat r = 0.0;
    GLfloat inc = 0.001;

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        // glDrawArrays(GL_TRIANGLES, 0, 3);
        
        glUniform4f(loc, r, 0.2, 0.8, 1.0);
        KICALL(glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, (void*)0));
        
        if (r > 1.0) inc = -0.001;
        else if (r < 0.0) inc = 0.001;
        r += inc;

        // lagecy
        // glBegin(GL_TRIANGLES);
        // glVertex2f(-0.5f,  0.5f);
        // glVertex2f( 0.0f, -0.5f);
        // glVertex2f( 0.5f,  0.5f);
        // glEnd();

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}