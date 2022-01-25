//
// Created by bk296745 on 21/01/2022.
//

#ifndef RO_LISTVILLE_H
#define RO_LISTVILLE_H

#include <list>
#include "ville.h"

enum TypeGeneration : int {
    Random,
    Croissant,
};

class listVille {
public:
    listVille(TypeGeneration type);
    void insert(ville newVille);
    double distance(ville* ville1, ville* ville2);
    ville* getVille(int NumVille);
    std::string toString();
    std::string toShortString();
private:
    listVille();
    void readFromFile();
    void random();
    std::list<ville> listeVilles;
};

#endif //RO_LISTVILLE_H
