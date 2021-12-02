#include <iostream>
#include <vector>
#include "Eigen/Dense"
#include "Geometry/Line.h"

int main()
{
    Eigen::Vector3f start {0, 0, 0};
    Eigen::Vector3f end {0, 0, 1};
    kgl::Line l(start, end);
    kgl::Line l2(start, end);
}