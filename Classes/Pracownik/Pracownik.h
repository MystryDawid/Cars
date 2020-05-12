//
// Created by Mystry on 24.04.2020.
//
#ifndef CARS_PRACOWNIK_H
#define CARS_PRACOWNIK_H
#include "QString"
#include "QVector"

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
        void zapis();
        void odczyt();
        QVector<Pracownik> wszyscy();
        void dodaj_do_pracownikow();

};


#endif //CARS_PRACOWNIK_H