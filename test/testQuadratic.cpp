#include <cstdio>
#include <cmath>
#include "testQuadratic.h"
#include "../include/quadratic.h"


/*!
 * @brief Accuracy with which two numbers are approximately equal
 */
static const double ACCURACY = 1e-5;

/*!
 * @brief Number is almost zero, if it's in range [-EPSILON; +EPSILON]
 */
static const double EPSILON = 1e-6;

/*!
 * @brief Text with available numbers of quadratic equation's roots
 */
static const char AVAILABLE_NUMBERS_OF_ROOTS[] = "Available numbers of roots:\n"
                                                 "2 - two roots; 1 - one root; 0 - zero roots; -1 - infinity roots.\n";

/*!
 * @brief Prints text about success of the test
 * @param testName STRING Name of the test
 */
static void printAboutSuccess(const char* const testName) {
    printf("TEST (%s) WAS SUCCESSFUL!\n", testName);
}

/*!
 * @brief Prints text about fail of the test
 * @param testName STRING Name of the test
 */
static void printAboutFail(const char* const testName) {
    printf("TEST (%s) FAILED!\n", testName);
}

/*!
 * @brief Prints failed test report
 * @param failCode    INT Code of fail
 * @param reportInfo1 VOID* Info for reporting
 * @param reportInfo2 VOID* Info for reporting
 */
static void printFailReport(const int failCode, const void* const reportInfo1, const void* const reportInfo2) {
    switch (failCode) {
        case 2: {
            printf("Number of expected roots: %d, number of calculated roots: %d.\n",
                   *((int*)reportInfo1), *((int*)reportInfo2));
            break;
        }
        case 1: {
            printf("Expected root: %lf, calculated root: %lf.\n",
                   *((double*)reportInfo1), *((double*)reportInfo2));
            break;
        }
        default: {
            printf("No report about fail with code %d.\n", failCode);
            break;
        }
    }
}

/*!
 * @brief Checks if putted numbers are almost equal
 * @param a DOUBLE First number
 * @param b DOUBLE Second number
 * @return 1 if putted numbers are almost equal
 */
static int isApproximatelyEqual(const double a, const double b) {
    if (a == 0)
        return fabs(b) <= EPSILON;
    if (b == 0)
        return fabs(a) <= EPSILON;
    
    return fabs((a - b) / a) <= ACCURACY &&
           fabs((a - b) / b) <= ACCURACY;
}

int testQuadratic(const char* const testName, const double a, const double b, const double c,
                  const int expectedNumberOfRoots, const double expectedX1, const double expectedX2) {
    
    QuadraticRoots quadraticRoots = {0, 0, 0};
    const int isSuccessSolve = solveQuadratic(a, b, c, &quadraticRoots);
    const int calcNumberOfRoots = quadraticRoots.numberOfRoots;
    /*
     const int isSuccessSolve    = solveQuadratic(a, b, c, &quadraticRoots),
               calcNumberOfRoots = quadraticRoots->numberOfRoots;
     */
    const double calcX1     = quadraticRoots.x1,
                 calcX2     = quadraticRoots.x2;
    
    
    // Error
    if (!isSuccessSolve) {
        printf("TEST (%s) ERROR!\n"
               "Function (%s) works incorrect.\n"
               "Unknown number (%d) of calculated roots.\n"
               "%s",
               testName, "solveQuadratic", calcNumberOfRoots, AVAILABLE_NUMBERS_OF_ROOTS);
        
        return 0;
    }
    
    
    switch (expectedNumberOfRoots) {
        case 2: {
            if (calcNumberOfRoots == 2 &&
                (isApproximatelyEqual(expectedX1, calcX1) && isApproximatelyEqual(expectedX2, calcX2)
                ||
                isApproximatelyEqual(expectedX1, calcX2) && isApproximatelyEqual(expectedX2, calcX1)))
                
                printAboutSuccess(testName);
            
            else {
                printAboutFail(testName);
                
                if (calcNumberOfRoots != 2)
                    printFailReport(2, &expectedNumberOfRoots, &calcNumberOfRoots);
                else
                    if (isApproximatelyEqual(expectedX1, calcX1))
                        printFailReport(1, &expectedX2, &calcX2);
                    else if (isApproximatelyEqual(expectedX1, calcX2))
                        printFailReport(1, &expectedX2, &calcX1);
                    else if (isApproximatelyEqual(expectedX2, calcX2))
                        printFailReport(1, &expectedX1, &calcX1);
                    else if (isApproximatelyEqual(expectedX2, calcX1))
                        printFailReport(1, &expectedX1, &calcX2);
                    else {
                        printFailReport(1, &expectedX1, &calcX1);
                        printFailReport(1, &expectedX2, &calcX2);
                    }
            }
            
            break;
        }
        case 1: {
            if (calcNumberOfRoots == 1 &&
                isApproximatelyEqual(expectedX1, calcX1))
                printAboutSuccess(testName);
            
            else {
                printAboutFail(testName);
                
                if (calcNumberOfRoots != 1)
                    printFailReport(2, &expectedNumberOfRoots, &calcNumberOfRoots);
                else
                    printFailReport(1, &expectedX1, &calcX1);
            }
            
            break;
        }
        case 0: {
            if (calcNumberOfRoots == 0)
                printAboutSuccess(testName);
            
            else {
                printAboutFail(testName);
                printFailReport(2, &expectedNumberOfRoots, &calcNumberOfRoots);
            }
            
            break;
        }
        case -1: {
            if (calcNumberOfRoots == -1)
                printAboutSuccess(testName);
            
            else {
                printAboutFail(testName);
                printFailReport(2, &expectedNumberOfRoots, &calcNumberOfRoots);
            }
            
            break;
        }
        default: {
            printAboutFail(testName);
            printFailReport(2, &expectedNumberOfRoots, &calcNumberOfRoots);
            printf("%s", AVAILABLE_NUMBERS_OF_ROOTS);
            
            break;
        }
    }
    
    return 1;
}

void readyTestsQuadratic() {
    /*
    testQuadratic("1",     1, -3, -4, 2, 4,          -1);
    testQuadratic("2",     5, 2,  3,  0, 0,          0);
    testQuadratic("3",     0, 0,  0, -1, 0,          0);
    testQuadratic("4",     2, 0,  0,  1, 0,          0);
    testQuadratic("5",     1, 4,  -2, 2, 0,          0);
    testQuadratic("6",     1, 4,  -2, 2, 0.449490,   -4.449490);
    testQuadratic("7",     1, 4,  -2, 2, -4.449490,  0.449490);
    testQuadratic("What?", 1, 4,  -2, 100, 0.449490, -4.449490);
    */
    testQuadratic("1",     1, -3, -4,    2,    4,        -1);
    testQuadratic("2",     5,  2,  3,    0,    0,         0);
    testQuadratic("3",     0,  0,  0,   -1,    0,         0);
    testQuadratic("4",     2,  0,  0,    1,    0,         0);
    testQuadratic("5",     1,  4, -2,    2,    0,         0);
    testQuadratic("6",     1,  4, -2,    2,    0.449490, -4.449490);
    testQuadratic("7",     1,  4, -2,    2,   -4.449490,  0.449490);
    testQuadratic("8",     1,  4, -2,    2,   -4.449490,  0);
    testQuadratic("What?", 1,  4, -2,    100,  0.449490, -4.449490);
    
}