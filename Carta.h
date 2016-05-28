//
// Created by mauro on 3/05/16.
//

#ifndef PRACTICAFINAL_CARTA_H
#define PRACTICAFINAL_CARTA_H


class Carta {
    //DESCRIPCIO: Classe carta amb les propietats d'una carta corrent, pal, valor, color, si esta girada.
public:
    //CONSTRUCTORS
    //Pre:--;Post: Crea una carta amb les propietats buides i la visibilitat a false.
    Carta();
    //Pre: rep dos chars per crear la carta:Post: Crea la carta amb el pal i el valor corresponent, no visible, i amb el seu color adhient.
    Carta(char p, char v);

    //CONSULTORS
    //Pre:--;Post:Metode que mostra les propietats de la carta si esta visible, sino imprimeix ** o si no hi ha carta un espai
    void mostrar() const;
    //Pre:Carta anterior no buida; Post: Retorna true si les cartes casen, false altrament
    bool casen(Carta anterior) const;
    //Pre:--;Post: Retorna el pal de la carta.
    char getPal() const;
    //Pre:--;Post: Retorna el valor de la carta.
    char getValor() const;
    //Pre:Carta no buida; Post: retorna un boolea si la carta es mes petita a c.
    bool esMesPetita(Carta c) const;
    //Pre:Carta no buida; Post: retorna un boolea si la carta es mes gran a c.
    bool esMesGran(Carta c) const;
    //Pre:--;Post: Retorna un true si la carta esta girada, false altrament.
    bool getVisible() const;

    //MODIFICADORS
    //Pre:--;Post: Canvia la propietat visible de la carta a true;
    void setVisible();
    //Pre:--;Post: Canvia la propietat visible de la carta a false;
    void setAmagada();

private:
    //Propietats de la carta.
    char pal;
    char valor;
    bool visible;
    char color;
};


#endif //PRACTICAFINAL_CARTA_H
