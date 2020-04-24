//
// Created by Mystry on 24.04.2020.
//
#include <iostream>
#include "Pracownik.h"
#include <fstream>
using namespace std;

Pracownik::Pracownik(string imie_,string naziwkos_,int staz){

    id = ++nextID;
    imie = imie_;
    nazwisko = naziwkos_;
    staz_pracy = staz;
    zapis();
}

Pracownik::Pracownik(){

    id = ++nextID;
    imie = "Bob";
    nazwisko = "Budowniczy";
    staz_pracy = 100;
    zapis();
}

Pracownik::Pracownik(Pracownik *p){

    id = p->id;
    imie = p->imie;
    nazwisko = p->nazwisko;
    staz_pracy = p->staz_pracy;
}

void Pracownik::zapis(){
    std::string plik = "../Files/" + file_name_pracownik + ".dat";
    fstream File;
    File.open(plik, ios::out | ios::binary | ios::app);
    File.write((char*)this, sizeof(Pracownik));
    File.close();
};

void Pracownik::odczyt(){
    Pracownik tmp;
    std::string plik = "../Files/" + file_name_pracownik + ".dat";
    fstream File;
    File.open(plik, ios::in | ios::binary);
    while(File.read((char*)&tmp, sizeof(Pracownik))){
        cout<<tmp.id<<endl;
    }
    File.close();
};

int Pracownik::nextID = 0;