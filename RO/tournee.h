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
    PlusProcheVoisin,
    InsertionProche
};

class tournee {
public:
    explicit tournee(TypeGeneration type = Croissant, int numVille = 0);
    void insert(ville &newVille);
    static double distance(ville &ville1, ville &ville2);
    double coutTournee();
    ville* getVille(int NumVille);
    string toString();
    string afficheTour();
    vector<ville> plusProcheVoisin(ville &s);
    void plusProcheVoisinAmeliore();
    pair<ville, ville> deuxVillesLesPlusEloignees();
private:
    void readFromFile();
    void random();
    void insertionProche();
    ville plusProche(ville &v, map<ville, bool> estVisite);
    vector<ville> listeVilles;
    string name;
    pair<int, ville> plusProcheDeLaTournee(vector<ville> tournee, map<ville, bool> estVisite);
};

#endif //RO_TOURNEE_H
