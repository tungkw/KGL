#ifndef __KGL_LINE_H
#define __KGL_LINE_H
#include "Object.h"


namespace kgl
{
    
class Line
    : public Object<Vertice>
{
public:
    Line(Eigen::Vector3f start_pos, Eigen::Vector3f end_pos);
    ~Line();
};

Line::Line(Eigen::Vector3f start_pos, Eigen::Vector3f end_pos)
{
    num_vertex = 2;
    num_primitives = 1;
    vertex = new Vertice[num_vertex];
    primitives = new unsigned int[2*num_primitives];

    SetColor({0.7f, 0.7f, 0.7f, 0.7f});

    vertex[0].pos = start_pos;
    vertex[1].pos = end_pos;

    primitives[0] = 0;
    primitives[1] = 1;
}

Line::~Line()
{
    delete[] vertex;
    delete[] primitives;
}

}


#endif