//
// Created by mauro on 3/05/16.
//

#include "Joc.h"
#include <iostream>

using namespace std;
Joc::Joc(Baralla b) {
    ma = pilaCartes();
    tauler = Tauler();
    descartades = pilaCartes();
    coll1 = pilaCartes();
    coll2 = pilaCartes();
    coll3 = pilaCartes();
    coll4 = pilaCartes();

    int fila = 0;
    int cont2 = 0;
    int i = 0;
    for(i;i<tauler.getFiles();i++){
        Carta nova = b.agafaCarta();
        tauler.afageixCarta(nova, i, fila);
        if(i == tauler.getFiles()-1){
            fila++;
            i = cont2++;
        }
    }

    int cartesSobrants = b.getMida();
    for(int i=0;i<=cartesSobrants;i++){
        Carta sobrant = b.repartirSobrants(i);
        ma.empila(sobrant);
    }



}
void Joc::mostrar() const{

    cout << "ESTAT DEL JOC" << endl;
    coll1.cim().mostrar();
    coll2.cim().mostrar();
    coll3.cim().mostrar();
    coll4.cim().mostrar();
    cout << "   ";
    ma.cim().mostrar();
    descartades.cim().mostrar();
    cout << endl;
    for(int i=0;i<tauler.getFiles();i++){
        cout << "c" << i+1 << " ";
    }
    cout << endl;
    int files = 7, cont = 0, i=0, columnes = 7;
    while(cont < columnes){
        for(i;i<files;i++){
            Carta agafada = tauler.getCarta(i,cont);
            if(i==cont){
                agafada.setVisible();
            }
            agafada.mostrar();
        }
        cout << "f" <<cont+1 <<  endl;
        i = 0;
        cont++;


    }
}
void Joc::obreCarta() {
    if(ma.esBuida()){
        ma = descartades;
        descartades = pilaCartes();
    }else {
        Carta agafada = ma.desempila();
        agafada.setVisible();
        descartades.empila(agafada);
    }

}
bool Joc::descartadesBuida() const {
    return descartades.esBuida();
}
void Joc::posarAlTauler(int colum) {
    if(colum != -1){
        int ultimaFila = tauler.getColumna(colum);
        Carta agafada = descartades.desempila();
        Carta anterior = tauler.getCarta(colum-1, ultimaFila-1);
        if(agafada.casen(anterior)){
            tauler.afageixCarta(agafada, colum-1, ultimaFila);
        }else{
            cout << "LA CARTA NO ES POT POSAR A LA COLUMNA " << colum << endl;
            descartades.empila(agafada);
        }
    }

}
void Joc::posarAlaPila() {

    //REPASSAR , no pot ser que hi hagi tants ifs, fer una funcio amb el parametre de la carta.
    Carta agafada = descartades.cim();

    if(agafada.getPal() == 'c'){
        if(coll2.esBuida() and agafada.getValor() == 'A'){
            coll2.empila(descartades.desempila());
        }else {
            if(agafada.esMesPetita(coll2.cim())){
                coll2.empila(descartades.desempila());
            }else{
                mostraError();
            }
        }
    }
    if(agafada.getPal() == 'P'){
        if(coll1.esBuida() and agafada.getValor() == 'A'){
            coll1.empila(descartades.desempila());
        }else{
            if(agafada.esMesPetita(coll1.cim())){
                coll1.empila(descartades.desempila());
            }else{
                mostraError();
            }
        }
    }
    if(agafada.getPal() == 'd'){
        if(coll3.esBuida() and agafada.getValor() == 'A'){
            coll3.empila(descartades.desempila());
        }else {
            if(agafada.esMesPetita(coll3.cim())){
                coll3.empila(descartades.desempila());
            }else{
                mostraError();
            }
        }
    }
    if(agafada.getPal() == 'T'){
        if(coll4.esBuida() and agafada.getValor() == 'A'){
            coll4.empila(descartades.desempila());
        }else {
            if(agafada.esMesPetita(coll4.cim())){
                coll4.empila(descartades.desempila());
            }else{
                mostraError();
            }
        }
    }

}
void Joc::mostraError() {
    cout << "NO ES POT APILAR LA CARTA" << endl;
}