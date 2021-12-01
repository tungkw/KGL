cmake_minimum_required(VERSION 3.14)
# COMPILE_FLAGS(-std=c++11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")
project(GL)

set(EXECUTABLE_OUTPUT_PATH ./..)

include_directories(
    ./dep/glew/include
    ./dep/glfw/include
    ./utils/stb_image
    ./dep/eigen
)
link_directories(
    # ./dep/glew/lib/Release/x64/
    # ./dep/glfw/lib-mingw-w64/

    ./dep/glew/lib/Release/ubuntu18/
    ./dep/glfw/ubuntu18/
)



include_directories(./inc)

link_libraries(
    # glew32s
    # glfw3
    # Opengl32
    # Gdi32

    GLEW
    glfw3
    GL
    -lpthread
    -ldl
    # Gdi32
)
add_executable(main 
    main.cpp 
    
    src/Logger.cpp 
    src/VertexBuffer.cpp 
    src/IndexBuffer.cpp
    src/VertexArray.cpp
    src/VertexBufferLayout.cpp
    src/Shader.cpp
    src/Texture.cpp
    
    ./utils/stb_image/stb_image.cpp
)
