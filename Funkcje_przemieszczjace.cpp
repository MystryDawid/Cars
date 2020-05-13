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
/// koniec idz do
