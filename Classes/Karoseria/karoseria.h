#ifndef KAROSERIA_H
#define KAROSERIA_H
#include "QString"


class Karoseria{

public:
    QString typ, material;
    float masa;
    Karoseria(QString typ, QString material, float masa);
    Karoseria();
    Karoseria(Karoseria *tk);
    friend bool zapisz_typ_karoserii();
    friend bool wczytaj_typ_karoserii();

};



#endif // KAROSERIA_H
