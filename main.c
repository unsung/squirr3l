#include "rk4.h"
#include "def.h"


int main() {

	double r0, t0, v0;
	double dt, t, tf;
	double a;

	r0 = 1;
	t0 = 1; // t0 = r0*sqrt(r0/GME);//hr
	v0 = r0 / t0;

	dt=1.e-4;

	State sun     = {0, 0, 0  ,0, 1};
	State earth   = {1, 0, 0  ,1, 3e-6};

	a=M_PI/180*60;
	State jupiter = {5*cos(a), 5*sin(a),-.5*sin(a),.5*cos(a), 9.5511e-4};

	State probe   = earth;

	probe.vx += 0.2;
	probe.vy += 0.2;

	State* planet_bodies[] = {&sun};
	State* probe_bodies[] = {&sun, &earth, &jupiter};

	for(t=0;t<2*M_PI;t+=dt) {
		update(dt, &probe  , probe_bodies  , 3);
		update_planet(dt, &earth);
		update_planet(dt, &jupiter);

		printf("%f\t%f\t%f\t%f\t%f\t%f\n",
				probe.x, probe.y,
				earth.x, earth.y,
				jupiter.x, jupiter.y);
	}
	//printf("%f\n"

	return 0;

}
