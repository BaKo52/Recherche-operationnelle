#include <iostream>
#include <iomanip>
#include "tournee.h"
#include <windows.h>

int main() {
    SetConsoleOutputCP( 65001 );
    std::string entry;
    tournee list;
    pair<ville, ville> res;

    std::cout << "Que voulez-vous faire ? : " << std::endl;
    std::cout << "1 - Générer une tournée croissante" << std::endl;
    std::cout << "2 - Générer une tournée aléatoire" << std::endl;
    std::cout << "3 - Glouton plus proche voisin" << std::endl;
    std::cout << "4 - Glouton plus proche voisin amélioré" << std::endl;
    std::cout << "5 - Donner les deux villes les plus éloignées" << std::endl;
    std::cout << "6 - Glouton insertion proche" << std::endl;
    std::cout << "7 - Recherche local premier d'abord" << std::endl;
    std::cout << "FIN pour quitter" << std::endl;

    std::cin >> entry;

    while(!std::equal(entry.begin(), entry.end(), "FIN")){
        switch(entry.at(0)){
            case '1':
                list = tournee(Croissant, vector<ville>());
                break;
            case '2':
                list = tournee(Random, vector<ville>());
                break;
            case '3':
                list = tournee(PlusProcheVoisin, vector<ville>());
                list.plusProcheVoisin(*list.getVille(1));
                break;
            case '4':
                list = tournee(PlusProcheVoisin, vector<ville>());
                list.plusProcheVoisinAmeliore();
                break;
            case '5':
                list = tournee(Croissant, vector<ville>());
                res = list.deuxVillesLesPlusEloignees();
                std::cout << res.first.toString() << endl;
                std::cout << res.second.toString() << endl;
                break;
            case '6':
                //Deux villes les plus éloignées : Santenay (80) et Sainte-Colombe-Sur-Seine (69)
                list = tournee(InsertionProche, vector<ville>());
                break;
            case '7':
                list = tournee(PremierDabord, vector<ville>());
                list.setName("Premier d'abord");
                break;
        }

        std::cout << list.toString() << std::endl << std::endl;
        std::cout << list.afficheTour() << std::endl << std::endl;
        std::cout << "Cout de la tournée " << list.getName() << " : " << list.coutTournee() << " km" << std::endl << std::endl;

        std::cout << "Que voulez-vous faire ? : " << std::endl;
        std::cout << "1 - Générer une tournée croissante" << std::endl;
        std::cout << "2 - Générer une tournée aléatoire" << std::endl;
        std::cout << "3 - Glouton plus proche voisin" << std::endl;
        std::cout << "4 - Glouton plus proche voisin amélioré" << std::endl;
        std::cout << "5 - Donner les deux villes les plus éloignées" << std::endl;
        std::cout << "6 - Glouton insertion proche" << std::endl;
        std::cout << "7 - Recherche local premier d'abord" << std::endl;
        std::cout << "FIN pour quitter" << std::endl;

        std::cin >> entry;
    }

    return 0;
}
