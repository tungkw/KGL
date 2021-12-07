#include "Transformation.h"
#include <iostream>

namespace kgl{

Eigen::Matrix4f RotateZ(float theta)
{
    Eigen::Matrix4f rmat{
        {cosf(theta),   -sinf(theta),   0.f,    0.f},
        {sinf(theta),   cosf(theta),    0.f,    0.f},
        {0.f,           0.f,            1.f,    0.f},
        {0.f,           0.f,            0.f,    1.f},
    };
    return rmat;
}

Eigen::Matrix4f RotateX(float theta)
{
    Eigen::Matrix4f rmat{
        {1.f,   0.f,            0.f,            0.f},
        {0.f,   cosf(theta),    -sinf(theta),   0.f},
        {0.f,   sinf(theta),    cosf(theta),    0.f},
        {0.f,   0.f,            0.f,            1.f},
    };
    return rmat;
}

Eigen::Matrix4f RotateY(float theta)
{
    Eigen::Matrix4f rmat{
        {cosf(theta),   0.f,    sinf(theta),    0.f},
        {0.f,           1.f,    0.f,            0.f},
        {-sinf(theta),  0.f,    cosf(theta),    0.f},
        {0.f,           0.f,    0.f,            1.f},
    };
    return rmat;
}

Eigen::Matrix4f Translation(float x, float y, float z)
{
    Eigen::Matrix4f t = Eigen::Matrix4f::Identity();
    t.block<3, 1>(0, 3) = Eigen::Vector3f(x, y, z);
    return t;
}

Eigen::Matrix3f Hat(Eigen::Vector3f omega)
{
    Eigen::Matrix3f mat;
    mat <<  0, -omega(2), omega(1),
            omega(2), 0, -omega(0),
            -omega(1), omega(0), 0;
    return mat;
}

/*
rotation vector
*/

/*
Qaternion
*/
Eigen::Vector4f QuaternionFromMatrix(Eigen::Matrix3f mat)
{
    Eigen::Vector4f q;
    float tr = mat(0,0) + mat(1,1) + mat(2,2);

    if (tr > 0) 
    { 
        float S = sqrt(tr+1.0) * 2; // S=4*q(3) 
        q(3) = 0.25 * S;
        q(0) = (mat(2,1) - mat(1,2)) / S;
        q(1) = (mat(0,2) - mat(2,0)) / S; 
        q(2) = (mat(1,0) - mat(0,1)) / S; 
    } 
    else if ((mat(0,0) > mat(1,1))&(mat(0,0) > mat(2,2))) 
    { 
        float S = sqrt(1.0 + mat(0,0) - mat(1,1) - mat(2,2)) * 2; // S=4*q(0) 
        q(3) = (mat(2,1) - mat(1,2)) / S;
        q(0) = 0.25 * S;
        q(1) = (mat(0,1) + mat(1,0)) / S; 
        q(2) = (mat(0,2) + mat(2,0)) / S; 
    } 
    else if (mat(1,1) > mat(2,2)) 
    { 
        float S = sqrt(1.0 + mat(1,1) - mat(0,0) - mat(2,2)) * 2; // S=4*q(1)
        q(3) = (mat(0,2) - mat(2,0)) / S;
        q(0) = (mat(0,1) + mat(1,0)) / S; 
        q(1) = 0.25 * S;
        q(2) = (mat(1,2) + mat(2,1)) / S; 
    } 
    else 
    { 
        float S = sqrt(1.0 + mat(2,2) - mat(0,0) - mat(1,1)) * 2; // S=4*q(2)
        q(3) = (mat(1,0) - mat(0,1)) / S;
        q(0) = (mat(0,2) + mat(2,0)) / S;
        q(1) = (mat(1,2) + mat(2,1)) / S;
        q(2) = 0.25 * S;
    }
    if (q.hasNaN())
    {
        std::cout << "QuaternionFromMatrix" << std::endl
                  << mat << std::endl
                  << q << std::endl;
        exit(0);
    }
    return q;
}

Eigen::Matrix3f MatrixFromQuaternion(Eigen::Vector4f q)
{
    Eigen::Matrix3f mat, v_hat = Hat(q.block<3, 1>(0, 0));
    mat = Eigen::Matrix3f::Identity() + 2 * q(3) * v_hat + 2 * v_hat * v_hat;
    if (mat.hasNaN())
    {
        std::cout << "MatrixFromQuaternion" << std::endl
                  << q.transpose() << std::endl
                  << mat << std::endl;
        exit(0);
    }
    return mat;
}

Eigen::Vector4f QuaternionMul(Eigen::Vector4f q1, Eigen::Vector4f q2)
{
    Eigen::Vector4f q;
    Eigen::Vector3f w1 = q1.block<3, 1>(0, 0), w2 = q2.block<3, 1>(0, 0);
    q.block<3, 1>(0,0) = w1 * q2(3) + w2 * q1(3) + Hat(w1) * w2;
    q(3) = q1(3)*q2(3) - w1.dot(w2);
    if (q.hasNaN())
    {
        std::cout << "QuaternionMul" << std::endl
                  << "q1 " << q1.hasNaN() << std::endl
                  << "q2 " << q2.hasNaN() << std::endl;
    }
    q = q.normalized();
    if (q.hasNaN())
    {
        std::cout << "QuaternionMul normalized" << std::endl;
        std::cout << q1.transpose() << std::endl;
        std::cout << q2.transpose() << std::endl;
        exit(0);
    }
    return q;
}


/*
projection
*/
Eigen::Matrix4f ViewMatrix(Eigen::Vector3f pos, Eigen::Vector3f up, Eigen::Vector3f target)
{
    Eigen::Vector3f z = (target-pos).normalized();
    Eigen::Vector3f y = (up - pos).normalized();
    y = y - z * z.dot(y);
    Eigen::Vector3f x = y.cross(z).normalized();
    Eigen::Matrix4f trans {
        {1.f, 0.f, 0.f, -pos(0)},
        {0.f, 1.f, 0.f, -pos(1)},
        {0.f, 0.f, 1.f, -pos(2)},
        {0.f, 0.f, 0.f, 1},
    };
    Eigen::Matrix4f view {
        {x(0), x(1), x(2), 0.f},
        {y(0), y(1), y(2), 0.f},
        {z(0), z(1), z(2), 0.f},
        {0.f,  0.f,  0.f,  1.f},
    };
    return view * trans;
}

Eigen::Matrix4f OthogonalMatrix(float xl, float xu, float yl, float yu, float zl, float zu)
{
    Eigen::Matrix4f trans{
        {1.f, 0.f, 0.f, -(xu+xl)/2.f},
        {0.f, 1.f, 0.f, -(yu+yl)/2.f},
        {0.f, 0.f, 1.f, -(zu+zl)/2.f},
        {0.f, 0.f, 0.f, 1.f},
    };
    Eigen::Matrix4f otho{
        {2.f/(xu-xl),   0.f,            0.f,            0.f},
        {0.f,           2.f/(yu-yl),    0.f,            0.f},
        {0.f,           0.f,            2.f/(zu-zl),    0.f},
        {0.f,           0.f,            0.f,            1.f},
    };
    return otho * trans;
}

Eigen::Matrix4f ProjectionMatrix(float near, float far, float fov, float aspect)
{
    float yu = near * tanf(fov/2.f);
    float xu = yu * aspect;
    Eigen::Matrix4f proj{
        {near,  0.f,    0.f,        0.f},
        {0.f,   near,   0.f,        0.f},
        {0.f,   0.f,    near+far,   -near*far},
        {0.f,   0.f,    1.f,        0.f},
    };
    // swap (xu xl) (zu zl) to trans camera frame to window frame
    proj = OthogonalMatrix(xu, -xu, -yu, yu, near, far) * proj;
    return proj;
}


} // namespace kgl