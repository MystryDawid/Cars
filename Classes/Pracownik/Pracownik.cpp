//
// Created by Mystry on 24.04.2020.
//
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "pracownik.h"
#include "QFile"
#include "QMessageBox"
#include "iostream"

using namespace std;

QVector<Pracownik> Tabela_Pracownikow;

QDataStream &operator <<(QDataStream &out, Pracownik const &p){
    out << p.imie << p.nazwisko << p.staz_pracy;
    return out;
}

QDataStream &operator >>(QDataStream &in, Pracownik &p){
    in >> p.imie >> p.nazwisko >> p.staz_pracy;
    return in;
}

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
    if(Tabela_Pracownikow.isEmpty()) return 0;
    QString plik = "./pracownicy.dat";
    QFile file(plik);
    file.open(QIODevice::WriteOnly);
    QDataStream out(&file);
    for(int i = 0; i < Tabela_Pracownikow.length(); i++){
         out << Tabela_Pracownikow.at(i);
    }
    file.close();
    return true;

};

bool wczytaj_pracownikow(){
    QString plik = "./pracownicy.dat";
    QFile file(plik);
    file.open(QIODevice::ReadOnly);
    QDataStream in(&file);
    Tabela_Pracownikow.clear();
    while(!in.atEnd()){
       Pracownik p;
       in >> p;
       Tabela_Pracownikow.append(p);
    }
    file.close();
    return true;
};


void MainWindow::on_dodajPracownika_clicked()
{
    QMessageBox msgBox;
    if(!ui->imie->text().isEmpty() && !ui->nazwisko->text().isEmpty()
            && !ui->staz->text().isEmpty()){

        QString imie = ui->imie->text();
        QString nazwisko = ui->nazwisko->text();

        Tabela_Pracownikow.append(
                    Pracownik(imie,
                              nazwisko,
                              ui->staz->value()));

        ui->listaPracownikow->addItem(imie + " " + nazwisko);
        ui->karoseriePracownicy->addItem(imie + " " + nazwisko);
        ui->kolaPracownicy->addItem(imie + " " + nazwisko);
        ui->napedPracownicy->addItem(imie + " " + nazwisko);
        ui->silnikPracownicy->addItem(imie + " " + nazwisko);
        ui->autoPracownicy->addItem(imie + " " + nazwisko);

        msgBox.setText("Dodano pracownika.");
    }else{
        msgBox.setText("Proszę wypełnić wszystkie pola.");
    }
    msgBox.exec();
}

void MainWindow::on_usunPracownika_clicked()
{
    QMessageBox msgBox;
    int row =  ui->listaPracownikow->currentRow();
    if(ui->listaPracownikow->count() && row != -1){

        Tabela_Pracownikow.remove(row);
        ui->listaPracownikow->takeItem(row);
        ui->karoseriePracownicy->removeItem(row);
        ui->kolaPracownicy->removeItem(row);
        ui->napedPracownicy->removeItem(row);
        ui->silnikPracownicy->removeItem(row);
        ui->autoPracownicy->removeItem(row);

        msgBox.setText("Usunięto pracownika.");
    }else{
        msgBox.setText("Usunięcie pracownika nie powiodło się.");
    }
    msgBox.exec();
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

        ui->listaPracownikow->clear();
        ui->karoseriePracownicy->clear();
        ui->kolaPracownicy->clear();
        ui->silnikPracownicy->clear();
        ui->autoPracownicy->clear();

        for (int i = 0;i < Tabela_Pracownikow.length(); i++) {

            QString imie = Tabela_Pracownikow.at(i).imie;
            QString nazwisko = Tabela_Pracownikow.at(i).nazwisko;

            ui->listaPracownikow->addItem(imie + " " + nazwisko);
            ui->karoseriePracownicy->addItem(imie + " " + nazwisko);
            ui->kolaPracownicy->addItem(imie + " " + nazwisko);
            ui->napedPracownicy->addItem(imie + " " + nazwisko);
            ui->silnikPracownicy->addItem(imie + " " + nazwisko);
            ui->autoPracownicy->addItem(imie + " " + nazwisko);
        }
        msgBox.setText("Wczytano pracowników.");
    }else{
        msgBox.setText("Nie wczytano pracowników.");
    }
    msgBox.exec();
}

void MainWindow::on_listaPracownikow_clicked()
{
   ui->imie->setText(Tabela_Pracownikow.at(ui->listaPracownikow->currentIndex().row()).imie);
   ui->nazwisko->setText(Tabela_Pracownikow.at(ui->listaPracownikow->currentIndex().row()).nazwisko);
   ui->staz->setValue(Tabela_Pracownikow.at(ui->listaPracownikow->currentIndex().row()).staz_pracy);
}

void MainWindow::on_modyfikuj_clicked()
{
    QMessageBox msgBox;
    if(!ui->imie->text().isEmpty() && !ui->nazwisko->text().isEmpty()
            && !ui->staz->text().isEmpty()){

        QString imie = ui->imie->text();
        QString nazwisko = ui->nazwisko->text();

        ui->listaPracownikow->currentItem()->setText(imie + " " + nazwisko);

        ui->karoseriePracownicy->setItemText(ui->listaPracownikow->currentRow(),
                                             imie + " " + nazwisko);

        ui->kolaPracownicy->setItemText(ui->listaPracownikow->currentRow(),
                                        imie + " " + nazwisko);

        ui->napedPracownicy->setItemText(ui->listaPracownikow->currentRow(),
                                         imie + " " + nazwisko);

        ui->silnikPracownicy->setItemText(ui->listaPracownikow->currentRow(),
                                          imie + " " + nazwisko);

        ui->autoPracownicy->setItemText(ui->listaPracownikow->currentRow(),
                                        imie + " " + nazwisko);

        Tabela_Pracownikow.replace(ui->listaPracownikow->currentRow(),
                                   Pracownik(imie, nazwisko,
                                                 ui->staz->value()));

        msgBox.setText("Zmodyfikowano pracownika.");
    }else{
        msgBox.setText("Proszę wybrać pracowanika z listy po lewej.");
    }
    msgBox.exec();
}
