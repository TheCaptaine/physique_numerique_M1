#ifndef FCTS_H
#define FCTS_H
#include <Eigen/Dense>
using namespace Eigen;
VectorXf dydt(float t, VectorXf y);
float sinfty(float x);
VectorXf dydt_new(float t, VectorXf y);
#endif
