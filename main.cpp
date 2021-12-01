#include "Render.h"
#include "Transformation.h"
#include "Geometry/Cuboid.h"
#include "Geometry/Line.h"
#include "Geometry/Vertice.h"
#include "Buffer.h"
#include <iostream>
#include <string>


    // kgl::Texture texture("res/tex.png");
    // texture.Bind(0);
    // shader.SetUniform<int>(1, GL_INT, "u_Texture", std::vector<int>({0}));

int main(void)
{

    kgl::Render* render = new kgl::Render;
    render->Open(640, 480, "Hello World");

    // // triangles
    // kgl::Cuboid obj(1, 2, 1);
    // kgl::Cuboid obj2;
    
    // Eigen::Matrix4f pose = Eigen::Matrix4f::Identity();
    // pose(0, 3) = -1;
    // obj.SetPose(pose);

    // pose(0, 3) = 1;
    // obj2.SetPose(pose);

    // kgl::TriangleBuffer<kgl::NormalVertice> triangle_buffer;
    // triangle_buffer.Add(&obj);
    // triangle_buffer.Add(&obj2);
    // triangle_buffer.Attach();

    // kgl::Shader shader("res/shaders/shader.hlsl");
    // shader.Compile();

    // line
    kgl::Line xax(Eigen::Vector3f(0, 0, 0), Eigen::Vector3f(1, 0, 0));
    kgl::Line yax(Eigen::Vector3f(0, 0, 0), Eigen::Vector3f(0, 1, 0));
    kgl::Line zax(Eigen::Vector3f(0, 0, 0), Eigen::Vector3f(0, 0, 1));

    xax.SetColor({1, 0, 0, 1});
    yax.SetColor({0, 1, 0, 1});
    zax.SetColor({0, 0, 1, 1});

    kgl::LineBuffer<kgl::Vertice> line_buffer;
    line_buffer.Add(&xax);
    line_buffer.Add(&yax);
    line_buffer.Add(&zax);
    line_buffer.Attach();

    kgl::Shader line_shader("res/shaders/shader_line.hlsl");
    line_shader.Compile();



    /* Loop until the user closes the window */
    GLfloat r = 0.0;
    GLfloat inc = 0.1;
    while (!render->Closed())
    {
        /* Render here */
        render->Clear();
        
        Eigen::Matrix4f model, view, proj;
        model = RotateX(r);
        float d = 10;
        view = ViewMatrix(Eigen::Vector3f(0, 0, d), Eigen::Vector3f(0, 1, d), Eigen::Vector3f(0, 0, -1));
        proj = ProjectionMatrix(0.1, 20, 3.14f/4, 640.f/480.f);
        // proj = OthogonalMatrix(-2*640.f/480.f, 2*640.f/480.f, -2.f, 2.f, -2.f, 2.f);

        // shader.Bind();
        // shader.Matrix4f("mv", view * model);
        // shader.Matrix4f("proj", proj);
        // render->Draw(triangle_buffer, shader);

        line_shader.Bind();
        line_shader.Matrix4f("mv", view * model);
        line_shader.Matrix4f("proj", proj);
        render->Draw(line_buffer, line_shader);

        r += inc;

        // updata draww
        render->Spin();
    }

    render->Terminate();

    return 0;
}