#ifndef COORD_INCLUDED
#define COORD_INCLUDED

// G*ME in km^3 kg^-1 hr^-2 where 
// G is the gravitational constant
// and ME is the mass of the earth
#define GME 1.72113e18

typedef struct State {
	double x,y,vx,vy,m;
} State;

#endif
