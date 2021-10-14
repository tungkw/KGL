cmake_minimum_required(VERSION 3.17)
# COMPILE_FLAGS(-std=c++11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")
project(KiGL)

include_directories(
    ./dep/glew/include
    ./dep/glfw/include
    ./utils/stb_image
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
add_executable(main 
    main.cpp 
    KiLogger.cpp 
    KiVertexBuffer.cpp 
    KiIndexBuffer.cpp
    KiVertexArray.cpp
    KiVertexBufferLayout.cpp
    KiShader.cpp
    KiTexture.cpp
    # KiRender.cpp
    ./utils/stb_image/stb_image.cpp
)
