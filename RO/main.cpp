#include <iostream>
#include <iomanip>
#include "tournee.h"
#include <windows.h>

int main() {
    SetConsoleOutputCP( 65001 );
    tournee list(Croissant);

    std::cout << list.toString() << std::endl;
    std::cout << std::endl;
    std::cout << list.afficheTour() << std::endl;
    std::cout << std::endl;
    std::cout << std::setprecision(20) << "Distance entre la ville 1 et la ville 2 : " << tournee::distance(list.getVille(1), list.getVille(2)) << " km" << std::endl;
    std::cout << std::endl;
    std::cout << "Cout de la tournée : " << list.coutTournee() << " km" << std::endl;

    list = tournee(Random);

    std::cout << list.toString() << std::endl;
    std::cout << std::endl;
    std::cout << list.afficheTour() << std::endl;
    std::cout << std::endl;
    std::cout << "Cout de la tournée : " << list.coutTournee() << " km" << std::endl;

    return 0;
}
