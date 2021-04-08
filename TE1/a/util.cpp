#include <stdlib.h>
#include <cstdio>
#include "util.h"

int ecrit(int size, double *arrayX, double *arrayY) {
	FILE *file = fopen("data.res", "w");
	if (file == NULL)
		exit(1);
	for (int i = 0; i < size; i++)
		fprintf(file, "%f %f\n", arrayX[i], arrayY[i]);
	fclose(file);
	return 0;
}
