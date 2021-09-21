cmake_minimum_required(VERSION 3.0)
project(C C)

set(CMAKE_C_STANDARD 11)

add_executable(C src/main.c src/utils/utils.c src/utils/utils.h src/solverQE/solverQE.c src/solverQE/solverQE.h src/utils/testQE/testQE.c src/utils/testQE/testQE.h src/utils/testQE/readyTestsQE.c src/utils/testQE/readyTestsQE.h)
