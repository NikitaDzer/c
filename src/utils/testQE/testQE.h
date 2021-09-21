#ifndef C_TESTQE_H
#define C_TESTQE_H

#include <stdbool.h>

/*!
 * @brief The test for function 'solveQE'
 * @param testName Name of test
 * @param a Coefficient A
 * @param b Coefficient B
 * @param c Coefficient C
 * @param numberOfExpectedRoots Number of expected roots
 * @param ... Expected roots must be DOUBLE-TYPE!
 * @return Was the test without error
 */
bool testQE(const char testName, const double a, const double b, const double c, const int numberOfExpectedRoots, ...);

#endif //C_TESTQE_H
