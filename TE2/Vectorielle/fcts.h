#ifndef FCTS_H
#define FCTS_H
#include <Eigen/Dense>
using namespace Eigen;
VectorXf dydt(float t, VectorXf y);
VectorXf sol(float t, float t0, VectorXf y_0);
VectorXf dydt_non_lineaire(float t, VectorXf y);
VectorXf E_m(VectorXf y1, VectorXf y2);
#endif
