#include <string>
#include <chrono>
#include <iostream>
#include <string>
#include <math.h>
#include <Eigen/Dense>
#include <Eigen/Sparse>
#include "matrices.h"
#include "condlim.h"
#include "io.h"

using namespace Eigen;
using namespace std;
using namespace std::chrono;

int main(void) {
    string name_file;
    name_file = "laplace";
    int method = 0;
    int init = 0;
    int dx = 4;
    int dy = 5;
    float p = 0;
    cout << "p ? ";
    cin >> p;
    int nl = dx/p-1;
    int nc = dy/p-1;
    cout << "nl = " << nl << ", nc = " << nc << endl;
    MatrixXf mat;
    mat = matl2d(nl, nc);
	VectorXf nord(nc), sud(nc), est(nl), ouest(nl), sm, temp;
    cout << "initial condition ? 1 for condlimit1 or 2 for condlimit2 \n";
    cin >> init;
    switch(init) {
        case 1 : {
            name_file += "-condlimt1";
            condlimites1(nord, sud, ouest, est);
        }break;
        case 2 : {
            name_file += "-condlimt2";
            condlimites2(nord, sud, ouest, est);
            /*for (int i = 0; i < est.size(); i++)
                cout << est(i) << " ";
            cout << "\n";
            for (int i = 0; i < ouest.size(); i++)
                cout << ouest(i) << " ";
            cout << "\n";*/
        }break;
        default : {
            std::cout << "Error (1) !\n";
            exit(1);
        }break;
    }
    sm = second_membre(nord, sud, ouest, est);
    /*for (int i = 0; i < sm.size(); i++)
        cout << sm(i) << " ";*/
    cout << "Press 1 to use colPiv, 2 for ldt or 3 for matcr \n";
    cin >> method;
    switch(method) {
        case 1 : {
            name_file += "-colPiv";
            auto start = high_resolution_clock::now();
            temp = mat.colPivHouseholderQr().solve(sm);
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast < milliseconds > (stop - start);
            cout << "Temps de calcul : " << duration.count() << " ms" << endl;
        }break;
        case 2 : {
            name_file += "-ldt";
            auto start = high_resolution_clock::now();
            temp = mat.ldlt().solve(sm);
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast < milliseconds > (stop - start);
            cout << "Temps de calcul : " << duration.count() << " ms" << endl;
        }break;
        case 3 : {
            name_file += "-matcr";
            int n = nl*nc;
            auto start1 = high_resolution_clock::now();
            SparseMatrix<float> matcr(n, n);
            matcr.reserve(VectorXi::Constant(n, 5));
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                    if (mat(i, j) != 0)
                        matcr.insert(i, j) = mat(i, j);
            matcr.makeCompressed();
            auto stop1 = high_resolution_clock::now();
            auto duration1 = duration_cast < milliseconds > (stop1 - start1);
            cout << "Temps de création : " << duration1.count() << " ms" << endl;
            auto start2 = high_resolution_clock::now();
            SimplicialLDLT<SparseMatrix<float>> solver;
            solver.compute(matcr);
            if (solver.info() != Success)
                exit(1);
            temp = solver.solve(sm);
            auto stop2 = high_resolution_clock::now();
            auto duration2 = duration_cast < milliseconds > (stop2 - start2);
            cout << "Temps de calcul : " << duration2.count() << " ms" << endl;
        }break;
        default : {
            std::cout << "Error (2) !\n";
            exit(1);
        }break;
    }
    name_file += ".dat";
    ecritemp(name_file, temp, nord, sud, ouest, est, p);
	return 0;
}
