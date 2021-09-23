#include <stdio.h>
#include <stdbool.h>
#include <stdarg.h>
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

bool isAnyZero(const int countOfNumbers, ...) {
	va_list numbers = {0};
	va_start(numbers, countOfNumbers);

	bool wasZero = false;
	for (int i = 0; i < countOfNumbers; ++i)
		if (isZero(va_arg(numbers, double))) {
            wasZero = true;
            break;
        }
    
	va_end(numbers);

	return wasZero;
}

bool isAllZero(const int countOfNumbers, ...) {
	va_list numbers = {0};
	va_start(numbers, countOfNumbers);

	bool allZero = true;
	for (int i = 0; i < countOfNumbers; ++i)
		if (!isZero(va_arg(numbers, double))) {
            allZero = false;
            break;
        }
    
	va_end(numbers);

	return allZero;
}

bool isApproximatelyEqual(const double a, const double b) {
    if (a == 0)
        return isZero(b);
    if (b == 0)
        return isZero(a);
    
    return fabs((a - b) / a) < ACCURACY &&
           fabs((a - b) / b) < ACCURACY;
}

bool isPositive(const double a) {
    return !isZero(a) && a > 0;
}

void getCoefficient(double* const pCoefficient, const char signOfCoefficient) {
	printf("%c: ", signOfCoefficient);

	while (!scanf("%lf", pCoefficient)) {
		printf("You can use only numbers.\n"
               "%c: ", signOfCoefficient);
		clearInput();
	}
 
	clearInput();
}

bool getSomeCoefficients(const int countOfCoefficients, ...) {
	if (countOfCoefficients > 'z' - 'A') return false;

	va_list psOfCoefficients = {0};
	va_start(psOfCoefficients, countOfCoefficients);

	for (char lastCoefficient = 'A' + countOfCoefficients, coefficient = 'A';
         coefficient < lastCoefficient;
         ++coefficient)
        getCoefficient(va_arg(psOfCoefficients, double*), coefficient);

	va_end(psOfCoefficients);

	return true;
}
