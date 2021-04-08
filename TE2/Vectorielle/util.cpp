#include <iomanip>
#include <cstdio>
#include <iostream>
#include <fstream>
#include <math.h>
#include <cmath>
#include <Eigen/Dense>
#include <string>
#include "util.h"

using namespace Eigen;
using namespace std;

float v0;

int ecrit(MatrixXf t, MatrixXf estime, MatrixXf exact, VectorXf Em, string m) {
	int indice_max = 0;
    float h = t(1)-t(0);
	ofstream file(m + to_string(v0) + "_Vectorielle_" + to_string(h) + ".txt");
    file << setiosflags(ios::scientific) << setprecision(7);
	file << "# " << h << " " << m << endl;
	file << "# Position " << (estime.row(0) - exact.row(0)).cwiseAbs().maxCoeff(&indice_max) << " " << indice_max << endl;
    file << "# Vitesse " << (estime.row(1) - exact.row(1)).cwiseAbs().maxCoeff(&indice_max) << " " << indice_max << endl;
	for (int i = 0; i < t.size(); i++)
		file << t(i) << " " << estime.row(0)(i) << " " << exact.row(0)(i) << " " << estime.row(0)(i)-exact.row(0)(i) << " " << estime.row(1)(i) << " " << exact.row(1)(i) << " " << estime.row(1)(i)-exact.row(1)(i) << " " << Em(i) << endl;
	file.close();
	return 0;
}
