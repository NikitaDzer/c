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
 * @param countOfNumbers INT-TYPE Count of putted numbers
 * @param ... DOUBLE-TYPE list of numbers
 * @return True if at least one of putted numbers is almost zero
 */
bool isAnyZero(const int countOfNumbers, ...);

/*!
 * @brief Checks if all putted numbers are almost zero
 * @param countOfNumbers INT-TYPE Count of putted numbers
 * @param ... DOUBLE-TYPE list of numbers
 * @return True if all putted numbers are almost zero
 */
bool isAllZero(const int countOfNumbers, ...);

/*!
 * @brief Checks if putted numbers are almost equal
 * @param a DOUBLE-TYPE number
 * @param b DOUBLE-TYPE number
 * @return True if putted numbers are almost equal
 */
bool isApproximatelyEqual(const double a, const double b);

/*!
 * @brief Checks if putted number is positive
 * @param a DOUBLE-TYPE number
 * @return True if number is positive
 */
bool isPositive(const double a);

/*!
 * @brief Interactively gets one double coefficient
 * @param pCoefficient DOUBLE-POINTER-TYPE Pointer of coefficient
 * @param signOfCoefficient CHAR-TYPE Sign of coefficient
 */
void getCoefficient(double* const pCoefficient, const char signOfCoefficient);

/*!
 * @brief Interactively gets from 0 to 57 (A...z) DOUBLE-TYPE coefficients
 * @param countOfCoefficients INT-TYPE Count of putted pointers of coefficients
 * @param ... DOUBLE-POINTER-TYPE list of pointers of coefficients
 * @return True if function got all coefficients
 */
bool getSomeCoefficients(const int countOfCoefficients, ...);

#endif
