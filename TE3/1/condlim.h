#ifndef CONDLIM_H
#define CONDLIM_H
#include <Eigen/Dense>
using namespace Eigen;
void condlimites1(VectorXf &nord, VectorXf &sud, VectorXf &ouest, VectorXf &est);
VectorXf second_membre(VectorXf &nord, VectorXf &sud, VectorXf &ouest, VectorXf &est);
void condlimites2(VectorXf &nord, VectorXf &sud, VectorXf &ouest, VectorXf &est);
#endif
