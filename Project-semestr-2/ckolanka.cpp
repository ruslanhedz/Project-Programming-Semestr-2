#include "ckolanka.h"

cKolanka::cKolanka()
{}

cKolanka::cKolanka(unsigned long long int Lp, int Dostepna_Ilosc, int Ilosc_Na_Amazonie, QString Nazwa, QString Kategoria_Produktu,
         QString Producent, double Waga, QString Kolor, double Cena, double Vat, QString Material,
         double Srednica, double Kat_Nachylenia, double Dlugosc): cProdukt(Lp, Dostepna_Ilosc, Ilosc_Na_Amazonie, Nazwa,
         Kategoria_Produktu, Producent, Waga, Kolor, Cena, Vat), mMaterial(Material), mSrednica(Srednica),
         mKat_Nachylenia(Kat_Nachylenia), mDlugosc(Dlugosc)
{}

//cProdukt* cKolanka::Copy()
//{
//    cProdukt* ptr = new cKolanka(mLp, mDostepna_Ilosc, Ilosc_na_amazonie, mNazwa, mKategoria_Produktu, mProducent, mWaga,
//                                 mKolor, mCena, mVat, mMaterial, mSrednica, mKat_Nachylenia, mDlugosc);
//    return ptr;
//}

void cKolanka::Info_Produkt(Ui::ProduktInfo* ui, ProduktInfo* Widget)
{
    cProdukt::Info_Produkt(ui, Widget);
    Widget->Material = std::make_shared<QLabel>("Material: " + mMaterial);
    Widget->Srednica = std::make_shared<QLabel>("Srednica: " + QString::number(mSrednica));
    Widget->Kat_Nachylenia = std::make_shared<QLabel>("Kąt nachylenia: " + QString::number(mKat_Nachylenia));
    Widget->Dlugosc = std::make_shared<QLabel>("Długość: " + QString::number(mDlugosc));
    ui->verticalLayout_2->addWidget(Widget->Material.get());
    ui->verticalLayout_2->addWidget(Widget->Srednica.get());
    ui->verticalLayout_2->addWidget(Widget->Kat_Nachylenia.get());
    ui->verticalLayout_2->addWidget(Widget->Dlugosc.get());
}

//QString cKolanka::typ()
//{
//    return "Kolanki";
//}

void cKolanka::Edytowanie_Produktu(Ui::DodanieNowegoProduktu* ui, DodanieNowegoProduktu* Widget)
{
    cProdukt::Edytowanie_Produktu(ui, Widget);
    Widget->Material = std::make_shared<QLabel>("Material: ");
    Widget->Srednica = std::make_shared<QLabel>("Średnica: ");
    Widget->Kat_Nachylenia = std::make_shared<QLabel>("Kąt nachylenia: ");
    Widget->Dlugosc = std::make_shared<QLabel>("Długość: ");
    Widget->MaterialEdit = std::make_shared<QLineEdit>(mMaterial);
    Widget->SrednicaEdit = std::make_shared<QLineEdit>(QString::number(mSrednica));
    Widget->Kat_NachyleniaEdit = std::make_shared<QLineEdit>(QString::number(mKat_Nachylenia));
    Widget->DlugoscEdit = std::make_shared<QLineEdit>(QString::number(mDlugosc));
    ui->formLayout->addRow(Widget->Material.get(), Widget->MaterialEdit.get());
    ui->formLayout->addRow(Widget->Srednica.get(), Widget->SrednicaEdit.get());
    ui->formLayout->addRow(Widget->Kat_Nachylenia.get(), Widget->Kat_NachyleniaEdit.get());
    ui->formLayout->addRow(Widget->Dlugosc.get(), Widget->DlugoscEdit.get());
    Widget->index_var = 3;
    ui->TypProduktu->setCurrentIndex(3);
}

void cKolanka::Zapis_Binarny(std::fstream& plik)
{
    int typ = 5;
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
    plik << mSrednica;
    plik << mKat_Nachylenia;
    plik << mDlugosc;
}

void cKolanka::Odczyt_Binarny(std::fstream& plik)
{
    cProdukt::Odczyt_Binarny(plik);
    plik >> mMaterial;
    plik >> mSrednica;
    plik >> mKat_Nachylenia;
    plik >> mDlugosc;
}
//cKolanka::~cKolanka()
//{}
