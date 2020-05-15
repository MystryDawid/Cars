#ifndef NAPED_H
#define NAPED_H
#include "QString"

class Naped{
public:
    QString naped;
    int przod,tyl;
    Naped();
    Naped(QString naped, int przod, int tyl);
    Naped(Naped *n);
    friend bool zapisz_naped();
    friend bool wczytaj_naped();

};

#endif // NAPED_H
