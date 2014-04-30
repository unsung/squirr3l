#include "rk4.h"
#include "coord.h"


int main() {

	State probe = {1,1,1,0};
	State sun = {1,0,0,0};
	State* bodies[] = { &sun };
	update(&probe, bodies, 1);


	return 0;

}
