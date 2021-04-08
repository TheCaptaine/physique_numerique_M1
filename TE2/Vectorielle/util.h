#ifndef UTIL_H
#define UTIL_H
#include <Eigen/Dense>
using namespace Eigen;
using namespace std;
int ecrit(MatrixXf t, MatrixXf estime, MatrixXf exact, VectorXf Em, string m);
#endif
