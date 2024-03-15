#include "csluchawki.h"

cSluchawki::cSluchawki()
{}

cSluchawki::cSluchawki(unsigned long long int Lp, int Dostepna_Ilosc, int Ilosc_Na_Amazonie, QString Nazwa, QString Kategoria_Produktu,
                QString Producent, double Waga, QString Kolor, double Cena, double Vat,
                QString Typ_Zlacza, double Ilosc_Godzin_Pracy): cProdukt(Lp, Dostepna_Ilosc, Ilosc_Na_Amazonie, Nazwa,
                Kategoria_Produktu, Producent, Waga, Kolor, Cena, Vat), mTyp_Zlacza(Typ_Zlacza),
                mIlosc_Godzin_Pracy(Ilosc_Godzin_Pracy)
{}

//cProdukt* cSluchawki::Copy()
//{
//    cProdukt* ptr = new cSluchawki(mLp, mDostepna_Ilosc, Ilosc_na_amazonie, mNazwa, mKategoria_Produktu, mProducent, mWaga,
//                                   mKolor, mCena, mVat, mTyp_Zlacza, mIlosc_Godzin_Pracy);
//    return ptr;
//}

void cSluchawki::Info_Produkt(Ui::ProduktInfo* ui, ProduktInfo* Widget)
{
    cProdukt::Info_Produkt(ui, Widget);
    Widget->Typ_Zlacza = std::make_shared<QLabel>("Typ złącza: " + mTyp_Zlacza);
    ui->verticalLayout_2->addWidget(Widget->Typ_Zlacza.get());
    if(mTyp_Zlacza != "Przewodowe")
    {
        Widget->Ilosc_Godzin_Pracy = std::make_shared<QLabel>("Ilość godzin pracy: " + QString::number(mIlosc_Godzin_Pracy));
        ui->verticalLayout_2->addWidget(Widget->Ilosc_Godzin_Pracy.get());
    }
}

//QString cSluchawki::typ()
//{
//    return "Sluchawki";
//}

void cSluchawki::Edytowanie_Produktu(Ui::DodanieNowegoProduktu* ui, DodanieNowegoProduktu* Widget)
{
    cProdukt::Edytowanie_Produktu(ui, Widget);
    ui->TypProduktu->setCurrentIndex(4);
    Widget->Typ_Zlacza = std::make_shared<QLabel>("Typ złącza: ");
    Widget->Ilosc_Godzin_Pracy = std::make_shared<QLabel>("Ilość godzin pracy");
    Widget->Typ_ZlaczaBox = std::make_shared<QComboBox>();
    Widget->Typ_ZlaczaBox->addItem("Bezprzewodowe");
    Widget->Typ_ZlaczaBox->addItem("Przewodowe");
    if(mTyp_Zlacza == "Bezprzewodowe")
    {
        Widget->Typ_ZlaczaBox->setCurrentIndex(0);
    }
    else Widget->Typ_ZlaczaBox->setCurrentIndex(1);
    Widget->Ilosc_Godzin_PracyEdit = std::make_shared<QLineEdit>(QString::number(mIlosc_Godzin_Pracy));
    Widget->index_var = 4;
    ui->TypProduktu->setCurrentIndex(4);
}

void cSluchawki::Zapis_Binarny(std::fstream& plik)
{
    int typ = 6;
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
    plik << mTyp_Zlacza;
    plik << mIlosc_Godzin_Pracy;
}

void cSluchawki::Odczyt_Binarny(std::fstream& plik)
{
    cProdukt::Odczyt_Binarny(plik);
    plik >> mTyp_Zlacza;
    plik >> mIlosc_Godzin_Pracy;
}
//cSluchawki::~cSluchawki()
//{}
