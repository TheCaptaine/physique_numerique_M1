#include <iostream>
#include <math.h>
#include "matrices.h"
#include <Eigen/Dense>

using namespace Eigen;

MatrixXf matalpha(int nx, float alpha) {
	MatrixXf mat = MatrixXf::Zero(nx, nx);
    mat(0, 0) = 1+2*alpha;
	mat(1, 0) = -alpha;
	mat(nx-1, nx-1) = 1+2*alpha;
	mat(nx-2, nx-1) = -alpha;
	for (int i = 1; i < nx-1; i++) {
		mat(i-1, i) = -alpha;
		mat(i, i) = 1+2*alpha;
		mat(i+1, i) = -alpha;
	}
	return mat;
}
