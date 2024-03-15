#include "cprodukt.h"
//#include "ui_produktinfo.h"
#include "mainwindow.h"
#include <fstream>

cProdukt::cProdukt()
{}

cProdukt::cProdukt(unsigned long long int Lp, int Dostepna_Ilosc, int Ilosc_Na_Amazonie, QString Nazwa, QString Kategoria_Produktu,
         QString Producent, double Waga, QString Kolor, double Cena, double Vat) : mLp(Lp),
        mDostepna_Ilosc(Dostepna_Ilosc), mNazwa(Nazwa), mKategoria_Produktu(Kategoria_Produktu),
    mProducent(Producent), mWaga(Waga), mKolor(Kolor), mCena(Cena), mVat(Vat), Ilosc_na_amazonie(Ilosc_Na_Amazonie)
{}


QString cProdukt::Return_Name()
{
    return mNazwa;
}

unsigned long long int cProdukt::Return_LP()
{
    return mLp;
}

//cProdukt* cProdukt::Copy()
//{
//    cProdukt* ptr = new cProdukt(mLp, mDostepna_Ilosc, Ilosc_na_amazonie, mNazwa, mKategoria_Produktu, mProducent, mWaga,
//                                 mKolor, mCena, mVat);
//    return ptr;
//}

void cProdukt::Info_Produkt(Ui::ProduktInfo* ui, ProduktInfo* Widget)
{
    ui->LiczbaPodatkowaLabel->setText(ui->LiczbaPodatkowaLabel->text() + QString::number(mLp));
    ui->NazwaLabel->setText(ui->NazwaLabel->text() + mNazwa);
    //ui->DostepnaIloscLabel = ui->DostepnaIloscLabel + QString::number(mDostepna_Ilosc);
    //*(ui->DostepnaIloscLabel) = *(ui->DostepnaIloscLabel) + QString::number(mDostepna_Ilosc);
    ui->DostepnaIloscLabel + QString::number(mDostepna_Ilosc);
    ui->IloscNaAmazonieLabel + QString::number(Ilosc_na_amazonie);
    ui->KategoriaProduktuLabel + mKategoria_Produktu;
    ui->ProducentLabel + mProducent;
    ui->WagaLabel + QString::number(mWaga);
    ui->KolorLabel + mKolor;
    ui->CenaLabel + QString::number(mCena);
    ui->VATLabel + QString::number(mVat);
}

//QString cProdukt::typ()
//{
//    return "Produkt";
//}

void cProdukt::Edytowanie_Produktu(Ui::DodanieNowegoProduktu* ui, DodanieNowegoProduktu* Widget)
{
    ui->TypProduktu->setCurrentIndex(8);
    ui->EditLP->setText(QString::number(mLp));
    ui->EditNazwa->setText(mNazwa);
    ui->lineEditDostepnaIlosc->setText(QString::number(mDostepna_Ilosc));
    ui->lineEditIloscnaamazonie->setText(QString::number(Ilosc_na_amazonie));
    ui->lineEditKategoria->setText(mKategoria_Produktu);
    ui->lineEditProducent->setText(mProducent);
    ui->lineEditWaga->setText(QString::number(mWaga));
    ui->lineEditKolor->setText(mKolor);
    ui->lineEditCena->setText(QString::number(mCena));
    ui->lineEditVat->setText(QString::number(mVat));
    Widget->index_var = 8;
}

int cProdukt::Return_Ilosc()
{
    return mDostepna_Ilosc;
}

void cProdukt::Zmnien_ilosc(int Ilosc)
{
    mDostepna_Ilosc = Ilosc;
}

int cProdukt::Return_Ilosc_Amazon()
{
    return Ilosc_na_amazonie;
}

void cProdukt::Zmien_Ilosc_Amazon(int Ilosc)
{
    Ilosc_na_amazonie = Ilosc;
}

QString cProdukt::Return_Typ()
{
    return mKategoria_Produktu;
}

void cProdukt::Dodac_odjac_Ilosc(int Ilosc)
{
    mDostepna_Ilosc+=Ilosc;
}

void cProdukt::Dodac_Ilosc_Na_Amazonie(int Ilosc)
{
    Ilosc_na_amazonie += Ilosc;
}

double cProdukt::Return_Cena()
{
    return mCena;
}

void cProdukt::Zapis_Binarny(std::fstream& plik)
{
    int typ = 1;
    plik << typ;
    plik << mLp;
    plik << mDostepna_Ilosc;
    plik << Ilosc_na_amazonie;
    plik << mNazwa;
    plik << mKategoria_Produktu;
    plik << mProducent;
    plik << mWaga;
    plik << mKolor;
    plik << mCena;
    plik << mVat;
}

void cProdukt::Odczyt_Binarny(std::fstream& plik)
{
    plik >> mLp;
    plik >> mDostepna_Ilosc;
    plik >> Ilosc_na_amazonie;
    plik >> mNazwa;
    plik >> mKategoria_Produktu;
    plik >> mProducent;
    plik >> mWaga;
    plik >> mKolor;
    plik >> mCena;
    plik >> mVat;
}
//cProdukt::~cProdukt()
//{}
