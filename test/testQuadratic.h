#ifndef C_TESTQUADRATIC_H
#define C_TESTQUADRATIC_H



/*!
 * @brief                       The test for function 'solveQE'
 * @param testName              Name of test
 * @param a                     Quadratic equation's coefficients 'A'
 * @param b                     Quadratic equation's coefficients 'B'
 * @param c                     Quadratic equation's coefficients 'C'
 * @param numberOfExpectedRoots Number of expected roots (2 - two roots; 1 - one root; 0 - zero roots; -1 - infinity roots)
 * @param x1                    First expected root
 * @param x2                    Second expected root
 * @return                      True if test finished without error
 */
int testQuadratic(const char testName, const double a, const double b, const double c,
                  const int numberOfExpectedRoots, const double expectedX1, const double expectedX2);

/*!
 * @brief Ready-made tests for function 'solveQuadratic'
 */
void readyTestsQuadratic();

#endif //C_TESTQUADRATIC_H
