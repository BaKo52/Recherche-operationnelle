//
// Created by bkott on 25/01/2022.
//

#ifndef RO_TOUR_H
#define RO_TOUR_H
#include "listVille.h";

class tour {
public:
    double cout();
    std::string afficheTour();
private:
    listVille tournee;
    std::string Name;
};


#endif //RO_TOUR_H
