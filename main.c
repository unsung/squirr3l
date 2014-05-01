#include "rk4.h"
#include "def.h"


int main(int argc, char** argv) {

	double dt, t, tf;
	double rj, vj;
	double a, sina, cosa;

	rj=5.2; // AU
	vj=.43877; // unitless multiple of v0

	a=9.94;
	
	sina=sin((90-a)*M_PI/180);
	cosa=cos((90-a)*M_PI/180);

	dt=1.e-4;



	State sun     = {0, 0, 0  ,0, 1};
	State earth   = {1, 0, 0  ,1, 0};
	State jupiter = {rj*cosa, rj*sina,-vj*sina,vj*cosa, 9.5511e-4};

	State probe   = earth;

	probe.vy += .9;

	State* probe_bodies[] = {&sun, &jupiter};

	for(t=0;t<2*M_PI;t+=dt) {
		update(dt, &probe  , probe_bodies  , 2);
		update_planet(dt, &earth);
		update_planet(dt, &jupiter);

		/*
		if(probe.x*probe.x+probe.y*probe.y >= 27.04) {
			printf("%f\n", atan(jupiter.y/jupiter.x)-atan(probe.y/probe.x));
			break;
		}
		*/

		printf("%f\t%f\t%f\t%f\t%f\t%f\n",
				probe.x, probe.y,
				earth.x, earth.y,
				jupiter.x, jupiter.y);
	}

	return 0;

}
