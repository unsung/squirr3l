#include "rk4.h"
#include "coord.h"


int main() {

	State probe = {1,0,0,1};
	Coord bodies = {0,0};
	update(&probe, &bodies, 1);


	return 0;

}
