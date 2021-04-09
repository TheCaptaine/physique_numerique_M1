#ifndef METHODES_H
#define METHODES_H
#include <Eigen/Dense>
using namespace Eigen;
VectorXf avance_expl(VectorXf &uold, float alpha, float ug, float ud);
VectorXf avance_impl(MatrixXf &invmalpha, VectorXf &uold, float alpha, VectorXf &V);
VectorXf avance_cranknic(MatrixXf &invmalpha, VectorXf &uold, float alpha, VectorXf &V);
#endif