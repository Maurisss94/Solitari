//
// Created by mauro on 25/05/16.
//

#ifndef PRACTICAFINAL_PILACARTES_H
#define PRACTICAFINAL_PILACARTES_H

#include "Carta.h"


class pilaCartes {

public:
    pilaCartes();
    pilaCartes(const pilaCartes &o);
    ~pilaCartes();

    //CONSULTORS
    bool esBuida() const;
    Carta cim() const;


    //MODIFICADORS
    void empila(Carta c);
    Carta desempila();


    pilaCartes& operator=(const pilaCartes& o);

private:

    struct Node {
        Carta valor;
        Node* seg;
    };

    Node* a_cim;

    void copia(const pilaCartes& o);
    void allibera();

};


#endif //PRACTICAFINAL_PILACARTES_H
