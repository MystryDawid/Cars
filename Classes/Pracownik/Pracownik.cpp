//
// Created by Mystry on 24.04.2020.
//
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include "Pracownik.h"
#include "QFile"
#include "QMessageBox"


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

bool zapisz_pracownikow(){
    QString plik = "./pracownicy.dat";
    QFile file(plik);
    file.open(QIODevice::WriteOnly);
    QDataStream out(&file);
    for(int i =0; i < Tabela_Pracownikow.length(); i++){
         out << Tabela_Pracownikow.at(i).imie << Tabela_Pracownikow.at(i).nazwisko << Tabela_Pracownikow.at(i).staz_pracy;
    }

    return true;

};

bool wczytaj_pracownikow(){
    QString plik = "./pracownicy.dat";
    QFile file(plik);
    file.open(QIODevice::ReadOnly);
    QDataStream in(&file);
    Tabela_Pracownikow.clear();
    while(!in.atEnd()){
       Pracownik p = new Pracownik();
       in >> p.imie >> p.nazwisko >> p.staz_pracy;
       Tabela_Pracownikow.append(p);
    }
    return true;
};


void MainWindow::on_dodajPracownika_clicked()
{
    QMessageBox msgBox;
    if(!ui->imie->text().isEmpty() && !ui->nazwisko->text().isEmpty() && !ui->staz->text().isEmpty()){
        Tabela_Pracownikow.append(Pracownik(ui->imie->text(),ui->nazwisko->text(),ui->staz->value()));
        ui->comboBox->addItem(Tabela_Pracownikow.last().imie);
        msgBox.setText("Dodano pracownika.");
    }else{
        msgBox.setText("Proszę wypełnić wszystkie pola.");
    }
    msgBox.exec();
}

void MainWindow::on_usunPracownika_clicked()
{
    QMessageBox msgBox;
    if(ui->comboBox->count()){
        Tabela_Pracownikow.remove(ui->comboBox->currentIndex());
        ui->comboBox->removeItem(ui->comboBox->currentIndex());
        msgBox.setText("Usunięto pracownika.");
    }else{
        msgBox.setText("Usunięcie pracownika nie powiodło się.");
    }
    msgBox.exec();
}

void MainWindow::on_test_clicked()
{
    for (int i = 0;i < Tabela_Pracownikow.length(); i++) {
        std::cout<<Tabela_Pracownikow.at(i).imie.toUtf8().toStdString()<<std::endl;
    }
}

void MainWindow::on_zapisz_zmiany_clicked()
{
    QMessageBox msgBox;
    if(zapisz_pracownikow()){
        msgBox.setText("Zapisano pracowników.");
    }else{
        msgBox.setText("Nie zapisano pracowników.");
    }
    msgBox.exec();
}

void MainWindow::on_wczytaj_pracownikow_clicked()
{
    QMessageBox msgBox;
    if(wczytaj_pracownikow()){
        msgBox.setText("Wczytano pracowników.");
    }else{
        msgBox.setText("Nie wczytano pracowników.");
    }
    ui->comboBox->clear();
    for (int i = 0;i < Tabela_Pracownikow.length(); i++) {
        ui->comboBox->addItem(Tabela_Pracownikow.at(i).imie);
    }
    msgBox.exec();
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






