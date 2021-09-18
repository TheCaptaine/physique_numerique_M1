#include <string>
#include <chrono>
#include <iostream>
#include <string>
#include <math.h>
#include <Eigen/Dense>
#include "fcts.h"
#include "methodes.h"
#include "util.h"

using namespace std;
using namespace Eigen;
extern float mu;
extern float alpha;

int main() {
    float a = 0.1;
    float b = 0.5;
    float precision = pow(10, -6);
    string name_file;
    int method = 0;
    cout << "Press 1 to use Euler method, 2 for RK4 or 3 double Euler \n";
    cin >> method;
	mu = 0.1;
	float r0 = 1.5;
	alpha = r0*mu;
	int t0 = 0;
	int tf = 600;
	float h = 0;
	cout << "h ? ";
	cin >> h;
	int nt = (tf-t0)/h+1;
    MatrixXf u(2, nt);
	VectorXf t(nt), y0(2);
    t(0) = t0;
    y0(0) = 1-pow(10, -6);
    y0(1) = pow(10, -6);
    u.col(0) = y0;
    if (method == 3) {
        y0(0) = log(y0(0));
        y0(1) = log(y0(1));
        u.col(0) = y0;
    }
    for (int i = 0; i < nt-1; i++) {
        t(i+1) = t0 + h * (i + 1);
        switch(method) {
                case 1 : {
                    name_file = "euler";
                    u.col(i+1) = euler(u.col(i), t(i), h, dydt);
                    //std::cout << "Euler method\n";
                }break;
                case 2 : {
                    name_file = "rk4";
                    u.col(i+1) = runge_kutta_4(u.col(i), t(i), h, dydt);
                    //std::cout << "Point milieu method\n";
                }break;
                case 3 : {
                    name_file = "double-euler";
                    u.col(i+1) = sympl(u.col(i), t(i), h, dydt_new);
                }break;
                default : {
                    std::cout << "Error (1) !\n";
                    exit(1);
                }break;
        }
    }
    if (method == 3) {
        for (int i = 0; i < nt; i++) {
            u.row(0)(i) = exp(u.row(0)(i));
            u.row(1)(i) = exp(u.row(1)(i));
        }        
    }
    dichotomie(a, b, sinfty, precision);
    ecrit(name_file, t, u);
	return 0;
}
