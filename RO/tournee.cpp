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

tournee::tournee(TypeGeneration type, vector<ville> villes) {
    switch (type) {
        case Random:
            this->random();
            this->name = "aléatoire";
            break;
        case Croissant:
            this->readFromFile();
            this->name = "croissante";
            break;
        case PlusProcheVoisin:
            this->readFromFile();
            this->name = "plus_proche_voisin";
            break;
        case InsertionProche:
            this->readFromFile();
            this->insertionProche();
            this->name = "insertion_proche";
            break;
        case PremierDabord:
            this->readFromFile();
            this->plusProcheVoisin(*this->getVille(1));
            this->rechercheLocale(type);
            this->name = "premier_d_abord";
        case Copie:
            if(villes.size() == 0){
                this->readFromFile();
                this->plusProcheVoisin(*this->getVille(1));
            }else{
                this->listeVilles = villes;
            }
            this->name = "copie";
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

/**
 * WIP !
 */
void tournee::insertionProche() {
    map<ville, bool> estVisite;
    vector<ville> final;
    ville suivant;
    pair<int, ville> paire;

    for(ville &v : this->listeVilles){
        estVisite[v] = false;
    }

    final.push_back(*this->getVille(24));
    final.push_back(*this->getVille(69));

    estVisite[*this->getVille(24)] = true;
    estVisite[*this->getVille(69)] = true;

    for(int i = 0; i < 78; i++){
        paire = plusProcheDeLaTournee(final, estVisite);
        suivant = paire.second;
        final.insert(final.begin() + paire.first + 1, suivant);
        estVisite[suivant] = true;
    }

    this->listeVilles = final;
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
    ville v;

    for(int i = 0; i < 80; i++){
        if(i != 79){
            res += tournee::distance(this->listeVilles.at(i), this->listeVilles.at(i + 1));
        }else{
            res += tournee::distance(this->listeVilles.back(), this->listeVilles.front());
        }
    }

    return res;
}

vector<ville> tournee::plusProcheVoisin(ville &s) {
    map<ville, bool> estVisite;
    vector<ville> final;
    ville suivant;

    //On initialise la map à false
    for(ville &v : this->listeVilles){
        estVisite[v] = false;
    }

    //On valide notre ville de départ
    //Ajout au résultat final + map estVisite
    final.push_back(s);
    estVisite[s] = true;

    //On recherche la ville la plus proche non visite et on l'ajoute au résultat final
    //On fait ça 79 fois afin de parcourir toutes les autres villes
    for(int i = 0; i < 79; i++){
        suivant = plusProche(s, estVisite);
        estVisite[suivant] = true;
        final.push_back(suivant);
        s = suivant;
    }

    this->listeVilles = final;
    return final;
}

ville tournee::plusProche(ville &start, map<ville,bool> estVisite) {
    map<double, ville *> distance;

    //Calcul des distances entre start et les autres villes
    //Et on les rentre dans une map<distance, destination>
    for (int i = 0; i < 80; i++) {
        if (!estVisite[this->listeVilles.at(i)]) {
            if(distance.find(this->distance(start, this->listeVilles.at(i))) == distance.end()){
                distance[this->distance(start, this->listeVilles.at(i))] = &this->listeVilles.at(i);
            }
        }
    }

    //On prend l'élément minimum
    auto ville = min_element(distance.begin(), distance.end());

    //On retourne la ville
    return *ville->second;
}

void tournee::plusProcheVoisinAmeliore() {
    map<double, vector<ville>> gloutons;
    vector<ville> temp;

    for(int i = 0; i < 80; i++){
        temp = this->plusProcheVoisin(*this->getVille(i + 1));
        gloutons[this->coutTournee()] = temp;
    }

    this->listeVilles = min_element(gloutons.begin(), gloutons.end())->second;
}

/**
 * Code permettant de savoir les deux villes les plus éloignées
 * @return une paire contenant les deux villes les plus éloignées
 * Deux villes les plus éloignées : Seurre (24) et Sainte-Colombe-Sur-Seine (69)
 */
pair<ville, ville> tournee::deuxVillesLesPlusEloignees() {
    map<double, pair<ville, ville>> distances;
    vector<pair<ville, ville>> aVisiter;
    pair<ville, ville> paire;

    for(int i = 0; i < 40; i++){
        for(int j = 40; j < 80; j++){
            paire.first = this->listeVilles.at(i);
            paire.second = this->listeVilles.at(j);
            aVisiter.push_back(paire);
        }
    }

    for(pair<ville, ville> &pvv : aVisiter){
        distances[this->distance(pvv.first, pvv.second)] = pvv;
    }

    return max_element(distances.begin(), distances.end())->second;
}

pair<int, ville> tournee::plusProcheDeLaTournee(vector<ville> tournee, map<ville, bool> estVisite) {
    map<double, pair<int, ville> > distance;
    vector<ville> toDo;

    for(ville &v : this->listeVilles){
        if(!estVisite[v]){
            toDo.push_back(v);
        }
    }

    for(int i = 0; i < tournee.size(); i++){
        for(ville &vToDo : toDo){
            distance[this->distance(tournee.at(i), vToDo)] = pair<int, ville>(i, vToDo);
        }
    }

    return min_element(distance.begin(), distance.end())->second;
}

/**
 * WIP /!\
 * @param type type de recherche locale
 */
void tournee::rechercheLocale(TypeGeneration type) {
    tournee tCourante = tournee(Copie, this->listeVilles);
    tournee temp;
    tournee tVoisin;
    bool end = false;

    while(!end){
        end = true;
        switch(type){
            case PremierDabord:
                for(int i = 0; i < tCourante.listeVilles.size(); i++){
                    std::copy(temp.listeVilles.begin(), temp.listeVilles.end(), tCourante.listeVilles);
                    //tVoisin = temp;
                    if(tVoisin.coutTournee() < tCourante.coutTournee()){
                        std::copy(tCourante.listeVilles.begin(), tCourante.listeVilles.end(), tVoisin.listeVilles);
                        end = false;
                    }
                }
                break;
        }
        cout << tCourante.coutTournee() << endl;
    }

    this->listeVilles = tCourante.listeVilles;
}

void tournee::setName(const char *string) {
    this->name = string;
}
