#include "ctasmy.h"
#include "mainwindow.h"

cTasmy::cTasmy()
{}

cTasmy::cTasmy(unsigned long long int Lp, int Dostepna_Ilosc, int Ilosc_Na_Amazonie, QString Nazwa, QString Kategoria_Produktu,
               QString Producent, double Waga, QString Kolor, double Cena, double Vat, double Dlugosc,
               double Szerokosc, double Grubosc, QString Funkcja): cProdukt(Lp, Dostepna_Ilosc, Ilosc_Na_Amazonie, Nazwa,
               Kategoria_Produktu, Producent, Waga, Kolor, Cena, Vat), mDlugosc(Dlugosc),
               mSzerokosc(Szerokosc), mGrubosc(Grubosc), mFunkcja(Funkcja)
{}

//cProdukt* cTasmy::Copy()
//{
//    cProdukt* ptr = new cTasmy(mLp, mDostepna_Ilosc, Ilosc_na_amazonie, mNazwa, mKategoria_Produktu, mProducent, mWaga,
//                               mKolor, mCena, mVat, mDlugosc, mSzerokosc, mGrubosc, mFunkcja);
//    return ptr;
//}

void cTasmy::Info_Produkt(Ui::ProduktInfo* ui, ProduktInfo* Widget)
{
    cProdukt::Info_Produkt(ui, Widget);
    Widget->Dlugosc = std::make_shared<QLabel>();
    Widget->Szerokosc = std::make_shared<QLabel>();
    Widget->Grubosc = std::make_shared<QLabel>();
    Widget->Funkcja = std::make_shared<QLabel>();
    Widget->Dlugosc->setText("Dlugość: " + QString::number(mDlugosc));
    Widget->Szerokosc->setText("Szerokość: " + QString::number(mSzerokosc));
    Widget->Grubosc->setText("Grubość: " + QString::number(mGrubosc));
    Widget->Funkcja->setText("Funkcja: " + mFunkcja);
    ui->verticalLayout_2->addWidget(Widget->Dlugosc.get());
    ui->verticalLayout_2->addWidget(Widget->Szerokosc.get());
    ui->verticalLayout_2->addWidget(Widget->Grubosc.get());
    ui->verticalLayout_2->addWidget(Widget->Funkcja.get());
}

//QString cTasmy::typ()
//{
//    return "Tasmy";
//}

void cTasmy::Edytowanie_Produktu(Ui::DodanieNowegoProduktu* ui, DodanieNowegoProduktu* Widget)
{
    cProdukt::Edytowanie_Produktu(ui, Widget);
    Widget->Dlugosc = std::make_shared<QLabel>("Długość: ");
    Widget->Szerokosc = std::make_shared<QLabel>("Szerokość: ");
    Widget->Grubosc = std::make_shared<QLabel>("Grubość: ");
    Widget->Funkcja = std::make_shared<QLabel>("Funkcja: ");
    Widget->DlugoscEdit = std::make_shared<QLineEdit>(QString::number(mDlugosc));
    Widget->SzerokoscEdit = std::make_shared<QLineEdit>(QString::number(mSzerokosc));
    Widget->GruboscEdit = std::make_shared<QLineEdit>(QString::number(mGrubosc));
    Widget->FunkcjaEdit = std::make_shared<QLineEdit>(mFunkcja);
    ui->formLayout->addRow(Widget->Dlugosc.get(), Widget->DlugoscEdit.get());
    ui->formLayout->addRow(Widget->Szerokosc.get(), Widget->SzerokoscEdit.get());
    ui->formLayout->addRow(Widget->Grubosc.get(), Widget->GruboscEdit.get());
    ui->formLayout->addRow(Widget->Funkcja.get(), Widget->FunkcjaEdit.get());
    Widget->index_var = 0;
    ui->TypProduktu->setCurrentIndex(0);
}

void cTasmy::Zapis_Binarny(std::fstream& plik)
{
    int typ = 2;
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
    plik << mDlugosc;
    plik << mSzerokosc;
    plik << mGrubosc;
    plik << mFunkcja;
}

void cTasmy::Odczyt_Binarny(std::fstream& plik)
{
    cProdukt::Odczyt_Binarny(plik);
    plik >> mDlugosc;
    plik >> mSzerokosc;
    plik >> mGrubosc;
    plik >> mFunkcja;
}
//cTasmy::~cTasmy()
//{}
