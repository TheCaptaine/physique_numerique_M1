#ifndef MATRICES_H
#define MATRICES_H
#include <Eigen/Dense>
using namespace Eigen;
MatrixXf matl2d(int nl, int nc);
MatrixXf mat_diag(int n);
MatrixXf mat_id(int n);
#endif
