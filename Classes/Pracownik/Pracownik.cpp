//
// Created by Mystry on 24.04.2020.
//
#include <iostream>
#include "Pracownik.h"
#include "QFile"


using namespace std;




Pracownik::Pracownik(QString imie_,QString naziwkos_,int staz){

    this->imie = imie_;
    this->nazwisko = naziwkos_;
    this->staz_pracy = staz;
}


Pracownik::Pracownik(){

    this->imie = "Bob";
    this->nazwisko = "Budowniczy";
    this->staz_pracy = 100;
}


Pracownik::Pracownik(Pracownik *p){

    this->imie = p->imie;
    this->nazwisko = p->nazwisko;
    this->staz_pracy = p->staz_pracy;
}

void Pracownik::zapis(){
    QString plik = "pracownicy.dat";
    QFile FileZ(plik);
    FileZ.open(QIODevice::WriteOnly | QIODevice::Text);
    FileZ.write((char*)this, sizeof(Pracownik));
    FileZ.close();
};

void Pracownik::odczyt(){
    Pracownik tmp = new Pracownik();
    QString plik = "pracownicy.dat";
    QFile FileO(plik);
    FileO.open(QIODevice::ReadOnly | QIODevice::Text);
    while(FileO.read((char*)&tmp, sizeof(Pracownik))){
        cout<<tmp.staz_pracy<<endl;
    }
    FileO.close();
};

QVector<Pracownik> Pracownik::wszyscy(){
    QVector<Pracownik> tab;
    Pracownik tmp;
    QString plik = "pracownicy.dat";
    QFile File(plik);
    if(File.open(QIODevice::ReadOnly | QIODevice::Text)){
        while(File.read((char*)&tmp, sizeof(Pracownik))){
            tab.append(tmp);
        }
        File.close();
    }
    return tab;
};




