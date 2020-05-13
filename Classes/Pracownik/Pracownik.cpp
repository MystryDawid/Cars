//
// Created by Mystry on 24.04.2020.
//
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include "Pracownik.h"
#include "QFile"


using namespace std;

QVector<Pracownik> Tabela_Pracownikow;

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

void zapisz_pracownikow(){
    QString plik = "pracownicy.dat";
    QFile FileZ(plik);
    FileZ.open(QIODevice::WriteOnly | QIODevice::Text);
    for(int i = 0; i < Tabela_Pracownikow.length(); i++){
        FileZ.write((char*)&Tabela_Pracownikow[i], sizeof(Pracownik));
    }
    FileZ.close();

};

void wczytaj_pracownikow(){
    Pracownik tmp;
    Tabela_Pracownikow.clear();
    QString plik = "pracownicy.dat";
    QFile File(plik);
    if(File.open(QIODevice::ReadOnly | QIODevice::Text)){
        //while(){
            //File.read((char*)&tmp, sizeof(Pracownik));
            std::cout<<tmp.imie.toUtf8().toStdString()<<std::endl;
            Tabela_Pracownikow.append(tmp);
        //}
        File.close();
    }
};


void MainWindow::on_dodajPracownika_clicked()
{
    Tabela_Pracownikow.append(Pracownik(ui->imie->text(),ui->nazwisko->text(),ui->staz->value()));
    ui->comboBox->addItem(Tabela_Pracownikow.last().imie);
}

void MainWindow::on_usunPracownika_clicked()
{
    Tabela_Pracownikow.remove(ui->comboBox->currentIndex());
    ui->comboBox->removeItem(ui->comboBox->currentIndex());
}

void MainWindow::on_test_clicked()
{
    for (int i = 0;i < Tabela_Pracownikow.length(); i++) {
        std::cout<<Tabela_Pracownikow.at(i).imie.toUtf8().toStdString()<<std::endl;
    }
}

void MainWindow::on_zapisz_zmiany_clicked()
{
    zapisz_pracownikow();
}

void MainWindow::on_wczytaj_pracownikow_clicked()
{
    wczytaj_pracownikow();
    ui->comboBox->clear();
    ui->comboBox->addItem("XXXXXXXXXXXXXXXXXXXXXXxxx");
    for (int i = 0;i < Tabela_Pracownikow.length(); i++) {
        ui->comboBox->addItem(Tabela_Pracownikow.at(i).imie);
    }


}

void MainWindow::on_pushButton_clicked()
{
    Tabela_Pracownikow.append(Pracownik("Adam","o",1));
    Tabela_Pracownikow.append(Pracownik("Adamm","o",1));
    Tabela_Pracownikow.append(Pracownik("Adammm","o",1));
    Tabela_Pracownikow.append(Pracownik("Adammmm","o",1));
    Tabela_Pracownikow.append(Pracownik("Adammmmm","o",1));
    Tabela_Pracownikow.append(Pracownik("Adammmmmm","o",1));
    Tabela_Pracownikow.append(Pracownik("Ada","o",1));


    for (int i = 0;i < Tabela_Pracownikow.length(); i++) {
        ui->comboBox->addItem(Tabela_Pracownikow.at(i).imie);
    }
}






