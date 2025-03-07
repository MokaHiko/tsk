cmake_minimum_required(VERSION 3.0.0...3.5)
project(tsk VERSION 1.0 LANGUAGES CXX)

set(TSK_BUILD_SHARED_LIBS OFF CACHE BOOL "Build shared libraries" FORCE)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCES
    include/tsk/endian.h
    include/tsk/time.h
    include/tsk/file.h
    include/tsk/tsk.h

    include/tsk/murmur_hash_3.h

    src/endian.cpp
    src/file.cpp
    src/time.cpp
    src/tsk.cpp

    src/murmur_hash_3.cpp
)

if(TSK_BUILD_SHARED_LIBS)
    add_library(tsk SHARED ${SOURCES})
    add_definitions(-DTSK_EXPORTS)
else()
    add_library(tsk STATIC ${SOURCES})
endif()

# Check for different platforms
if (CMAKE_SYSTEM_NAME STREQUAL "Windows")
    message(STATUS "Building on Windows")
    target_compile_definitions(tsk PUBLIC TSK_WIN32)
elseif (CMAKE_SYSTEM_NAME STREQUAL "Linux")
    message(STATUS "Building on Linux")
elseif (CMAKE_SYSTEM_NAME STREQUAL "Darwin")
    target_compile_definitions(tsk PUBLIC TSK_UNIX)
    message(STATUS "Building on macOS")
    target_compile_definitions(tsk PUBLIC TSK_MACOS)
else()
    message(WARNING "Unsupported platform: ${CMAKE_SYSTEM_NAME}")
endif()

target_precompile_headers(tsk PUBLIC include/tsk_pch.h)

# Public include directories
target_include_directories(tsk PUBLIC ./include)

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    target_compile_definitions(tsk PUBLIC TSK_DEBUG=1)
else()
    target_compile_definitions(tsk PUBLIC TSK_DEBUG=0)
endif()

