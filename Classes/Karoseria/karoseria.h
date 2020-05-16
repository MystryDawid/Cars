#ifndef KAROSERIA_H
#define KAROSERIA_H
#include "QString"
#include "Classes/Pracownik/pracownik.h"

class Karoseria{

public:
    QString typ, material;
    float masa;
    Pracownik p;
    Karoseria(QString typ, QString material, float masa, Pracownik p);
    Karoseria();
    Karoseria(Karoseria *tk);
    friend bool zapisz_typ_karoserii();
    friend bool wczytaj_typ_karoserii();
    friend QDataStream &operator <<(QDataStream &out, Karoseria const &k);
    friend QDataStream &operator >>(QDataStream &in, Karoseria &k);

};



#endif // KAROSERIA_H
