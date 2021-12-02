#ifndef __KGL_OBJECT_H
#define __KGL_OBJECT_H
#include <Eigen/Dense>
#include <vector>

namespace kgl
{

template<typename T>
class Object
{
protected:
    /* data */
    std::vector<T> vertex;
    std::vector<unsigned int> primitives;
    int num_vertex;
    int num_primitives;
    Eigen::Matrix4f pose;

public:

    Object(/* args */){ pose = Eigen::Matrix4f::Identity(); }

    void SetPose(Eigen::Matrix4f pose)
    {
        for (int i = 0 ; i < num_vertex; i++)
        {
            vertex[i].pos = this->pose.block<3, 3>(0, 0).transpose() * (vertex[i].pos - this->pose.block<3, 1>(0, 3));
            vertex[i].pos = pose.block<3, 3>(0, 0) * vertex[i].pos + pose.block<3, 1>(0, 3);
        }
        this->pose = pose;
    }
    
    void Translation(Eigen::Matrix4f trans)
    {
        for (int i = 0 ; i < num_vertex; i++)
        {
            vertex[i].pos = trans.block<3, 3>(0, 0) * vertex[i].pos + trans.block<3, 1>(0, 3);
        }
        this->pose = trans * pose;
    }

    void SetColor(Eigen::Vector4f color)
    {
        for(int i = 0 ; i < num_vertex; i++)
            vertex[i].color = color;
    }

    void* GetVertexData() { return &vertex[0]; }
    void* GetPrimitivesData() { return &primitives[0]; }

    int GetVertexNum() const { return num_vertex; }
    int GetPrimitivesNum() const { return num_primitives; }
    Eigen::Matrix4f GetPose() const { return pose; }
};


} // namespace kgl


#endif