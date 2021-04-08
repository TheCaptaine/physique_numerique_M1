#include "methode.h"

float euler(float u_i, float t_i, float h, float dydt(float, float)) {
	return u_i + h * dydt(t_i, u_i);
}

float point_milieu(float u_i, float t_i, float h, float dydt(float, float)) {
    return u_i + h * dydt(t_i + h/2, u_i + h/2 * dydt(t_i, u_i));
}

float runge_kutta_4(float u_i, float t_i, float h, float dydt(float, float)) {
	float k1, k2, k3, k4;
    k1 = dydt(t_i, u_i);
    k2 = dydt(t_i + h/2, u_i + k1 * h/2);
    k3 = dydt(t_i + h/2, u_i + k2 * h/2);
    k4 = dydt(t_i + h, u_i + k3 * h);
    return u_i + (k1 + 2 * k2 + 2 * k3 + k4)*h/6;
}
