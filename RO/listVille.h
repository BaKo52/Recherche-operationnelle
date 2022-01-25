//
// Created by bk296745 on 21/01/2022.
//

#ifndef RO_LISTVILLE_H
#define RO_LISTVILLE_H

#include <list>
#include "ville.h"

class listVille {
public:
    listVille();
    void insert(ville newVille);

private:
    std::list<ville> listeVilles;

};

#endif //RO_LISTVILLE_H
