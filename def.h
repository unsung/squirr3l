#ifndef COORD_INCLUDED
#define COORD_INCLUDED

#define GME 1.72113e18

typedef struct Coord {
	double x,y;
} Coord;

typedef struct State {
	double x,y,vx,vy;
} State;

#endif
