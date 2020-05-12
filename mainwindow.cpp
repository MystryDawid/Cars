#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Classes/Pracownik/Pracownik.h"
#include "QString"
#include <iostream>
#include "QFile"

QVector<Pracownik> tab;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);



    Pracownik a1 = new Pracownik("Adam","o",1);

    tab.append(Pracownik("Adam","o",1));
    tab.append(Pracownik("Adamm","o",1));
    tab.append(Pracownik("Adammm","o",1));
    tab.append(Pracownik("Adammmm","o",1));
    tab.append(Pracownik("Adammmmm","o",1));
    tab.append(Pracownik("Adammmmmm","o",1));
    tab.append(Pracownik("Ada","o",1));


    a1.zapis();




    tab.append(a1);

    int liczba_pracowikow = tab.length();

    a1.wszyscy();

    for (int i = 0;i < liczba_pracowikow; i++) {
        ui->comboBox->addItem(tab.at(i).imie);
    }


}


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_dodajPracownika_clicked()
{
    tab.append(Pracownik(ui->imie->text(),ui->nazwisko->text(),ui->staz->value()));
    ui->comboBox->addItem(tab.last().imie);
}

void MainWindow::on_usunPracownika_clicked()
{
    tab.remove(ui->comboBox->currentIndex());
    ui->comboBox->removeItem(ui->comboBox->currentIndex());
}

void MainWindow::on_test_clicked()
{
    for (int i = 0;i < tab.length(); i++) {
        std::cout<<tab.at(i).imie.toUtf8().toStdString()<<std::endl;
    }
}

void MainWindow::on_wroc_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_wroc_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_wroc_3_clicked()
{

}

void MainWindow::on_wroc_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_goToPracownikForm_clicked()
{
     ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_goToWybierzAuto_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_goToDodajCzesci_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_goToStworzAuto_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}





