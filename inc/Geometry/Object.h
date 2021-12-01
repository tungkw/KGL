#ifndef __KGL_OBJECT_H
#define __KGL_OBJECT_H
#include <Eigen/Dense>


namespace kgl
{

template<typename T>
class Object
{
private:
    /* data */

public:
    T * vertex;
    unsigned int * primitives;
    int num_vertex;
    int num_primitives;
    Eigen::Matrix4f pose;

    Object(/* args */){ pose = Eigen::Matrix4f::Identity(); }

    void SetPose(Eigen::Matrix4f pose)
    {
        this->pose = pose;
        for (int i = 0 ; i < num_vertex; i++)
        {
            vertex[i].pos = pose.block<3, 3>(0, 0) * vertex[i].pos + pose.block<3, 1>(0, 3);
        }
    }

    void SetColor(Eigen::Vector4f color)
    {
        for(int i = 0 ; i < num_vertex; i++)
            vertex[i].color = color;
    }
};


} // namespace kgl


#endif