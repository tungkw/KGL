#include <iostream>
#include <string>
#include "Render.h"
#include "Buffer.h"
#include "Transformation.h"
#include "Geometry/Cuboid.h"
#include "Geometry/Line.h"
#include "Geometry/Vertice.h"
#include "Geometry/Point.h"


    // kgl::Texture texture("res/tex.png");
    // texture.Bind(0);
    // shader.SetUniform<int>(1, GL_INT, "u_Texture", std::vector<int>({0}));

Eigen::Matrix4f model, view, proj;


void scroll_cb(GLFWwindow *context, double x_offset, double y_offset)
{
    view(2, 3) -= y_offset;
}

// void mouse_btn_cb(GLFWwindow *context, int button, int action, int mods)
// {
//     if (button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_PRESS)
//         popup_menu();
// }

void cursor_pos_cb(GLFWwindow *context, double x_pos, double y_pos)
{
    static double x_pos_pre = -1;
    static double y_pos_pre = -1;
    if (x_pos_pre > 0)
    {
        int left_state = glfwGetMouseButton(context, GLFW_MOUSE_BUTTON_LEFT);
        int right_state = glfwGetMouseButton(context, GLFW_MOUSE_BUTTON_RIGHT);
        int ctrl_state = glfwGetKey(context, GLFW_KEY_LEFT_CONTROL);
        if (left_state == GLFW_PRESS)
        {
            if (ctrl_state == GLFW_PRESS)
                view = kgl::RotateZ((y_pos-y_pos_pre)/100.f) * view;
            else
                view = kgl::RotateX((y_pos-y_pos_pre)/100.f) * kgl::RotateY(-(x_pos-x_pos_pre)/100.f) * view;
        }
        else if (right_state == GLFW_PRESS)
        {
            view(0, 3) += -(x_pos-x_pos_pre)/100.f;
            view(1, 3) += -(y_pos-y_pos_pre)/100.f;
        }
    }
    x_pos_pre = x_pos;
    y_pos_pre = y_pos;
}

int main(void)
{

    kgl::Render* render = new kgl::Render;
    render->Open(640, 480, "Hello World");
    render->SetScrollCallback(scroll_cb);
    render->SetCursorPosCallback(cursor_pos_cb);

    // Point
    kgl::PointBuffer<kgl::NormalVertice> point_buffer;
    kgl::PointCloudSurfel points("2.obj");

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



    // Eigen::Matrix4f model, view, proj;
    // model = RotateX(r);
    model = Eigen::Matrix4f::Identity();
    view = kgl::ViewMatrix(Eigen::Vector3f(5, 5, 5), Eigen::Vector3f(0, 0, 10), Eigen::Vector3f(0, 0, 0));
    proj = kgl::ProjectionMatrix(0.1, 100, 3.14f/4, 640.f/480.f);
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
        // obj.Transform(T);

        point_buffer.Clear();
        point_buffer.Add(&points);
        point_buffer.Attach();

        shader.Bind();
        shader.Matrix4f("mv", view * model);
        shader.Matrix4f("proj", proj);
        shader.Vectorf("light", {5.f, 5.f, 5.f});
        render->Draw(point_buffer, shader);


        // std::cout << obj.GetPose().block<3,3>(0,0).determinant() << std::endl;
        Eigen::Matrix4f N = T * obj.GetPose();
        // obj.SetPose(N);
        obj.Transform(T);
        triangle_buffer.Clear();
        triangle_buffer.Add(&obj);
        triangle_buffer.Add(&obj2);
        triangle_buffer.Attach();

        shader.Bind();
        shader.Matrix4f("mv", view * model);
        shader.Matrix4f("proj", proj);
        shader.Vectorf("light", {5.f, 5.f, 5.f});
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