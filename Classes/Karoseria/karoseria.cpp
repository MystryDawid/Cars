#include "karoseria.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMessageBox"
#include "QFile"

QVector<Karoseria> Tabela_Karoseria;

Karoseria::Karoseria(){
    this->typ = "";
    this->material = "";
    this->masa = 0.0;
}

Karoseria::Karoseria(QString typ, QString material, float masa){
    this->typ = typ;
    this->material = material;
    this->masa = masa;
}

Karoseria::Karoseria(Karoseria *k){
    this->typ = k->typ;
    this->masa = k->masa;
    this->material = k->material;
}


bool zapisz_typy_karoserii(){
    if(Tabela_Karoseria.isEmpty()) return 0;
    QString plik = "./karoserie.dat";
    QFile file(plik);
    file.open(QIODevice::WriteOnly);
    QDataStream out(&file);
    for(int i = 0; i < Tabela_Karoseria.length(); i++){
         out << Tabela_Karoseria.at(i).typ <<
                Tabela_Karoseria.at(i).material <<
                Tabela_Karoseria.at(i).masa;
    }
    file.close();
    return true;

};

bool wczytaj_typy_karoserii(){
    QString plik = "./karoserie.dat";
    QFile file(plik);
    file.open(QIODevice::ReadOnly);
    QDataStream in(&file);
    Tabela_Karoseria.clear();
    while(!in.atEnd()){
       Karoseria k = new Karoseria();
       in >> k.typ >> k.material >> k.masa;
       Tabela_Karoseria.append(k);
    }
    file.close();
    return true;
};

void MainWindow::on_dodajTypKaroserii_clicked()
{
    QMessageBox msgBox;
    if(!ui->typTypKaroserii->text().isEmpty() &&
            !ui->material->text().isEmpty() &&
            !ui->masa->text().isEmpty()){
        Tabela_Karoseria.append(Karoseria(
                                    ui->typTypKaroserii->text(),
                                    ui->material->text(),
                                    ui->masa->value()));
        ui->listaTypyKaroserii->addItem(Tabela_Karoseria.last().typ + " " +
                                        Tabela_Karoseria.last().material + " " +
                                        QString::number(Tabela_Karoseria.last().masa));
        msgBox.setText("Dodano karoserię.");
    }else{
        msgBox.setText("Proszę wypełnić wszystkie pola.");
    }
    msgBox.exec();
}

void MainWindow::on_usunTypKaroserii_clicked()
{
    QMessageBox msgBox;
    int row = ui->listaTypyKaroserii->currentRow();
    if(row != -1){
        Tabela_Karoseria.remove(row);
        ui->listaTypyKaroserii->takeItem(row);
        msgBox.setText("Usunięto karoserie.");
    }else{
        msgBox.setText("Usunięcie karoserii nie powiodło się.");
    }
    msgBox.exec();
}

void MainWindow::on_zapiszZamianyKaroserii_clicked()
{
    QMessageBox msgBox;
    if(zapisz_typy_karoserii()){
        msgBox.setText("Zapisano karoserie.");
    }else{
        msgBox.setText("Nie zapisano karoserii.");
    }
    msgBox.exec();
}

void MainWindow::on_wczytajTypyKaroserii_clicked()
{
    QMessageBox msgBox;
    if(wczytaj_typy_karoserii()){
        ui->listaTypyKaroserii->clear();
        for (int i = 0;i < Tabela_Karoseria.length(); i++) {
            ui->listaTypyKaroserii->addItem(Tabela_Karoseria.at(i).typ + " " +
                                            Tabela_Karoseria.at(i).material + " " +
                                            QString::number(Tabela_Karoseria.at(i).masa));
        }
        msgBox.setText("Wczytano karoserie.");
    }else{
        msgBox.setText("Nie wczytano karoserii.");
    }
    msgBox.exec();
}


void MainWindow::on_listaTypyKaroserii_clicked()
{
    Karoseria tmp = new Karoseria(Tabela_Karoseria.at(ui->listaTypyKaroserii->currentIndex().row()));
    ui->typTypKaroserii->setText(tmp.typ);
    ui->masa->setValue(tmp.masa);
    ui->material->setText(tmp.material);
}

void MainWindow::on_modyfikujTypKaroserii_clicked()
{
    QMessageBox msgBox;
    if(!ui->typTypKaroserii->text().isEmpty() &&
            !ui->material->text().isEmpty() &&
            !ui->masa->text().isEmpty()){
        ui->listaTypyKaroserii->currentItem()->setText(ui->typTypKaroserii->text() + " " +
                                                       ui->material->text() + " " +
                                                       QString::number(ui->masa->value()));
        Tabela_Karoseria.replace(ui->listaTypyKaroserii->currentRow(),
                                   new Karoseria(
                                     ui->typTypKaroserii->text(),
                                     ui->material->text(),
                                     ui->masa->value()));
        msgBox.setText("Zmodyfikowano karoserię.");
    }else{
        msgBox.setText("Proszę wybrać karoserię z listy po lewej.");
    }
    msgBox.exec();
}

