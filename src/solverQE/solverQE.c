#include <stdio.h>
#include <stdbool.h>
#include <iso646.h>
#include "../utils/utils.h"
#include "solverQE.h"


static void getCoefficientsQE(double* const pA, double* const pB, double* const pC) {
	printf("Type 3 numerical coefficients of a quadratic equation.\n");
    getSomeCoefficients(3, pA, pB, pC);
	printf("\n");
}

static void printRootsQE(
	const double a, const double b, const double c,
	const double const roots[], const int numOfRoots
) {
	char signA = a < 0 ? '-' : '\0',
		signB = b < 0 ? '-' : '+',
		signC = c < 0 ? '-' : '+';
	double absA = a < 0 ? -a : a,
		absB = b < 0 ? -b : b,
		absC = c < 0 ? -c : c;

	printf("The equation %c%lg*X^2 %c %lg*X %c %lg = 0 has ", signA, absA, signB, absB, signC, absC);
	switch (numOfRoots) {
	case 2: {
		printf("two real roots:\nX1 = %lg; X2 = %lg", roots[0], roots[1]);
		break;
	}
	case 1: {
		printf("one real root:\nX = %lg", roots[0]);
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
		printf("ERROR! Invalid number of quadratic equation roots!");
        break;
	}
}

static void getAndSolveQE() {
	double a = 0, b = 0, c = 0;
	getCoefficientsQE(&a, &b, &c);

	double roots[2] = { 0, 0 };
	printRootsQE(a, b, c, roots,
		          solveQE(a, b, c, roots));
}

static bool stopSolverQE() {
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

int solverQE() {
	printf(
		"\nHello to you, Stranger! I'm Quadratic Equation's Solver.\n"
		"I can solve equations of the following form: A*X^2 + B*X + C = 0.\n"
		"-------\n"
	);

    int numOfQES = 0;
	while (true) {
		getAndSolveQE();
        ++numOfQES;
        
		if (stopSolverQE()) break;
	}
    
    return numOfQES;
}

