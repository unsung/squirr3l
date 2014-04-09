#include <stdio.h>
#include "rk4.h"

int main() {

	double f[] = {0,0,0,1};

	printf("%f", rk4(f, 0, 3.14)[0]);

	return 0;

}
