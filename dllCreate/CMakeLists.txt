cmake_minimum_required(VERSION 3.26)
project(dllCreate)

set(CMAKE_CXX_STANDARD 17)

add_library(dllCreate SHARED library.cpp)
