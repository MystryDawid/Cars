#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Classes/Pracownik/pracownik.h"
#include "QString"
#include <iostream>
#include "QFile"




MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}




