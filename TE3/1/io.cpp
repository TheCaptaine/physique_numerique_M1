#include <iostream>
#include <fstream>
#include "io.h"

using namespace std;
using namespace Eigen;

void ecritemp(string filename, const VectorXf &temp,
              const VectorXf &nord, const VectorXf &sud,
              const VectorXf &ouest, const VectorXf &est, float pas) {

    ofstream my_file;
    int nl = est.size(), nc = nord.size();

    my_file.open(filename);
    // Verification de la connexion du fichier au flot my_file
    if (! my_file) {
      cerr << "erreur ouverture du fichier " << filename;
      exit(EXIT_FAILURE);
    }

    // entete d'une ligne  : nb de lignes et de colonnes (bords compris)
    my_file << "# " << nl+2 << " " << nc+2 << " " << pas << endl;

    // bord du haut (Nord)
    my_file << 0.5*(nord(0)+ouest(0)) << " ";
    for (int i=0; i < nc; i++) {
      my_file << nord(i) << " ";
    }
    my_file << 0.5*(nord(nc-1)+est(0)) << endl;

    // lignes 1 a nl
    for (int i=0; i<nl; i++)
    {
       my_file << ouest(i) << " ";
       for (int j=0; j < nc; j++) {
         my_file << temp(i*nc+j) << " ";
       }
       my_file << est(i) << endl;
    }

    // bord du bas (Sud)
    my_file << 0.5*(sud(0)+ouest(nl-1)) << " ";
    for (int i=0; i < nc; i++) {
      my_file << sud(i) << " ";
    }
    my_file << 0.5*(sud(nc-1)+est(nl-1)) << endl;

    my_file.close();
}
