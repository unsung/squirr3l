#include "rk4.h"

double g(int i, double* f, double* k, double t) {

	switch (i) {
		case 0: // dx= ux*dt
			return  f[2]+2*k[2];
		case 1: // dy= uy*dt
		case 2: // dux=uy*dt
			return  f[3]+k[3];
		case 3: // duy=ux*dt
			return -f[2]-2*k[2];
	}

}

double* rk4(double* f, double ti, double tf) {
	int i, step;

	double zero[4] = {0,0,0,0}; // used later as k1 depends on no other k values
	//double f[] = {0, 0, 0, 1}; // x,y,ux,uy
	double k1[4], k2[4], k3[4], k4[4]; // k values for each coordinate of f
									   // k1,k3,k4 stored as half of normal value to make calculation easier
	double t, dt;
	t = ti;
	dt = 1.0e-7;
	step = 0;

	do {
		// calculate k1,k2,k3,k4
		for(i=0; i<4; i++)
			k1[i] = 0.5*dt*g(i, f, zero, t);

		for(i=0; i<4; i++)
			k2[i] = 0.5*dt*g(i, f, k1  , t+0.5*dt);

		for(i=0; i<4; i++)
			k3[i] =		dt*g(i, f, k2  , t+0.5*dt);

		for(i=0; i<4; i++)
			k4[i] = 0.5*dt*g(i, f, k3  , t+dt);

		// find new state of particle
		for(i=0; i<4; i++)
			f[i]+=(k1[i]+2*k2[i]+k3[i]+k4[i])/3;

		// increment time
		t = ti+dt*step++;

	} while(t<tf);

	return f;
}
