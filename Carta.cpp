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
}
Carta::Carta(char p, char v) {
    pal = p;
    valor = v;
    visible = false;
}
void Carta::setVisible() {
    visible = true;
}
void Carta::mostrar() const {
    if(visible){
        cout << valor << pal ;
    }else if((pal == ' ')or(valor==' ')){
        cout << "  ";
    }else{
        cout << "**";
    }

}