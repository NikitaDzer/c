#ifndef C_TESTQUADRATIC_H
#define C_TESTQUADRATIC_H

#include <stdbool.h>

/*!
 * @brief The test for function 'solveQE'
 * @param testName Name of test
 * @param a Coefficient A
 * @param b Coefficient B
 * @param c Coefficient C
 * @param numberOfExpectedRoots Number of expected roots (2 - two roots; 1 - one root; 0 - zero roots; -1 - infinity roots)
 * @param x1 First expected root
 * @param x2 Second expected root
 * @return Test finished without error
 */
bool testQuadratic(const char testName, const double a, const double b, const double c,
                   const int numberOfExpectedRoots, const double x1, const double x2);

#endif //C_TESTQUADRATIC_H
