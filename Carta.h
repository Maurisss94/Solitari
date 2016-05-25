//
// Created by mauro on 3/05/16.
//

#ifndef PRACTICAFINAL_CARTA_H
#define PRACTICAFINAL_CARTA_H


class Carta {

public:
    Carta();
    Carta(char p, char v);

    void mostrar() const;
    void setVisible();



private:
    char pal;
    char valor;
    bool visible;
};


#endif //PRACTICAFINAL_CARTA_H
