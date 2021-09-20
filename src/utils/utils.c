#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
#include <stdbool.h>
#include <stdarg.h>
#include <float.h>
#include <math.h>
#include <iso646.h>
#include "utils.h"


static const long double EPSILON = 100 * LDBL_EPSILON;

void clearInput() {
	while (getchar() != '\n') {};
}

bool isZero(const long double a) {
	return fabs(a) < EPSILON;
}

bool isAnyZero(const int countOfNums, ...) {
	va_list nums;
	va_start(nums, countOfNums);

	bool wasZero = false;
	for (int i = 0; i < countOfNums; ++i)
		if (isZero(va_arg(nums, long double))) wasZero = true;

	va_end(nums);

	return wasZero;
}

bool isAllZero(const int countOfNums, ...) {
	va_list nums;
	va_start(nums, countOfNums);

	bool allZero = true;
	for (int i = 0; i < countOfNums; ++i)
		if (!isZero(va_arg(nums, long double))) allZero = false;

	va_end(nums);

	return allZero;
}

long double calcDiscriminant(const long double a, const long double b, const long double c) {
	return b * b - 4 * a * c;
}

void calcAndPutRoots(
	long double a, const long double b, const long double discriminant,
	long double* const pX1, long double* const pX2
) {
	long double sqrtDiscriminant = sqrt(discriminant),
	            doubleA = 2 * a;

	*pX1 = (-b + sqrtDiscriminant) / doubleA;
	*pX2 = (-b - sqrtDiscriminant) / doubleA;
}

void getCoefficient(long double* const pCoefficient, const char symbolCoefficient) {
	printf("%c: ", symbolCoefficient);

	while (!scanf("%Lf", pCoefficient)) {
		printf("You can use only numbers.\n%c: ", symbolCoefficient);
		clearInput();
	}

	clearInput();
}

bool getSomeCoefficients(const int countOfCoeffs, ...) {
	if (countOfCoeffs > 57) return false; // 'z' - 'A' = 57

	va_list psOfCoeffs;
	va_start(psOfCoeffs, countOfCoeffs);

	for (char lastCoeff = 'A' + countOfCoeffs, coeff = 'A'; coeff < lastCoeff; ++coeff)
		getCoefficient(va_arg(psOfCoeffs, long double*), coeff);

	va_end(psOfCoeffs);

	return true;
}


int solveIncompleteQE(const long double a, const long double b, const long double c, long double roots[]) {
	if (isZero(a)) {
		if (isZero(b)) return 0;

		roots[0] = -c / b;
		return 1;
	}

	if (isZero(b)) {
		if (a * c > 0) return 0;
		// if (a * c > 0.0) return 0;

		long double root = sqrt(-c / a);

		roots[0] = root;
		roots[1] = -root;
	}
	else {
		roots[0] = 0;
		// roots[0] = 0.0;
		roots[1] = -b / a;
	}

	return 2;
}

int solveCompleteQE(const long double a, const long double b, const long double c, long double roots[]) {
	long double discriminant = calcDiscriminant(a, b, c);

	if (discriminant < 0) return 0;
	if (discriminant == 0)
		roots[0] = roots[1] = -b / (2 * a);
	else {
		long double x1 = 0, x2 = 0;
		calcAndPutRoots(a, b, discriminant, &roots[0], &roots[1]);
		// calcAndPutRoots(a, b, discriminant, roots, (roots + 1));
	}

	return 2;
}

int solveQE(const long double a, const long double b, const long double c, long double roots[]) {
	if (isAllZero(3, a, b, c))	return -1; // infinity roots
	if (isAnyZero(3, a, b, c))
		return solveIncompleteQE(a, b, c, roots);

	return solveCompleteQE(a, b, c, roots);
}