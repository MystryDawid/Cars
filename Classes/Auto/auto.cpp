#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "auto.h"
#include "QFile"
#include "QMessageBox"
#include "iostream"

QVector<Auto> Tabela_Aut;

Auto::Auto(){
    this->karoseria = new Karoseria();
    this->kola = new Kola();
    this->naped = new Naped();
    this->silnik = new Silnik();
    this->pracownik = new Pracownik();
}

Auto::Auto(Auto *a){
    this->karoseria = a->karoseria;
    this->kola = a->kola;
    this->naped = a->naped;
    this->silnik = a->silnik;
    this->pracownik = a->pracownik;

}

Auto::Auto(Karoseria k, Kola kola, Naped n, Pracownik p, Silnik s){
    this->karoseria = new Karoseria(k);
    this->kola = new Kola(kola);
    this->naped = new Naped(n);
    this->silnik = new Silnik(s);
    this->pracownik = new Pracownik(p);
}

QDataStream &operator <<(QDataStream &out, Auto const &a){
    out << a.karoseria << a.kola << a.naped << a.silnik << a.pracownik;
    return out;
}

QDataStream &operator >>(QDataStream &in, Auto &a){
    in >> a.karoseria >> a.kola >> a.naped >> a.silnik >> a.pracownik;
    return in;
}

bool zapisz_auta(){
    if(Tabela_Aut.isEmpty()) return 0;
    QString plik = "./auta.dat";
    QFile file(plik);
    file.open(QIODevice::WriteOnly);
    QDataStream out(&file);
    for(int i = 0; i < Tabela_Aut.length(); i++){
         out << Tabela_Aut.at(i);
    }
    file.close();
    return true;

};

bool wczytaj_auta(){
    QString plik = "./auta.dat";
    QFile file(plik);
    file.open(QIODevice::ReadOnly);
    QDataStream in(&file);
    Tabela_Aut.clear();
    while(!in.atEnd()){
       Auto a = new Auto();
       in >> a;
       Tabela_Aut.append(a);
    }
    file.close();
    return true;
};

void MainWindow::on_dodajAuto_clicked(){
    QMessageBox msgBox;
    if(ui->AutaKaroseria->count() > 0 &&
            ui->AutaKola->count() > 0 &&
            ui->AutaNaped->count() > 0 &&
            ui->AutaSilnik->count() > 0 &&
            ui->autoPracownicy->count() > 0){

        Tabela_Aut.append(new Auto(
                              Tabela_Karoseria.at(ui->AutaKaroseria->currentIndex()),
                              Tabela_Kola.at(ui->AutaKola->currentIndex()),
                              Tabela_Naped.at(ui->AutaNaped->currentIndex()),
                              Tabela_Pracownikow.at(ui->autoPracownicy->currentIndex()),
                              Tabela_Silnik.at(ui->AutaSilnik->currentIndex())
                                    ));

        ui->listaAut->addItem(Tabela_Aut.last().karoseria.karoseriaTyp + " " +
                              QString::number(Tabela_Aut.last().naped.tyl) + " " +
                              Tabela_Aut.last().silnik.typSilnika + " " +
                              QString::number(Tabela_Aut.last().kola.wielkosc) + " " +
                              Tabela_Aut.last().pracownik.imie);


        msgBox.setText("Dodano Samochód.");
    }else{
        msgBox.setText("Proszę wypełnić wszystkie pola.");
    }
    msgBox.exec();
}

void MainWindow::on_usunAuto_clicked(){
    QMessageBox msgBox;
    int row = ui->listaAut->currentRow();
    if(row != -1){
        Tabela_Aut.remove(row);
        ui->listaAut->takeItem(row);
        msgBox.setText("Usunięto Samochód.");
    }else{
        msgBox.setText("Usunięcie samochodu nie powiodło się.");
    }
    msgBox.exec();
}

void MainWindow::on_zapiszAuto_clicked(){
    QMessageBox msgBox;
    if(zapisz_auta()){
        msgBox.setText("Zapisano samochody.");
    }else{
        msgBox.setText("Nie zapisano samochodów.");
    }
    msgBox.exec();
}

void MainWindow::on_wczytajAuto_clicked(){
    QMessageBox msgBox;
    if(wczytaj_auta()){
        ui->listaAut->clear();
        for (int i = 0;i < Tabela_Aut.length(); i++) {
            ui->listaAut->addItem(Tabela_Aut.at(i).karoseria.karoseriaTyp + " " +
                                  QString::number(Tabela_Aut.at(i).naped.tyl) + " " +
                                  Tabela_Aut.at(i).silnik.typSilnika + " " +
                                  QString::number(Tabela_Aut.at(i).kola.wielkosc) + " " +
                                  Tabela_Aut.at(i).pracownik.imie);
        }
        msgBox.setText("Wczytano samochody.");
    }else{
        msgBox.setText("Nie wczytano samochodów.");
    }
    msgBox.exec();
}

void MainWindow::on_modyfikujAuto_clicked(){
    QMessageBox msgBox;
    if(ui->AutaKaroseria->count() > 0 &&
            ui->AutaKola->count() > 0 &&
            ui->AutaNaped->count() > 0 &&
            ui->AutaSilnik->count() > 0 &&
            ui->autoPracownicy->count() > 0 &&
            ui->listaAut->currentRow() != -1){

        Tabela_Aut.replace(ui->listaAut->currentRow(),new Auto(
                              Tabela_Karoseria.at(ui->AutaKaroseria->currentIndex()),
                              Tabela_Kola.at(ui->AutaKola->currentIndex()),
                              Tabela_Naped.at(ui->AutaNaped->currentIndex()),
                              Tabela_Pracownikow.at(ui->autoPracownicy->currentIndex()),
                              Tabela_Silnik.at(ui->AutaSilnik->currentIndex())
                                    ));

        ui->listaAut->currentItem()->setText(
                    Tabela_Aut.at(ui->listaAut->currentRow()).karoseria.karoseriaTyp + " " +
                    QString::number(Tabela_Aut.at(ui->listaAut->currentRow()).naped.tyl) + " " +
                    Tabela_Aut.at(ui->listaAut->currentRow()).silnik.typSilnika + " " +
                    QString::number(Tabela_Aut.at(ui->listaAut->currentRow()).kola.wielkosc) + " " +
                    Tabela_Aut.at(ui->listaAut->currentRow()).pracownik.imie);



        msgBox.setText("Zmodyfikowano sammochód.");
    }else{
        msgBox.setText("Proszę wybrać samochód z listy po lewej.");
    }
    msgBox.exec();
}
