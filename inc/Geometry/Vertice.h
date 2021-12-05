#ifndef __KGL_VERTICE_H
#define __KGL_VERTICE_H
#include <Eigen/Dense>
#include "VertexBufferLayout.h"

namespace kgl
{

struct Vertice
{
    EIGEN_MAKE_ALIGNED_OPERATOR_NEW
    Eigen::Vector3f pos;
    Eigen::Vector4f color;
    static VertexBufferLayout GetLayout()
    {
        VertexBufferLayout vbl;
        vbl.Push<GLfloat>(offsetof(kgl::Vertice, color) - offsetof(kgl::Vertice, pos), 3);
        vbl.Push<GLfloat>(sizeof(kgl::Vertice) - offsetof(kgl::Vertice, color), 4);
        return vbl;
    }
};

struct NormalVertice
    : public Vertice
{
    Eigen::Vector3f normal;
    static VertexBufferLayout GetLayout()
    {
        VertexBufferLayout vbl;
        vbl.Push<GLfloat>(offsetof(kgl::NormalVertice, color) - offsetof(kgl::NormalVertice, pos), 3);
        vbl.Push<GLfloat>(offsetof(kgl::NormalVertice, normal) - offsetof(kgl::NormalVertice, color), 4);
        vbl.Push<GLfloat>(sizeof(kgl::NormalVertice) - offsetof(kgl::NormalVertice, normal), 3);
        return vbl;
    }
};




} // namespace kgl


#endif __KGL_VERTICE_H