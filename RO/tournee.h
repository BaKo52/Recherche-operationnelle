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
    InsertionProche,
    PremierDabord,
    Copie
};

class tournee {
public:
    tournee();

    explicit tournee(TypeGeneration type, vector<ville> villes);
    void insert(ville &newVille);
    static double distance(ville &ville1, ville &ville2);
    double coutTournee();
    ville* getVille(int NumVille);
    string toString();
    string afficheTour();
    vector<ville> plusProcheVoisin(ville &s);
    void plusProcheVoisinAmeliore();
    pair<ville, ville> deuxVillesLesPlusEloignees();
    string getName() {return this->name;}

    void setName(const char *string);

private:
    void readFromFile();
    void random();
    void insertionProche();
    void rechercheLocale(TypeGeneration type);
    ville plusProche(ville &v, map<ville, bool> estVisite);
    pair<int, ville> plusProcheDeLaTournee(vector<ville> tournee, map<ville, bool> estVisite);
    vector<ville> listeVilles;
    string name;
};

#endif //RO_TOURNEE_H
