#include <iostream>
#include <iomanip>
#include "tournee.h"
#include <windows.h>

int main() {
    SetConsoleOutputCP( 65001 );
    std::string holdup;


    tournee list(Croissant);
    std::cout << "------------------------- Croissant -------------------------" << std::endl;
    std::cout << list.toString() << std::endl;
    std::cout << std::endl;
    std::cout << list.afficheTour() << std::endl;
    std::cout << std::endl;
    std::cout << std::setprecision(20) << "Distance entre la ville 1 et la ville 2 : " << tournee::distance(*list.getVille(1), *list.getVille(2)) << " km" << std::endl;
    std::cout << std::endl;
    std::cout << "Cout de la tournée en ordre croissant : " << list.coutTournee() << " km" << std::endl;
    std::cout << std::endl;


    list = tournee(Random);
    std::cout << "------------------------- Full random -------------------------" << std::endl;
    std::cout << list.toString() << std::endl;
    std::cout << std::endl;
    std::cout << list.afficheTour() << std::endl;
    std::cout << std::endl;
    std::cout << "Cout de la tournée aléatoire : " << list.coutTournee() << " km" << std::endl;
    std::cout << std::endl;


    list = tournee(GloutonPlusProcheVoisin);
    std::cout << "------------------------- Glouton plus proche voisin -------------------------" << std::endl;
    list.plusProcheVoisin(*list.getVille(1));
    std::cout << list.toString() << std::endl;
    std::cout << std::endl;
    std::cout << list.afficheTour() << std::endl;
    std::cout << std::endl;
    std::cout << "Cout de la tournée plus proche voisin : " << list.coutTournee() << " km" << std::endl;
    std:cin >> holdup;

    return 0;
}
