//
// Created by mauro on 3/05/16.
//

#ifndef PRACTICAFINAL_JOC_H
#define PRACTICAFINAL_JOC_H

#include "Tauler.h"
#include "pilaCartes.h"

class Joc {
public:
    Joc();
    Joc(Baralla b);

    //CONSULTORS
    void mostrar() const;
    bool descartadesBuida() const;
    bool comprovaSituacio(int colum, int fila) const;

    void obreCarta();
    void posarAlTauler(int colum);
    void posarAlaPila();
    void mouCarta(int colum, int fila, int desti);
    void mouCartaPila(int desti);


private:


    Tauler tauler;
    pilaCartes ma, descartades, coll1, coll2, coll3, coll4;

    void mostraError();
    bool primeraInsercio(Carta darrera, int desti, int &cont);
    void mostrarErrorPila();
    void girarUltima(int desti);

};


#endif //PRACTICAFINAL_JOC_H
