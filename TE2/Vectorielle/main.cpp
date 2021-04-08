#include <iostream>
#include <string>
#include <stdio.h>
#include <math.h>
#include <Eigen/Dense>
#include "fcts.h"
#include "methode.h"
#include "util.h"

using namespace Eigen;
extern float k;
extern float v0;

int main(void) {
    k = 1;
    int choice_name_file = 0;
    int choice_2 = 0;
    float h = 0;
	std::string name_file;
    std::cout << "Press 1 to use euler method, 2 for point milieu or 3 for RK4 \n";
    std::cin >> choice_name_file ;
    std::cout << "Choice of step : ";
    std::cin >> h;
    std::cout << "Press : 1 for linear estimation or 2 for non-linear estimation \n";
    std::cin >> choice_2;
    std::cout << "Choose your y0' \n";
    std::cin >> v0;
    if (choice_2 != 1)
        if (choice_2 != 2) {
            std::cout << "Invalid choice !\n";
            exit(1);
        }  
    float t_0 = 0;
	float t_fin = 20;
	int n = (t_fin - t_0) / h + 1;
    VectorXf t(n), y_0(2), Em(n);
    t(0) = t_0;
    y_0(0) = 0;
    y_0(1) = v0;
	MatrixXf estime(2, n), exact(2, n);
    estime.col(0) = y_0;
    exact.col(0) = y_0;
    for (int i = 0; i < n-1; i++) {
        t(i+1) = t_0 + h * (i + 1);
        switch(choice_name_file) {
                case 1 : {
                    if (choice_2 == 1) {
                        name_file = "euler_";
                        estime.col(i+1) = euler(estime.col(i), t(i), h, dydt);
                    }
                    else {
                        name_file = "euler_non_lineaire_";
                        estime.col(i+1) = euler(estime.col(i), t(i), h, dydt_non_lineaire);
                    }      
                //std::cout << "Euler method\n";
                }break;
                case 2 : {
                    if (choice_2 == 1) {
                        name_file = "milieu_";
                        estime.col(i+1) = point_milieu(estime.col(i), t(i), h, dydt);
                    }
                    else {
                        name_file = "milieu_non_lineaire_";
                        estime.col(i+1) = point_milieu(estime.col(i), t(i), h, dydt_non_lineaire);
                    }
                    //std::cout << "Point milieu method\n";
                }break;
                case 3 : {
                    if (choice_2 == 1) {
                        name_file = "rk4_";
                        estime.col(i+1) = runge_kutta_4(estime.col(i), t(i), h, dydt);
                    }
                    else {
                        name_file = "rk4_non_lineaire_";
                        estime.col(i+1) = runge_kutta_4(estime.col(i), t(i), h, dydt_non_lineaire);
                    }
                    //std::cout << "RK4 method\n";
                }break;
                default : {
                    std::cout << "Error !\n";
                    exit(1);
                }break;
            }
        exact.col(i+1) = sol(t(i+1), t_0, y_0);
        }
    Em = E_m(estime.row(1), estime.row(0));
	ecrit(t, estime, exact, Em, name_file);
	return 0;
}
 
