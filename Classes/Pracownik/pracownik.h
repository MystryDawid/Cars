//
// Created by Mystry on 24.04.2020.
//
#ifndef CARS_PRACOWNIK_H
#define CARS_PRACOWNIK_H
#include "QString"


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
};



#endif //CARS_PRACOWNIK_H


