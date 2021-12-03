#ifndef __KGL_TRANSFORMATION_H
#define __KGL_TRANSFORMATION_H

#include <Eigen/Dense>

namespace kgl{

#define EPSILON 1e-6

Eigen::Matrix4f RotateZ(float theta);
Eigen::Matrix4f RotateX(float theta);
Eigen::Matrix4f RotateY(float theta);
Eigen::Matrix3f Hat(Eigen::Vector3f omega);

/*
Qaternion
*/
Eigen::Vector4f QuaternionFromMatrix(Eigen::Matrix3f mat);
Eigen::Matrix3f MatrixFromQuaternion(Eigen::Vector4f q);
Eigen::Vector4f QuaternionMul(Eigen::Vector4f q1, Eigen::Vector4f q2);


/*
projection
*/
Eigen::Matrix4f ViewMatrix(Eigen::Vector3f pos, Eigen::Vector3f up, Eigen::Vector3f target);
Eigen::Matrix4f OthogonalMatrix(float xl, float xu, float yl, float yu, float zl, float zu);
Eigen::Matrix4f ProjectionMatrix(float near, float far, float fov, float aspect);


} // namespace kgl

#endif