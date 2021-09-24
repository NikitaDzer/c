#include <stdio.h>
#include <stdbool.h>
#include "../utils/utils.h"
#include "solver.h"
#include "../solveQuadratic/solveQuadratic.h"


static void getCoefficientsQuadratic(double* const pA, double* const pB, double* const pC) {
	printf("Type 3 numerical coefficients of a quadratic equation.\n");
    getSomeCoefficients(3, pA, pB, pC);
	printf("\n");
}

static void printRootsQuadratic(
	const double a, const double b, const double c,
	const double roots[], const int numberOfRoots
) {
	char signA = a < 0 ? '-' : '\0',
		 signB = b < 0 ? '-' : '+',
		 signC = c < 0 ? '-' : '+';
	double absA = a < 0 ? -a : a,
		   absB = b < 0 ? -b : b,
           absC = c < 0 ? -c : c;

	printf("The equation %c%lg*X^2 %c %lg*X %c %lg = 0 has ", signA, absA, signB, absB, signC, absC);
	switch (numberOfRoots) {
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
        default: {
            printf("ERROR! Invalid number of quadratic equation roots!");
            break;
        }
    }
}

static bool stopSolverQuadratic(void) {
	printf("\n\nIf you want to stop me, start the input with 'n' or 'N': ");

	char userChar = getchar();
	clearInput();

	if (userChar == 'n' || userChar == 'N') {
		printf("\nGood luck, Stranger!\n=======\n");
		return true;
	}

	printf("-------\n");
	return false;
}

int solver(void) {
	printf("\nHello to you, Stranger! I'm Quadratic Equation's Solver.\n"
		   "I can solve equations of the following form: A*X^2 + B*X + C = 0.\n"
		   "-------\n");

    int numberOfQuadratics = 0, numberOfRoots = 0;
    double roots[2] = {0, 0};
    double a = 0, b = 0, c = 0;
    do {
        getCoefficientsQuadratic(&a, &b, &c);
        numberOfRoots = solveQuadratic(a, b, c, roots);
        printRootsQuadratic(a, b, c, roots, numberOfRoots);
    } while (!stopSolverQuadratic());
    
    return numberOfQuadratics;
}

