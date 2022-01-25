//
// Created by bk296745 on 21/01/2022.
//

#include <fstream>
#include <iostream>
#include <cmath>
#include <math.h>
#include <algorithm>
#include <iomanip>
#include "listVille.h"

using namespace std;

listVille::listVille() {

}

void listVille::insert(ville newVille) {
    this->listeVilles.push_back(newVille);
}

std::string listVille::toString() {
    std::string output;

    for (ville item : this->listeVilles){
        output = output + item.toString() + "\n";
    }

    return output;
}

double listVille::distance(ville* ville1, ville* ville2) {
    double res;
    const int r = 6371;

    double y1 = ville1->getLatitude() * (M_PI/180);
    double y2 = ville2->getLatitude() * (M_PI/180);
    double x1 = ville1->getLongitude() * (M_PI/180);
    double x2 = ville2->getLongitude() * (M_PI/180);

    res = abs( r * acos( (sin(y1) * sin(y2)) + (cos(y1) * cos(y2) * cos(x1 - x2)) ) );

    return res;
}

ville* listVille::getVille(int NumVille) {
    _List_iterator<ville> pos = std::find(this->listeVilles.begin(), this->listeVilles.end(), ville(NumVille));
    return pos->copy();
}

std::string listVille::toShortString() {
    std::string res;

    for(ville elt : this->listeVilles){
        res += elt.getNumVille() + ",";
    }
}

void listVille::readFromFile() {
    string line;

    ifstream file;
    file.open("../top80.txt", ios_base::in);

    if(file.is_open()){
        getline(file, line);

        while (!file.eof()){
            this->insert(ville(line));
            getline(file, line);
        }

        file.close();
    }else{
        cout << "Impossible de lire le fichier";
    }
}

listVille::listVille(TypeGeneration type) {
    switch (type) {
        case Random:
            this->random();
            break;
        case Croissant:
            this->readFromFile();
            break;
    }
}




