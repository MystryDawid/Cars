#ifndef KOLA_H
#define KOLA_H
#include "QString"

class Kola{
public:

    QString material;
    float wielkosc;
    Kola();
    Kola(QString material, float wielkosc);
    Kola(Kola *k);
    friend bool zapisz_kola();
    friend bool wczytaj_kopa();
};

#endif // KOLA_H
