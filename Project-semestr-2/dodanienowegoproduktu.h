#ifndef DODANIENOWEGOPRODUKTU_H
#define DODANIENOWEGOPRODUKTU_H

#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QComboBox>
#include <QObject>
#include <QMessageBox>
//#include "myapplication.h"
//#include "mainwindow.h"
class cBaza;
class cProdukt;
class cBluza;
class cHDD;
class cKolanka;
class cKoszulka;
class cRecznik;
class cSluchawki;
class cSSD;
class cTasmy;
//#include "cbaza.h"
//#include "cprodukt.h"
//#include "ctasmy.h"
//#include "cbluza.h"
//#include "chdd.h"
//#include "ckolanka.h"
//#include "csluchawki.h"
//#include "ckoszulka.h"
//#include "crecznik.h"
//#include "cssd.h"
#include "ui_dodanienowegoproduktu.h"

class cBaza;

namespace Ui {
class DodanieNowegoProduktu;
}

class DodanieNowegoProduktu : public QDialog
{
    Q_OBJECT

public:
    explicit DodanieNowegoProduktu(QWidget *parent = nullptr, cBaza* aBaza = nullptr, cProdukt* Produkt = nullptr);
    //explicit DodanieNowegoProduktu(QWidget *parent = nullptr, cBaza* aBaza = nullptr, cProdukt* Produkt = nullptr);
    ~DodanieNowegoProduktu();
    friend cProdukt;
    friend cTasmy;
    friend cBluza;
    friend cHDD;
    friend cKolanka;
    friend cKoszulka;
    friend cRecznik;
    friend cSluchawki;
    friend cSSD;


private slots:
    void on_TypProduktu_currentIndexChanged(int index);

    void on_pushButton_clicked();

    void on_ZgenerujLP_clicked();

private:
    Ui::DodanieNowegoProduktu *ui;
    cBaza* BazaProdukty;
    cProdukt* mProdukt;
    std::shared_ptr<QLabel> Dlugosc;
    std::shared_ptr<QLabel> Szerokosc;
    std::shared_ptr<QLabel> Grubosc;
    std::shared_ptr<QLabel> Funkcja;
    std::shared_ptr<QLabel> Rozmiar;
    std::shared_ptr<QLabel> Material;
    std::shared_ptr<QLabel> Pojemnosc;
    std::shared_ptr<QLabel> Szybkosc_Odczytu;
    std::shared_ptr<QLabel> Szybkosc_Zapisu;
    std::shared_ptr<QLabel> Typ_SATA;
    std::shared_ptr<QLabel> Format_Dysku;
    std::shared_ptr<QLabel> Srednica;
    std::shared_ptr<QLabel> Kat_Nachylenia;
    std::shared_ptr<QLabel> Typ_Zlacza;
    std::shared_ptr<QLabel> Ilosc_Godzin_Pracy;
    std::shared_ptr<QLineEdit> DlugoscEdit;
    std::shared_ptr<QLineEdit> SzerokoscEdit;
    std::shared_ptr<QLineEdit> GruboscEdit;
    std::shared_ptr<QLineEdit> FunkcjaEdit;
    std::shared_ptr<QLineEdit> RozmiarEdit;
    std::shared_ptr<QLineEdit> MaterialEdit;
    std::shared_ptr<QLineEdit> PojemnoscEdit;
    std::shared_ptr<QLineEdit> Szybkosc_OdczytuEdit;
    std::shared_ptr<QLineEdit> Szybkosc_ZapisuEdit;
    std::shared_ptr<QLineEdit> Typ_SATAEdit;
    std::shared_ptr<QLineEdit> Format_DyskuEdit;
    std::shared_ptr<QLineEdit> SrednicaEdit;
    std::shared_ptr<QLineEdit> Kat_NachyleniaEdit;
    std::shared_ptr<QComboBox> Typ_ZlaczaBox;
    std::shared_ptr<QLineEdit> Ilosc_Godzin_PracyEdit;
//    QLabel* Pojemnosc;
//    QLabel* Szybkosc_Odczytu;
//    QLabel* Szybkosc_Zapisu;
//    QLabel* Typ_SATA;
//    QLabel* Format_Dysku;
//    QLabel* Srednica;
//    QLabel* Kat_Nachylenia;
//    QLabel* Typ_Zlacza;
//    QLabel* Ilosc_Godzin_Pracy;
//    QLineEdit* DlugoscEdit;
//    QLineEdit* SzerokoscEdit;
//    QLineEdit* GruboscEdit;
//    QLineEdit* FunkcjaEdit;
//    QLineEdit* RozmiarEdit;
//    QLineEdit* MaterialEdit;
//    QLineEdit* PojemnoscEdit;
//    QLineEdit* Szybkosc_OdczytuEdit;
//    QLineEdit* Szybkosc_ZapisuEdit;
//    QLineEdit* Typ_SATAEdit;
//    QLineEdit* Format_DyskuEdit;
//    QLineEdit* SrednicaEdit;
//    QLineEdit* Kat_NachyleniaEdit;
//    QComboBox* Typ_ZlaczaBox;
//    QLineEdit* Ilosc_Godzin_PracyEdit;
    short int index_var;

};

#endif // DODANIENOWEGOPRODUKTU_H
