#include "karoseria.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMessageBox"
#include "QFile"

QVector<Karoseria> Tabela_Karoseria;

Karoseria::Karoseria(){
    this->karoseriaTyp = "";
    this->karoseriaMaterial = "";
    this->masa = 0.0;
    this->p = new Pracownik();
}

Karoseria::Karoseria
(QString typ, QString material, float masa, Pracownik p){
    this->karoseriaTyp = typ;
    this->karoseriaMaterial = material;
    this->masa = masa;
    this->p = new Pracownik(p);
}

Karoseria::Karoseria(Karoseria *k){
    this->karoseriaTyp = k->karoseriaTyp;
    this->masa = k->masa;
    this->karoseriaMaterial = k->karoseriaMaterial;
    this->p = k->p;
}

QDataStream &operator <<(QDataStream &out, Karoseria const &k){
    out << k.karoseriaTyp << k.karoseriaMaterial << k.masa<< k.p;
    return out;
}

QDataStream &operator >>(QDataStream &in, Karoseria &k){
    in >> k.karoseriaTyp >> k.karoseriaMaterial >> k.masa >> k.p;
    return in;
}

bool zapisz_typy_karoserii(){
    if(Tabela_Karoseria.isEmpty()) return 0;
    QString plik = "./karoserie.dat";
    QFile file(plik);
    file.open(QIODevice::WriteOnly);
    QDataStream out(&file);
    for(int i = 0; i < Tabela_Karoseria.length(); i++){
         out << Tabela_Karoseria.at(i);
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
       in >> k;
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
            !ui->masa->text().isEmpty() &&
            ui->karoseriePracownicy->count() > 0){
        Tabela_Karoseria.append(Karoseria(
                                    ui->typTypKaroserii->text(),
                                    ui->material->text(),
                                    ui->masa->value(),
                                    Tabela_Pracownikow.at(ui->karoseriePracownicy->currentIndex())
                                    ));
        ui->listaTypyKaroserii->addItem(Tabela_Karoseria.last().karoseriaTyp + " " +
                                        Tabela_Karoseria.last().karoseriaMaterial + " " +
                                        QString::number(Tabela_Karoseria.last().masa) + " " +
                                        Tabela_Karoseria.last().p.imie);
        ui->AutaKaroseria->addItem(Tabela_Karoseria.last().karoseriaTyp + " " +
                                        Tabela_Karoseria.last().karoseriaMaterial + " " +
                                        QString::number(Tabela_Karoseria.last().masa) + " " +
                                        Tabela_Karoseria.last().p.imie);

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
        ui->AutaKaroseria->removeItem(row);
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
        ui->AutaKaroseria->clear();
        for (int i = 0;i < Tabela_Karoseria.length(); i++) {
            ui->listaTypyKaroserii->addItem(Tabela_Karoseria.at(i).karoseriaTyp + " " +
                                            Tabela_Karoseria.at(i).karoseriaMaterial + " " +
                                            QString::number(Tabela_Karoseria.at(i).masa) + " " +
                                            Tabela_Karoseria.at(i).p.imie);

            ui->AutaKaroseria->addItem(Tabela_Karoseria.at(i).karoseriaTyp + " " +
                                            Tabela_Karoseria.at(i).karoseriaMaterial + " " +
                                            QString::number(Tabela_Karoseria.at(i).masa) + " " +
                                            Tabela_Karoseria.at(i).p.imie);
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
    ui->typTypKaroserii->setText(tmp.karoseriaTyp);
    ui->masa->setValue(tmp.masa);
    ui->material->setText(tmp.karoseriaMaterial);
}

void MainWindow::on_modyfikujTypKaroserii_clicked()
{
    QMessageBox msgBox;
    if(!ui->typTypKaroserii->text().isEmpty() &&
            !ui->material->text().isEmpty() &&
            !ui->masa->text().isEmpty()){
        ui->listaTypyKaroserii->currentItem()->setText(ui->typTypKaroserii->text() + " " +
                                                       ui->material->text() + " " +
                                                       QString::number(ui->masa->value()) + " " +
                                                       ui->karoseriePracownicy->currentText());
        ui->AutaKaroseria->setItemText(ui->listaPracownikow->currentRow(), ui->typTypKaroserii->text() + " " +
                                                       ui->material->text() + " " +
                                                       QString::number(ui->masa->value()) + " " +
                                                       ui->karoseriePracownicy->currentText());

        Tabela_Karoseria.replace(ui->listaTypyKaroserii->currentRow(),
                                   new Karoseria(
                                     ui->typTypKaroserii->text(),
                                     ui->material->text(),
                                     ui->masa->value(),
                                     Tabela_Pracownikow.at(ui->karoseriePracownicy->currentIndex())));
        msgBox.setText("Zmodyfikowano karoserię.");
    }else{
        msgBox.setText("Proszę wybrać karoserię z listy po lewej.");
    }
    msgBox.exec();
}

