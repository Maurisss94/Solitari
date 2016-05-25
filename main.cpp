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

void gestionaOpcio(int opcio, Joc joc) {
    while(opcio != 0){
        if (opcio == 1) {
            joc.obreCarta();
            joc.mostrar();
            seguentOpcio(opcio);
        }
        if(opcio == 2){
            joc.mostrar();
            seguentOpcio(opcio);
        }
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