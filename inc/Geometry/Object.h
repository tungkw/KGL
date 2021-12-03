#ifndef __KGL_OBJECT_H
#define __KGL_OBJECT_H
#include <vector>
#include "Eigen/Dense"
#include "Transformation.h"
#include "Geometry/Vertice.h"

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
    Eigen::Vector4f quaternion;

public:

    Object(/* args */){ pose = Eigen::Matrix4f::Identity(); }

    void SetPose(Eigen::Matrix4f pose_)
    {
        this->quaternion = QuaternionFromMatrix(pose_.block<3, 3>(0, 0));
        Eigen::Matrix4f new_pose = Eigen::Matrix4f::Identity();
        new_pose.block<3, 3>(0, 0) = MatrixFromQuaternion(this->quaternion);
        new_pose.block<3, 1>(0, 3) = pose_.block<3, 1>(0, 3);
        for (int i = 0 ; i < num_vertex; i++)
        {
            vertex[i].pos = this->pose.block<3, 3>(0, 0).transpose() * (vertex[i].pos - this->pose.block<3, 1>(0, 3));
            vertex[i].pos = new_pose.block<3, 3>(0, 0) * vertex[i].pos + new_pose.block<3, 1>(0, 3);
        }
        this->pose = new_pose;
    }
    
    void Transfrom(Eigen::Matrix4f trans)
    {
        Eigen::Vector4f q_r = QuaternionFromMatrix(trans.block<3,3>(0,0));
        this->quaternion = QuaternionMul(this->quaternion, q_r);
        Eigen::Matrix4f new_pose = Eigen::Matrix4f::Identity();
        new_pose.block<3, 3>(0, 0) = MatrixFromQuaternion(this->quaternion);
        new_pose.block<3, 1>(0, 3) = trans.block<3,3>(0,0) * this->pose.block<3, 1>(0, 3) + trans.block<3, 1>(0, 3);
        for (int i = 0 ; i < num_vertex; i++)
        {
            // vertex[i].pos = this->pose.block<3, 3>(0, 0).transpose() * (vertex[i].pos - this->pose.block<3, 1>(0, 3));
            // vertex[i].pos = new_pose.block<3, 3>(0, 0) * vertex[i].pos + new_pose.block<3, 1>(0, 3);
            vertex[i].pos = trans.block<3, 3>(0, 0) * vertex[i].pos + trans.block<3, 1>(0, 3);
        }
        this->pose = new_pose;
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