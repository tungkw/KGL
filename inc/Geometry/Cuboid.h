#ifndef __KGL_CUBOID_H
#define __KGL_CUBOID_H
#include "Object.h"


namespace kgl
{

std::vector<Eigen::Vector3f> positions = {
    {-0.5f,  0.5f,  0.5f},
    { 0.5f,  0.5f,  0.5f},
    { 0.5f, -0.5f,  0.5f},
    {-0.5f, -0.5f,  0.5f},
    {-0.5f,  0.5f, -0.5f},
    { 0.5f,  0.5f, -0.5f},
    { 0.5f, -0.5f, -0.5f},
    {-0.5f, -0.5f, -0.5f},
    {-0.5f,  0.5f,  0.5f},
    { 0.5f,  0.5f,  0.5f},
    { 0.5f, -0.5f,  0.5f},
    {-0.5f, -0.5f,  0.5f},
    {-0.5f,  0.5f, -0.5f},
    { 0.5f,  0.5f, -0.5f},
    { 0.5f, -0.5f, -0.5f},
    {-0.5f, -0.5f, -0.5f},
    {-0.5f,  0.5f,  0.5f},
    { 0.5f,  0.5f,  0.5f},
    { 0.5f, -0.5f,  0.5f},
    {-0.5f, -0.5f,  0.5f},
    {-0.5f,  0.5f, -0.5f},
    { 0.5f,  0.5f, -0.5f},
    { 0.5f, -0.5f, -0.5f},
    {-0.5f, -0.5f, -0.5f},
};

std::vector<Eigen::Vector3f> normals = {
    { 0.f,  0.f,  1.f},
    { 0.f,  0.f,  1.f},
    { 0.f,  0.f,  1.f},
    { 0.f,  0.f,  1.f},
    { 0.f,  0.f, -1.f},
    { 0.f,  0.f, -1.f},
    { 0.f,  0.f, -1.f},
    { 0.f,  0.f, -1.f},
    { 0.f,  1.f,  0.f},
    { 0.f,  1.f,  0.f},
    { 0.f, -1.f,  0.f},
    { 0.f, -1.f,  0.f},
    { 0.f,  1.f,  0.f},
    { 0.f,  1.f,  0.f},
    { 0.f, -1.f,  0.f},
    { 0.f, -1.f,  0.f},
    {-1.f,  0.f,  0.f},
    { 1.f,  0.f,  0.f},
    { 1.f,  0.f,  0.f},
    {-1.f,  0.f,  0.f},
    {-1.f,  0.f,  0.f},
    { 1.f,  0.f,  0.f},
    { 1.f,  0.f,  0.f},
    {-1.f,  0.f,  0.f},
};

unsigned int faces[] = {
    // font
    0, 3, 1,
    1, 3, 2,

    // back
    4, 5, 7,
    7, 5, 6,

    // top
    4+8, 0+8, 5+8,
    5+8, 0+8, 1+8,

    // bottom
    7+8, 6+8, 3+8,
    3+8, 6+8, 2+8,

    // left
    7+16, 3+16, 4+16,
    4+16, 3+16, 0+16,

    // right
    1+16, 2+16, 5+16,
    5+16, 2+16, 6+16,
};

class Cuboid
    : public Object<NormalVertice>
{
public:
    Cuboid(float x=1, float y=1, float z=1);
};

Cuboid::Cuboid(float x, float y, float z)
{
    num_vertex = 24;
    num_primitives = 12;

    kgl::NormalVertice vertice;
    for(int i = 0 ; i < 24; i++)
    {
        vertice.pos = positions[i];
        vertice.color = {0.7f, 0.7f, 0.7f, 1.0f};
        vertice.normal = normals[i];
        vertex.push_back(vertice);
    }

    for (int i = 0 ; i < 12; i++)
    {
        primitives.push_back(faces[i*3 + 0]);
        primitives.push_back(faces[i*3 + 1]);
        primitives.push_back(faces[i*3 + 2]);
    }
}


}


#endif