#include "dep/eigen/Eigen/Dense"
#include <iostream>

struct Vertex
{
    Eigen::Vector3f vec;
    Eigen::Vector4f color;
    Eigen::Vector2f tex_id;
    float tex_slot;
};

int main(int argc, char const *argv[])
{
    Eigen::Vector4f vec;
    std::cout << sizeof(Vertex) << std::endl;
    std::cout << offsetof(Vertex, vec) << std::endl;
    std::cout << offsetof(Vertex, color) << std::endl;
    std::cout << offsetof(Vertex, tex_id) << std::endl;
    std::cout << offsetof(Vertex, tex_slot) << std::endl;
    return 0;
}
