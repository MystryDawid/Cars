#include "mainwindow.h"
#include "ui_mainwindow.h"

/// wróć
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
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_wroc_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_wroc_5_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_wroc_6_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_wroc_7_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}
///koniec wróć


/// idz do
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

void MainWindow::on_typy_karoserii_button_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}

void MainWindow::on_naped_button_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);
}

void MainWindow::on_pushButton_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(7);
}

/// koniec idz do
