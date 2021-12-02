#include <Eigen/Dense>


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