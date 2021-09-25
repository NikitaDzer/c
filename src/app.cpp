#include "../include/app.h"
#include "../include/quadratic.h"
#include "../include/io.h"

int app() {
    QuadraticRoots quadraticRoots = {0, 0, 0};
    double a = 0,
           b = 0,
           c = 0;
    int numberOfEquations       = 0,
        numberOfSolvedEquations = 0;
    
    printGreetings();
    do {
        getValidCoefficients(&a, &b, &c);
        numberOfSolvedEquations += solveQuadratic(a, b, c, &quadraticRoots);
        printEquationAndRoots(a, b, c, &quadraticRoots);
        
        ++numberOfEquations;
    } while (askForNextEquation());
    
    return numberOfEquations == numberOfSolvedEquations;
}

