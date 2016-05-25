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
    int max = 7, cont = 0, i=0;
    while(cont < max){
        for(i;i<max;i++){
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