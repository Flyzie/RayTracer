cmake_minimum_required(VERSION 3.30)
project(RayTracer)

set(CMAKE_CXX_STANDARD 17)

project(RayTracer)

add_executable(RayTracer main.cpp
        Math/vec3.cpp
        Math/vec3.h
        Math/mat3x3.cpp
        Math/mat3x3.h
        Math/mat4x4.cpp
        Math/mat4x4.h
        Math/ray.cpp
        Math/ray.h
        Math/sphere.cpp
        Math/sphere.h
        Math/plane.cpp
        Math/plane.h
        Math/triangle.cpp
        Math/triangle.h
)

target_include_directories(${PROJECT_NAME} PUBLIC Math Utils)
