#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "silnik.h"
#include "QFile"
#include "QMessageBox"
#include "iostream"

using namespace std;

QVector<Silnik> Tabela_Silnik;

Silnik::Silnik()
{
    this->mocSilnika = 0;
    this->typSilnika = "";
    this->p = new Pracownik();
}

Silnik::Silnik(QString typSilnika, int mocSilnika, Pracownik p)
{
    this->mocSilnika = mocSilnika;
    this->typSilnika = typSilnika;
    this->p = new Pracownik(p);
}

Silnik::Silnik(Silnik *s)
{
    this->mocSilnika = s->mocSilnika;
    this->typSilnika = s->typSilnika;
    this->p = s->p;
}

QDataStream &operator <<(QDataStream &out, Silnik const &s){
    out << s.mocSilnika << s.typSilnika << s.p;
    return out;
}

QDataStream &operator >>(QDataStream &in, Silnik &s){
    in >> s.mocSilnika >> s.typSilnika >> s.p;
    return in;
}

bool zapisz_silniki(){
    if(Tabela_Silnik.size() == 0) return 0;
    QString plik = "./silniki.dat";
    QFile file(plik);
    file.open(QIODevice::WriteOnly);
    QDataStream out(&file);
    for(int i = 0; i < Tabela_Silnik.length(); i++){
         out << Tabela_Silnik.at(i);
    }
    return true;
}

bool wczytaj_silniki(){
    QString plik = "./silniki.dat";
    QFile file(plik);
    file.open(QIODevice::ReadOnly);
    QDataStream in(&file);
    Tabela_Silnik.clear();
    while(!in.atEnd()){
       Silnik s;
       in >> s;
       Tabela_Silnik.append(s);
    }
    return true;
}

void MainWindow::on_dodajSilnik_clicked()
{
    QMessageBox msgBox;
    if(!ui->silnikTyp->text().isEmpty() &&
            !ui->silnikKonie->text().isEmpty() &&
            ui->napedPracownicy->count() > 0){

        QString silnik = ui->silnikTyp->text();
        int konie = ui->silnikKonie->value();

        Tabela_Silnik.append(Silnik(silnik,
                                  konie,
                                  Tabela_Pracownikow.at(ui->silnikPracownicy->currentIndex())));

        ui->listaSilnikow->addItem(silnik + " " +
                                QString::number(konie) + " " +
                                Tabela_Silnik.last().p.imie);

        ui->AutaSilnik->addItem(silnik + " " +
                                QString::number(konie) + " " +
                                Tabela_Silnik.last().p.imie);

        msgBox.setText("Dodano silnik.");
    }else{
        msgBox.setText("Proszę wypełnić wszystkie pola.");
    }
    msgBox.exec();
}

void MainWindow::on_usunSilnik_clicked()
{
    QMessageBox msgBox;
    int row =  ui->listaSilnikow->currentRow();
    if(row != -1){

        Tabela_Silnik.remove(row);
        ui->listaSilnikow->takeItem(row);
        ui->AutaSilnik->removeItem(row);

        msgBox.setText("Usunięto silnik.");
    }else{
        msgBox.setText("Usunięcie silnika nie powiodło się.");
    }
    msgBox.exec();
}

void MainWindow::on_zapiszSilniki_clicked()
{
    QMessageBox msgBox;
    if(zapisz_silniki()){
        msgBox.setText("Zapisano silniki.");
    }else{
        msgBox.setText("Nie zapisano silników.");
    }
    msgBox.exec();
}

void MainWindow::on_wczytajSilniki_clicked()
{
    QMessageBox msgBox;
    if(wczytaj_silniki()){

        ui->listaSilnikow->clear();

        for (int i = 0;i < Tabela_Silnik.length(); i++) {

            QString silnik = Tabela_Silnik.at(i).typSilnika;
            int moc = Tabela_Silnik.at(i).mocSilnika;
            QString imie = Tabela_Silnik.last().p.imie;

            ui->listaSilnikow->addItem(silnik + " " +
                                    QString::number(moc) + " " +
                                    imie);

            ui->AutaSilnik->addItem(silnik + " " +
                                    QString::number(moc) + " " +
                                    imie);
        }
        msgBox.setText("Wczytano silniki.");
    }else{
        msgBox.setText("Nie wczytano silników.");
    }
    msgBox.exec();
}

void MainWindow::on_modyfikujSilnik_clicked()
{
    QMessageBox msgBox;
    if(!ui->silnikTyp->text().isEmpty() && !ui->silnikKonie->text().isEmpty()){

        QString silnik = ui->silnikTyp->text();
        int moc = ui->silnikKonie->value();
        QString silnikPracownik = ui->silnikPracownicy->currentText();

        ui->listaSilnikow->currentItem()->setText(silnik + " " +
                                                  QString::number(moc) + " " +
                                                  silnikPracownik);

        ui->AutaSilnik->setItemText(ui->listaPracownikow->currentRow(),
                                    silnik + " " + QString::number(moc) + " " +
                                    silnikPracownik);

        Tabela_Silnik.replace(ui->listaSilnikow->currentRow(),
                                   Silnik(silnik,
                                          moc,
                                          Tabela_Pracownikow.at(ui->silnikPracownicy->currentIndex())));

        msgBox.setText("Zmodyfikowano silnik.");
    }else{
        msgBox.setText("Proszę wybrać silnik z listy po lewej.");
    }
    msgBox.exec();
}


void MainWindow::on_listaSilnikow_clicked()
{
    Silnik tmp = Tabela_Silnik.at(ui->listaSilnikow->currentIndex().row());
    ui->silnikTyp->setText(tmp.typSilnika);
    ui->silnikKonie->setValue(tmp.mocSilnika);
}



