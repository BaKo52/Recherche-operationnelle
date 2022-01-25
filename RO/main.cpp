#include <iostream>
#include <iomanip>
#include "listVille.h"

int main() {
    listVille list;

    std::cout << list.toString() << std::endl;
    std::cout << std::setprecision(20) << "Distance entre la ville 1 et la ville 2 : " << list.distance(list.getVille(1), list.getVille(2)) << std::endl;
    return 0;
}
