//
// Created by bk296745 on 21/01/2022.
//

#include <fstream>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <chrono>
#include <random>
#include <map>
#include "ville.h"
#include "tournee.h"

using namespace std;

tournee::tournee() = default;

tournee::tournee(TypeGeneration type) {
    switch (type) {
        case Random:
            this->random();
            this->name = "aléatoire";
            break;
        case Croissant:
            this->readFromFile();
            this->name = "croissante";
            break;
        case GloutonPlusProcheVoisin:
            this->readFromFile();
            this->name = "plus_proche_voisin";
            break;
    }
}

void tournee::readFromFile() {
    string line;

    ifstream file;
    file.open("../top80.txt", ios_base::in);

    if(file.is_open()){
        getline(file, line);

        while (!file.eof()){
            this->insert(*ville(line).copy());
            getline(file, line);
        }

        file.close();
    }else{
        cout << "Impossible de lire le fichier";
    }
}

void tournee::random() {
    this->readFromFile();
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    shuffle(this->listeVilles.begin(), this->listeVilles.end(), default_random_engine(seed));
}

void tournee::insert(ville& newVille) {
    this->listeVilles.push_back(newVille);
}

double tournee::distance(ville &ville1, ville &ville2) {
    double res;
    const int r = 6371;

    double y1 = ville1.getLatitude() * (M_PI/180);
    double y2 = ville2.getLatitude() * (M_PI/180);
    double x1 = ville1.getLongitude() * (M_PI/180);
    double x2 = ville2.getLongitude() * (M_PI/180);

    res = abs( r * acos( (sin(y1) * sin(y2)) + (cos(y1) * cos(y2) * cos(x1 - x2)) ) );

    return res;
}

ville* tournee::getVille(int NumVille) {
    auto pos = std::find(this->listeVilles.begin(), this->listeVilles.end(), ville(NumVille));
    return pos->copy();
}

std::string tournee::toString() {
    std::string output;

    for (const ville &item : this->listeVilles){
        output += item.toString() + "\n";
    }

    return output;
}

std::string tournee::afficheTour() {
    std::string res = "Tournée " + this->name + " [";

    for(const ville &elt : this->listeVilles){
        res += to_string(elt.getNumVille()) + ", ";
    }

    res += "]";

    return res;
}

double tournee::coutTournee() {
    double res = 0.0;
    vector<ville>::iterator it;

    for(it = this->listeVilles.begin(); it != listeVilles.end(); it++){
        if(it->getNumVille() != 80){
            res += tournee::distance(*it, *next(it));
        }else{
            res += tournee::distance(this->listeVilles.back(), this->listeVilles.front());
        }
    }

    return res;
}

void tournee::plusProcheVoisin(ville &s) {
    map<ville, bool> estVisite;
    vector<ville> final;
    ville suivant;

    final.push_back(s);
    estVisite[s] = true;

    while(estVisite.size() < 80){
        suivant = tournee::plusProche(s, estVisite);
        estVisite[suivant] = true;
        final.push_back(suivant);
        s = suivant;
    }

    this->listeVilles = final;
}

ville tournee::plusProche(ville &start, const map<ville, bool>& estVisite) {
    map<double, ville *> distance;
    bool found = false;

    for (ville &v: this->listeVilles) {
        if (v.getNumVille() != start.getNumVille()) {
            distance[this->distance(start, v)] = &v;
        }
    }

    auto ville = min_element(distance.begin(), distance.end());

    while (!found) {
        if (estVisite.count(*ville->second) != 0) {
            remove(distance.begin(), distance.end(), *ville->second);
            ville = min_element(distance.begin(), distance.end());
        } else {
            found = true;
        }
    }

    return *ville->second;
}