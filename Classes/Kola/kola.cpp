#include "kola.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QFile"
#include "QMessageBox"
#include "iostream"

QVector<Kola> Tabela_Kola;

Kola::Kola(){
    this->material = "";
    this->wielkosc = 20;
}

Kola::Kola(QString material, float wielkosc){
    this->material = material;
    this->wielkosc = wielkosc;
}

Kola::Kola(Kola *k){
    this->material = k->material;
    this->wielkosc = k->wielkosc;
}

bool zapisz_kola(){
    if(Tabela_Kola.isEmpty()) return 0;
    QString plik = "./kola.dat";
    QFile file(plik);
    file.open(QIODevice::WriteOnly);
    QDataStream out(&file);
    for(int i = 0; i < Tabela_Kola.length(); i++){
         out << Tabela_Kola.at(i).material <<
                Tabela_Kola.at(i).wielkosc;
    }
    file.close();
    return true;
}

bool wczytaj_kopa(){
    QString plik = "./kola.dat";
    QFile file(plik);
    file.open(QIODevice::ReadOnly);
    QDataStream in(&file);
    Tabela_Kola.clear();
    while(!in.atEnd()){
       Kola k = new Kola();
       in >> k.material >> k.wielkosc;
       Tabela_Kola.append(k);
    }
    file.close();
    return true;
}

void MainWindow::on_zapisz_kola_clicked()
{
    QMessageBox msgBox;
    if(zapisz_kola()){
        msgBox.setText("Zapisano koła.");
    }else{
        msgBox.setText("Nie zapisano kół.");
    }
    msgBox.exec();
}

void MainWindow::on_wczytajKola_clicked()
{
    QMessageBox msgBox;
    if(wczytaj_kopa()){
        ui->listaKol->clear();
        for (int i = 0;i < Tabela_Kola.length(); i++) {
            ui->listaKol->addItem(Tabela_Kola.at(i).material + " " +
                                  QString::number(Tabela_Kola.at(i).wielkosc));
        }
        msgBox.setText("Wczytano koła.");
    }else{
        msgBox.setText("Nie wczytano kół.");
    }
    msgBox.exec();
}

void MainWindow::on_dodajKola_clicked()
{
    QMessageBox msgBox;
    if(!ui->KoloMaterial->text().isEmpty()){
        Tabela_Kola.append(Kola(ui->KoloMaterial->text(),
                                  ui->wielkoscKola->value()));
        ui->listaKol->addItem(Tabela_Kola.last().material + " " +
                              QString::number(Tabela_Kola.last().wielkosc));
        msgBox.setText("Dodano koła.");
    }else{
        msgBox.setText("Proszę wypełnić wszystkie pola.");
    }
    msgBox.exec();
}

void MainWindow::on_modyfikujKola_clicked()
{
    QMessageBox msgBox;
    if(!ui->KoloMaterial->text().isEmpty()){
        ui->listaKol->currentItem()->setText(ui->KoloMaterial->text() + " " +
                                             QString::number(ui->wielkoscKola->value()));
        Tabela_Kola.replace(ui->listaKol->currentRow(),
                                   new Kola(ui->KoloMaterial->text(),
                                            ui->wielkoscKola->value()));
        msgBox.setText("Zmodyfikowano koła.");
    }else{
        msgBox.setText("Proszę wybrać koła z listy po lewej.");
    }
    msgBox.exec();
}

void MainWindow::on_usunKola_clicked()
{
    QMessageBox msgBox;
    int row =  ui->listaKol->currentRow();
    if(row != -1){
        Tabela_Kola.remove(row);
        ui->listaKol->takeItem(row);
        msgBox.setText("Usunięto napęd.");
    }else{
        msgBox.setText("Usunięcie napędu nie powiodło się.");
    }
    msgBox.exec();
}

void MainWindow::on_wielkoscKola_valueChanged(int value)
{
    ui->lcdNumberKoloWielkosc->display(value);
}
