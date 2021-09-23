#include "readyTestsQuadratic.h"
#include "testQuadratic.h"

void readyTestsQuadratic() {
    testQuadratic('1', 1, -3, -4, 2, 4, -1);
    testQuadratic('2', 5, 2, 3, 0, 0, 0);
    testQuadratic('3', 0, 0, 0, -1, 0, 0);
    testQuadratic('4', 2, 0, 0, 1, 0, 0);
    testQuadratic('5', 1, 4, -2, 2, 0, 0);
    testQuadratic('6', 1, 4, -2, 2, 0.449490, -4.449490);
    testQuadratic('7', 1, 4, -2, 100, 0.449490, -4.449490);
}