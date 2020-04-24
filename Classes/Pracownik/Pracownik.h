//
// Created by Mystry on 24.04.2020.
//
#include <string>
#ifndef CARS_PRACOWNIK_H
#define CARS_PRACOWNIK_H

using namespace std;



class Pracownik{
    private:
        const string file_name_pracownik = "pracownicy";
    protected:

        static int nextID;
    public:

        int id,staz_pracy;
        string imie,nazwisko;

        Pracownik(string imie_,string naziwkos_,int staz);
        Pracownik();
        Pracownik(Pracownik *p);
        void zapis();
        void odczyt();

};


#endif //CARS_PRACOWNIK_H
