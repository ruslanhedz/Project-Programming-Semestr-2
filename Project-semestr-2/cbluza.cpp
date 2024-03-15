#include "cbluza.h"
//#include "dodanienowegoproduktu.h"
#include "mainwindow.h"

cBluza::cBluza()
{}

cBluza::cBluza(unsigned long long int Lp, int Dostepna_Ilosc, int Ilosc_Na_Amazonie, QString Nazwa, QString Kategoria_Produktu,
               QString Producent, double Waga, QString Kolor, double Cena, double Vat, QString Rozmiar,
               QString Material) : cProdukt(Lp, Dostepna_Ilosc, Ilosc_Na_Amazonie, Nazwa, Kategoria_Produktu, Producent,
                                            Waga, Kolor, Cena, Vat), mRozmiar(Rozmiar), mMaterial(Material)
{}

//cProdukt* cBluza::Copy()
//{
//    cProdukt* ptr = new cBluza(mLp, mDostepna_Ilosc, Ilosc_na_amazonie, mNazwa, mKategoria_Produktu, mProducent, mWaga,
//                               mKolor, mCena, mVat, mRozmiar, mMaterial);
//    return ptr;
//}


void cBluza::Info_Produkt(Ui::ProduktInfo* ui, ProduktInfo* Widget)
{
    cProdukt::Info_Produkt(ui, Widget);
    Widget->Rozmiar = std::make_shared<QLabel>();
    Widget->Material = std::make_shared<QLabel>();
    Widget->Rozmiar->setText("Roziar: " + mRozmiar);
    Widget->Material->setText("Material: " + mMaterial);
    ui->verticalLayout_2->addWidget(Widget->Rozmiar.get());
    ui->verticalLayout_2->addWidget(Widget->Material.get());
}

//QString cBluza::typ()
//{
//    return "Bluzy";
//}

void cBluza::Edytowanie_Produktu(Ui::DodanieNowegoProduktu* ui, DodanieNowegoProduktu* Widget)
{
    cProdukt::Edytowanie_Produktu(ui, Widget);
    Widget->Rozmiar = std::make_shared<QLabel>("Rozmiar");
    Widget->Material = std::make_shared<QLabel>("Material");
    Widget->RozmiarEdit = std::make_shared<QLineEdit>(mRozmiar);
    Widget->MaterialEdit = std::make_shared<QLineEdit>(mMaterial);
    ui->formLayout->addRow(Widget->Rozmiar.get(), Widget->RozmiarEdit.get());
    ui->formLayout->addRow(Widget->Material.get(), Widget->MaterialEdit.get());
    Widget->index_var = 1;
    ui->TypProduktu->setCurrentIndex(1);
}

void cBluza::Zapis_Binarny(std::fstream& plik)
{
    int typ = 3;
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
    plik << mRozmiar;
    plik << mMaterial;
}

void cBluza::Odczyt_Binarny(std::fstream& plik)
{
    cProdukt::Odczyt_Binarny(plik);
    plik >> mRozmiar;
    plik >> mMaterial;
}
//cBluza::~cBluza()
//{}
