cmake_minimum_required(VERSION 3.14)
set( CMAKE_CXX_STANDARD 17 )
project(GL)

set(EXECUTABLE_OUTPUT_PATH ./..)

include_directories(
    ./inc
    ./dep/glew/include
    ./dep/glfw/include
    ./utils/stb_image
    ./dep/eigen
)


IF(CMAKE_SYSTEM_NAME MATCHES "Linux")
    message("build in Linux")
    link_directories(
        ./dep/glew/lib/Release/ubuntu18/
        ./dep/glfw/ubuntu18/
    )
ELSEIF(CMAKE_SYSTEM_NAME MATCHES "Windows")
    message("build in Windows")
    link_directories(
        ./dep/glew/lib/Release/Win32/
        ./dep/glfw/lib-mingw-w64/Win32/
    )
ENDIF()


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

IF(CMAKE_SYSTEM_NAME MATCHES "Linux")
    target_link_libraries(main
        GLEW
        glfw3
        GL
        -lpthread
        -ldl
    )
ELSEIF(CMAKE_SYSTEM_NAME MATCHES "Windows")
    target_link_libraries(main
        glew32s
        glfw3
        Opengl32
        Gdi32
    )
ENDIF()


add_executable(test test.cpp)