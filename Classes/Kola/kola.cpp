#include "kola.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QFile"
#include "QMessageBox"
#include "iostream"

QVector<Kola> Tabela_Kola;

Kola::Kola(){
    this->kolaMaterial = "";
    this->wielkosc = 20;
    this->p = new Pracownik();
}

Kola::Kola(QString material, float wielkosc, Pracownik p){
    this->kolaMaterial = material;
    this->wielkosc = wielkosc;
    this->p = new Pracownik(p);
}

Kola::Kola(Kola *k){
    this->kolaMaterial = k->kolaMaterial;
    this->wielkosc = k->wielkosc;
    this->p = k->p;
}

QDataStream &operator <<(QDataStream &out, Kola const &k){
    out << k.kolaMaterial << k.wielkosc << k.p;
    return out;
}

QDataStream &operator >>(QDataStream &in, Kola &k){
    in >> k.kolaMaterial >> k.wielkosc >> k.p;
    return in;
}


bool zapisz_kola(){
    if(Tabela_Kola.isEmpty()) return 0;
    QString plik = "./kola.dat";
    QFile file(plik);
    file.open(QIODevice::WriteOnly);
    QDataStream out(&file);
    for(int i = 0; i < Tabela_Kola.length(); i++){
         out << Tabela_Kola.at(i);
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
       in >> k;
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
            ui->listaKol->addItem(Tabela_Kola.at(i).kolaMaterial + " " +
                                  QString::number(Tabela_Kola.at(i).wielkosc) + " " +
                                  Tabela_Kola.at(i).p.imie);

            ui->AutaKola->addItem(Tabela_Kola.at(i).kolaMaterial + " " +
                                  QString::number(Tabela_Kola.at(i).wielkosc) + " " +
                                  Tabela_Kola.at(i).p.imie);
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
    if(!ui->KoloMaterial->text().isEmpty() &&
            ui->kolaPracownicy->count() > 0){
        Tabela_Kola.append(Kola(ui->KoloMaterial->text(),
                                  ui->wielkoscKola->value(),
                                    Tabela_Pracownikow.at(ui->kolaPracownicy->currentIndex())));
        ui->listaKol->addItem(Tabela_Kola.last().kolaMaterial + " " +
                              QString::number(Tabela_Kola.last().wielkosc) + " " +
                              Tabela_Kola.last().p.imie);

        ui->AutaKola->addItem(Tabela_Kola.last().kolaMaterial + " " +
                              QString::number(Tabela_Kola.last().wielkosc) + " " +
                              Tabela_Kola.last().p.imie);
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
                                             QString::number(ui->wielkoscKola->value()) + " " +
                                             ui->kolaPracownicy->currentText());

        ui->AutaKola->setItemText(ui->listaPracownikow->currentRow(),ui->KoloMaterial->text() + " " +
                                             QString::number(ui->wielkoscKola->value()) + " " +
                                             ui->kolaPracownicy->currentText());

        Tabela_Kola.replace(ui->listaKol->currentRow(),
                                   new Kola(ui->KoloMaterial->text(),
                                            ui->wielkoscKola->value(),
                                            Tabela_Pracownikow.at(ui->kolaPracownicy->currentIndex())));
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
        ui->AutaKola->removeItem(row);
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

void MainWindow::on_listaKol_clicked(){
    ui->KoloMaterial->setText(Tabela_Kola.at(ui->listaKol->currentIndex().row()).kolaMaterial);
    ui->wielkoscKola->setValue(Tabela_Kola.at(ui->listaKol->currentIndex().row()).wielkosc);
}

