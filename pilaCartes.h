//
// Created by mauro on 25/05/16.
//

#ifndef PRACTICAFINAL_PILACARTES_H
#define PRACTICAFINAL_PILACARTES_H

#include "Carta.h"


class pilaCartes {
    //DESCRIPCIO: Una pila de objectes Carta.
public:
    //CONSTRUCTORS I DESTRUCTORS
    // Pre: --; Post: pila buida
    pilaCartes();
    // Pre: --; Post: aquesta pila es copia de la pila o
    pilaCartes(const pilaCartes &o);
    // Pre: --; Post: memoria alliberada
    ~pilaCartes();

    //CONSULTORS
    // Pre: -- ; Post: retorna cert si la pila es buida; fals en c.c.
    bool esBuida() const;
    // Pre: pila no buida; Post: retorna el valor del cim de la pila
    Carta cim() const;


    //MODIFICADORS
    // Pre: --; Post: ha afegit s a dalt de la pila
    void empila(Carta c);
    // Pre: pila no buida; Post: ha eliminat element de dalt de la pila i el retorna.
    Carta desempila();

    // OPERADORS REDEFINITS ---------------------------------------
    // Pre: -- ; Post: aquesta pila es copia de la pila o
    pilaCartes& operator=(const pilaCartes& o);

private:

    struct Node {
        Carta valor;
        Node* seg;
    };

    Node* a_cim;
    // METODES PRIVATS
    // Pre: pila buida; Post: aquesta pila es copia de o
    void copia(const pilaCartes& o);
    // Pre: --; Post: memoria alliberada
    void allibera();

};


#endif //PRACTICAFINAL_PILACARTES_H
