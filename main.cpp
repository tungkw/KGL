#include "Render.h"
#include "Transformation.h"
#include <iostream>
#include <string>

int main(void)
{

    kgl::Render* render = new kgl::Render;
    render->Open(640, 480, "Hello World");

    /* start drawing */
    float data[] = {
        -0.5f,  0.5f,   0,  0,
        0.5f,   0.5f,   1,  0,
        0.5f,  -0.5f,   1,  1,
        -0.5f,  -0.5f,  0,  1,
    };
    unsigned int indices[6] = {
        0, 3, 1,
        3, 2, 1,
    };

    kgl::VertexBuffer vb(data, 4*4*sizeof(float));
    kgl::IndexBuffer ib(indices, 6);

    kgl::VertexBufferLayout vbl;
    vbl.Push<GLfloat>(2);
    vbl.Push<GLfloat>(2);

    kgl::VertexArray va;
    va.Add(vb, vbl);

    kgl::Shader shader("res/shaders/shader.hlsl");
    shader.Compile();

    kgl::Texture texture("res/tex.png");
    texture.Bind(0);
    // shader.SetUniform<int>(1, GL_INT, "u_Texture", std::vector<int>({0}));

    va.Unbind();
    vb.Unbind();
    ib.Unbind();


    /* Loop until the user closes the window */
    GLfloat r = 0.0;
    GLfloat inc = 0.001;
    while (!render->Closed())
    {
        /* Render here */
        render->Clear();

        shader.Bind();
        shader.FloatVector("u_Color", {sinf(r)/2.0f+0.5f, 0.2, 0.8, 1.0});
        Eigen::Matrix4f mvp;
        mvp = RotateZ(r);
        float d = (sinf(r)+1.f)*5.f;
        mvp = ViewMatrix(Eigen::Vector3f(0, 0, d), Eigen::Vector3f(0, 1, d), Eigen::Vector3f(0, 0, -1)) * mvp;
        mvp = ProjectionMatrix(0.1, 20, 3.14f/4, 640.f/480.f) * mvp;
        // mvp = OthogonalMatrix(-640.f/480.f, 640.f/480.f, -2.f, 0.f, -1.f, 1.f) * mvp;
        shader.Matrix4f("mvp", mvp);

        render->Draw(va, ib, shader);
        r += inc;

        render->Spin();
    }

    render->Terminate();

    return 0;
}