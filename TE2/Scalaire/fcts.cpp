#include <math.h>
#include "fcts.h"

float tau;
float a;

float dydt(float t, float y) {
	return -(t - a)/(tau * tau) * y;
}

float sol(float t, float t0, float y_0) {
	return y_0*exp(0.5*pow((t0 - a)/tau, 2))*exp(-0.5*pow((t - a)/tau, 2));
}