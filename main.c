#include "rk4.h"
#include "def.h"


int main() {

	double r0, t0, v0;
	r0=149598262;
	t0 = r0*sqrt(r0/GME);//hr
	v0=r0/t0;

	double dt, t, tf;
	int N=1;

	State sun = {0,0,0,0};
	State earth = {147098291/r0,0,0,109034.3202/v0};
	State* bodies[] = {&sun};


	dt=1.e-4;

	for(t=0;t<2*M_PI;t+=dt) {
		update(dt, &earth, bodies, 1);
	}

	printf("r0 = %f\nt0 = %f\nv0 = %f\n",r0,t0,v0);
	printf("earth state: %f %f\n",
			r0*sqrt(earth.x *earth.x  + earth.y *earth.y ),
			v0*sqrt(earth.vx*earth.vx + earth.vy*earth.vy));

	return 0;

}
