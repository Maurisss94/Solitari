#include <iostream>

using namespace std;

#include "Joc.h"

void llegirValors(int &llavor, int &passos){

    cout << "ENTRA LA LLAVOR:" << endl;
    cin >> llavor;
    cout << "ENTRA ELS PASSOS: " << endl;
    cin >> passos;

}
void mostrarMenu(int &opcio){
    cout << "JOC EN CURS\n"
            "MENU\n"
            "1. OBRIR UNA CARTA (O TORNAR A COMENCAR)\n"
            "2. POSAR UNA CARTA (MA->TAULER)\n"
            "3. POSAR UNA CARTA (MA->PILA)\n"
            "4. MOURE UNA CARTA (TAULER->TAULER)\n"
            "5. MOURE UNA CARTA (TAULER->PILA)\n"
            "6. RECUPERAR UNA CARTA (PILA->TAULER)\n"
            "9. MOSTRAR MENU\n"
            "0. ABANDONAR LA PARTIDA\n"
            "OPCIO:"<< endl;
    cin >> opcio;
}
void seguentOpcio(int &opcio){
    cout << "JOC EN CURS\n"
            "OPCIO: \n";
    cin >> opcio;

}
int demanaColumna(){
    int c;
    cout << "A QUINA COLUMNA LA VOLS POSAR:" << endl;
    cin >> c;
    if((c < 1) or (c >7)){
        cout << "LA CARTA NO ES POT POSAR A LA COLUMNA " << c << endl;
        return -1;
    }
    return c;
}
void demanaOrigen(int &columna, int &fila){
    cout << "ENTRA LA COLUMNA ORIGEN I LA FILA ORIGEN:" << endl;
    cin >> columna;
    cin >> fila;
}
int demanaColumnaDesti(){
    int colum;
    cout << "ENTRA LA COLUMNA DESTI:" << endl;
    cin >> colum;
    return colum;
}
int demanaPila(){
    int pila;
    cout << "ENTRA LA PILA: " << endl;
    cin >> pila;
    return pila;
}
void gestionaOpcio(int opcio, Joc joc) {
    while((opcio != 0) and !joc.haAcabat()){
        if (opcio == 1) {
            joc.obreCarta();
            joc.mostrar();
            seguentOpcio(opcio);
        }
        if(opcio == 2){
            if(joc.descartadesBuida()){
                cout << "NO HI HA CAP CARTA PER AGAFAR" << endl;
                joc.mostrar();
                seguentOpcio(opcio);
            }else{
                int colum = demanaColumna();
                joc.posarAlTauler(colum);
                joc.mostrar();
                seguentOpcio(opcio);
            }
        }
        if(opcio == 3){
            if(joc.descartadesBuida()){
                cout << "NO HI HA CAP CARTA PER AGAFAR" << endl;
                joc.mostrar();
                seguentOpcio(opcio);
            }else{
                joc.posarAlaPila();
                joc.mostrar();
                seguentOpcio(opcio);
            }
        }
        if(opcio == 4){
            int colum, fila;
            demanaOrigen(colum, fila);
            if(joc.comprovaSituacio(colum, fila)){
                int desti = demanaColumnaDesti();
                joc.mouCarta(colum, fila, desti);
            }else{
                cout << "LA CARTA NO ES POT MOURE" << endl;
            }
            joc.mostrar();
            seguentOpcio(opcio);
        }
        if(opcio == 5){
            int desti = demanaColumnaDesti();
            joc.mouCartaPila(desti);
            joc.mostrar();
            seguentOpcio(opcio);

        }
        if(opcio == 6){
            int pila = demanaPila();
            if(joc.esPotRecuperar(pila)){
                int columna = demanaColumna();
                joc.recuperaCarta(pila, columna);
            }else{
                cout << "A LA PILA NO HI HA CAP CARTA PER RECUPERAR" << endl;
            }
            joc.mostrar();
            seguentOpcio(opcio);
        }
        if(opcio == 9){
            mostrarMenu(opcio);
        }
    }
    if(joc.haAcabat()){
        cout << "PARTIDA GUANYADA" << endl;
    }else{
        cout << "PARTIDA ABANDONADA" << endl;
    }


}
int main() {
    int llavor, passos, opcio;
    llegirValors(llavor, passos);
    Baralla baralla(llavor, passos);
    Joc joc(baralla);
    joc.mostrar();

    mostrarMenu(opcio);
    gestionaOpcio(opcio, joc);
    return 0;
}