# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/tungkw/code/opengl_l

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/tungkw/code/opengl_l/build

# Include any dependencies generated for this target.
include CMakeFiles/main.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/main.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/main.dir/flags.make

CMakeFiles/main.dir/main.cpp.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tungkw/code/opengl_l/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/main.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/main.dir/main.cpp.o -c /home/tungkw/code/opengl_l/main.cpp

CMakeFiles/main.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tungkw/code/opengl_l/main.cpp > CMakeFiles/main.dir/main.cpp.i

CMakeFiles/main.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tungkw/code/opengl_l/main.cpp -o CMakeFiles/main.dir/main.cpp.s

CMakeFiles/main.dir/src/Logger.cpp.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/src/Logger.cpp.o: ../src/Logger.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tungkw/code/opengl_l/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/main.dir/src/Logger.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/main.dir/src/Logger.cpp.o -c /home/tungkw/code/opengl_l/src/Logger.cpp

CMakeFiles/main.dir/src/Logger.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/src/Logger.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tungkw/code/opengl_l/src/Logger.cpp > CMakeFiles/main.dir/src/Logger.cpp.i

CMakeFiles/main.dir/src/Logger.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/src/Logger.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tungkw/code/opengl_l/src/Logger.cpp -o CMakeFiles/main.dir/src/Logger.cpp.s

CMakeFiles/main.dir/src/VertexBuffer.cpp.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/src/VertexBuffer.cpp.o: ../src/VertexBuffer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tungkw/code/opengl_l/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/main.dir/src/VertexBuffer.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/main.dir/src/VertexBuffer.cpp.o -c /home/tungkw/code/opengl_l/src/VertexBuffer.cpp

CMakeFiles/main.dir/src/VertexBuffer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/src/VertexBuffer.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tungkw/code/opengl_l/src/VertexBuffer.cpp > CMakeFiles/main.dir/src/VertexBuffer.cpp.i

CMakeFiles/main.dir/src/VertexBuffer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/src/VertexBuffer.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tungkw/code/opengl_l/src/VertexBuffer.cpp -o CMakeFiles/main.dir/src/VertexBuffer.cpp.s

CMakeFiles/main.dir/src/IndexBuffer.cpp.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/src/IndexBuffer.cpp.o: ../src/IndexBuffer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tungkw/code/opengl_l/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/main.dir/src/IndexBuffer.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/main.dir/src/IndexBuffer.cpp.o -c /home/tungkw/code/opengl_l/src/IndexBuffer.cpp

CMakeFiles/main.dir/src/IndexBuffer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/src/IndexBuffer.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tungkw/code/opengl_l/src/IndexBuffer.cpp > CMakeFiles/main.dir/src/IndexBuffer.cpp.i

CMakeFiles/main.dir/src/IndexBuffer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/src/IndexBuffer.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tungkw/code/opengl_l/src/IndexBuffer.cpp -o CMakeFiles/main.dir/src/IndexBuffer.cpp.s

CMakeFiles/main.dir/src/VertexArray.cpp.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/src/VertexArray.cpp.o: ../src/VertexArray.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tungkw/code/opengl_l/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/main.dir/src/VertexArray.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/main.dir/src/VertexArray.cpp.o -c /home/tungkw/code/opengl_l/src/VertexArray.cpp

CMakeFiles/main.dir/src/VertexArray.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/src/VertexArray.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tungkw/code/opengl_l/src/VertexArray.cpp > CMakeFiles/main.dir/src/VertexArray.cpp.i

CMakeFiles/main.dir/src/VertexArray.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/src/VertexArray.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tungkw/code/opengl_l/src/VertexArray.cpp -o CMakeFiles/main.dir/src/VertexArray.cpp.s

CMakeFiles/main.dir/src/VertexBufferLayout.cpp.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/src/VertexBufferLayout.cpp.o: ../src/VertexBufferLayout.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tungkw/code/opengl_l/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/main.dir/src/VertexBufferLayout.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/main.dir/src/VertexBufferLayout.cpp.o -c /home/tungkw/code/opengl_l/src/VertexBufferLayout.cpp

CMakeFiles/main.dir/src/VertexBufferLayout.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/src/VertexBufferLayout.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tungkw/code/opengl_l/src/VertexBufferLayout.cpp > CMakeFiles/main.dir/src/VertexBufferLayout.cpp.i

CMakeFiles/main.dir/src/VertexBufferLayout.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/src/VertexBufferLayout.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tungkw/code/opengl_l/src/VertexBufferLayout.cpp -o CMakeFiles/main.dir/src/VertexBufferLayout.cpp.s

CMakeFiles/main.dir/src/Shader.cpp.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/src/Shader.cpp.o: ../src/Shader.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tungkw/code/opengl_l/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/main.dir/src/Shader.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/main.dir/src/Shader.cpp.o -c /home/tungkw/code/opengl_l/src/Shader.cpp

CMakeFiles/main.dir/src/Shader.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/src/Shader.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tungkw/code/opengl_l/src/Shader.cpp > CMakeFiles/main.dir/src/Shader.cpp.i

CMakeFiles/main.dir/src/Shader.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/src/Shader.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tungkw/code/opengl_l/src/Shader.cpp -o CMakeFiles/main.dir/src/Shader.cpp.s

CMakeFiles/main.dir/src/Texture.cpp.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/src/Texture.cpp.o: ../src/Texture.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tungkw/code/opengl_l/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/main.dir/src/Texture.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/main.dir/src/Texture.cpp.o -c /home/tungkw/code/opengl_l/src/Texture.cpp

CMakeFiles/main.dir/src/Texture.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/src/Texture.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tungkw/code/opengl_l/src/Texture.cpp > CMakeFiles/main.dir/src/Texture.cpp.i

CMakeFiles/main.dir/src/Texture.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/src/Texture.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tungkw/code/opengl_l/src/Texture.cpp -o CMakeFiles/main.dir/src/Texture.cpp.s

CMakeFiles/main.dir/utils/stb_image/stb_image.cpp.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/utils/stb_image/stb_image.cpp.o: ../utils/stb_image/stb_image.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tungkw/code/opengl_l/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/main.dir/utils/stb_image/stb_image.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/main.dir/utils/stb_image/stb_image.cpp.o -c /home/tungkw/code/opengl_l/utils/stb_image/stb_image.cpp

CMakeFiles/main.dir/utils/stb_image/stb_image.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/utils/stb_image/stb_image.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tungkw/code/opengl_l/utils/stb_image/stb_image.cpp > CMakeFiles/main.dir/utils/stb_image/stb_image.cpp.i

CMakeFiles/main.dir/utils/stb_image/stb_image.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/utils/stb_image/stb_image.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tungkw/code/opengl_l/utils/stb_image/stb_image.cpp -o CMakeFiles/main.dir/utils/stb_image/stb_image.cpp.s

# Object files for target main
main_OBJECTS = \
"CMakeFiles/main.dir/main.cpp.o" \
"CMakeFiles/main.dir/src/Logger.cpp.o" \
"CMakeFiles/main.dir/src/VertexBuffer.cpp.o" \
"CMakeFiles/main.dir/src/IndexBuffer.cpp.o" \
"CMakeFiles/main.dir/src/VertexArray.cpp.o" \
"CMakeFiles/main.dir/src/VertexBufferLayout.cpp.o" \
"CMakeFiles/main.dir/src/Shader.cpp.o" \
"CMakeFiles/main.dir/src/Texture.cpp.o" \
"CMakeFiles/main.dir/utils/stb_image/stb_image.cpp.o"

# External object files for target main
main_EXTERNAL_OBJECTS =

../main: CMakeFiles/main.dir/main.cpp.o
../main: CMakeFiles/main.dir/src/Logger.cpp.o
../main: CMakeFiles/main.dir/src/VertexBuffer.cpp.o
../main: CMakeFiles/main.dir/src/IndexBuffer.cpp.o
../main: CMakeFiles/main.dir/src/VertexArray.cpp.o
../main: CMakeFiles/main.dir/src/VertexBufferLayout.cpp.o
../main: CMakeFiles/main.dir/src/Shader.cpp.o
../main: CMakeFiles/main.dir/src/Texture.cpp.o
../main: CMakeFiles/main.dir/utils/stb_image/stb_image.cpp.o
../main: CMakeFiles/main.dir/build.make
../main: CMakeFiles/main.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/tungkw/code/opengl_l/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Linking CXX executable ../main"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/main.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/main.dir/build: ../main

.PHONY : CMakeFiles/main.dir/build

CMakeFiles/main.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/main.dir/cmake_clean.cmake
.PHONY : CMakeFiles/main.dir/clean

CMakeFiles/main.dir/depend:
	cd /home/tungkw/code/opengl_l/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/tungkw/code/opengl_l /home/tungkw/code/opengl_l /home/tungkw/code/opengl_l/build /home/tungkw/code/opengl_l/build /home/tungkw/code/opengl_l/build/CMakeFiles/main.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/main.dir/depend

