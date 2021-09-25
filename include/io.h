#ifndef QUADRATIC_IO_H
#define QUADRATIC_IO_H

#include "quadratic.h"

/*!
 * @brief Prints greeting text to user
 */
void printGreetings();

/*!
 * @brief Gets validated quadratic equation's coefficients from user
 * @param pA DOUBLE* Pointer to quadratic equation's coefficients 'A'
 * @param pB DOUBLE* Pointer to quadratic equation's coefficients 'B'
 * @param pC DOUBLE* Pointer to quadratic equation's coefficients 'C'
 */
void getValidCoefficients(double* const pA, double* const pB, double* const pC);

/*!
 * @brief Prints original quadratic equation and it's calculated roots
 * @param a              DOUBLE Quadratic equation's coefficients 'A'
 * @param b              DOUBLE Quadratic equation's coefficients 'B'
 * @param c              DOUBLE Quadratic equation's coefficients 'C'
 * @param quadraticRoots QuadraticRoots* Pointer to struct for equation's roots
 */
void printEquationAndRoots(
        const double a, const double b, const double c,
        QuadraticRoots* quadraticRoots
);

/*!
 * @brief  Asks user does he want to solve another equation
 * @return 1 if user want to solve another equation
 */
int askForNextEquation();



#endif //QUADRATIC_IO_H
