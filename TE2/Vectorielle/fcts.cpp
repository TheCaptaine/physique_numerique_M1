#include <math.h>
#include <Eigen/Dense>
#include <iostream>
#include "fcts.h"

using namespace Eigen;
float k;

VectorXf dydt(float t, VectorXf y) {
	VectorXf dy((y.size()));
    dy(0) = y(1);
    dy(1) = -k*k*y(0);
    return dy;
}

VectorXf sol(float t, float t0, VectorXf y_0) {
    float A = (k*y_0(0)*cos(k*t0)-y_0(1)*sin(k*t0))/k;
    float B = (k*y_0(0)*sin(k*t0)+y_0(1)*cos(k*t0))/k;
	VectorXf analytique_sol(y_0.size());
    analytique_sol(0) = A*cos(k*t)+B*sin(k*t);
    analytique_sol(1) = -A*k*sin(k*t)+B*k*cos(k*t);
    return analytique_sol;
}

VectorXf dydt_non_lineaire(float t, VectorXf y) {
	VectorXf dy((y.size()));
    dy(0) = y(1);
    dy(1) = -k*k*sin(y(0));
    return dy;
}

VectorXf E_m(VectorXf y1, VectorXf y2) {
    VectorXf y(y1.size()), x(y1.size());
    for (int i = 0; i < y1.size(); i++) {
        y(i) = y1(i)*y1(i);
        x(i) = 1-cos(y2(i));
    }
    return 0.5*y+k*k*x;
}