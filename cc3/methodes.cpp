#include <math.h>
#include <iostream>
#include <Eigen/Dense>
#include "methodes.h"

using namespace std;
using namespace Eigen;

VectorXf euler(VectorXf u_i, float t_i, float h, VectorXf dydt(float, VectorXf)) {
	return u_i + h * dydt(t_i, u_i);
}

VectorXf runge_kutta_4(VectorXf u_i, float t_i, float h, VectorXf dydt(float, VectorXf)) {
	VectorXf k1(u_i.size()), k2(u_i.size()), k3(u_i.size()), k4(u_i.size());
    k1 = dydt(t_i, u_i);
    k2 = dydt(t_i + h/2, u_i + k1 * h/2);
    k3 = dydt(t_i + h/2, u_i + k2 * h/2);
    k4 = dydt(t_i + h, u_i + k3 * h);
    return u_i + (k1 + 2 * k2 + 2 * k3 + k4)*h/6;
}

float dichotomie(float a, float b, float f(float), float precision) {
     if (f(a)*f(b) > 0) {
                cout << "error interval : f(a) and f(b) are same symbol" << endl;
                exit(1);
        }
        cout << "Intervalle de depart : [" << a << ";" << b << "]" << endl;
        int compteur = 0;
        float x = 0;
        float ResultCondition = 0;
        do {
                compteur++;
                x = (a + b)/2;
                ResultCondition = f(x)*f(a);
                if (ResultCondition < 0)
                        b = x;
                else if (ResultCondition > 0)
                        a = x;
                else
                        break;
        }
        while (fabs(b-a) > precision);
        cout << "Nombre d'iteration : " << compteur << "\nSolution : x = " << x << endl;
        return x;
}

VectorXf sympl(VectorXf u_i, float t_i, float h, VectorXf dydt(float, VectorXf)) {
	VectorXf y(u_i.size()), gg(u_i.size());
    gg = euler(u_i, t_i, h, dydt);
    y(1) = u_i(1) + h * dydt(t_i + h, gg)(1);
    y(0) = gg(0);
    return y;
}