cmake_minimum_required(VERSION 3.17)
project(KiGL)

include_directories(
    ./dep/glew/include
    ./dep/glfw/include
)
link_directories(
    ./dep/glew/lib/Release/Win32/
    ./dep/glfw/lib-static-ucrt/
)
link_libraries(
    glew32s
    glfw3
    Opengl32
    Gdi32
)
add_executable(main main.cpp KiLogger.cpp KiVertexBuffer.cpp KiIndexBuffer.cpp)