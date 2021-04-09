#ifndef IO_H
#define IO_H
#include <Eigen/Dense>
//#include <eigen3/Eigen/Dense>
void ecritemp(std::string filename, const Eigen::VectorXf &temp,
              const Eigen::VectorXf &nord, const Eigen::VectorXf &sud,
              const Eigen::VectorXf &ouest, const Eigen::VectorXf &est, float pas);
#endif
