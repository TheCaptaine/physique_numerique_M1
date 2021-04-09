#include <iostream>
#include <math.h>
#include "methodes.h"
#include <Eigen/Dense>

using namespace std;
using namespace Eigen;

VectorXf avance_expl(VectorXf &uold, float alpha, float ug, float ud) {
    VectorXf unew(uold.size());
    unew(0) = (1-2*alpha)*uold(0)+alpha*uold(1)+alpha*ug;
    unew(unew.size()-1) = alpha*uold(unew.size()-2)+(1-2*alpha)*uold(unew.size()-1)+alpha*ud;
	for (int j = 1; j < unew.size()-1; j++)
		unew(j) = alpha*uold(j-1)+(1-2*alpha)*uold(j)+alpha*uold(j+1);
	return unew;
}

VectorXf avance_impl(MatrixXf &invmalpha, VectorXf &uold, float alpha, VectorXf &V) {
	return invmalpha*(uold+alpha*V);
}

VectorXf avance_cranknic(MatrixXf &invmalpha, VectorXf &uold, float alpha, VectorXf &V) {
	return invmalpha*(invmalpha*uold+alpha/2*(V+V));
}