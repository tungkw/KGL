#ifndef __KGL_CUBOID_H
#define __KGL_CUBOID_H
#include "Object.h"


namespace kgl
{

class Cuboid
    : public Object<NormalVertice>
{
public:
    Cuboid(float x=1, float y=1, float z=1);
    ~Cuboid();
};

Cuboid::Cuboid(float x, float y, float z)
{
    num_vertex = 24;
    num_primitives = 12;
    vertex = new NormalVertice[24];
    primitives = new unsigned int[12*3];

    SetColor({0.7f, 0.7f, 0.7f, 0.7f});

    vertex[0].pos = {-x/2.0f,  y/2.0f,  z/2.0f};
    vertex[1].pos = { x/2.0f,  y/2.0f,  z/2.0f};
    vertex[2].pos = { x/2.0f, -y/2.0f,  z/2.0f};
    vertex[3].pos = {-x/2.0f, -y/2.0f,  z/2.0f};
    vertex[4].pos = {-x/2.0f,  y/2.0f, -z/2.0f};
    vertex[5].pos = { x/2.0f,  y/2.0f, -z/2.0f};
    vertex[6].pos = { x/2.0f, -y/2.0f, -z/2.0f};
    vertex[7].pos = {-x/2.0f, -y/2.0f, -z/2.0f};
    vertex[0+8].pos = {-x/2.0f,  y/2.0f,  z/2.0f};
    vertex[1+8].pos = { x/2.0f,  y/2.0f,  z/2.0f};
    vertex[2+8].pos = { x/2.0f, -y/2.0f,  z/2.0f};
    vertex[3+8].pos = {-x/2.0f, -y/2.0f,  z/2.0f};
    vertex[4+8].pos = {-x/2.0f,  y/2.0f, -z/2.0f};
    vertex[5+8].pos = { x/2.0f,  y/2.0f, -z/2.0f};
    vertex[6+8].pos = { x/2.0f, -y/2.0f, -z/2.0f};
    vertex[7+8].pos = {-x/2.0f, -y/2.0f, -z/2.0f};
    vertex[0+16].pos = {-x/2.0f,  y/2.0f,  z/2.0f};
    vertex[1+16].pos = { x/2.0f,  y/2.0f,  z/2.0f};
    vertex[2+16].pos = { x/2.0f, -y/2.0f,  z/2.0f};
    vertex[3+16].pos = {-x/2.0f, -y/2.0f,  z/2.0f};
    vertex[4+16].pos = {-x/2.0f,  y/2.0f, -z/2.0f};
    vertex[5+16].pos = { x/2.0f,  y/2.0f, -z/2.0f};
    vertex[6+16].pos = { x/2.0f, -y/2.0f, -z/2.0f};
    vertex[7+16].pos = {-x/2.0f, -y/2.0f, -z/2.0f};

    vertex[0].normal = {0.f, 0.f,  1.f};
    vertex[1].normal = {0.f, 0.f,  1.f};
    vertex[2].normal = {0.f, 0.f,  1.f};
    vertex[3].normal = {0.f, 0.f,  1.f};
    vertex[4].normal = {0.f, 0.f, -1.f};
    vertex[5].normal = {0.f, 0.f, -1.f};
    vertex[6].normal = {0.f, 0.f, -1.f};
    vertex[7].normal = {0.f, 0.f, -1.f};
    vertex[0+8].normal = {0.f,  1.f, 0.f};
    vertex[1+8].normal = {0.f,  1.f, 0.f};
    vertex[2+8].normal = {0.f, -1.f, 0.f};
    vertex[3+8].normal = {0.f, -1.f, 0.f};
    vertex[4+8].normal = {0.f,  1.f, 0.f};
    vertex[5+8].normal = {0.f,  1.f, 0.f};
    vertex[6+8].normal = {0.f, -1.f, 0.f};
    vertex[7+8].normal = {0.f, -1.f, 0.f};
    vertex[0+16].normal = {-1.f, 0.f, 0.f};
    vertex[1+16].normal = { 1.f, 0.f, 0.f};
    vertex[2+16].normal = { 1.f, 0.f, 0.f};
    vertex[3+16].normal = {-1.f, 0.f, 0.f};
    vertex[4+16].normal = {-1.f, 0.f, 0.f};
    vertex[5+16].normal = { 1.f, 0.f, 0.f};
    vertex[6+16].normal = { 1.f, 0.f, 0.f};
    vertex[7+16].normal = {-1.f, 0.f, 0.f};
    
    unsigned int faces_[] = {
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
    memcpy(primitives, faces_, 12*3*sizeof(unsigned int));
}

Cuboid::~Cuboid()
{
    delete[] vertex;
    delete[] primitives;
}


}


#endif