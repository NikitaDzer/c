#include <stdio.h>
#include <stdarg.h>
#include <iso646.h>
#include "../utils.h"
#include "testQE.h"


static void necessaryPrintAND(bool* needToAddAND) {
    if (*needToAddAND)
        printf("and\n");
    
    *needToAddAND = true;
}

static bool isInRange(const int numberOfRoots) {
    return -1 <= numberOfRoots and numberOfRoots <= 2;
}

static void printAvailableNumbersOfRoots() {
    printf("Available numbers of roots:\n"
           "2 - two roots; 1 - one root; 0 - zero roots; -1 - infinity roots.\n");
}

bool testQE(const char testName, const double a, const double b, const double c, const int numberOfExpectedRoots, ...) {
    double calcRoots[2] = {};
    const int numberOfCalcRoots = solveQE(a, b, c, calcRoots);
    
    bool isError = false;
    if (!isInRange(numberOfExpectedRoots)) {
        printf("ERROR IN TEST '%c'!\n"
               "Unknown number (%d) of expected roots.\n",
               testName, numberOfExpectedRoots);
        printAvailableNumbersOfRoots();
        isError = true;
    }
    if (!isInRange(numberOfCalcRoots)) {
        printf("Function 'solveQE' works incorrect!.\n"
               "Unknown number (%d) of calculated roots.\n",
               numberOfCalcRoots);
        printAvailableNumbersOfRoots();
        isError = true;
    }
    
    if (isError) return false;
    
    switch (numberOfExpectedRoots) {
        case 2: {
            va_list roots = {0};
            va_start(roots, 2);
            double expectedRoots[2] = { va_arg(roots, double), va_arg(roots, double) };
            
            // Warning
            if (isAllZero(2, expectedRoots[0], calcRoots[0]))
                printf("WARNING! If you put nonzero number to expected roots, you must cast it to double-type.\n");
            
            if (numberOfCalcRoots != 2 or !isEqual(expectedRoots[0], calcRoots[0]) or !isEqual(expectedRoots[1], calcRoots[1])) {
                bool needToAddAND = false;
    
                printf("TEST '%c' FAILED!\n", testName);
                
                if (numberOfCalcRoots != 2) {
                    necessaryPrintAND(&needToAddAND);
                    printf("Number of expected roots: %d, number of calculated roots: %d.\n",
                           numberOfExpectedRoots, numberOfCalcRoots);
                }
                
                if (numberOfCalcRoots >= 1) {
                    if (!isEqual(expectedRoots[0], calcRoots[0])) {
                        necessaryPrintAND(&needToAddAND);
                        printf("Expected first root: %lf, calculated first root: %lf.\n",
                               expectedRoots[0], calcRoots[0]);
                    }
    
                    if (!isEqual(expectedRoots[1], calcRoots[1])) {
                        necessaryPrintAND(&needToAddAND);
                        printf("Expected second root: %lf, calculated second root: %lf.\n",
                               expectedRoots[1], calcRoots[1]);
                    }
                }
            }
            else printf("TEST '%c' WAS SUCCESSFUL!\n", testName);
            
            break;
        }
        case 1: {
            va_list roots = {0};
            va_start(roots, 1);
            double expectedRoots[1] = { va_arg(roots, double) };
    
            // Warning
            if (isZero(expectedRoots[0]))
                printf("WARNING! If you put nonzero number to expected root, you must cast it to double-type.\n");
            
            if (numberOfCalcRoots != 1 or !isEqual(expectedRoots[0], calcRoots[0])) {
                bool needToAddAND = false;
        
                printf("TEST '%c' FAILED!\n", testName);
        
                if (numberOfCalcRoots != 1) {
                    necessaryPrintAND(&needToAddAND);
                    printf("Number of expected roots: %d, number of calculated roots: %d.\n",
                           numberOfExpectedRoots, numberOfCalcRoots);
                }
    
                if (testName == '4') printf("\n%d\n", isEqual(expectedRoots[0], calcRoots[0]));
                if (numberOfCalcRoots >= 1) {
                    if (!isEqual(expectedRoots[0], calcRoots[0])) {
                        necessaryPrintAND(&needToAddAND);
                        printf("Expected root: %lf, calculated root: %lf.\n",
                               expectedRoots[0], calcRoots[0]);
                    }
                }
            }
            else printf("TEST '%c' WAS SUCCESSFUL!\n", testName);
    
            break;
        }
        case 0: {
            if (numberOfCalcRoots != 0) {
                printf("TEST '%c' FAILED!\n", testName);
                printf("Number of expected roots: %d, number of calculated roots: %d.\n",
                       numberOfExpectedRoots, numberOfCalcRoots);
            }
            else printf("TEST '%c' WAS SUCCESSFUL!\n", testName);
            
            break;
        }
        case -1: {
            if (numberOfCalcRoots != -1) {
                printf("TEST '%c' FAILED!\n", testName);
                printf("Number of expected roots: infinity, number of calculated roots: %d.\n",
                       numberOfCalcRoots);
            }
            else printf("TEST '%c' WAS SUCCESSFUL!\n", testName);
            break;
        }
        default: {
            printf("Function 'testQE' works incorrect! Invalid number of expected numbers.");
            return false;
        }
    }
    printf("\n");
    
    return true;
}