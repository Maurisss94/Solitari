//
// Created by mauro on 3/05/16.
//

#include "Baralla.h"
#include <cstdlib>


using namespace std;


unsigned Baralla::a_llavor = 1;

Baralla::Baralla() {

}
Baralla::Baralla(int llavor, int passos) {

    iniLlavor(llavor);
    pas = passos;
    char pal [] = {'P','c','d', 'T'};
    char valor [] = {'A', '2', '3', '4', '5', '6', '7', '8', '9', 'D', 'J', 'Q', 'K'};
    a_n = 0;

    for(int i=0;i<4;i++){
        for(int j=0;j<13;j++){
            Carta novaCarta(pal[i], valor[j]);
            llistaCartes[a_n] = novaCarta;
            a_n++;
        }
    }
    Carta aux;
    for(int i=0;i<passos;i++){
        int num1 =aleatori(a_n);
        int num2 = aleatori(a_n);
        Carta carta1 = llistaCartes[num1];
        Carta carta2 = llistaCartes[num2];

        aux = carta1;
        carta1 = carta2;
        carta2 = aux;

        llistaCartes[num1] = carta1;
        llistaCartes[num2] = carta2;
    }

}


void Baralla::iniLlavor(int llavor)
{
// metode de classe
    a_llavor = abs(llavor);
    if (a_llavor == 0)
        a_llavor++;
}


int Baralla::aleatori(int max)
{
    a_llavor = a_llavor * 1103515245 + 12345;
    int res = (a_llavor/32) % 32768;

    return res % max;
}
int Baralla::getMida() const {
    return a_n;
}
Carta Baralla::agafaCarta() {
    a_n--;
    return llistaCartes[a_n];
}