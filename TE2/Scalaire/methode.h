#ifndef METHODE_H
#define METHODE_H
float euler(float u_i, float t_i, float h, float f(float, float));
float point_milieu(float u_i, float t_i, float h, float dydt(float, float));
float runge_kutta_4(float u_i, float t_i, float h, float dydt(float, float));
#endif
