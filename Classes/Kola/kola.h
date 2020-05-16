#ifndef KOLA_H
#define KOLA_H
#include "QString"
#include "Classes/Pracownik/pracownik.h"

class Kola{
public:

    QString material;
    float wielkosc;
    Pracownik p;
    Kola();
    Kola(QString material, float wielkosc, Pracownik p);
    Kola(Kola *k);
    friend bool zapisz_kola();
    friend bool wczytaj_kopa();
};

#endif // KOLA_H
