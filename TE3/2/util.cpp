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

void ecrit_entete(string file_name, int nx, int nt, float dx, float dt, float alpha) {
	ofstream file(file_name + ".txt");
	file << "# " << nx + 2 << " " << nt << " " << dx << " " << dt << " " << alpha << endl;
	file.close();
}

void ecrit(string file_name, VectorXf u, float ug, float ud) {
	ofstream file;
    file.open(file_name + ".txt", ios::app);
//	file.seekp(0, ios::app);
    file << ug << " ";
	for (int i = 0; i < u.size(); i++)
		file << u(i) << " ";
    file << ud << endl;
	file.close();
}
