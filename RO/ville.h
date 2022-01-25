//
// Created by bk296745 on 21/01/2022.
//

#ifndef RO_VILLE_H
#define RO_VILLE_H


#include <string>

class ville {

public:
    ville(int numVille, double latitude = 0, double longitude = 0, std::string nom = " ");
    ville(std::string line);
    std::string toString();
    const std::string &getNom() const;
    int getNumVille() const;
    double getLatitude() const;
    double getLongitude() const;
    bool operator==(const ville &rhs) const;
    bool operator!=(const ville &rhs) const;
    ville* copy();

private:
    std::string Nom;
    int NumVille;
    double Latitude;
    double Longitude;
};


#endif //RO_VILLE_H
