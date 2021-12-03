#include <iostream>
#include <string>
#include "Render.h"
#include "Buffer.h"
#include "Transformation.h"
#include "Geometry/Cuboid.h"
#include "Geometry/Line.h"
#include "Geometry/Vertice.h"


    // kgl::Texture texture("res/tex.png");
    // texture.Bind(0);
    // shader.SetUniform<int>(1, GL_INT, "u_Texture", std::vector<int>({0}));

int main(void)
{

    kgl::Render* render = new kgl::Render;
    render->Open(640, 480, "Hello World");


    // triangles
    kgl::TriangleBuffer<kgl::NormalVertice> triangle_buffer;

    kgl::Cuboid obj(1, 2, 1);
    kgl::Cuboid obj2;
    
    Eigen::Matrix4f pose = Eigen::Matrix4f::Identity();
    pose(0, 3) = -1;
    obj.SetPose(pose);
    obj.SetColor({1, 0, 0, 1});

    pose(0, 3) = 1;
    obj2.SetPose(pose);
    obj2.SetColor({0, 0, 1, 1});

    kgl::Shader shader("../res/shaders/shader.hlsl");
    shader.Compile();


    // line
    kgl::LineBuffer<kgl::Vertice> line_buffer;

    kgl::Line xax(Eigen::Vector3f(0, 0, 0), Eigen::Vector3f(1, 0, 0));
    xax.SetColor({1, 0, 0, 1});
    kgl::Line yax(Eigen::Vector3f(0, 0, 0), Eigen::Vector3f(0, 1, 0));
    yax.SetColor({0, 1, 0, 1});
    kgl::Line zax(Eigen::Vector3f(0, 0, 0), Eigen::Vector3f(0, 0, 1));
    zax.SetColor({0, 0, 1, 1});

    kgl::Shader line_shader("../res/shaders/shader_line.hlsl");
    line_shader.Compile();



    Eigen::Matrix4f model, view, proj;
    // model = RotateX(r);
    model = Eigen::Matrix4f::Identity();
    view = kgl::ViewMatrix(Eigen::Vector3f(5, 5, 5), Eigen::Vector3f(0, 0, 10), Eigen::Vector3f(0, 0, 0));
    proj = kgl::ProjectionMatrix(0.1, 20, 3.14f/4, 640.f/480.f);
    // proj = OthogonalMatrix(-2*640.f/480.f, 2*640.f/480.f, -2.f, 2.f, -2.f, 2.f);

    /* Loop until the user closes the window */
    GLfloat r = 0.0;
    GLfloat inc = 0.1;
    Eigen::Matrix4f T = kgl::RotateX(0.01);
    while (!render->Closed())
    {
        /* Render here */
        render->Clear();


        // std::cout << obj.GetPose().block<3,3>(0,0).determinant() << std::endl;
        // Eigen::Matrix4f N = T * obj.GetPose();
        // obj.SetPose(N);
        obj.Translation(T);
        triangle_buffer.Clear();
        triangle_buffer.Add(&obj);
        triangle_buffer.Add(&obj2);
        triangle_buffer.Attach();

        shader.Bind();
        shader.Matrix4f("mv", view * model);
        shader.Matrix4f("proj", proj);
        render->Draw(triangle_buffer, shader);


        line_buffer.Clear();
        line_buffer.Add(&xax);
        line_buffer.Add(&yax);
        line_buffer.Add(&zax);
        line_buffer.Attach();

        line_shader.Bind();
        line_shader.Matrix4f("mv", view * model);
        line_shader.Matrix4f("proj", proj);
        render->Draw(line_buffer, line_shader);

        r += inc;

        // updata draww
        render->Spin();
    }

    // delete some buffer pointer before render is terminated, i.e. before glfw is terminated;
    triangle_buffer.Terminate();
    render->Terminate();

    return 0;
}