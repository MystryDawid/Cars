#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "naped.h"
#include "QFile"
#include "QMessageBox"
#include "iostream"


using namespace std;

QVector<Naped> Tabela_Naped;

Naped::Naped(QString naped,int przod, int tyl, Pracownik p){
    this->naped = naped;
    this->przod = przod;
    this->tyl = tyl;
    this->p = new Pracownik(p);
}

Naped::Naped(){
    this->naped = "Bob";
    this->przod = 100;
    this->tyl = 100;
    this->p = new Pracownik();
}

Naped::Naped(Naped *n){
    this->naped = n->naped;
    this->przod = n->przod;
    this->tyl = n->tyl;
    this->p = n->p;
}

QDataStream &operator <<(QDataStream &out, Naped const &n){
    out << n.naped << n.przod << n.tyl << n.p;
    return out;
}

QDataStream &operator >>(QDataStream &in, Naped &n){
    in >> n.naped >> n.przod >> n.tyl >> n.p;
    return in;
}

bool zapisz_naped(){
    if(Tabela_Naped.isEmpty()) return 0;
    QString plik = "./napedy.dat";
    QFile file(plik);
    file.open(QIODevice::WriteOnly);
    QDataStream out(&file);
    for(int i = 0; i < Tabela_Naped.length(); i++){
         out << Tabela_Naped.at(i);
    }

    return true;

};

bool wczytaj_naped(){
    QString plik = "./napedy.dat";
    QFile file(plik);
    file.open(QIODevice::ReadOnly);
    QDataStream in(&file);
    Tabela_Naped.clear();
    while(!in.atEnd()){
       Naped n;
       in >> n;
       Tabela_Naped.append(n);
    }
    return true;
};

void MainWindow::on_dodajNaped_clicked()
{
    QMessageBox msgBox;

    if(!ui->napedNaped->text().isEmpty() &&
            ui->napedPracownicy->count() > 0){

        QString text = ui->napedNaped->text();
        int przod = ui->wartoscPrzod->value();
        int tyl = ui->wartoscTyl->value();
        QString imie = Tabela_Naped.last().p.imie;

        Tabela_Naped.append(Naped(text,
                                  przod,
                                  tyl,
                                  Tabela_Pracownikow.at(ui->napedPracownicy->currentIndex())));

        ui->listaNaped->addItem(text + " " +
                                QString::number(przod) + " " +
                                QString::number(tyl) + " " +
                                imie);

        ui->AutaNaped->addItem(text + " " +
                                QString::number(przod) + " " +
                                QString::number(tyl) + " " +
                                imie);

        msgBox.setText("Dodano napęd.");
    }else{
        msgBox.setText("Proszę wypełnić wszystkie pola.");
    }
    msgBox.exec();
}

void MainWindow::on_usunNaped_clicked()
{
    QMessageBox msgBox;
    int row =  ui->listaNaped->currentRow();

    if(row != -1){

        Tabela_Naped.remove(row);
        ui->listaNaped->takeItem(row);
        ui->AutaNaped->removeItem(row);

        msgBox.setText("Usunięto napęd.");
    }else{
        msgBox.setText("Usunięcie napędu nie powiodło się.");
    }
    msgBox.exec();
}

void MainWindow::on_zapiszNaped_clicked()
{
    QMessageBox msgBox;
    if(zapisz_naped()){
        msgBox.setText("Zapisano napędy.");
    }else{
        msgBox.setText("Nie zapisano napędów.");
    }
    msgBox.exec();
}

void MainWindow::on_wczytajNaped_clicked()
{
    QMessageBox msgBox;

    if(wczytaj_naped()){

        ui->listaNaped->clear();

        for (int i = 0;i < Tabela_Naped.length(); i++) {

            QString naped = Tabela_Naped.at(i).naped;
            int przod = Tabela_Naped.at(i).przod;
            int tyl = Tabela_Naped.at(i).tyl;
            QString imie = Tabela_Naped.last().p.imie;

            ui->listaNaped->addItem(naped + " " +
                                    QString::number(przod) + " " +
                                    QString::number(tyl) + " " +
                                    imie);

            ui->AutaNaped->addItem(naped + " " +
                                    QString::number(przod) + " " +
                                    QString::number(tyl) + " " +
                                    imie);
        }
        msgBox.setText("Wczytano napędy.");
    }else{
        msgBox.setText("Nie wczytano napędów.");
    }
    msgBox.exec();
}

void MainWindow::on_listaNaped_clicked()
{
    Naped tmp = Tabela_Naped.at(ui->listaNaped->currentIndex().row());
    ui->napedNaped->setText(tmp.naped);
    ui->wartoscPrzod->setValue(tmp.przod);
    ui->wartoscTyl->setValue(tmp.tyl);
}

void MainWindow::on_modyfikujNaped_clicked()
{
    QMessageBox msgBox;

    if(!ui->napedNaped->text().isEmpty()){

        int przod = ui->wartoscPrzod->value();
        int tyl = ui->wartoscTyl->value();
        QString naped = ui->napedNaped->text();
        QString napedPracownik = ui->napedPracownicy->currentText();

        ui->listaNaped->currentItem()->setText(naped + " " +
                                               QString::number(przod) + " " +
                                               QString::number(tyl) + " " +
                                               napedPracownik);

        ui->AutaNaped->setItemText(ui->listaPracownikow->currentRow(),naped + " " +
                                               QString::number(przod) + " " +
                                               QString::number(tyl) + " " +
                                               napedPracownik);

        Tabela_Naped.replace(ui->listaNaped->currentRow(),
                                   Naped(naped,
                                         przod,
                                         tyl,
                                         Tabela_Pracownikow.at(ui->napedPracownicy->currentIndex())));

        msgBox.setText("Zmodyfikowano pracownika.");
    }else{
        msgBox.setText("Proszę wybrać pracowanika z listy po lewej.");
    }
    msgBox.exec();
}


void MainWindow::on_wartoscPrzod_valueChanged(int value)
{
    ui->lcdNumberPrzod->display(value);

}

void MainWindow::on_wartoscTyl_valueChanged(int value)
{
    ui->lcdNumberTyl->display(value);
}










