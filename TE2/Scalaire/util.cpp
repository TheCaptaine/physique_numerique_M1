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

int ecrit(VectorXf &t, VectorXf &estime, VectorXf &exact, string m) {
	int indice_max = 0;
    float h = t(1)-t(0);
	ofstream file(m + "_Scalaire_" + to_string(h) + ".txt");
	file << "# " << h << " " << m << endl;
	file << "# " << (estime - exact).cwiseAbs().maxCoeff(&indice_max) << " " << indice_max << endl;
	for (int i = 0; i < t.size(); i++)
		file << t(i) << " " << estime(i) << " " << exact(i) << " " << estime(i)-exact(i) << endl;
	file.close();
	return 0;
}
