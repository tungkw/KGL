#include "Render.h"

namespace kgl
{


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

    glClearColor(1, 1, 1, 1);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_MULTISAMPLE);
    
}

void Render::Activate()
{
    glfwMakeContextCurrent(window); 
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

} // namespace kgl