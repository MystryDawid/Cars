//
// Created by Mystry on 24.04.2020.
//
#ifndef CARS_PRACOWNIK_H
#define CARS_PRACOWNIK_H
#include "QString"
#include "QDataStream"

using namespace std;

class Pracownik{

    public:
        int staz_pracy;
        QString imie,nazwisko;

        Pracownik(QString imie_,QString naziwkos_,int staz);
        Pracownik();
        Pracownik(Pracownik *p);

        friend bool zapisz_pracownikow();
        friend bool wczytaj_pracownikow();
        friend QDataStream &operator <<(QDataStream &out, Pracownik const &p);
        friend QDataStream &operator >>(QDataStream &in, Pracownik &p);
};

extern QVector<Pracownik> Tabela_Pracownikow;


#endif //CARS_PRACOWNIK_H



