#include <iostream>
#include <iomanip>
#include "tournee.h"
#include <windows.h>

int main() {
    SetConsoleOutputCP( 65001 );
    std::string holdup;


    tournee list(Croissant);
    std::cout << "------------------------- Croissant -------------------------" << std::endl;
    std::cout << list.toString() << std::endl << std::endl;
    std::cout << list.afficheTour() << std::endl << std::endl;
    std::cout << std::setprecision(20) << "Distance entre la ville 1 et la ville 2 : " << tournee::distance(*list.getVille(1), *list.getVille(2)) << " km" << std::endl << std::endl;
    std::cout << "Cout de la tournée en ordre croissant : " << list.coutTournee() << " km" << std::endl << std::endl;


    list = tournee(Random);
    std::cout << "------------------------- Full random -------------------------" << std::endl;
    std::cout << list.toString() << std::endl << std::endl;
    std::cout << list.afficheTour() << std::endl << std::endl;
    std::cout << "Cout de la tournée aléatoire : " << list.coutTournee() << " km" << std::endl << std::endl;


    list = tournee(PlusProcheVoisin);
    std::cout << "------------------------- Glouton plus proche voisin -------------------------" << std::endl;
    list.plusProcheVoisin(*list.getVille(1));
    std::cout << list.toString() << std::endl << std::endl;
    std::cout << list.afficheTour() << std::endl << std::endl;
    std::cout << "Cout de la tournée plus proche voisin : " << list.coutTournee() << " km" << std::endl << std::endl;


    list = tournee(PlusProcheVoisin);
    std::cout << "------------------------- Glouton plus proche voisin amelioré -------------------------" << std::endl;
    list.plusProcheVoisinAmeliore();
    std::cout << list.toString() << std::endl << std::endl;
    std::cout << list.afficheTour() << std::endl << std::endl;
    std::cout << "Cout de la tournée plus proche voisin amélioré : " << list.coutTournee() << " km" << std::endl << std::endl;


    std::cout << "------------------------- Deux villes les plus éloignées -------------------------" << std::endl;
    list = tournee(Croissant);
    auto res = list.deuxVillesLesPlusEloignees();
    std::cout << res.first.toString() << endl;
    std::cout << res.second.toString() << endl;


    list = tournee(InsertionProche);
    std::cout << "------------------------- Glouton insertion proche -------------------------" << std::endl;
    //Deux villes les plus éloignées : Santenay (80) et Sainte-Colombe-Sur-Seine (69)
    std::cout << list.toString() << std::endl << std::endl;
    std::cout << list.afficheTour() << std::endl << std::endl;
    std::cout << "Cout de la tournée insertion proche : " << list.coutTournee() << " km" << std::endl << std::endl;

    list = tournee(PremierDabord);
    std::cout << "------------------------- Recherche locale premier d'abord -------------------------" << std::endl;
    std::cout << list.toString() << std::endl << std::endl;
    std::cout << list.afficheTour() << std::endl << std::endl;
    std::cout << "Cout de la tournée premier d'abord : " << list.coutTournee() << " km" << std::endl << std::endl;
    cin >> holdup;

    return 0;
}
