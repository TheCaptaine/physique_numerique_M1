#include <math.h>
#include <Eigen/Dense>
#include "fcts.h"

using namespace std;
using namespace Eigen;

float mu;
float alpha;

VectorXf dydt(float t, VectorXf y) {
	VectorXf dy((y.size()));
	dy(0) = -alpha*y(0)*y(1);
	dy(1) = alpha*y(0)*y(1)-mu*y(1);
	return dy;
}

float sinfty(float x) {
    return alpha/mu*(x-1)-log(x);
}

VectorXf dydt_new(float t, VectorXf y) {
    VectorXf dy((y.size()));
	dy(0) = -alpha*exp(y(1));
	dy(1) = alpha*exp(y(0))-mu;
    return dy;
}