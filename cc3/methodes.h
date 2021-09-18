#ifndef METHODES_H
#define METHODES_H
#include <Eigen/Dense>
using namespace Eigen;
VectorXf euler(VectorXf u_i, float t_i, float h, VectorXf dydt(float, VectorXf));
VectorXf runge_kutta_4(VectorXf u_i, float t_i, float h, VectorXf dydt(float, VectorXf));
float dichotomie(float a, float b, float f(float), float precision);
VectorXf sympl(VectorXf u_i, float t_i, float h, VectorXf dydt(float, VectorXf));
#endif
