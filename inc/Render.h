#ifndef __KGL_RENDER_H
#define __KGL_RENDER_H

#include "Buffer.h"
#include "Shader.h"
#include "Logger.h"
#include "Texture.h"


namespace kgl
{
class Render
{

    GLFWwindow* window;

public:
    Render(): window(nullptr) {}
    int Open(int width, int height, const char* title);
    void Spin();
    bool Closed();
    void Terminate();
    void Clear() const {KGLCALL(glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);)}

    template<typename T>
    void Draw(TriangleBuffer<T>& buffer, Shader& shader);

    template<typename T>
    void Draw(LineBuffer<T>& buffer, Shader& shader);
};

int Render::Open(int width, int height, const char* title)
{
    /* Initialize the library */
    if (!glfwInit())
    {
        std::cout << "GLFW initialization failed" << std::endl;
        return -1;
    }
    

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(width, height, title, NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    /* GLEW init */
    if(glewInit() != GLEW_OK) std::cout << "error" << std::endl;
    else std::cout << glGetString(GL_VERSION) << std::endl;

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_MULTISAMPLE);
}

void Render::Spin()
{
    /* Swap front and back buffers */
    glfwSwapBuffers(window);

    /* Poll for and process events */
    glfwPollEvents();
}

bool Render::Closed()
{
    return glfwWindowShouldClose(window);
}

void Render::Terminate()
{
    glfwTerminate();
}

template<typename T>
void Render::Draw(TriangleBuffer<T>& buffer, Shader& shader)
{
    buffer.Bind();
    shader.Bind();
    KGLCALL(glDrawElements(GL_TRIANGLES, buffer.GetNumIndex(), GL_UNSIGNED_INT, (void*)0);)
}

template<typename T>
void Render::Draw(LineBuffer<T>& buffer, Shader& shader)
{
    buffer.Bind();
    shader.Bind();
    KGLCALL(glDrawElements(GL_LINES, buffer.GetNumIndex(), GL_UNSIGNED_INT, (void*)0);)
}
    
} // namespace kgl

#endif