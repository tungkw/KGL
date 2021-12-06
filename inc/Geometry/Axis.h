#ifndef __KGL_AXIS_H
#define __KGL_AXIS_H
#include "Object.h"
#include "Vertice.h"


namespace kgl
{



class Axis
    : public kgl::Object<kgl::Vertice>
{
public:
    Axis(float length)
    {
        num_vertex = 6;
        num_primitives = 3;

        kgl::Vertice vertice;
    
        vertice.pos = Eigen::Vector3f(0, 0, 0);
        vertice.color = Eigen::Vector4f(1, 0, 0, 1);
        vertex.push_back(vertice);
        vertice.pos = Eigen::Vector3f(1, 0, 0) * length;
        vertice.color = Eigen::Vector4f(1, 0, 0, 1);
        vertex.push_back(vertice);
        primitives.push_back(0);
        primitives.push_back(1);

        vertice.pos = Eigen::Vector3f(0, 0, 0);
        vertice.color = Eigen::Vector4f(0, 1, 0, 1);
        vertex.push_back(vertice);
        vertice.pos = Eigen::Vector3f(0, 1, 0) * length;
        vertice.color = Eigen::Vector4f(0, 1, 0, 1);
        vertex.push_back(vertice);
        primitives.push_back(2);
        primitives.push_back(3);

        vertice.pos = Eigen::Vector3f(0, 0, 0);
        vertice.color = Eigen::Vector4f(0, 0, 1, 1);
        vertex.push_back(vertice);
        vertice.pos = Eigen::Vector3f(0, 0, 1) * length;
        vertice.color = Eigen::Vector4f(0, 0, 1, 1);
        vertex.push_back(vertice);
        primitives.push_back(4);
        primitives.push_back(5);
    }
};

}


#endif