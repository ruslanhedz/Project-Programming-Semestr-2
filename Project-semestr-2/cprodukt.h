#ifndef CPRODUKT_H
#define CPRODUKT_H
#include <QString>
#include <QDialog>
#include <QLabel>
#include "produktinfo.h"
#include "ui_produktinfo.h"
#include "produktinfo.h"
#include "ui_dodanienowegoproduktu.h"
#include <QLabel>
#include "dodanienowegoproduktu.h"
#include "mainwindow.h"
//#include "dodanienowegoproduktu.h"
//class DodanieNowegoProduktu;

class cProdukt
{
protected:
    unsigned long long int mLp;
    int mDostepna_Ilosc;
    int Ilosc_na_amazonie;
    QString mNazwa;
    QString mKategoria_Produktu;
    QString mProducent;
    double mWaga;
    QString mKolor;
    double mCena;
    double mVat;
public:
    cProdukt();
    cProdukt(unsigned long long int Lp, int Dostepna_Ilosc, int Ilosc_Na_Amazonie, QString Nazwa, QString Kategoria_Produktu,
             QString Producent, double Waga, QString Kolor, double Cena, double Vat);
    QString Return_Name();
    unsigned long long int Return_LP();
    int Return_Ilosc();
    int Return_Ilosc_Amazon();
    void Zmnien_ilosc(int);
    void Zmien_Ilosc_Amazon(int);
    QString Return_Typ();
    void Dodac_odjac_Ilosc(int Ilosc);
    void Dodac_Ilosc_Na_Amazonie(int Ilosc);
    double Return_Cena();
//    virtual cProdukt* Copy();
    virtual void Info_Produkt(Ui::ProduktInfo* ui, ProduktInfo* Widget);
    virtual void Edytowanie_Produktu(Ui::DodanieNowegoProduktu* ui, DodanieNowegoProduktu* Widget);
    virtual void Zapis_Binarny(std::fstream& plik);
    virtual void Odczyt_Binarny(std::fstream& plik);
    //    virtual QString typ();
    //    virtual ~cProdukt();
    //void Edytowanie_Produktu(Ui::DodanieNowegoProduktu* ui);

};

#endif // CPRODUKT_H
