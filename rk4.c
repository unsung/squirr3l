#include "rk4.h"
#include "def.h"

void update_v(double px, double py, State* k, State** bodies, int num_bodies) {
	int i;
	double invr, dx, dy;

	for(i=0; i<num_bodies; i++) {
		dx=bodies[i]->x - px;
		dy=bodies[i]->y - py;
		invr=pow(dx*dx+dy*dy, -0.5);
		k->vx = (bodies[i]->x - px)*invr*invr*invr;
		k->vy = (bodies[i]->y - py)*invr*invr*invr;
	}

}

void update(double dt, State* probe, State** bodies, int num_bodies) {

	State k[4] = {{0}};

	k[0].x=0.5*dt*(probe->vx);
	k[0].y=0.5*dt*(probe->vy);
	update_v(probe->x, probe->y, k, bodies, num_bodies);
	k[0].vx*=dt*0.5;
	k[0].vy*=dt*0.5;

	k[1].x=0.5*dt*(probe->vx+k[0].vx);
	k[1].y=0.5*dt*(probe->vy+k[0].vy);
	update_v(probe->x + k[0].x, probe->y + k[0].y, k+1, bodies, num_bodies);
	k[1].vx*=dt*0.5;
	k[1].vy*=dt*0.5;

	k[2].x=dt*(probe->vx+k[1].vx);
	k[2].y=dt*(probe->vy+k[1].vy);
	update_v(probe->x + k[1].x, probe->y + k[1].y, k+2, bodies, num_bodies);
	k[2].vx*=dt;
	k[2].vy*=dt;

	k[3].x=0.5*dt*(probe->vx+k[2].vx);
	k[3].y=0.5*dt*(probe->vy+k[2].vy);
	update_v(probe->x + k[2].x, probe->y + k[2].y, k+3, bodies, num_bodies);
	k[3].vx*=dt*0.5;
	k[3].vy*=dt*0.5;

	probe->x  += (k[0].x +2*k[1].x +k[2].x +k[3].x )/3;
	probe->y  += (k[0].y +2*k[1].y +k[2].y +k[3].y )/3;
	probe->vx += (k[0].vx+2*k[1].vx+k[2].vx+k[3].vx)/3;
	probe->vy += (k[0].vy+2*k[1].vy+k[2].vy+k[3].vy)/3;

}
