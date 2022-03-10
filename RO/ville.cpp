//
// Created by bk296745 on 21/01/2022.
//

#include <iostream>
#include "ville.h"

ville::ville(int numVille, double latitude, double longitude, std::string nom) : NumVille(numVille), Latitude(latitude),
                                                                               Longitude(longitude), Nom(nom) {}

ville::ville(std::string line) {
    double latitude;
    double longitude;
    std::string name;
    int id;
    int firstpos = 0;
    int lastpos = 0;

    for(int i = 0; i < 4; i++){
        firstpos = firstpos;
        lastpos = line.find(" ") + 1;

        switch (i) {
            case 0:
                id = std::stoi(line.substr(firstpos, lastpos));
                break;
            case 1:
                name = line.substr(firstpos, lastpos-1);
                break;
            case 2:
                latitude = std::stod(line.substr(firstpos, lastpos-1));
                break;
            case 3:
                longitude = std::stod(line.substr(firstpos, lastpos-1));
                break;
        }

        line.erase(firstpos, lastpos);
    }

    this->NumVille = id;
    this->Nom = name;
    this->Latitude = latitude;
    this->Longitude = longitude;
}

std::string ville::toString() const {
    std::string output = std::to_string(this->NumVille) + " " + this->Nom + " " + std::to_string(this->Latitude) + " " + std::to_string(this->Longitude);
    return output;
}

const std::string &ville::getNom() const {
    return Nom;
}

int ville::getNumVille() const {
    return NumVille;
}

double ville::getLatitude() const {
    return Latitude;
}

double ville::getLongitude() const {
    return Longitude;
}

bool ville::operator==(const ville &rhs) const {
    return NumVille == rhs.NumVille;
}

bool ville::operator!=(const ville &rhs) const {
    return !(rhs == *this);
}

ville* ville::copy() {
    return this;
}

