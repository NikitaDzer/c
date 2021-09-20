#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <iso646.h>
#include "../utils/utils.h"
#include "solverQE.h"


void getCoefficientsQE(long double* const pA, long double* const pB, long double* const pC) {
	printf("Type numerical coefficients of a quadratic equation.\n");
	getSomeCoefficients(3, pA, pB, pC);
	printf("\n");
}

void printRootsQE(
	const long double a, const long double b, const long double c,
	const long double const roots[], const int numOfRoots
) {
	char signA = a < 0 ? '-' : '\0',
		signB = b < 0 ? '-' : '+',
		signC = c < 0 ? '-' : '+';
	long double absA = a < 0 ? -a : a,
		absB = b < 0 ? -b : b,
		absC = c < 0 ? -c : c;

	printf("The equation %c%Lg*X^2 %c %Lg*X %c %Lg = 0 has ", signA, absA, signB, absB, signC, absC);
	switch (numOfRoots) {
	case 2: {
		printf("two real roots:\nX1 = %Lg; X2 = %Lg", roots[0], roots[1]);
		break;
	}
	case 1: {
		printf("one real root:\nX = %Lg", roots[0]);
		break;
	}
	case 0: {
		printf("no real roots.");
		break;
	}
	case -1: {
		printf("infinity roots.");
		break;
	}
	default:
		printf("Invalid number of quadratic equation roots!");
	}
}

void getAndSolveQE() {
	long double a = 0, b = 0, c = 0;
	getCoefficientsQE(&a, &b, &c);

	long double roots[2] = { 0, 0 };
	printRootsQE(a, b, c, roots,
		          solveQE(a, b, c, roots));
}

bool stopSolverQES() {
	printf("\n\nIf you want to stop me, start the input with 'n' or 'N': ");

	char userChar = getchar();
	clearInput();

	if (userChar == 'n' or userChar == 'N') {
		printf("\nGood luck, Stranger!\n=======\n");
		return true;
	}

	printf("-------\n");
	return false;
}

void solverQES() {
	printf(
		"\nHello to you, Stranger! I'm Quadratic Equation's Solver.\n"
		"I can solve equations of the following form: A*X^2 + B*X + C = 0.\n"
		"-------\n"
	);

	while (true) {
		getAndSolveQE();

		if (stopSolverQES()) break;
	}
}