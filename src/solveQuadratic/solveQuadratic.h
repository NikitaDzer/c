#ifndef C_SOLVEQUADRATIC_H
#define C_SOLVEQUADRATIC_H

/*!
 * Solves a quadratic equation and returns number of roots (ax^2 + bx + c = 0)
 * @param a DOUBLE Coefficient 'a' of quadratic equation
 * @param b DOUBLE Coefficient 'b' of quadratic equation
 * @param c DOUBLE Coefficient 'c' of quadratic equation
 * @param roots DOUBLE-ARRAY Array for calculated roots
 * @return Number of roots (2 - two roots; 1 - one root; 0 - zero roots; -1 - infinity roots)
 */
int solveQuadratic(const double a, const double b, const double c, double roots[]);

#endif //C_SOLVEQUADRATIC_H
