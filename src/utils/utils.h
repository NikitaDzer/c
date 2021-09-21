#ifndef __utils__
#define __utils__

#include <stdbool.h>


/**
* Clears an input buffer
*/
void clearInput();

/**
* Checks if a number is almost zero
*/
bool isZero(const double a);


/**
* Checks if at least one of putted numbers is almost zero
*/
bool isAnyZero(const int countOfnumbers, ...);

/**
* Checks if all putted numbers is almost zero
*/
bool isAllZero(const int countOfnumbers, ...);

/**
* Checks if putted numbers are equal
*/
bool isEqual(const double a, const double b);

/**
* Checks if a number is positive
*/
bool isPositive(const double a);

/**
* Interactively gets one double coefficient
*/
void getCoefficient(double* const pCoefficient, const char symbolCoefficient);

/**
* Interactively gets from 0 to 57 (A...z) double coefficients
*/
bool getSomeCoefficients(const int countOfCoefficients, ...);

/*
 * Solves a linear equation and returns number of roots
 */
int solveLE(const double a, const double b, double roots[]);

/* 
* Solves a quadratic equation and returns number of roots
*/
int solveQE(const double a, const double b, const double c, double roots[]);

#endif
