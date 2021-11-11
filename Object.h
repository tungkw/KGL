#ifndef __KGL_OBJECT_H
#define __KGL_OBJECT_H
#include <Eigen/Dense>


namespace kgl
{

struct Vertice
{
    Eigen::Vector3f pos;
    Eigen::Vector4f color;
    Eigen::Vector2f tex_id;
    float tex_slot;
};

class Object
{
private:
    /* data */

public:
    Vertice * vertex;
    unsigned int * faces;
    int num_vertex;
    int num_faces;
    Eigen::Matrix4f pose;

    Object(/* args */);
    ~Object();
};

Object::Object(/* args */)
{
    pose = Eigen::Matrix4f::Identity();
}

Object::~Object()
{
}

} // namespace kgl


#endif