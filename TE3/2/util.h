#ifndef UTIL_H
#define UTIL_H
#include <Eigen/Dense>
using namespace Eigen;
using namespace std;
void ecrit_entete(string file_name, int nx, int nt, float dx, float dt, float alpha);
void ecrit(string file_name, VectorXf u, float ug, float ud);
#endif