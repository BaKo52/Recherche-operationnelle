//
// Created by bk296745 on 21/01/2022.
//

#ifndef RO_VILLE_H
#define RO_VILLE_H


#include <string>

class ville {

public:
    ville(int numVille, float latitude, float longitude, std::string nom);

private:
    std::string Nom;
    int NumVille;
    float Latitude;
    float Longitude;
};


#endif //RO_VILLE_H
