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

void ecrit(string meth, const VectorXf &t, const MatrixXf &u) {
	float h = t(1)-t(0);
	ofstream file(meth + ".txt");
	file << setiosflags(ios::scientific) << setprecision(7);
	file << "# " << meth << " " << h << " " << u.row(0)(t.size()-1) << endl;
	for (int i = 0; i < t.size(); i++)
		file << t(i) << " " << u.row(0)(i) << " " << u.row(1)(i) << " " << 1-u.row(0)(i)-u.row(1)(i) << endl;
	file.close();
}
