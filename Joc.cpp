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
    int i = 0, cont=0;
    for(i;i<tauler.getFiles();i++){
        Carta nova = b.agafaCarta();
        if(i==cont2){
            nova.setVisible();
        }
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
    int gran = tauler.getColumna(0);
    for(int i=1;i<=tauler.getFiles();i++){
        cout << "c" << i << " ";
        if(gran < tauler.getColumna(i)){
            gran = tauler.getColumna(i);
        }
    }
    cout << endl;

    int files = 7, cont = 0, i=0;
    while(cont < gran){
        for(i;i<files;i++){
            Carta agafada = tauler.getCarta(i,cont);
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
        int ultimaFila = tauler.getColumna(colum-1);
        Carta agafada = descartades.desempila();
        Carta anterior = tauler.getCarta(colum-1, ultimaFila-1);
        if(agafada.esMesGran(anterior)){
            //ultimaFila++;
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
bool Joc::comprovaSituacio(int colum, int fila) const{
    if((colum < 1 or colum > 7) or (fila < 1 or fila > tauler.getColumna(colum-1)) or (!tauler.getCarta(colum-1, fila-1).getVisible())){
        return false;
    }else{
        return true;
    }

}
void Joc::mouCarta(int colum, int fila, int desti) {
    colum = colum -1;
    fila = fila -1;
    desti = desti -1;
    Carta cartaMoure = tauler.getCarta(colum, fila);
    Carta ultimaVisible = tauler.getUltimaCartaVisible(desti);
    if(cartaMoure.casen(ultimaVisible)){
        int max = tauler.getColumna(fila);
        for(int i=0;i<max;i++){
            if(tauler.getCarta(colum, i).getVisible() and tauler.getCarta(colum, i).casen(ultimaVisible)){
                Carta extreta = tauler.extreuCarta(colum, i);
                tauler.afageixCartaFinal(extreta, desti);
            }
        }
        girarUltima(colum);

    }else{
        cout << "LA CARTA NO ES POT POSAR A LA COLUMNA " << desti+1 << endl;
    }

}
void Joc::mouCartaPila(int desti) {
    int aux = desti -1;
    int cont = 0;
    if(!(desti < 0 or desti > 6) or tauler.getColumna(desti) != 0){
        Carta darrera = tauler.getUltimaCartaVisible(aux);
        if(primeraInsercio(darrera, aux, cont)){
            girarUltima(aux);
        }else{
            if(darrera.getPal() == 'P' and darrera.esMesPetita(coll1.cim())){
                coll1.empila(darrera);
                tauler.extreuDarrera(aux);
                girarUltima(aux);
                cont++;
            }
            if(darrera.getPal() == 'c' and darrera.esMesPetita(coll2.cim())){
                coll2.empila(darrera);
                tauler.extreuDarrera(aux);
                girarUltima(aux);
                cont++;
            }
            if(darrera.getPal() == 'd' and darrera.esMesPetita(coll3.cim())){
                coll3.empila(darrera);
                tauler.extreuDarrera(aux);
                girarUltima(aux);
                cont++;
            }
            if(darrera.getPal() == 'T' and darrera.esMesPetita(coll4.cim())){
                coll4.empila(darrera);
                tauler.extreuDarrera(aux);
                girarUltima(aux);
                cont++;
            }
            if(cont == 0){
                mostrarErrorPila();
            }

        }
        }
}
bool Joc::primeraInsercio(Carta darrera, int desti, int &cont) {
    int final = false;
    if(darrera.getValor() == 'A' and coll1.esBuida() and darrera.getPal() == 'P'){
        coll1.empila(darrera);
        tauler.extreuDarrera(desti);
        final = true;
        cont++;
    }
    if(darrera.getValor() == 'A' and coll2.esBuida() and darrera.getPal() == 'c'){
        coll2.empila(darrera);
        tauler.extreuDarrera(desti);
        final = true;
        cont++;
    }
    if(darrera.getValor() == 'A' and coll3.esBuida() and darrera.getPal() == 'd'){
        coll3.empila(darrera);
        tauler.extreuDarrera(desti);
        final = true;
        cont++;
    }
    if(darrera.getValor() == 'A' and coll4.esBuida() and darrera.getPal() == 'T'){
        coll4.empila(darrera);
        tauler.extreuDarrera(desti);
        final = true;
        cont++;
    }

    return final;

}
void Joc::mostrarErrorPila() {
    cout << "LA CARTA NO ES POT APILAR" << endl;
}
void Joc::girarUltima(int desti) {

    Carta ultima = tauler.getUltimaCartaVisible(desti);
    if(!ultima.getVisible()){
        ultima.setVisible();
        tauler.substitueix(ultima, desti);

    }

}