#include "rk4.h"
#include "coord.h"


int main() {

	double dt, t, tf;
	int N=1;

	State sun = {0,0,0,0};
	State probe = {1,0,0,1};
	State* bodies[] = {&sun};


	dt=1.e-4;

	for(t=0;t<2*M_PI;t+=dt) {
		update(dt, &probe, bodies, 1);
	}

	printf("Probe state: %f %f %f %f\n", probe.x, probe.y, probe.vx, probe.vy);

	return 0;

}
