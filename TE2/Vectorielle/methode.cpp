#include <Eigen/Dense>
#include "methode.h"

using namespace Eigen;

VectorXf euler(VectorXf u_i, float t_i, float h, VectorXf dydt(float, VectorXf)) {
	return u_i + h * dydt(t_i, u_i);
}

VectorXf point_milieu(VectorXf u_i, float t_i, float h, VectorXf dydt(float, VectorXf)) {
    return u_i + h * dydt(t_i + h/2, u_i + h/2 * dydt(t_i, u_i));
}

VectorXf runge_kutta_4(VectorXf u_i, float t_i, float h, VectorXf dydt(float, VectorXf)) {
	VectorXf k1(u_i.size()), k2(u_i.size()), k3(u_i.size()), k4(u_i.size());
    k1 = dydt(t_i, u_i);
    k2 = dydt(t_i + h/2, u_i + k1 * h/2);
    k3 = dydt(t_i + h/2, u_i + k2 * h/2);
    k4 = dydt(t_i + h, u_i + k3 * h);
    return u_i + (k1 + 2 * k2 + 2 * k3 + k4)*h/6;
}
