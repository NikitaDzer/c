#include <stdio.h>
#include <stdbool.h>
#include <stdarg.h>
#include <iso646.h>
#include <float.h>
#include <math.h>
#include "utils.h"


/*!
 * @brief Number is almost zero, if it's in range (-EPSILON; +EPSILON)
 */
static const double EPSILON = 1000 * DBL_EPSILON;

/*!
 * @brief Accuracy with which two numbers are approximately equal
 */
static const double ACCURACY = 1e-5;

void clearInput() {
	while (getchar() != '\n');
}

bool isZero(const double a) {
	return fabs(a) < EPSILON;
}

bool isAnyZero(const int countOfNums, ...) {
	va_list nums = {0};
	va_start(nums, countOfNums);

	bool wasZero = false;
	for (int i = 0; i < countOfNums; ++i)
		if (isZero(va_arg(nums, double))) wasZero = true;

	va_end(nums);

	return wasZero;
}

bool isAllZero(const int countOfNums, ...) {
	va_list nums = {0};
	va_start(nums, countOfNums);

	bool allZero = true;
	for (int i = 0; i < countOfNums; ++i)
		if (!isZero(va_arg(nums, double))) allZero = false;

	va_end(nums);

	return allZero;
}

bool isEqual(const double a, const double b) {
    if (isZero(a)) return isZero(a - b);
    
    return fabs((a - b) / a) < ACCURACY and fabs((a - b) / b) < ACCURACY;
}

bool isPositive(const double a) {
    return !isZero(a) and isEqual(a, fabs(a));
}

double calcDiscriminant(const double a, const double b, const double c) {
	return b * b - 4 * a * c;
}

void getCoefficient(double* const pCoefficient, const char symbolCoefficient) {
	printf("%c: ", symbolCoefficient);

	while (!scanf("%lf", pCoefficient)) {
		printf("You can use only numbers.\n"
               "%c: ", symbolCoefficient);
		clearInput();
	}
 
	clearInput();
}

bool getSomeCoefficients(const int countOfCoeffs, ...) {
	if (countOfCoeffs > 57) return false; // 'z' - 'A' == 57

	va_list psOfCoeffs = {0};
	va_start(psOfCoeffs, countOfCoeffs);

	for (char lastCoeff = 'A' + countOfCoeffs, coeff = 'A'; coeff < lastCoeff; ++coeff)
		getCoefficient(va_arg(psOfCoeffs, double*), coeff);

	va_end(psOfCoeffs);

	return true;
}

static void calcAndPutRoots(
        double a, const double b, const double discriminant,
        double* const pX1, double* const pX2
) {
    double sqrtDiscriminant = sqrt(discriminant),
            doubleA = 2 * a;
    
    *pX1 = (-b + sqrtDiscriminant) / doubleA;
    *pX2 = (-b - sqrtDiscriminant) / doubleA;
}

int solveLE(const double a, const double b, double roots[]) {
    if (isAllZero(2, a, b)) return -1; // infinity roots
    if (isZero(a)) return 0; // no roots
    
    roots[0] = -b / a;
    return 1;
}

static int solveIncompleteQE(const double a, const double b, const double c, double roots[]) {
	if (isZero(a)) {
		return solveLE(b, c, roots);
	}

	if (isZero(b)) {
		if (isPositive(a * c)) return 0;
        if (isZero(c)) {
            roots[0] = 0;
            return 1;
        }

		double root = sqrt(-c / a);

		roots[0] = root;
		roots[1] = -root;
	}
    // c == 0
	else {
		roots[0] = 0;
		roots[1] = -b / a;
	}

	return 2;
}

static int solveCompleteQE(const double a, const double b, const double c, double roots[]) {
	double discriminant = calcDiscriminant(a, b, c);

	if (!isPositive(discriminant)) return 0;
	if (isZero(discriminant)) {
        roots[0] = -b / (2 * a);
        return 1;
    }
	
    double x1 = 0, x2 = 0;
    calcAndPutRoots(a, b, discriminant, &roots[0], &roots[1]);

	return 2;
}

int solveQE(const double a, const double b, const double c, double roots[]) {
	if (isAllZero(3, a, b, c))	return -1; // infinity roots
	if (isAnyZero(3, a, b, c))
		return solveIncompleteQE(a, b, c, roots);

	return solveCompleteQE(a, b, c, roots);
}