//
// Created by bk296745 on 21/01/2022.
//

#ifndef RO_TOURNEE_H
#define RO_TOURNEE_H

#include <list>
#include "ville.h"
#include <vector>

enum TypeGeneration : int {
    Random,
    Croissant,
};

class tournee {
public:
    explicit tournee(TypeGeneration type);
    void insert(const ville& newVille);
    static double distance(ville* ville1, ville* ville2);
    double coutTournee();
    ville* getVille(int NumVille);
    std::string toString();
    std::string afficheTour();
private:
    tournee();
    void readFromFile();
    void random();
    std::vector<ville> listeVilles;
    std::string name;
};

#endif //RO_TOURNEE_H
