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
    bool casen(Carta anterior) const;
    char getPal() const;
    char getValor() const;
    bool esMesPetita(Carta c) const;
    bool esMesGran(Carta c) const;
    void setVisible();
    void setAmagada();



private:
    char pal;
    char valor;
    bool visible;
    char color;
};


#endif //PRACTICAFINAL_CARTA_H
