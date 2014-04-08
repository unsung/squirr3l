#ifndef RK4_INCLUDED
#define RK4_INCLUDED

double g(int i, double* f, double* k, double t);

double* rk4(double* f, double ti, double tf);

#endif
