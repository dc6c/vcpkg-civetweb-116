cmake_minimum_required(VERSION 3.25)
project(vcpkgcivet116)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(prometheus-cpp CONFIG REQUIRED)

add_executable(vcpkgcivet116 main.cpp)
target_link_libraries(vcpkgcivet116 PRIVATE prometheus-cpp::pull)
