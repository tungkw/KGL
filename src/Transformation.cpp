#include "Transformation.h"

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
Qaternion
*/
Eigen::Vector4f QuaternionFromMatrix(Eigen::Matrix3f mat)
{
    Eigen::Vector4f q;
    float trace = mat(0,0) + mat(1,1) + mat(2,2);
    float theta = acosf((trace-1.f)/(2.f));
    if (sinf(theta) < EPSILON)
    {
        theta = 0.f;
        q = {0.f, 0.f, 0.f, 1.f};
    }
    else
    {
        Eigen::Vector3f omega = Eigen::Vector3f(mat(2,1)-mat(1,2), mat(0,2)-mat(2,0), mat(1,0)-mat(0,1)) / (2.f*sinf(theta));
        q.block<3, 1>(0,0) = sinf(theta/2.f) * omega.normalized();
        q(3) = cosf(theta/2.f);
    }
    return q.normalized();
}

Eigen::Matrix3f MatrixFromQuaternion(Eigen::Vector4f q)
{
    Eigen::Matrix3f mat, omega_hat;
    Eigen::Vector3f omega;
    float theta;

    theta = 2.0f * acosf(q(3));
    if (sinf(theta/2.0f) < EPSILON)
    {
        return Eigen::Matrix3f::Identity();
    }
    else
    {
        omega = q.block<3, 1>(0, 0) / sinf(theta/2.0f);
        omega_hat = Hat(omega);
        mat = Eigen::Matrix3f::Identity() + omega_hat * sinf(theta) + omega_hat * omega_hat * (1-cosf(theta));
        return mat;
    }
}

Eigen::Vector4f QuaternionMul(Eigen::Vector4f q1, Eigen::Vector4f q2)
{
    Eigen::Vector4f q;
    q.block<3, 1>(0,0) = q1.block<3, 1>(0,0) * q2(3) + 
                         q2.block<3, 1>(0,0) * q1(3) + 
                         q1.block<3, 1>(0,0).cross(q2.block<3, 1>(0,0));
    q(3) = q1(3)*q2(3) - q1.block<3, 1>(0,0).transpose().dot(q2.block<3, 1>(0,0));
    return q.normalized();
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