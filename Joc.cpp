//
// Created by mauro on 3/05/16.
//

#include "Joc.h"
#include <iostream>

using namespace std;
Joc::Joc(Baralla b) {
    ma = b;
    tauler = Tauler();

    int fila = 0;
    int cont2 = 0;
    int i = 0;
    for(i;i<tauler.getFiles();i++){
        Carta nova = ma.agafaCarta();
        tauler.afageixCarta(nova, i, fila);
        if(i == tauler.getFiles()-1){
            fila++;
            i = cont2++;
        }
    }


}
void Joc::mostrar() const{

    cout << "ESTAT DEL JOC" << endl;

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
            cout << " " ;
        }
        cout << "f" <<cont+1 <<  endl;
        i = 0;
        cont++;

    }


}