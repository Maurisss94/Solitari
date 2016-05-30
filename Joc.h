//
// Created by mauro on 3/05/16.
//

#ifndef PRACTICAFINAL_JOC_H
#define PRACTICAFINAL_JOC_H

#include "Tauler.h"
#include "pilaCartes.h"

class Joc {
    //DESCRIPCIO: Classe principal anomenada joc, gestiona tot el que succeeix al joc.
public:
    //CONSTRUCTOR
    //Pre:Baralla no buida;Post:Inicialitza el joc, reparteix les cartes de la baralla al tauler, i les sobrants les coloca a la ma.
    Joc(Baralla b);

    //CONSULTORS
    //Pre:--; Post: Mostra el tauler les piles de colls, la ma i la pila de descartades.
    void mostrar() const;
    //Pre:--;Post: Retorna true si la pila de descartades es buida, false altrament.
    bool descartadesBuida() const;
    //Pre: columna i fila entrades per l'user;Post: Comprova la situacio del tauler per poder moure les cartes.
    bool comprovaSituacio(int colum, int fila) const;
    //Pre:Numero de la pila de colls;Post: Retorna true si es pot agafar una carta de la pila indicada per l'usuari.
    bool esPotRecuperar(int pila) const;
    //Pre:--;Post: REtorna true si el joc a ha acabat, totes les piles de colles estan plenes.
    bool haAcabat() const;

    //MODIFICADORS
    //Pre:--;Post:Agafa una carta de la ma i la coloca a la pila de descartades.
    void obreCarta();
    //Pre:Columna a la cual inserir la carta;Post: Insereix al tauler la carta de la primera carta de la ma de descartades.
    void posarAlTauler(int colum);
    //Pre:--;Post: Posa a la pila una carta de la pila de descartades.
    void posarAlaPila();
    //Pre: columna i fila de la carta a moure, i a quina columna es moura;Post:Mou la carta indicada per l'usuari a la columna desti.
    void mouCarta(int colum, int fila, int desti);
    //Pre:Columna desti;Post: Mou una carta del tauler a una pila de colls.
    void mouCartaPila(int desti);
    //Pre: Pila d'on recuperar la carta, i a on colocarla;Post: Recupera la carta de la pila de colls i la coloca al tauler.
    void recuperaCarta(int pila, int columna);



private:

    //ATRIBUTS
    Tauler tauler;
    pilaCartes ma, descartades, coll1, coll2, coll3, coll4;

    //Pre:--;Post:Mostra un error de pila;
    void mostraError();
    //Pre:carta, posicio i contador no siguin nul o 0;Post:Retorna true si es pot inserir a la pila la primera vegada.
    bool primeraInsercio(Carta darrera, int desti, int &cont);
    //Pre:--;Post: Mostra un error diferent de la pila.
    void mostrarErrorPila();
    //Pre:columna desti; Post:Gira l'ultima carta del tauler si esta no visible.
    void girarUltima(int desti);
    //Pre:--;Post:Metode que copia la pila de descartades a la ma.
    void reciclar();

};


#endif //PRACTICAFINAL_JOC_H
