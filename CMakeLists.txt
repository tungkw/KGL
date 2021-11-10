cmake_minimum_required(VERSION 3.17)
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
    ./dep/glew/lib/Release/x64/
    ./dep/glfw/lib-mingw-w64/
)



link_libraries(
    glew32s
    glfw3
    Opengl32
    Gdi32
)
add_executable(main 
    main.cpp 
    Logger.cpp 
    VertexBuffer.cpp 
    IndexBuffer.cpp
    VertexArray.cpp
    VertexBufferLayout.cpp
    Shader.cpp
    Texture.cpp
    # Render.cpp
    ./utils/stb_image/stb_image.cpp
)
