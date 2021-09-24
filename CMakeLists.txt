cmake_minimum_required(VERSION 3.20)
project(quadratic)

set(CMAKE_CXX_STANDARD 17)

add_executable(quadratic src/main.cpp src/utils/utils.cpp src/utils/utils.h src/solver/solver.cpp src/solver/solver.h src/solveQuadratic/test/testQuadratic.cpp src/solveQuadratic/test/testQuadratic.h src/solveQuadratic/test/readyTestsQuadratic.cpp src/solveQuadratic/test/readyTestsQuadratic.h src/solveQuadratic/solveQuadratic.cpp src/solveQuadratic/solveQuadratic.h)
