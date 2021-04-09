#include <iostream>
#include <math.h>
#include "matrices.h"
#include <Eigen/Dense>

using namespace Eigen;

MatrixXf matl2d(int nl, int nc) {
	MatrixXf mat(nl*nc, nc*nl);
    MatrixXf id = mat_id(nc);
	for (int i = 0; i < nc*(nl-1); i+=nc) {
        mat.block(i, i, nc, nc) = mat_diag(nc);
        mat.block(i+nc, i, nc, nc) = id;
        mat.block(i, i+nc, nc, nc) = id;
    }
    mat.block(nc*(nl-1), nc*(nl-1), nc, nc) = mat_diag(nc);
	return mat;
}

MatrixXf mat_diag(int n) {
	MatrixXf diag(n, n);
	for (int i = 0; i < n; i++) {
		diag(i, i) = -4;
		if (i == 0)
			diag(i, i+1) = 1;
		else if (i == n-1)
			diag(i, i-1) = 1;
		else {
			diag(i, i-1) = 1;
			diag(i, i+1) = 1;
		}
	}
	return diag;
}

MatrixXf mat_id(int n) {
	MatrixXf id(n, n);
	for (int i = 0; i < n; i++)
		id(i, i) = 1;
	return id;
}
