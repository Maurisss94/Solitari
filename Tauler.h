//
// Created by mauro on 3/05/16.
//

#ifndef PRACTICAFINAL_TAULER_H
#define PRACTICAFINAL_TAULER_H

#include "Baralla.h"

class Tauler {

public:
    //CONSTRUCTOR
    //Pre:--;Post:Crea un tauler adequat al solitari, amb les seves files i columnes.
    Tauler();

    //MODIFICADORS
    //Pre: Carta a inserir, fila i columna;Post: Insereix la carta a la fila i columna indicada.
    void afageixCarta(Carta nova, int i, int j);
    //Pre:--Posicions de la carta:Post: Extreu la carta indicada per la seva posicio.
    Carta extreuCarta(int i, int j);
    //Pre:Fila que es vol extreure la carta;Post: Extreu l'ultima carta visible de la fila indicada.
    Carta extreuDarrera(int i);
    //Pre:Carta a inserir en la fila;Post: Insereix la carta en la fila que se li indica.
    void afageixCartaFinal(Carta c, int i);
    //Pre:Carta no buida;Post: Subsituteix la carta que hi ha per un altra amb la visibilitat a true
    void substitueix(Carta c, int desti);

    //CONSULTORS
    //Pre:--;Post: REtorna el numero de files del tauler.
    int getFiles() const;
    //Pre:numero de fila;Post: Retorna la mida de la fila.
    int getColumna(int pos) const;
    //Pre:Posicio i i j de la carta; Post: Retorna la carta de la posicio indicada.
    Carta getCarta(int i, int j) const;
    //Pre: Fila; Post: REtorna l'ultima carta de la fila
    Carta getUltimaCartaVisible(int i) const;

    //DESTRUCTOR, OPERADOR ASSIGNACIO, CONSTRUCTOR COPIA
    ~Tauler();
    Tauler &operator= (const Tauler &elem);
    Tauler(const Tauler &elem);

private:

    //MEDOTES PRIVATS
    // Pre: --; Post: memoria alliberada
    void allibera();
    // Pre: pila buida; Post: aquesta matriu es copia de t
    void copia(const Tauler &t);
    //Pre:--;Post: inicialitza el tauler amb els valors necessaris perque es pugui simular un solitari.
    void inicialitza();

    int a_nf;
    int* a_ncMax; // llargada màxima de cada fila
    int* a_mida; // llargada real de cada fila
    Carta** a_mat;
};


#endif //PRACTICAFINAL_TAULER_H
