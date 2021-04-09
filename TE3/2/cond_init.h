#ifndef COND_INIT_H
#define COND_INIT_H
#include <Eigen/Dense>
using namespace Eigen;
VectorXf init2sinus(float L, float dx, int nx);
VectorXf step_init(float L, float dx, int nx);
#endif