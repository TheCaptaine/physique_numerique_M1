#include <iostream>
#include <string>
#include <stdio.h>
#include <math.h>
#include <Eigen/Dense>
#include "fcts.h"
#include "methode.h"
#include "util.h"

using namespace Eigen;
extern float a;
extern float tau;

int main(void) {
    int choice_name_file = 0;
    float h = 0;
	std::string name_file;
    std::cout << "Press 1 to use euler method, 2 for point milieu or 3 for runge kunta 4 \n";
    std::cin >> choice_name_file ;
    std::cout << "Choice of step : ";
    std::cin >> h;
	float t_0 = 0;
	a = 4;
	tau = sqrt(2);
	float t_fin = 20;
	float y_0 = 0.5;
	int n = (t_fin - t_0) / h + 1;
	VectorXf t(n), u(n), y(n);
    t(0) = t_0;
    u(0) = y_0;
    y(0) = y_0;
    for (int i = 0; i < n-1; i++) {
        t(i+1) = t_0 + h * (i + 1);
        switch(choice_name_file) {
                case 1 : {
                    name_file = "euler";
                    u(i+1) = euler(u(i), t(i), h, dydt);
                    //std::cout << "Euler method\n";
                }break;
                case 2 : {
                    name_file = "milieu";
                    u(i+1) = point_milieu(u(i), t(i), h, dydt);
                    //std::cout << "Point milieu method\n";
                }break;
                case 3 : {
                    name_file = "rk4";
                    u(i+1) = runge_kutta_4(u(i), t(i), h, dydt);
                    //std::cout << "RK4 method\n";
                }break;
                default : {
                    std::cout << "Error !\n";
                    exit(1);
                }break;
            }
        y(i+1) = sol(t(i+1), t_0, y_0);
        }
	ecrit(t, u, y, name_file);
	return 0;
}
 
