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
    void Activate();
    void Spin();
    bool Closed();
    void Terminate();
    void Clear() const {KGLCALL(glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);)}
    GLFWwindow* GetContext() const { return window; }

    template<typename T>
    void Draw(TriangleBuffer<T>& buffer, Shader& shader)
    {
        buffer.Bind();
        shader.Bind();
        KGLCALL(glDrawElements(GL_TRIANGLES, buffer.GetNumIndex(), GL_UNSIGNED_INT, (void*)0);)
    }

    template<typename T>
    void Draw(LineBuffer<T>& buffer, Shader& shader)
    {
        buffer.Bind();
        shader.Bind();
        KGLCALL(glDrawElements(GL_LINES, buffer.GetNumIndex(), GL_UNSIGNED_INT, (void*)0);)
    }

    template<typename T>
    void Draw(PointBuffer<T>& buffer, Shader& shader)
    {
        buffer.Bind();
        shader.Bind();
        glPointSize(0.9);
        KGLCALL(glDrawElements(GL_POINTS, buffer.GetNumIndex(), GL_UNSIGNED_INT, (void*)0);)
    }


    void SetKeyCallback(void(*key_callback)(GLFWwindow*, int, int, int, int)) { glfwSetKeyCallback(window, key_callback); }
    void SetCursorPosCallback(void(*cursor_position_callback)(GLFWwindow*, double, double)) { glfwSetCursorPosCallback(window, cursor_position_callback); }
    void SetCursorEnterCallback(void(*cursor_enter_callback)(GLFWwindow*, int)) { glfwSetCursorEnterCallback(window, cursor_enter_callback); }
    void SetMouseButtonCallback(void(*mouse_button_callback)(GLFWwindow*, int, int, int)) { glfwSetMouseButtonCallback(window, mouse_button_callback); }
    void SetScrollCallback(void(*scroll_callback)(GLFWwindow*, double, double)) { glfwSetScrollCallback(window, scroll_callback); }
};



// static void _cursor_position_callback(Render *render, GLFWwindow* window, double xpos, double ypos);

}


#endif