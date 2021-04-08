#include <stdio.h>
#include <stdlib.h>
#include "methode.h"

int tabule(double f(double), int size, double *arrayX, double *arrayY) {
	for (int i = 0; i < size ; i++)
		arrayY[i] = f(arrayX[i]);
	return 0;
}
