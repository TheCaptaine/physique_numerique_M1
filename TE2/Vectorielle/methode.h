#ifndef METHODE_H
#define METHODE_H
#include <Eigen/Dense>
using namespace Eigen;
VectorXf euler(VectorXf u_i, float t_i, float h, VectorXf dydt(float, VectorXf));
VectorXf point_milieu(VectorXf u_i, float t_i, float h, VectorXf dydt(float, VectorXf));
VectorXf runge_kutta_4(VectorXf u_i, float t_i, float h, VectorXf dydt(float, VectorXf));
#endif
