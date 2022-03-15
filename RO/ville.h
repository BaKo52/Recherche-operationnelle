//
// Created by bk296745 on 21/01/2022.
//

#ifndef RO_VILLE_H
#define RO_VILLE_H


#include <string>

class ville {

public:
    explicit ville(int numVille = 0, double latitude = 0.0, double longitude = 0.0, std::string nom = "Default");
    explicit ville(std::string line);
    std::string toString() const;
    const std::string &getNom() const;
    int getNumVille() const;
    double getLatitude() const;
    double getLongitude() const;
    bool operator<(const ville &ths) const;
    bool operator==(const ville &ths) const;
    ville* copy();

private:
    std::string Nom;
    int NumVille;
    double Latitude;
    double Longitude;
};


#endif //RO_VILLE_H
