#ifndef AUTO_H
#define AUTO_H
#include "Classes/Karoseria/karoseria.h"
#include "Classes/Kola/kola.h"
#include "Classes/Naped/naped.h"
#include "Classes/Pracownik/pracownik.h"
#include "Classes/Silnik/silnik.h"
#include "QString"

class Auto: Karoseria, Kola, Naped, Pracownik, Silnik{
public:
    Karoseria karoseria;
    Kola kola;
    Naped naped;
    Pracownik pracownik;
    Silnik silnik;
    Auto();
    Auto(Auto *a);
    Auto(Karoseria k, Kola kola, Naped n, Pracownik p, Silnik s);
    friend bool zapisz_silniki();
    friend bool wczytaj_silniki();
    friend QDataStream &operator <<(QDataStream &out, Auto const &a);
    friend QDataStream &operator >>(QDataStream &in, Auto &a);
};

#endif // AUTO_H
