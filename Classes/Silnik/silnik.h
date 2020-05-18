#ifndef SILNIK_H
#define SILNIK_H
#include "QString"
#include "Classes/Pracownik/pracownik.h"

class Silnik{
public:
    QString typSilnika;
    int mocSilnika;
    Pracownik p;
    Silnik();
    Silnik(QString typSilnika, int mocSilnika, Pracownik p);
    Silnik(Silnik *s);
    friend bool zapisz_silniki();
    friend bool wczytaj_silniki();
    friend QDataStream &operator <<(QDataStream &out, Silnik const &s);
    friend QDataStream &operator >>(QDataStream &in, Silnik &s);

};

extern QVector<Silnik> Tabela_Silnik;

#endif // SILNIK_H
