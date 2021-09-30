#include "KiHeader.h"
#include "KiLogger.h"
#include "KiVertexBuffer.h"
#include "KiIndexBuffer.h"
#include "KiVertexArray.h"
#include "KiShader.h"
#include "KiRender.h"
#include <iostream>
#include <string>


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


    /* start drawing */
    float data[] = {
        -0.5f,  0.5f,
        0.5f, 0.5f,
        0.5f,  -0.5f,
        -0.5f,  -0.5f,
    };
    unsigned int indices[6] = {
        0, 3, 1,
        3, 2, 1,
    };

    KiVertexBuffer vb(data, 4*2*sizeof(float));
    KiIndexBuffer ib(indices, 6);

    KiVertexBufferLayout vbl;
    vbl.Push<GLfloat>(2);

    KiVertexArray va;
    va.Add(vb, vbl);

    KiShader shader("res/shaders/shader.hlsl");
    shader.Compile();

    va.Unbind();
    vb.Unbind();
    ib.Unbind();


    /* Loop until the user closes the window */
    GLfloat r = 0.0;
    GLfloat inc = 0.001;
    KiRender render;
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        render.Clear();

        shader.Bind();
        shader.SetUniform(4, GL_FLOAT, "u_Color", std::vector<float>({float(r), 0.2, 0.8, 1.0}));

        render.Draw(va, ib, shader);
        
        // va.Bind();
        // ib.Bind();
        // KICALL(glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, (void*)0));
        
        if (r > 1.0) inc = -0.001;
        else if (r < 0.0) inc = 0.001;
        r += inc;
        
        // va.Bind();

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}