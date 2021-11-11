#ifndef __KGL_CUBOID_H
#define __KGL_CUBOID_H
#include "Object.h"


namespace kgl
{
    
class Cuboid
    : public Object
{
public:
    Cuboid(float x=1, float y=1, float z=1);
    ~Cuboid();
    void SetPose(Eigen::Matrix4f pose);
};

Cuboid::Cuboid(float x, float y, float z)
{
    vertex = new Vertice[8];
    faces = new unsigned int[12*3];

    vertex[0].pos = {-x/2.0f,  y/2.0f,  z/2.0f};
    vertex[1].pos = { x/2.0f,  y/2.0f,  z/2.0f};
    vertex[2].pos = { x/2.0f, -y/2.0f,  z/2.0f};
    vertex[3].pos = {-x/2.0f, -y/2.0f,  z/2.0f};
    vertex[4].pos = {-x/2.0f,  y/2.0f, -z/2.0f};
    vertex[5].pos = { x/2.0f,  y/2.0f, -z/2.0f};
    vertex[6].pos = { x/2.0f, -y/2.0f, -z/2.0f};
    vertex[7].pos = {-x/2.0f, -y/2.0f, -z/2.0f};
    
    vertex[0].color = {1.f, 1.f, 1.f, 1.f};
    vertex[1].color = {1.f, 1.f, 1.f, 1.f};
    vertex[2].color = {1.f, 1.f, 1.f, 1.f};
    vertex[3].color = {1.f, 1.f, 1.f, 1.f};
    vertex[4].color = {1.f, 1.f, 1.f, 1.f};
    vertex[5].color = {1.f, 1.f, 1.f, 1.f};
    vertex[6].color = {1.f, 1.f, 1.f, 1.f};
    vertex[7].color = {1.f, 1.f, 1.f, 1.f};
    
    vertex[0].tex_id = {1.f, 1.f};
    vertex[1].tex_id = {1.f, 1.f};
    vertex[2].tex_id = {1.f, 1.f};
    vertex[3].tex_id = {1.f, 1.f};
    vertex[4].tex_id = {1.f, 1.f};
    vertex[5].tex_id = {1.f, 1.f};
    vertex[6].tex_id = {1.f, 1.f};
    vertex[7].tex_id = {1.f, 1.f};

    vertex[0].tex_slot = 0.f;
    vertex[1].tex_slot = 0.f;
    vertex[2].tex_slot = 0.f;
    vertex[3].tex_slot = 0.f;
    vertex[4].tex_slot = 0.f;
    vertex[5].tex_slot = 0.f;
    vertex[6].tex_slot = 0.f;
    vertex[7].tex_slot = 0.f;

    unsigned int faces_[] = {
        0, 1, 4,
        1, 2, 5,
        2, 3, 6,
        3, 0, 7,

        0, 4, 7,
        1, 5, 4,
        2, 6, 5,
        3, 7, 6,

        0, 3, 1,
        1, 3, 2,
        4, 5, 7,
        5, 6, 7,
    };
    memcpy(faces, faces_, 12*3*sizeof(unsigned int));

    num_vertex = 8;
    num_faces = 12;
}

Cuboid::~Cuboid()
{
    delete[] vertex;
    delete[] faces;
}

void Cuboid::SetPose(Eigen::Matrix4f pose)
{
    this->pose = pose;
    for (int i = 0 ; i < num_vertex; i++)
    {
        vertex[i].pos = pose.block<3, 3>(0, 0) * vertex[i].pos + pose.block<3, 1>(0, 3);
    }
}

}


#endif