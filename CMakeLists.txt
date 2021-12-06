cmake_minimum_required(VERSION 3.14)
set( CMAKE_CXX_STANDARD 17 )
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -mstackrealign")
project(KGL)



add_library( ${PROJECT_NAME}
    ./src/Logger.cpp 
    ./src/VertexBuffer.cpp 
    ./src/IndexBuffer.cpp
    ./src/VertexArray.cpp
    ./src/VertexBufferLayout.cpp
    ./src/Shader.cpp
    ./src/Texture.cpp
    ./src/Transformation.cpp
    ./src/Render.cpp
    ./utils/stb_image/stb_image.cpp
)


target_include_directories( ${PROJECT_NAME} PUBLIC
    ./inc
    ./dep/glew/include
    ./dep/glfw/include
    ./utils/stb_image
    ./dep/eigen
)

IF(CMAKE_SYSTEM_NAME MATCHES "Linux")
    target_link_directories(${PROJECT_NAME} PUBLIC 
        ./dep/glew/lib/Release/ubuntu18/
        ./dep/glfw/ubuntu18/
    )
    target_link_libraries(${PROJECT_NAME}  PUBLIC 
        GLEW
        glfw3
        GL
        -lpthread
        -ldl
    )
ELSEIF(CMAKE_SYSTEM_NAME MATCHES "Windows")
    target_link_directories(${PROJECT_NAME} PUBLIC 
        ./dep/glew/lib/Release/Win32/
        ./dep/glfw/lib-mingw-w64/Win32/
    )
    target_link_libraries(${PROJECT_NAME} PUBLIC 
        glew32s
        glfw3
        Opengl32
        Gdi32
    )
ENDIF()

IF(KGL_EXAMPLE)
    message("KGL_EXAMPLE defined")
    add_executable(example
        example/example.cpp 
    )
    target_link_libraries(example KGL)
ENDIF()