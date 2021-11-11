#include "Render.h"
#include "Transformation.h"
#include "Cuboid.h"
#include <iostream>
#include <string>

int main(void)
{

    kgl::Render* render = new kgl::Render;
    render->Open(640, 480, "Hello World");

    kgl::Cuboid obj(1, 2, 1);
    kgl::Cuboid obj2;
    
    Eigen::Matrix4f pose = Eigen::Matrix4f::Identity();
    pose(0, 3) = -1;
    obj.SetPose(pose);
    pose(0, 3) = 1;
    obj2.SetPose(pose);

    kgl::VertexBuffer vb(1000);
    vb.Add(obj.vertex, sizeof(kgl::Vertice)*obj.num_vertex);
    vb.Add(obj2.vertex, sizeof(kgl::Vertice)*obj2.num_vertex);
    vb.Attach();

    kgl::IndexBuffer ib(1000);
    ib.Add(obj.faces, obj.num_faces*3, 0);
    ib.Add(obj2.faces, obj2.num_faces*3, obj.num_vertex);
    ib.Attach();

    kgl::VertexBufferLayout vbl;
    vbl.Push<GLfloat>((offsetof(kgl::Vertice, color) - offsetof(kgl::Vertice, pos)) / sizeof(float));
    vbl.Push<GLfloat>((offsetof(kgl::Vertice, tex_id) - offsetof(kgl::Vertice, color)) / sizeof(float));
    vbl.Push<GLfloat>((offsetof(kgl::Vertice, tex_slot) - offsetof(kgl::Vertice, tex_id)) / sizeof(float));
    vbl.Push<GLfloat>((sizeof(kgl::Vertice) - offsetof(kgl::Vertice, tex_slot)) / sizeof(float));

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
        mvp = RotateX(r);
        // float d = (sinf(r)+1.f)*5.f;
        float d = 10;
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