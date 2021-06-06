cmake_minimum_required(VERSION 3.17)
project(lab8)

set(CMAKE_CXX_STANDARD 14)

add_executable(lab8 main.cpp cmake-build-debug/customer.cpp cmake-build-debug/customer.h customer.h cmake-build-debug/customer.cpp cmake-build-debug/customer.h)