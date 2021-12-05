# KGL

OpenGL  render, with basic objects, buffer contorllers and mvp shaders.

# Dependencies

- GLFW

for window context control

- GLEW

for api definition finding

- Eigen 3.4.0

# Build

- c++17 for Eigen align problem

# Test
test with
- [ ] mingw-64w (x64)
- [ ] mingw-64w (86)
- [ ] ubuntu18

# BUG

## Eigen
- c++17 can not use operator new to create class with Vector4f or Matrix4f (but work for vector3f and Matrix3f), back to c++11 with macro EIGEN_MAKE_ALIGNED_OPERATOR_NEW fix it.
- callback function cannot do assignment to Matrix4f, alignment problem Cause 4, with compile flag -mstackrealign;  