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

    void on_goToPracownikForm_clicked();

    void on_goToWybierzAuto_clicked();

    void on_goToDodajCzesci_clicked();

    void on_goToStworzAuto_clicked();

    void on_wroc_clicked();

    void on_wroc_2_clicked();

    void on_wroc_3_clicked();

    void on_wroc_4_clicked();

    void on_zapisz_zmiany_clicked();

    void on_wczytaj_pracownikow_clicked();

    void on_listaPracownikow_clicked();

    void on_modyfikuj_clicked();

    void on_typy_karoserii_button_clicked();

    void on_wroc_5_clicked();

    void on_dodajTypKaroserii_clicked();

    void on_usunTypKaroserii_clicked();

    void on_wczytajTypyKaroserii_clicked();

    void on_zapiszZamianyKaroserii_clicked();

    void on_listaTypyKaroserii_clicked();

    void on_modyfikujTypKaroserii_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
