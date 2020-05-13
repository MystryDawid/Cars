//
// Created by Mystry on 24.04.2020.
//
#ifndef CARS_PRACOWNIK_H
#define CARS_PRACOWNIK_H
#include "QString"


using namespace std;

class Pracownik{

    protected:
        QString file_name_pracownik = "pracownicy";
    public:
        int staz_pracy;
        QString imie,nazwisko;

        Pracownik(QString imie_,QString naziwkos_,int staz);
        Pracownik();
        Pracownik(Pracownik *p);
        friend void zapisz_pracownikow();
        friend void wczytaj_pracownikow();
        void dodaj_do_pracownikow();

};



#endif //CARS_PRACOWNIK_H



