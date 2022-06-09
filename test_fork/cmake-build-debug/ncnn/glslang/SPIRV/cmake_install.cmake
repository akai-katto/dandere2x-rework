# Install script for directory: /home/tyler/Documents/github/dandere2x-rework/test_fork/ncnn/glslang/SPIRV

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "0")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/usr/bin/objdump")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "/home/tyler/Documents/github/dandere2x-rework/test_fork/cmake-build-debug/ncnn/glslang/SPIRV/libSPIRV.a")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/SPIRVTargets.cmake")
    file(DIFFERENT EXPORT_FILE_CHANGED FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/SPIRVTargets.cmake"
         "/home/tyler/Documents/github/dandere2x-rework/test_fork/cmake-build-debug/ncnn/glslang/SPIRV/CMakeFiles/Export/lib/cmake/SPIRVTargets.cmake")
    if(EXPORT_FILE_CHANGED)
      file(GLOB OLD_CONFIG_FILES "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/SPIRVTargets-*.cmake")
      if(OLD_CONFIG_FILES)
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/SPIRVTargets.cmake\" will be replaced.  Removing files [${OLD_CONFIG_FILES}].")
        file(REMOVE ${OLD_CONFIG_FILES})
      endif()
    endif()
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake" TYPE FILE FILES "/home/tyler/Documents/github/dandere2x-rework/test_fork/cmake-build-debug/ncnn/glslang/SPIRV/CMakeFiles/Export/lib/cmake/SPIRVTargets.cmake")
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake" TYPE FILE FILES "/home/tyler/Documents/github/dandere2x-rework/test_fork/cmake-build-debug/ncnn/glslang/SPIRV/CMakeFiles/Export/lib/cmake/SPIRVTargets-release.cmake")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/glslang/SPIRV" TYPE FILE FILES
    "/home/tyler/Documents/github/dandere2x-rework/test_fork/ncnn/glslang/SPIRV/bitutils.h"
    "/home/tyler/Documents/github/dandere2x-rework/test_fork/ncnn/glslang/SPIRV/spirv.hpp"
    "/home/tyler/Documents/github/dandere2x-rework/test_fork/ncnn/glslang/SPIRV/GLSL.std.450.h"
    "/home/tyler/Documents/github/dandere2x-rework/test_fork/ncnn/glslang/SPIRV/GLSL.ext.EXT.h"
    "/home/tyler/Documents/github/dandere2x-rework/test_fork/ncnn/glslang/SPIRV/GLSL.ext.KHR.h"
    "/home/tyler/Documents/github/dandere2x-rework/test_fork/ncnn/glslang/SPIRV/GlslangToSpv.h"
    "/home/tyler/Documents/github/dandere2x-rework/test_fork/ncnn/glslang/SPIRV/hex_float.h"
    "/home/tyler/Documents/github/dandere2x-rework/test_fork/ncnn/glslang/SPIRV/Logger.h"
    "/home/tyler/Documents/github/dandere2x-rework/test_fork/ncnn/glslang/SPIRV/SpvBuilder.h"
    "/home/tyler/Documents/github/dandere2x-rework/test_fork/ncnn/glslang/SPIRV/spvIR.h"
    "/home/tyler/Documents/github/dandere2x-rework/test_fork/ncnn/glslang/SPIRV/doc.h"
    "/home/tyler/Documents/github/dandere2x-rework/test_fork/ncnn/glslang/SPIRV/SpvTools.h"
    "/home/tyler/Documents/github/dandere2x-rework/test_fork/ncnn/glslang/SPIRV/disassemble.h"
    "/home/tyler/Documents/github/dandere2x-rework/test_fork/ncnn/glslang/SPIRV/GLSL.ext.AMD.h"
    "/home/tyler/Documents/github/dandere2x-rework/test_fork/ncnn/glslang/SPIRV/GLSL.ext.NV.h"
    "/home/tyler/Documents/github/dandere2x-rework/test_fork/ncnn/glslang/SPIRV/NonSemanticDebugPrintf.h"
    "/home/tyler/Documents/github/dandere2x-rework/test_fork/ncnn/glslang/SPIRV/SPVRemapper.h"
    "/home/tyler/Documents/github/dandere2x-rework/test_fork/ncnn/glslang/SPIRV/doc.h"
    )
endif()

