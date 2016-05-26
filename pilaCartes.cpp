//
// Created by mauro on 25/05/16.
//

#include "pilaCartes.h"
#include <iostream>

pilaCartes::pilaCartes() {
    a_cim = NULL;

}
pilaCartes::pilaCartes(const pilaCartes &o) {
    a_cim = NULL;
    copia(o);
}
pilaCartes::~pilaCartes() {
    allibera();
}

bool pilaCartes::esBuida() const {
    return a_cim == NULL;
}
Carta pilaCartes::cim() const {
    if(a_cim == NULL){
        Carta buida = Carta();
        return buida;
    }
    return a_cim->valor;
}

void pilaCartes::empila(Carta c) {
    Node* nou = new Node;
    nou->valor = c;
    nou->seg = a_cim;
    a_cim = nou;
}
Carta pilaCartes::desempila() {
    Node* aux= a_cim;
    Carta v;
    a_cim= a_cim->seg;
    v = aux->valor;
    delete aux;
    return v;
}
pilaCartes& pilaCartes::operator=(const pilaCartes &o) {
    if (this != &o){
        allibera();
        copia(o);
    }
    return *this;
}
void pilaCartes::copia(const pilaCartes &o) {
    if(!o.esBuida()){
        Node *p, *q, *aux;
        p = new Node; a_cim = p;
        aux = o.a_cim; p->valor = aux->valor; p->seg = o.a_cim;
        q = p;
        p->valor.setAmagada();
        while (aux->seg!=NULL) {
            aux = aux->seg;
            p = new Node; q->seg = p;
            p->valor = aux->valor; p->seg = NULL;
            q = p;
            p->valor.setAmagada();
        }
    }
}
void pilaCartes::allibera() {
    while (!esBuida()) {
        Node* aux= a_cim;
        a_cim= a_cim->seg;
        delete aux;
    }
}