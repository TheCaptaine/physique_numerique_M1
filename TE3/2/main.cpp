#include <string>
#include <chrono>
#include <iostream>
#include <math.h>
#include <Eigen/Dense>
#include "methodes.h"
#include "cond_init.h"
#include "matrices.h"
#include "util.h"

using namespace Eigen;
using namespace std;

int main(void) {
    string name_file;
    int method = 0;
    int init = 0;
    float dx = 0;
    float dt = 0;
    cout << "dx ? ";
    cin >> dx;
    cout << "dt ? ";
    cin >> dt;
    cout << "Press 1 to use explicit method, 2 for implicit or 3 for crank-nicolson \n";
    cin >> method;
    cout << "initial condition ? 1 for init2sinus or 2 for step_init \n";
    cin >> init;
    float L = 12.0;
    int nt = 1000;
    int nx = L/dx-1;
    float ug = 0;
    float ud = 0;
    float D = 0.01;
    float alpha = D*dt/(dx*dx);
	VectorXf unew(nx), uold(nx);
    switch(init) {
        case 1 : {
            name_file = "sinus-";
            ug = 1;
            ud = 1;
            uold = init2sinus(L, dx, nx);
        }break;
        case 2 : {
            name_file = "step-";
            ug = 1;
            ud = -1;
            uold = step_init(L, dx, nx);
        }break;
        default : {
            std::cout << "Error (1) !\n";
            exit(1);
        }break;
    }
    VectorXf V = VectorXf::Zero(nx);
    V(0) = ug;
    V(nx-1) = ud;
    switch(method) {
        case 1 : {
            name_file += "explicite";
            ecrit_entete(name_file, nx, nt, dx, dt, alpha);
            ecrit(name_file, uold, ug, ud);
            for (int i = 0; i < nt; i++) {
                unew = avance_expl(uold, alpha, ug, ud);
                ecrit(name_file, unew, ug, ud);
                uold = unew;
            }
        }break;
        case 2 : {
            name_file += "implicite";
            ecrit_entete(name_file, nx, nt, dx, dt, alpha);
            ecrit(name_file, uold, ug, ud);
            MatrixXf malpha(nx, nx), invmalpha(nx, nx);
            malpha = matalpha(nx, alpha);
            invmalpha = malpha.inverse();
            for (int i = 0; i < nt; i++) {
                unew = avance_impl(invmalpha, uold, alpha, V);
                ecrit(name_file, unew, ug, ud);
                uold = unew;
            }       
        }break;
        case 3 : {
            name_file += "crank-nicolson";
            ecrit_entete(name_file, nx, nt, dx, dt, alpha);
            ecrit(name_file, uold, ug, ud);
            MatrixXf malpha(nx, nx), invmalpha(nx, nx);
            malpha = matalpha(nx, alpha/2);
            invmalpha = malpha.inverse();
            for (int i = 0; i < nt; i++) {
                unew = avance_cranknic(invmalpha, uold, alpha, V);
                ecrit(name_file, unew, ug, ud);
                uold = unew;
            }
        }break;
        default : {
            std::cout << "Error (2) !\n";
            exit(1);
        }break;
    }
	return 0;
}
