#ifndef __utils__
#define __utils__

#include <stdbool.h>

/*!
 * @brief Clears an input buffer
 */
void clearInput();

/*!
 * @brief Checks if a number is almost zero
 * @param a DOUBLE-TYPE number
 * @return True if putted number is almost zero
 */
bool isZero(const double a);

/*!
 * @brief Checks if at least one of putted numbers is almost zero
 * @param countOfnumbers INT-TYPE Count of putted numbers
 * @param ... DOUBLE-TYPE list of numbers
 * @return True if at least one of putted numbers is almost zero
 */
bool isAnyZero(const int countOfnumbers, ...);

/*!
 * @brief Checks if all putted numbers are almost zero
 * @param countOfnumbers INT-TYPE Count of putted numbers
 * @param ... DOUBLE-TYPE list of numbers
 * @return True if all putted numbers are almost zero
 */
bool isAllZero(const int countOfnumbers, ...);

/*!
 * @brief Checks if putted numbers are almost equal
 * @param a DOUBLE-TYPE number
 * @param b DOUBLE-TYPE number
 * @return True if putted numbers are almost equal
 */
bool isEqual(const double a, const double b);

/*!
 * @brief Checks if putted number is positive
 * @param a DOUBLE-TYPE number
 * @return True if number is positive
 */
bool isPositive(const double a);

/*!
 * @brief Interactively gets one double coefficient
 * @param pCoefficient DOUBLE-POINTER-TYPE Pointer of coefficient
 * @param symbolCoefficient CHAR-TYPE Symbol of coefficient
 */
void getCoefficient(double* const pCoefficient, const char symbolCoefficient);

/*!
 * @brief Interactively gets from 0 to 57 (A...z) DOUBLE-TYPE coefficients
 * @param countOfCoefficients INT-TYPE Count of putted pointers of coefficients
 * @param ... DOUBLE-POINTER-TYPE list of pointers of coefficients
 * @return True if function got all coefficients
 */
bool getSomeCoefficients(const int countOfCoefficients, ...);

/*!
 * @brief Solves a linear equation (ax + b = 0)
 * @param a DOUBLE-TYPE Coefficient a
 * @param b DOUBLE-TYPE Coefficient b
 * @param roots DOUBLE-TYPE array for calculated root
 * @return Number of roots (1 - one root; 0 - zero roots; -1 - infinity roots)
 */
int solveLE(const double a, const double b, double roots[]);

/*!
 * Solves a quadratic equation and returns number of roots (ax^2 + bx + c = 0)
 * @param a DOUBLE-TYPE Coefficient a
 * @param b DOUBLE-TYPE Coefficient b
 * @param c DOUBLE-TYPE Coefficient c
 * @param roots DOUBLE-TYPE array for calculated roots
 * @return Number of roots (2 - two roots; 1 - one root; 0 - zero roots; -1 - infinity roots)
 */
int solveQE(const double a, const double b, const double c, double roots[]);

#endif
