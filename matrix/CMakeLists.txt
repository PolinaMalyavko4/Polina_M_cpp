cmake_minimum_required(VERSION 3.17)
project(matrix)

set(CMAKE_CXX_STANDARD 14)

add_executable(matrix main.cpp matrix.cpp matrix.h SingleMatrix.cpp SingleMatrix.h DiagonalMatrix.cpp DiagonalMatrix.h TriangleHighMatrix.cpp TriangleHighMatrix.h TriangleLowMatrix.cpp TriangleLowMatrix.h)