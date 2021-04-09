#include <iostream>
#include <math.h>
#include "condlim.h"
#include <Eigen/Dense>

using namespace Eigen;
using namespace std;

void condlimites1(VectorXf &nord, VectorXf &sud, VectorXf &ouest, VectorXf &est) {
	float tn = 0;
	float ts = 0;
	float tw = 0;
	float te = 0;
	cout << "tn ? ";
	cin >> tn;
	cout << "ts ? ";
        cin >> ts;
	cout << "tw ? ";
        cin >> tw;
	cout << "te ? ";
        cin >> te;
	nord = VectorXf::Constant(nord.size(), tn);
	sud = VectorXf::Constant(nord.size(), ts);
	ouest = VectorXf::Constant(ouest.size(), tw);
	est = VectorXf::Constant(ouest.size(), te);
}

VectorXf second_membre(VectorXf &nord, VectorXf &sud, VectorXf &ouest, VectorXf &est) {
    VectorXf B = VectorXf::Zero(nord.size()*ouest.size());
    B.head(nord.size()) = -nord;
    B.tail(nord.size()) = -sud;
    int k = 0;
    for (int i = 0; i < B.size()+1; i+=nord.size()) {
        if (i == 0)
            B(i) = B(i) - ouest(0);
        else if (i == B.size())
            B(i-1) = B(i-1) - est(est.size()-1);
        else {
            B(i) = B(i) - ouest(k);
            B(i-1) = B(i-1) - est(k-1);
        }
        k += 1;
    }
    return B;
}

void condlimites2(VectorXf &nord, VectorXf &sud, VectorXf &ouest, VectorXf &est) {
	float twn = 0;
    float ten = 0;
	float tws = 0;
	float tes = 0;
    float tnw = 0;
    float tsw = 0;
	float tne = 0;
	float tse = 0;
	cout << "twn ? ten ? tws ? tes ? tnw ? tsw ? tne ? tse \n";
	cin >> twn >> ten >> tws >> tes >> tnw >> tsw >> tne >> tse;
    for (int i = 0; i < nord.size(); i++)
        nord(i) = (twn-ten)/(1-nord.size())*i+twn;
    for (int i = 0; i < nord.size(); i++)
        sud(i) = (tws-tes)/(1-sud.size())*i+tws;
    for (int i = 0; i < ouest.size(); i++)
        ouest(i) = (tnw-tsw)/(1-ouest.size())*i+tnw;
    for (int i = 0; i < est.size(); i++)
        est(i) = (tne-tse)/(1-est.size())*i+tne;
}