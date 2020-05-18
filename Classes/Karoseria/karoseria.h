#ifndef KAROSERIA_H
#define KAROSERIA_H
#include "QString"
#include "Classes/Pracownik/pracownik.h"

class Karoseria{

public:
    QString karoseriaTyp, karoseriaMaterial;
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

extern QVector<Karoseria> Tabela_Karoseria;

#endif // KAROSERIA_H
