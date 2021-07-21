cmake_minimum_required(VERSION 3.19)
project(genlib)

set(CMAKE_CXX_STANDARD 17)

add_executable(genlib main.cpp graph.hpp testlib.h output.hpp generators/tree.hpp generators/sequence.hpp generators/output.hpp _genlib.hpp)