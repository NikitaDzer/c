#include <math.h>
#include "solveQuadratic.h"
#include "../utils/utils.h"


/*!
 * @brief Calculates quadratic equation (ax^2 + bx + c = 0) discriminant
 * @param a DOUBLE Coefficient 'a' of quadratic equation
 * @param b DOUBLE Coefficient 'b' of quadratic equation
 * @param c DOUBLE Coefficient 'c' of quadratic equation
 * @return Calculated discriminant
 */
static double calcDiscriminant(const double a, const double b, const double c) {
    return b * b - 4 * a * c;
}

/*!
 * @brief Calculates roots of quadratic equation (ax^2 + bx + c = 0)
 * @param a DOUBLE Coefficient 'a' of quadratic equation
 * @param b DOUBLE Coefficient 'b' of quadratic equation
 * @param discriminant DOUBLE Quadratic equation discriminant
 * @param pX1 DOUBLE-POINTER Pointer of first quadratic equation's root
 * @param pX2 DOUBLE-POINTER Pointer of second quadratic equation's root
 */
static void calcAndPutRoots(
        const double a, const double b, const double discriminant,
        double* const pX1, double* const pX2
) {
    double sqrtDiscriminant = sqrt(discriminant),
            doubleA          = 2 * a;
    
    *pX1 = (-b + sqrtDiscriminant) / doubleA;
    *pX2 = (-b - sqrtDiscriminant) / doubleA;
}

/*!
 * Solves a linear equation and returns number of roots (ax + b = 0)
 * @param a DOUBLE Coefficient 'a' of linear equation
 * @param b DOUBLE Coefficient 'b' of linear equation
 * @param roots DOUBLE-ARRAY Array for calculated roots
 * @return Number of roots (1 - one root; 0 - zero roots; -1 - infinity roots)
 */
static int solveLinear(const double a, const double b, double roots[]) {
    if (isAllZero(2, a, b))
        return -1; // infinity roots
    if (isZero(a))
        return 0; // no roots
    
    roots[0] = -b / a;
    return 1;
}

int solveQuadratic(const double a, const double b, const double c, double roots[]) {
    if (isAllZero(3, a, b, c))
        return -1; // infinity roots
    if (isZero(a))
        return solveLinear(b, c, roots); // linear equation
    if (isZero(b)) {
        if (isPositive(a) && isPositive(c))
            return 0;
        if (isZero(c)) {
            roots[0] = 0;
            return 1;
        }
        
        double root = sqrt(-c / a);
        roots[0] = root;
        roots[1] = -root;
        
        return 2;
    }
    if (isZero(c)) {
        roots[0] = 0;
        roots[1] = -b / a;
        
        return 2;
    }
    
    double discriminant = calcDiscriminant(a, b, c);
    if (!isPositive(discriminant))
        return 0;
    if (isZero(discriminant)) {
        roots[0] = -b / (2 * a);
        return 1;
    }
    calcAndPutRoots(a, b, discriminant, &roots[0], &roots[1]);
    
    return 2;
}