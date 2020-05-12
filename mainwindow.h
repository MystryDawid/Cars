#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_dodajPracownika_clicked();

    void on_usunPracownika_clicked();

    void on_test_clicked();

    void on_goToPracownikForm_clicked();

    void on_goToWybierzAuto_clicked();

    void on_goToDodajCzesci_clicked();

    void on_goToStworzAuto_clicked();

    void on_wroc_clicked();

    void on_wroc_2_clicked();

    void on_wroc_3_clicked();

    void on_wroc_4_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
