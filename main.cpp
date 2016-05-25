#include <iostream>

using namespace std;

#include "Joc.h"

void llegirValors(int &llavor, int &passos){

    cout << "ENTRA LA LLAVOR:" << endl;
    cin >> llavor;
    cout << "ENTRA ELS PASSOS: " << endl;
    cin >> passos;

}
int main() {
    int llavor, passos;
    llegirValors(llavor, passos);
    Baralla baralla(llavor, passos);
    Joc joc(baralla);

    joc.mostrar();
    return 0;
}