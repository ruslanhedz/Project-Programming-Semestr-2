#include "chdd.h"
//#include "dodanienowegoproduktu.h"

cHDD::cHDD()
{}

cHDD::cHDD(unsigned long long int Lp, int Dostepna_Ilosc, int Ilosc_Na_Amazonie, QString Nazwa, QString Kategoria_Produktu,
     QString Producent, double Waga, QString Kolor, double Cena, double Vat, int Pojemnosc,
     double Szybkosc_Odczytu, double Szybkosc_Zapisu, QString Typ_SATA, double Format_Dysku):
    cProdukt(Lp, Dostepna_Ilosc, Ilosc_Na_Amazonie, Nazwa, Kategoria_Produktu, Producent, Waga, Kolor, Cena, Vat),
    mPojemnosc(Pojemnosc), mSzybkosc_Odczytu(Szybkosc_Odczytu), mSzybkosc_Zapisu(Szybkosc_Zapisu),
    mTyp_SATA(Typ_SATA), mFormat_Dysku(Format_Dysku)
{}

//cProdukt* cHDD::Copy()
//{
//    cProdukt* ptr = new cHDD(mLp, mDostepna_Ilosc, Ilosc_na_amazonie, mNazwa, mKategoria_Produktu, mProducent, mWaga,
//                             mKolor, mCena, mVat, mPojemnosc, mSzybkosc_Odczytu, mSzybkosc_Zapisu,
//                             mTyp_SATA, mFormat_Dysku);
//    return ptr;
//}

void cHDD::Info_Produkt(Ui::ProduktInfo* ui, ProduktInfo* Widget)
{
    cProdukt::Info_Produkt(ui, Widget);
    Widget->Pojemnosc = std::make_shared<QLabel>();
    Widget->Szybkosc_Odczytu = std::make_shared<QLabel>();
    Widget->Szybkosc_Zapisu = std::make_shared<QLabel>();
    Widget->Typ_SATA = std::make_shared<QLabel>();
    Widget->Format_Dysku = std::make_shared<QLabel>();
    Widget->Pojemnosc->setText("Pojemność: " + QString::number(mPojemnosc));
    Widget->Szybkosc_Odczytu->setText("Szybkość odczytu: " + QString::number(mSzybkosc_Odczytu));
    Widget->Szybkosc_Zapisu->setText("Szybkość zapisu: " + QString::number(mSzybkosc_Zapisu));
    Widget->Typ_SATA->setText("Typ SATA: " + mTyp_SATA);
    Widget->Format_Dysku->setText("Format dysku: " + QString::number(mFormat_Dysku));
    ui->verticalLayout_2->addWidget(Widget->Pojemnosc.get());
    ui->verticalLayout_2->addWidget(Widget->Szybkosc_Odczytu.get());
    ui->verticalLayout_2->addWidget(Widget->Szybkosc_Zapisu.get());
    ui->verticalLayout_2->addWidget(Widget->Typ_SATA.get());
    ui->verticalLayout_2->addWidget(Widget->Format_Dysku.get());
}

//QString cHDD::typ()
//{
//    return "HDD";
//}

void cHDD::Edytowanie_Produktu(Ui::DodanieNowegoProduktu* ui, DodanieNowegoProduktu* Widget)
{
    cProdukt::Edytowanie_Produktu(ui, Widget);
    Widget->Pojemnosc = std::make_shared<QLabel>("Pojemność");
    Widget->Szybkosc_Odczytu = std::make_shared<QLabel>("Szybkość_Odczytu");
    Widget->Szybkosc_Zapisu = std::make_shared<QLabel>("Szybkość zapisu");
    Widget->Typ_SATA = std::make_shared<QLabel>("Typ SATA");
    Widget->Format_Dysku = std::make_shared<QLabel>("Format dysku");
    Widget->PojemnoscEdit = std::make_shared<QLineEdit>(QString::number(mPojemnosc));
    Widget->Szybkosc_OdczytuEdit = std::make_shared<QLineEdit>(QString::number(mSzybkosc_Odczytu));
    Widget->Szybkosc_ZapisuEdit = std::make_shared<QLineEdit>(QString::number(mSzybkosc_Zapisu));
    Widget->Typ_SATAEdit = std::make_shared<QLineEdit>(mTyp_SATA);
    ui->formLayout->addRow(Widget->Pojemnosc.get(), Widget->PojemnoscEdit.get());
    ui->formLayout->addRow(Widget->Szybkosc_Odczytu.get(), Widget->Szybkosc_OdczytuEdit.get());
    ui->formLayout->addRow(Widget->Szybkosc_Zapisu.get(), Widget->Szybkosc_ZapisuEdit.get());
    ui->formLayout->addRow(Widget->Typ_SATA.get(), Widget->Typ_SATAEdit.get());
    ui->formLayout->addRow(Widget->Format_Dysku.get(), Widget->Format_DyskuEdit.get());
    Widget->index_var = 2;
    ui->TypProduktu->setCurrentIndex(2);

}

void cHDD::Zapis_Binarny(std::fstream& plik)
{
    int typ = 4;
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
    plik << mPojemnosc;
    plik << mSzybkosc_Odczytu;
    plik << mSzybkosc_Zapisu;
    plik << mTyp_SATA;
    plik << mFormat_Dysku;
}

void cHDD::Odczyt_Binarny(std::fstream& plik)
{
    cProdukt::Odczyt_Binarny(plik);
    plik >> mPojemnosc;
    plik >> mSzybkosc_Odczytu;
    plik >> mSzybkosc_Zapisu;
    plik >> mTyp_SATA;
    plik >> mFormat_Dysku;
}
//cHDD::~cHDD()
//{}
