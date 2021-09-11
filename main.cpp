#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <string>
#include <malloc.h>

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

    glBindBuffer(GL_ARRAY_BUFFER, buffer_id);
    
    float data[6] = {
        -0.5f,  0.5f,
        0.0f, -0.5f,
        0.5f,  0.5f,
    };
    glBufferData(GL_ARRAY_BUFFER, 6*sizeof(float), data, GL_STATIC_DRAW);


    // glVertexAttribPointer(index, num_of_elements_of_one_attrubute, type_of_element_of_one_attribute, need_normalized, stride_byte, start_byte);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2*sizeof(float), (const void*)0);

    glEnableVertexAttribArray(0); //index


    std::string vertex_shader = 
    "#version 330 core\n"
    "layout(location=0) in vec4 position;"
    "void main()"
    "{"
    "   gl_Position = position;"
    "}"
    ;

    std::string fragment_shader = 
    "#version 330 core\n"
    "layout(location=0) out vec4 color;"
    "void main()"
    "{"
    "   color = vec4(1., 0., 0., 1.0);"
    "}"
    ;
    
    unsigned int shader = CreateShader(vertex_shader, fragment_shader);
    glUseProgram(shader);


    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        glDrawArrays(GL_TRIANGLES, 0, 3);

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