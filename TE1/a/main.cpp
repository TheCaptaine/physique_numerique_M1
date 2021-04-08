#include <stdio.h>
#include <stdlib.h>
#include "fcts.h"
#include "methode.h"
#include "util.h"

int main(void) {
	int first_elmt = 0;
	int last_elmt = 0;
	float pas = 0;
	printf("Abscisse de debut : ");
	scanf("%d", &first_elmt);
	printf("Abscisse de fin : ");
	scanf("%d", &last_elmt);
	printf("Pas : ");
        scanf("%f", &pas);
	int size = (last_elmt - first_elmt) / pas + 1;
	printf("%d", size);
	double *Xvalues = (double*)calloc(size, sizeof(double));
	for (int i = 0; i < size; i++)
		Xvalues[i] = first_elmt + pas*i;
	double *Yvalues = (double*)calloc(size, sizeof(double));
	tabule(fonction_carre, size, Xvalues, Yvalues);
	ecrit(size, Xvalues, Yvalues);
	return 0;
}
