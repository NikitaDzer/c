cmake_minimum_required(VERSION 3.0)
project(C C)

set(CMAKE_C_STANDARD 11)

add_executable(C src/main.c src/utils/utils.c src/utils/utils.h src/solver/solver.c src/solver/solver.h src/solveQuadratic/testQuadratic/testQuadratic.c src/solveQuadratic/testQuadratic/testQuadratic.h src/solveQuadratic/testQuadratic/readyTestsQuadratic.c src/solveQuadratic/testQuadratic/readyTestsQuadratic.h src/solveQuadratic/solveQuadratic.c src/solveQuadratic/solveQuadratic.h)
