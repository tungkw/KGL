#ifndef __KGL_LINE_H
#define __KGL_LINE_H
#include "Object.h"
#include "Vertice.h"


namespace kgl
{



class Line
    : public Object<Vertice>
{
public:
    Line(Eigen::Vector3f start, Eigen::Vector3f end)
    {
        num_vertex = 2;
        num_primitives = 1;

        kgl::Vertice vertice;
        Eigen::Vector4f color(0.7f, 0.7f, 0.7f, 1.0f);
    
        vertice.pos = start;
        vertice.color = color;
        vertex.push_back(vertice);

        vertice.pos = end;
        vertex.push_back(vertice);

        primitives.push_back(0);
        primitives.push_back(1);
    }
};

}


#endif