# Minimum CMake version required
cmake_minimum_required(VERSION 3.10)

# Project name and version
project(MyProject VERSION 1.0 LANGUAGES CXX)

# Compiler settings
set(CMAKE_CXX_STANDARD 20) # Match -std=c++20
set(CMAKE_CXX_STANDARD_REQUIRED True)
# Set compiler flags
if (CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wno-missing-braces -O3 -g")
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4 /O2":w)
endif()

# Include directories
include_directories(include src)

# Library search paths and libraries
link_directories(${CMAKE_SOURCE_DIR}/lib)
set(LIBS raylib opengl32 gdi32 winmm) # Equivalent to -lraylib -lopengl32 -lgdi32 -lwinmm

# Source files
file(GLOB_RECURSE SRCS "${CMAKE_SOURCE_DIR}/src/*.cpp" "${CMAKE_SOURCE_DIR}/main.cpp")

# Output directories
set(OUTPUT_DIR "${CMAKE_SOURCE_DIR}/bin")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${OUTPUT_DIR})

# Target executable
add_executable(main ${SRCS})
target_link_libraries(main PRIVATE ${LIBS})
