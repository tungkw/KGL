#ifndef __KGL_OBJECT_H
#define __KGL_OBJECT_H
#include <vector>
#include "Eigen/Dense"
#include "Transformation.h"
#include "Geometry/Vertice.h"

namespace kgl
{

class ObjectBase
{
public:
    virtual void SetPose(Eigen::Matrix4f pose_) = 0;
    virtual void Transform(Eigen::Matrix4f trans) = 0;
    virtual void Rotation(Eigen::Matrix3f rmat) = 0;
    virtual void Translation(Eigen::Vector3f tvec) = 0;
    virtual void SetColor(Eigen::Vector4f color) = 0;
    virtual void* GetVertexData() = 0;
    virtual void* GetPrimitivesData() = 0;
    virtual int GetVertexNum() const = 0;
    virtual int GetPrimitivesNum() const = 0;
    virtual Eigen::Matrix4f GetPose() const = 0;
    virtual Eigen::Vector4f GetQuaternion() const = 0;
    
};

template<typename T>
class Object
    : public kgl::ObjectBase
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
    EIGEN_MAKE_ALIGNED_OPERATOR_NEW

    Object(/* args */)
    { 
        pose = Eigen::Matrix4f::Identity();
        quaternion = Eigen::Vector4f(0, 0, 0, 1);
        num_vertex = 0;
        num_primitives = 0; 
    }

    virtual void SetPose(Eigen::Matrix4f pose_)
    {
        Eigen::Matrix4f pose = this->pose, pose_inv = Eigen::Matrix4f::Identity();
        pose_inv.block<3, 3>(0, 0) = pose.block<3, 3>(0, 0).transpose();
        pose_inv.block<3, 1>(0, 3) = - pose_inv.block<3, 3>(0, 0) * pose.block<3, 1>(0, 3);
        Eigen::Matrix4f trans = pose_ * pose_inv;
        this->Transform(trans);
    }
    
    virtual void Transform(Eigen::Matrix4f trans)
    {
        this->Rotation(trans.block<3, 3>(0, 0));
        this->Translation(trans.block<3, 1>(0, 3));
    }

    virtual void Rotation(Eigen::Matrix3f rmat)
    {
        Eigen::Vector4f q_r = kgl::QuaternionFromMatrix(rmat);
        rmat = kgl::MatrixFromQuaternion(q_r);
        this->quaternion = kgl::QuaternionMul(q_r, this->quaternion);
        for (int i = 0 ; i < num_vertex; i++)
        {
            vertex[i].pos = rmat * vertex[i].pos;
        }
        this->pose.block<3, 3>(0, 0) = kgl::MatrixFromQuaternion(this->quaternion);
        this->pose.block<3, 1>(0, 3) = rmat * this->pose.block<3, 1>(0, 3);
    }

    virtual void Translation(Eigen::Vector3f tvec)
    {
        this->pose.block<3, 1>(0, 3) += tvec;
        for (int i = 0 ; i < num_vertex; i++)
        {
            vertex[i].pos += tvec;
        }
    }

    virtual void SetColor(Eigen::Vector4f color)
    {
        for(int i = 0 ; i < num_vertex; i++)
            vertex[i].color = color;
    }

    virtual void* GetVertexData() { return &vertex[0]; }
    virtual void* GetPrimitivesData() { return &primitives[0]; }

    virtual int GetVertexNum() const { return num_vertex; }
    virtual int GetPrimitivesNum() const { return num_primitives; }
    virtual Eigen::Matrix4f GetPose() const { return pose; }
    virtual Eigen::Vector4f GetQuaternion() const { return this->quaternion; }
};


} // namespace kgl


#endif