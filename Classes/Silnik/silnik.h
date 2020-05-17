#ifndef SILNIK_H
#define SILNIK_H
#include "QString"
#include "Classes/Pracownik/pracownik.h"

class silnik{
public:
    QString typSilnika;
    int mocSilnika;
    Pracownik p;
    silnik();
    silnik(QString typSilnika, int mocSilnika, Pracownik p);
    silnik(silnik *s);
    friend bool zapisz_silniki();
    friend bool wczytaj_silniki();

};


#endif // SILNIK_H
