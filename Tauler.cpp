//
// Created by mauro on 3/05/16.
//

#include "Tauler.h"
#include <iostream>

using namespace std;
Tauler::Tauler(){
    a_mat = NULL;
    a_nf = 7;
    a_ncMax = NULL;
    a_mida = NULL;
    inicialitza();

}
Tauler::Tauler(const Tauler &elem) {
    copia(elem);
}
void Tauler::allibera() {
    // alliberament de cadascuna de les files
    for(int i=0; i<a_nf; i++)
       delete [] a_mat[i];
//
// alliberament del vector de punters
    delete [] a_mat;
    delete [] a_mida;
    delete [] a_ncMax;
}
Tauler::~Tauler() {
    allibera();
}
Tauler& Tauler::operator=(const Tauler &elem) {
    // Pre: --; Post: s’ha assignat sense aliasing la informació de t a l’objecte actual
    if(this!=&elem){
        allibera();
        copia(elem);
    }
    return *this;
}
void Tauler::copia(const Tauler &t) {
    a_nf = t.a_nf; inicialitza();
    for(int i =0;i<a_nf;i++){
        a_mat[i] = t.a_mat[i];
        a_mida[i] = t.a_mida[i];
        a_ncMax[i] = t.a_ncMax[i];
    }
}
//Pre:--;
//Post: Inicialitza el tauler de joc, amb el numero de columnes maxim, la mida de cada fila, el numero de files i el tauler on van les cartes col·locades.
void Tauler::inicialitza() {

    a_mat= new Carta*[a_nf];
    a_mida= new int[a_nf];
    a_ncMax = new int[a_nf];


    for(int i=0; i<a_nf; i++){
        a_mat[i]= new Carta[13+i];
        a_mida[i]= i+1;
        a_ncMax[i] = 13 + i;
    }

}
int Tauler::getColumna(int pos) const{
    return a_mida[pos];
}
int Tauler::getFiles() const {
    return a_nf;
}
void Tauler::afageixCarta(Carta nova, int i, int j) {
    int aux = j+1;
    a_mida[i] = aux;
    a_mat[i][j] = nova;
}
Carta Tauler::getCarta(int i, int j) const {
    return a_mat[i][j];
}
Carta Tauler::getUltimaCartaVisible(int i) const {
    for(int j = 0;j<=a_mida[i];j++){
        if(j == a_mida[i]){
            return a_mat[i][j-1];
        }
    }
}
Carta Tauler::extreuCarta(int i, int j) {
    Carta v = a_mat[i][j];
    a_mida[i]--;
    a_mat[i][j] = Carta();
    return v;
}
Carta Tauler::extreuDarrera(int i) {
    Carta v = a_mat[i][a_mida[i]];
    a_mida[i]--;
    a_mat[i][a_mida[i]] = Carta();
    return v;

}
void Tauler::afageixCartaFinal(Carta c, int i) {
    a_mida[i]++;
    for(int j=0;j<=a_mida[i];j++){
        if(j == a_mida[i]){
            a_mat[i][a_mida[i]-1] = c;
        }
    }
}
void Tauler::substitueix(Carta c, int desti) {
    a_mat[desti][a_mida[desti]-1] = c;
}