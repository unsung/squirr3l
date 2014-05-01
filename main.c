#include "rk4.h"
#include "def.h"

// set to 1 to find the value for a where slingshot behavior occurs
// where a is the angle clockwise of vertical that offsets jupiter's starting position
// set to 2 to get a plot of probe, earth, jupiter coordinates vs time
#define MODE 1

inline void step(double dt, State* probe, State** probe_bodies,
		State* earth, State* jupiter) {

	update(dt, probe, probe_bodies  , 2);
	update_planet(dt, earth);
	update_planet(dt, jupiter);
}

int main() {

	double dt, t, tf;
	double rj, vj;
	double a, sina, cosa;


	rj=5.2; // AU
	vj=.43877; // unitless multiple of v0

	a=-2.05; // angle difference from jupiter and 90 degrees from earth

	if(MODE==1) a=0;
	
	sina=sin((90-a)*M_PI/180);
	cosa=cos((90-a)*M_PI/180);

	dt=1.e-4;

	tf = 4*M_PI; // angular periods of earth orbit to simulate

	State sun     = {0, 0, 0  ,0, 1};
	State earth   = {1, 0, 0  ,1, 0};
	State jupiter = {rj*cosa, rj*sina,-vj*sina,vj*cosa, 9.5511e-4};

	State probe   = earth;

	probe.vy += .5; // relative velocity of probe as reduced tangential velocity

	State* probe_bodies[] = {&sun, &jupiter};

	if(MODE==1) for(t=0;t<tf;t+=dt) {
		step(dt, &probe, probe_bodies, &earth, &jupiter);

		if(probe.x*probe.x+probe.y*probe.y >= 27.04) {
			a=(atan(jupiter.y/jupiter.x)-atan(probe.y/probe.x))*180/M_PI;
			printf("Jupiter is %f degrees ahead\n", a);
			break;
		}
	}

	if(MODE==2) for(t=0;t<tf;t+=dt) {
		step(dt, &probe, probe_bodies, &earth, &jupiter);

		printf("%f\t%f\t%f\t%f\t%f\t%f\n",
				probe.x, probe.y,
				earth.x, earth.y,
				jupiter.x, jupiter.y);
	}

	return 0;

}
