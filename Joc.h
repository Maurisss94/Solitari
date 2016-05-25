//
// Created by mauro on 3/05/16.
//

#ifndef PRACTICAFINAL_JOC_H
#define PRACTICAFINAL_JOC_H

#include "Tauler.h"

class Joc {
public:
    Joc();
    Joc(Baralla b);

    //CONSULTORS
    void mostrar() const;


private:

    Baralla ma;
    Tauler tauler;

};


#endif //PRACTICAFINAL_JOC_H
