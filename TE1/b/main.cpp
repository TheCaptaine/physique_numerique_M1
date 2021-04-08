#include <stdio.h>
#include <math.h>
#include <Eigen/Dense>
#include "fcts.h"
#include "methode.h"
#include "util.h"

using namespace Eigen;
extern float kk;

int main(void) {
	double h_min = pow(10, -5);
	float h_max = 1.0;
	int n = 1000;
	float r = pow(h_max/h_min, 1/((float)n-1));
	printf("%f\n", r);
	kk = 1;
    float t0 = 0;
	float *h = (float*)calloc(n, sizeof(float));
	h[0] = h_min;
    	for (int i = 0; i < n-1; i++)
        	h[i+1] = h[0] * pow(r, i+1);
	MatrixXf values(n, 3);
	for (int i = 0; i < n; i++) {
		values(i, 0) = abs(deriv2tdd_decentree_droite(exponential, h[i], t0)-1);
		values(i, 1) = abs(deriv2tdd_decentree_gauche(exponential, h[i], t0)-1);
		values(i, 2) = abs(deriv2tdd_centree(exponential, h[i], t0)-1);
	}
	ecrit(n, h, values);
	return 0;
}
