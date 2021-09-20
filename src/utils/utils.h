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
bool isZero(const long double a);

/**
* Checks if at least one of putted numbers is almost zero
*/
bool isAnyZero(const int countOfnumbers, ...);

/**
* Checks if all putted numbers is almost zero
*/
bool isAllZero(const int countOfnumbers, ...);

/**
* Interactively gets one long double coefficient
*/
void getCoefficient(long double* const pCoefficient, const char symbolCoefficient);

/**
* Interactively gets from 0 to 57 (A...z) long double coefficients
*/
bool getSomeCoefficients(const int countOfCoefficients, ...);

/* 
* Solves a quadratic equation and returns number of roots
*/
int solveQE(const long double a, const long double b, const long double c, long double roots[]);

#endif
