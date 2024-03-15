#include "crecznik.h"

cRecznik::cRecznik()
{}

cRecznik::cRecznik(unsigned long long int Lp, int Dostepna_Ilosc, int Ilosc_Na_Amazonie, QString Nazwa, QString Kategoria_Produktu,
                QString Producent, double Waga, QString Kolor, double Cena, double Vat, QString Material,
                float Dlugosc, float Szerokosc): cProdukt(Lp, Dostepna_Ilosc, Ilosc_Na_Amazonie, Nazwa, Kategoria_Produktu,
                Producent, Waga, Kolor, Cena, Vat), mMaterial(Material), mDlugosc(Dlugosc),
                mSzerokosc(Szerokosc)
{}

//cProdukt* cRecznik::Copy()
//{
//    cProdukt* ptr = new cRecznik(mLp, mDostepna_Ilosc, Ilosc_na_amazonie, mNazwa, mKategoria_Produktu, mProducent, mWaga,
//                                 mKolor, mCena, mVat, mMaterial, mDlugosc, mSzerokosc);
//    return ptr;
//}

void cRecznik::Info_Produkt(Ui::ProduktInfo* ui, ProduktInfo* Widget)
{
    cProdukt::Info_Produkt(ui, Widget);
    Widget->Material = std::make_shared<QLabel>("Material: " + mMaterial);
    Widget->Dlugosc = std::make_shared<QLabel>("Długość: " + QString::number(mDlugosc));
    Widget->Szerokosc = std::make_shared<QLabel>("Szerokość: " + QString::number(mSzerokosc));
    ui->verticalLayout_2->addWidget(Widget->Material.get());
    ui->verticalLayout_2->addWidget(Widget->Dlugosc.get());
    ui->verticalLayout_2->addWidget(Widget->Szerokosc.get());
}

//QString cRecznik::typ()
//{
//    return "Reczniki";
//}

void cRecznik::Edytowanie_Produktu(Ui::DodanieNowegoProduktu* ui, DodanieNowegoProduktu* Widget)
{
    cProdukt::Edytowanie_Produktu(ui, Widget);
    Widget->Material = std::make_shared<QLabel>("Material: ");
    Widget->Dlugosc = std::make_shared<QLabel>("Dlugość: ");
    Widget->Szerokosc = std::make_shared<QLabel>("Szerokość: ");
    Widget->MaterialEdit = std::make_shared<QLineEdit>(mMaterial);
    Widget->DlugoscEdit = std::make_shared<QLineEdit>(QString::number(mDlugosc));
    Widget->SzerokoscEdit = std::make_shared<QLineEdit>(QString::number(mSzerokosc));
    ui->formLayout->addRow(Widget->Material.get(), Widget->MaterialEdit.get());
    ui->formLayout->addRow(Widget->Dlugosc.get(), Widget->DlugoscEdit.get());
    ui->formLayout->addRow(Widget->Szerokosc.get(), Widget->SzerokoscEdit.get());
    Widget->index_var = 6;
    ui->TypProduktu->setCurrentIndex(6);
}

void cRecznik::Zapis_Binarny(std::fstream& plik)
{
    int typ = 8;
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
    plik << mMaterial;
    plik << mDlugosc;
    plik << mSzerokosc;
}

void cRecznik::Odczyt_Binarny(std::fstream& plik)
{
    cProdukt::Odczyt_Binarny(plik);
    plik >> mMaterial;
    plik >> mDlugosc;
    plik >> mSzerokosc;
}
//cRecznik::~cRecznik()
//{}
