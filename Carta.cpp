//
// Created by mauro on 3/05/16.
//

#include "Carta.h"
#include <iostream>

using namespace std;

Carta::Carta() {
    pal = ' ';
    valor = ' ';
    visible = false;
    color = ' ';
}
Carta::Carta(char p, char v) {
    pal = p;
    valor = v;
    visible = false;
    if((pal == 'c') or (pal == 'd')){
        color = 'v';
    }else{
        color = 'n';
    }
}
void Carta::setVisible() {
    visible = true;
}
void Carta::setAmagada() {
    visible = false;
}
void Carta::mostrar() const {
    if(visible){
        cout << valor << pal << " ";
    }else if((pal == ' ')or(valor==' ')){
        cout << "   ";
    }else{
        cout << "**" << " ";
    }

}
bool Carta::casen(Carta anterior) const {
    bool casa;
    if(esMesGran(anterior) and (color != anterior.color)){
        casa = true;
    }else{
        casa = false;
    }
    return casa;
}
bool Carta::getVisible() const {
    return visible;
}
char Carta::getPal() const {
    return pal;
}
char Carta::getValor() const {
    return valor;
}
//Pre: La carta c ha de tenir un valor valid.
//Post: Aquest metode ens indica en quin ordre s'han de mantenir les cartes sobre el tauler, ordre descendent.
bool Carta::esMesGran(Carta c) const {
    int diferencia = 0;
    int nou = valor - '0';
    int anterior = c.valor - '0';
    if(c.valor == 'A'){
        return valor == 'K';
    }
    if(c.valor == 'K'){
        return valor == 'Q';
    }
    if(c.valor == 'Q'){
        return valor == 'J';
    }
    if(c.valor == 'J'){
        return valor == 'D';
    }
    if(c.valor == 'D'){
        return valor == '9';
    }
    if(c.valor == '2'){
        return valor == 'A';
    }
    if(c.valor == '\0'){
        return valor == 'K';
    }
    diferencia = anterior -nou;
    return diferencia == 1;

}
//Pre: La carta c ha de tenir un valor valid.
//Post: Aquest metode ens indica en quin ordre s'han de mantenir les cartes sobre el tauler, ordre ascendent, per les piles.
bool Carta::esMesPetita(Carta c) const {
    int diferencia = 0;
    int nou = valor - '0';
    int anterior = c.valor - '0';

    if(c.valor == 'A'){
        return valor == '2';
    }
    if(c.valor == '9'){
        return valor == 'D';
    }
    if(c.valor == 'D'){
        return valor == 'J';
    }
    if(c.valor == 'J'){
        return valor == 'Q';
    }
    if(c.valor == 'Q'){
        return valor == 'K';
    }
    if(c.valor == 'K'){
        return valor == 'Q';
    }
    diferencia = nou -anterior;
    return diferencia == 1;
}