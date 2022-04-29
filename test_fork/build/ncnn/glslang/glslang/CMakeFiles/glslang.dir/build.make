# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/tyler/Documents/github/waifu2x-ncnn-vulkan/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/tyler/Documents/github/waifu2x-ncnn-vulkan/src/build

# Include any dependencies generated for this target.
include ncnn/glslang/glslang/CMakeFiles/glslang.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include ncnn/glslang/glslang/CMakeFiles/glslang.dir/compiler_depend.make

# Include the progress variables for this target.
include ncnn/glslang/glslang/CMakeFiles/glslang.dir/progress.make

# Include the compile flags for this target's objects.
include ncnn/glslang/glslang/CMakeFiles/glslang.dir/flags.make

ncnn/glslang/glslang/CMakeFiles/glslang.dir/CInterface/glslang_c_interface.cpp.o: ncnn/glslang/glslang/CMakeFiles/glslang.dir/flags.make
ncnn/glslang/glslang/CMakeFiles/glslang.dir/CInterface/glslang_c_interface.cpp.o: ../ncnn/glslang/glslang/CInterface/glslang_c_interface.cpp
ncnn/glslang/glslang/CMakeFiles/glslang.dir/CInterface/glslang_c_interface.cpp.o: ncnn/glslang/glslang/CMakeFiles/glslang.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tyler/Documents/github/waifu2x-ncnn-vulkan/src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object ncnn/glslang/glslang/CMakeFiles/glslang.dir/CInterface/glslang_c_interface.cpp.o"
	cd /home/tyler/Documents/github/waifu2x-ncnn-vulkan/src/build/ncnn/glslang/glslang && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT ncnn/glslang/glslang/CMakeFiles/glslang.dir/CInterface/glslang_c_interface.cpp.o -MF CMakeFiles/glslang.dir/CInterface/glslang_c_interface.cpp.o.d -o CMakeFiles/glslang.dir/CInterface/glslang_c_interface.cpp.o -c /home/tyler/Documents/github/waifu2x-ncnn-vulkan/src/ncnn/glslang/glslang/CInterface/glslang_c_interface.cpp

ncnn/glslang/glslang/CMakeFiles/glslang.dir/CInterface/glslang_c_interface.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/glslang.dir/CInterface/glslang_c_interface.cpp.i"
	cd /home/tyler/Documents/github/waifu2x-ncnn-vulkan/src/build/ncnn/glslang/glslang && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tyler/Documents/github/waifu2x-ncnn-vulkan/src/ncnn/glslang/glslang/CInterface/glslang_c_interface.cpp > CMakeFiles/glslang.dir/CInterface/glslang_c_interface.cpp.i

ncnn/glslang/glslang/CMakeFiles/glslang.dir/CInterface/glslang_c_interface.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/glslang.dir/CInterface/glslang_c_interface.cpp.s"
	cd /home/tyler/Documents/github/waifu2x-ncnn-vulkan/src/build/ncnn/glslang/glslang && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tyler/Documents/github/waifu2x-ncnn-vulkan/src/ncnn/glslang/glslang/CInterface/glslang_c_interface.cpp -o CMakeFiles/glslang.dir/CInterface/glslang_c_interface.cpp.s

# Object files for target glslang
glslang_OBJECTS = \
"CMakeFiles/glslang.dir/CInterface/glslang_c_interface.cpp.o"

# External object files for target glslang
glslang_EXTERNAL_OBJECTS =

ncnn/glslang/glslang/libglslang.a: ncnn/glslang/glslang/CMakeFiles/glslang.dir/CInterface/glslang_c_interface.cpp.o
ncnn/glslang/glslang/libglslang.a: ncnn/glslang/glslang/CMakeFiles/glslang.dir/build.make
ncnn/glslang/glslang/libglslang.a: ncnn/glslang/glslang/CMakeFiles/glslang.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/tyler/Documents/github/waifu2x-ncnn-vulkan/src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libglslang.a"
	cd /home/tyler/Documents/github/waifu2x-ncnn-vulkan/src/build/ncnn/glslang/glslang && $(CMAKE_COMMAND) -P CMakeFiles/glslang.dir/cmake_clean_target.cmake
	cd /home/tyler/Documents/github/waifu2x-ncnn-vulkan/src/build/ncnn/glslang/glslang && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/glslang.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
ncnn/glslang/glslang/CMakeFiles/glslang.dir/build: ncnn/glslang/glslang/libglslang.a
.PHONY : ncnn/glslang/glslang/CMakeFiles/glslang.dir/build

ncnn/glslang/glslang/CMakeFiles/glslang.dir/clean:
	cd /home/tyler/Documents/github/waifu2x-ncnn-vulkan/src/build/ncnn/glslang/glslang && $(CMAKE_COMMAND) -P CMakeFiles/glslang.dir/cmake_clean.cmake
.PHONY : ncnn/glslang/glslang/CMakeFiles/glslang.dir/clean

ncnn/glslang/glslang/CMakeFiles/glslang.dir/depend:
	cd /home/tyler/Documents/github/waifu2x-ncnn-vulkan/src/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/tyler/Documents/github/waifu2x-ncnn-vulkan/src /home/tyler/Documents/github/waifu2x-ncnn-vulkan/src/ncnn/glslang/glslang /home/tyler/Documents/github/waifu2x-ncnn-vulkan/src/build /home/tyler/Documents/github/waifu2x-ncnn-vulkan/src/build/ncnn/glslang/glslang /home/tyler/Documents/github/waifu2x-ncnn-vulkan/src/build/ncnn/glslang/glslang/CMakeFiles/glslang.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : ncnn/glslang/glslang/CMakeFiles/glslang.dir/depend

