//
// Created by mauro on 3/05/16.
//
#ifndef BARALLA_H
#define BARALLA_H
#include "Carta.h"

class Baralla {
    static const int N = 52;
public:
    // FALTEN ELS METODES NORMALS
    Baralla();
    Baralla(int llavor, int passos);

    int getMida() const;
    Carta agafaCarta();
    Carta repartirSobrants(int i);


private:
    static void iniLlavor(int llavor);
    static int aleatori(int max);
    void intercanvi(int passos);

    Carta llistaCartes[N];
    int a_n;

    // atribut de classe
    static unsigned a_llavor;

};

#endif // BARRALLA_H