//
// Created by mauro on 3/05/16.
//
#ifndef BARALLA_H
#define BARALLA_H
#include "Carta.h"

class Baralla {
    //DESCRIPCIO: Classe baralla, que esta composada per 52 cartes, que formen una baralla francesa.
    //MIDA DE LA BARALLA
    static const int N = 52;
public:
    //CONSTRUCTORS
    //Pre:--; Post: Crea una baralla buida sense elements, i de mida 0.
    Baralla();
    //Pre: llavor i passos per poder barrejar la baralla. Post: Crea una baralla francesa amb les 52 cartes i les barreja.
    Baralla(int llavor, int passos);

    //CONSULTOR
    //Pre:--;Post: Retorna la mida actuak de la baralla.
    int getMida() const;

    //MODIFICADORS
    //Pre:--;Post: Retorna una carta de la baralla i decrementa la mida de la baralla.
    Carta agafaCarta();
    //Pre:Posicio que s'ha quedat la baralla;Post: Retorna les cartes sobrants de la baralla una vegada ja han estat repartides.
    Carta repartirSobrants(int i);


private:
    //METODES PRIVATS
    static void iniLlavor(int llavor);
    static int aleatori(int max);
    //Pre:numero de passos;Post:Intercanvi de posicions de les cartes per barrejarles.
    void intercanvi(int passos);

    Carta llistaCartes[N];
    int a_n;

    // atribut de classe
    static unsigned a_llavor;

};

#endif // BARRALLA_H