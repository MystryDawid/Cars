#ifndef SILNIK_H
#define SILNIK_H
#include "QString"

class silnik{

public:
    QString typ;
    int konie;
    silnik(QString typ, int konie);
    silnik();
    silnik(silnik *s);
    friend bool zapisz_silniki();
    friend bool wczytaj_silniki();

};

#endif // SILNIK_H
