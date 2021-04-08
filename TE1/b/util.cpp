#include <stdlib.h>
#include <cstdio>
#include <Eigen/Dense>
#include "util.h"

using namespace Eigen;

int ecrit(int size, float *h, MatrixXf values) {
	FILE *file = fopen("data.res", "w");
	if (file == NULL)
		exit(1);
    	fprintf(file, "#%d %g %g\n", size, h[0], h[size-1]);
    	for (int i = 0; i < 3; i++)
        	fprintf(file, "#%g %g\n", values.col(i).minCoeff(), values.col(i).maxCoeff());
	for (int i = 0; i < size; i++)
		fprintf(file, "%g %g %g %g\n", h[i], values(i, 0), values(i, 1), values(i, 2));
	fclose(file);
	return 0;
}
