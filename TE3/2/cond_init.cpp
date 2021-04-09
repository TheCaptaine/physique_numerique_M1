#include <iostream>
#include <cmath>
#include "cond_init.h"
#include <Eigen/Dense>

using namespace Eigen;
using namespace std;

VectorXf init2sinus(float L, float dx, int nx) {
    VectorXf u(nx);
	for (int i = 0; i < nx; i++)
		u(i) = 1+sin(M_PI*(i+1)*dx/L)+0.2*sin(5*M_PI*(i+1)*dx/L);
	return u;
}

VectorXf step_init(float L, float dx, int nx) {
    VectorXf u(nx);
    for (int i = 0; i < nx; i++) {
        if (i*dx <= L/2)
            u(i) = 1;
        else
            u(i) = -1;
    }
    return u;
}

