//
// Created by bkott on 25/01/2022.
//

#include "tour.h"

double tour::cout() {
    return 0;
}

std::string tour::afficheTour() {
    std::string res;

    res += this->Name + " [" + this->tournee.toShortString() + "]";

    res += "]";

    return res;
}
