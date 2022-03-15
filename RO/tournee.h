//
// Created by bk296745 on 21/01/2022.
//

#ifndef RO_TOURNEE_H
#define RO_TOURNEE_H

#include <list>
#include "ville.h"
#include <vector>
#include <map>

using namespace std;

enum TypeGeneration : int {
    Random,
    Croissant,
    GloutonPlusProcheVoisin
};

class tournee {
public:
    explicit tournee(TypeGeneration type);
    void insert(ville &newVille);
    static double distance(ville &ville1, ville &ville2);
    double coutTournee();
    ville* getVille(int NumVille);
    string toString();
    string afficheTour();
    void plusProcheVoisin(ville &s);
private:
    tournee();
    void readFromFile();
    void random();
    ville plusProche(ville &v, map<ville, bool> estVisite);
    vector<ville> listeVilles;
    string name;
};

#endif //RO_TOURNEE_H
