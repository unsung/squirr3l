#include "rk4.h"
#include "def.h"


int main() {

	double r0, t0, v0;
	double dt, t, tf;

	r0 = 1;
	t0 = 1; // t0 = r0*sqrt(r0/GME);//hr
	v0 = r0 / t0;

	dt=1.e-4;

	State sun     = {0, 0, 0  ,0, 1};
	//State earth   = {1, 0, 0  ,1, 3e-6};
	State earth   = {1, 0, 0  ,1, 0};
	State jupiter = {0, 5,-.5,0, 9.5511e-4};

	State probe   = earth;

	probe.vy += 0.01;

	State* probe_bodies[] = {&sun, &jupiter};

	for(t=0;t<2*M_PI;t+=dt) {
		update(dt, &probe  , probe_bodies  , 2);
		update_planet(dt, &earth);
		update_planet(dt, &jupiter);

		printf("%f\t%f\t%f\t%f\t%f\t%f\n",
				probe.x, probe.y,
				earth.x, earth.y,
				jupiter.x, jupiter.y);
	}

	return 0;

}
