#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <malloc.h>

struct ShaderNode{
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

    unsigned int buffer_id;
    glGenBuffers(1, &buffer_id);
    float data[] = {
        -0.5f,  0.5f,
        0.5f, 0.5f,
        0.5f,  -0.5f,
        -0.5f,  -0.5f,
    };
    glBindBuffer(GL_ARRAY_BUFFER, buffer_id);
    glBufferData(GL_ARRAY_BUFFER, 4*2*sizeof(float), data, GL_STATIC_DRAW);


    // glVertexAttribPointer(index, num_of_elements_of_one_attrubute, type_of_element_of_one_attribute, need_normalized, stride_byte, start_byte);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2*sizeof(float), (const void*)0);
    glEnableVertexAttribArray(0); //index


    ShaderNode sn = ParseShader(std::string("res/shaders/shader.hlsl"));
    std::cout << "vertex" << std::endl;
    std::cout << sn.vertex_shader << std::endl;
    std::cout << "fragment" << std::endl;
    std::cout << sn.fragment_shader << std::endl;
    unsigned int shader = CreateShader(sn.vertex_shader, sn.fragment_shader);
    glUseProgram(shader);


    unsigned int index_buffer_id;
    glGenBuffers(1, &index_buffer_id);
    unsigned int indices[6] = {
        0, 3, 1,
        3, 2, 1,
    };
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, index_buffer_id);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, 6*sizeof(unsigned int), indices, GL_STATIC_DRAW);


    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        // glDrawArrays(GL_TRIANGLES, 0, 3);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, (void*)0);
        
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