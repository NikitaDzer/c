#include <stdio.h>
#include "../../utils/utils.h"
#include "testQuadratic.h"
#include "../solveQuadratic.h"


static bool isInRange(const int numberOfRoots) {
    return -1 <= numberOfRoots && numberOfRoots <= 2;
}

static void printAvailableNumbersOfRoots(void) {
    printf("Available numbers of roots:\n"
           "2 - two roots; 1 - one root; 0 - zero roots; -1 - infinity roots.\n");
}

bool testQuadratic(const char testName, const double a, const double b, const double c,
                   const int numberOfExpectedRoots, const double x1, const double x2) {
    double expectedRoots[2] = {x1, x2},
           calcRoots[2]     = {0, 0};
    const int numberOfCalcRoots = solveQuadratic(a, b, c, calcRoots);
    
    bool wasError = false;
    if (!isInRange(numberOfExpectedRoots)) {
        printf("ERROR IN TEST '%c'!\n"
               "Unknown number (%d) of expected roots.\n",
               testName, numberOfExpectedRoots);
        printAvailableNumbersOfRoots();
        wasError = true;
    }
    if (!isInRange(numberOfCalcRoots)) {
        printf("Function 'solveQuadratic' works incorrect!\n"
               "Unknown number (%d) of calculated roots.\n",
               numberOfCalcRoots);
        printAvailableNumbersOfRoots();
        wasError = true;
    }
    if (wasError) return false;
    
    
    switch (numberOfExpectedRoots) {
        case 2: {
            if (numberOfCalcRoots == 2 &&
                (isApproximatelyEqual(expectedRoots[0], calcRoots[0]) &&
                isApproximatelyEqual(expectedRoots[1], calcRoots[1]))
                ||
                (isApproximatelyEqual(expectedRoots[1], calcRoots[0]) &&
                isApproximatelyEqual(expectedRoots[0], calcRoots[1])))
                
                printf("TEST '%c' WAS SUCCESSFUL!\n", testName);
            else {
                
                printf("TEST '%c' FAILED!\n", testName);
                
                if (numberOfCalcRoots != 2)
                    printf("Number of expected roots: %d, number of calculated roots: %d.\n",
                           numberOfExpectedRoots, numberOfCalcRoots);
                else {
                    if (!isApproximatelyEqual(expectedRoots[0], calcRoots[0])) {
                        printf("Expected root: %lf, calculated root: %lf.\n",
                               expectedRoots[0], calcRoots[0]);
                        
                        if (!isApproximatelyEqual(expectedRoots[1], calcRoots[1]))
                            printf("Expected root: %lf, calculated root: %lf.\n",
                                   expectedRoots[1], calcRoots[1]);
                    }
                    else if (!isApproximatelyEqual(expectedRoots[0], calcRoots[1])) {
                        printf("Expected root: %lf, calculated root: %lf.\n",
                               expectedRoots[0], calcRoots[1]);
                        
                        if (!isApproximatelyEqual(expectedRoots[1], calcRoots[0]))
                            printf("Expected root: %lf, calculated root: %lf.\n",
                                   expectedRoots[1], calcRoots[0]);
                    }
                }
            }
            
            break;
        }
        case 1: {
            if (numberOfCalcRoots != 1 ||
                !isApproximatelyEqual(expectedRoots[0], calcRoots[0])) {
                printf("TEST '%c' FAILED!\n", testName);
        
                if (numberOfCalcRoots != 1)
                    printf("Number of expected roots: %d, number of calculated roots: %d.\n",
                           numberOfExpectedRoots, numberOfCalcRoots);
                else if (!isApproximatelyEqual(expectedRoots[0], calcRoots[0]))
                    printf("Expected root: %lf, calculated root: %lf.\n",
                           expectedRoots[0], calcRoots[0]);
            }
            else
                printf("TEST '%c' WAS SUCCESSFUL!\n", testName);
    
            break;
        }
        case 0: {
            if (numberOfCalcRoots != 0)
                printf("TEST '%c' FAILED!\n"
                       "Number of expected roots: %d, number of calculated roots: %d.\n",
                       testName, numberOfExpectedRoots, numberOfCalcRoots);
            else
                printf("TEST '%c' WAS SUCCESSFUL!\n", testName);
            
            break;
        }
        case -1: {
            if (numberOfCalcRoots != -1)
                printf("TEST '%c' FAILED!\n"
                       "Number of expected roots: infinity, number of calculated roots: %d.\n",
                       testName, numberOfCalcRoots);
            else
                printf("TEST '%c' WAS SUCCESSFUL!\n", testName);
            
            break;
        }
        default: {
            printf("Function 'test' works incorrect! Invalid number of expected numbers.\n");
            return false;
        }
    }
    printf("\n");
    
    return true;
}