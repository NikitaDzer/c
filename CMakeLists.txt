cmake_minimum_required(VERSION 3.20)
project(quadratic)

set(CMAKE_CXX_STANDARD 17)

add_executable(quadratic src/main.cpp src/app.cpp include/app.h test/testQuadratic.cpp test/testQuadratic.h src/quadratic.cpp include/quadratic.h src/io.cpp include/io.h)
