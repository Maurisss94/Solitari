//
// Created by mauro on 3/05/16.
//

#ifndef PRACTICAFINAL_TAULER_H
#define PRACTICAFINAL_TAULER_H

#include "Baralla.h"

class Tauler {

public:

    Tauler();

    void inicialitza();
    void afageixCarta(Carta nova, int i, int j);
    Carta extreuCarta(int i, int j);
    Carta extreuDarrera(int i);
    void afageixCartaFinal(Carta c, int i);
    int getFiles() const;
    int getColumna(int pos) const;
    Carta getCarta(int i, int j) const;
    Carta getUltimaCartaVisible(int i) const;
    void substitueix(Carta c, int desti);

private:
    void allibera();
    void reserva();
    void copia(const Tauler &t);

    int a_nf;
    int* a_ncMax; // llargada màxima de cada fila
    int* a_mida; // llargada real de cada fila
    Carta** a_mat;
};


#endif //PRACTICAFINAL_TAULER_H
