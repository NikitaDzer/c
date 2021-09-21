#include "readyTestsQE.h"
#include "testQE.h"

void readyTestsQE() {
    testQE('1', 1, -3, -4, 2, 4., -1.);
    testQE('2', 5, 2, 3, 0);
    testQE('3', 0, 0, 0, -1);
    testQE('4', 2, 0, 0, 1, 0.);
    testQE('5', 1, 4, -2, 2, 0., 0.);
    testQE('6', 1, 4, -2, 2, 0.449490, -4.449490);
    testQE('7', 1, 4, -2, 100, 0.449490, -4.449490);
}