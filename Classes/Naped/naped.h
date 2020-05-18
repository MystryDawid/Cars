#ifndef NAPED_H
#define NAPED_H
#include "QString"
#include "Classes/Pracownik/pracownik.h"

class Naped{
public:
    QString naped;
    int przod,tyl;
    Pracownik p;
    Naped();
    Naped(QString naped, int przod, int tyl, Pracownik p);
    Naped(Naped *n);
    friend bool zapisz_naped();
    friend bool wczytaj_naped();
    friend QDataStream &operator <<(QDataStream &out, Naped const &n);
    friend QDataStream &operator >>(QDataStream &in, Naped &n);

};

extern QVector<Naped> Tabela_Naped;

#endif // NAPED_H
