#include <cstdio>
#include "../include/io.h"
#include "../include/quadratic.h"


static void clearInput() {
    while (getchar() != '\n');
}

static void getValidCoefficient(double* const pCoefficient, const char signOfCoefficient) {
    printf("%c: ", signOfCoefficient);
    while (!scanf("%lf", pCoefficient)) {
        printf("You can use only numbers.\n"
               "%c: ", signOfCoefficient);
        clearInput();
    }
    clearInput();
}

void getValidCoefficients(double* const pA, double* const pB, double* const pC) {
    /*
    getValidCoefficient(pA, 'A');
    getValidCoefficient(pB, 'B');
    getValidCoefficient(pC, 'C');
    */
    printf("A: ");
    while (!scanf("%lf", pA)) {
        printf("You can use only numbers.\n"
               "A: ");
        clearInput();
    }
    clearInput();
    
    printf("B: ");
    while (!scanf("%lf", pB)) {
        printf("You can use only numbers.\n"
               "B: ");
        clearInput();
    }
    clearInput();
    
    printf("C: ");
    while (!scanf("%lf", pC)) {
        printf("You can use only numbers.\n"
               "C: ");
        clearInput();
    }
    clearInput();
}

void printGreetings() {
    printf("\nHello to you, Stranger! I'm Quadratic Equation's Solver.\n"
           "I can solve equations of the following form: A*X^2 + B*X + C = 0.\n"
           "-------\n");
}

void printEquationAndRoots(
        const double a, const double b, const double c,
        QuadraticRoots* quadraticRoots
) {
    char signA = a < 0 ? '-' : '\0',
         signB = b < 0 ? '-' : '+',
         signC = c < 0 ? '-' : '+';
    double absA = a < 0 ? -a : a,
           absB = b < 0 ? -b : b,
           absC = c < 0 ? -c : c;
    
    printf("The equation %c%lg*X^2 %c %lg*X %c %lg = 0 has ", signA, absA, signB, absB, signC, absC);
    switch (quadraticRoots->numberOfRoots) {
        case 2: {
            printf("two real roots:\n"
                   "X1 = %lg; X2 = %lg\n", quadraticRoots->x1, quadraticRoots->x2);
            break;
        }
        case 1: {
            printf("one real root:\n"
                   "X = %lg\n", quadraticRoots->x1);
            break;
        }
        case 0: {
            printf("no real roots.\n");
            break;
        }
        case -1: {
            printf("infinity roots.\n");
            break;
        }
        default: {
            printf("ERROR!\n"
                   "Function (%s) or (%s) works incorrect.\n"
                   "Unknown number (%d) of calculated roots.\n",
                   "solveQuadratic", "printEquationAndRoots", quadraticRoots->numberOfRoots);
            break;
        }
    }
}

int askForNextEquation() {
    printf("Type 'n' to stop me: ");
    
    char userChar = getchar();
    clearInput();
    
    if (userChar == 'n' || userChar == 'N') {
        printf("Good luck, Stranger!\n"
               "=======\n");
        return 0;
    }
    
    printf("-------\n");
    return 1;
}