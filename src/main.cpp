#include "../test/testQuadratic.h"
#include "../include/app.h"

#define DEBUG

int main() {
#ifdef DEBUG
    readyTestsQuadratic();
#endif
    app();
    
	return 0;
}

