#ifndef KOLA_H
#define KOLA_H
#include "QString"
#include "Classes/Pracownik/pracownik.h"

class Kola{
public:

    QString kolaMaterial;
    float wielkosc;
    Pracownik p;
    Kola();
    Kola(QString material, float wielkosc, Pracownik p);
    Kola(Kola *k);
    friend bool zapisz_kola();
    friend bool wczytaj_kopa();
    friend QDataStream &operator <<(QDataStream &out, Kola const &k);
    friend QDataStream &operator >>(QDataStream &in, Kola &k);
};

extern QVector<Kola> Tabela_Kola;

#endif // KOLA_H
