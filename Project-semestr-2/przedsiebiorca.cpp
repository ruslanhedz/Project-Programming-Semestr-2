#include "przedsiebiorca.h"
#include "ui_pokazfaktury.h"
#include "mainwindow.h"
#include <QLabel>

Przedsiebiorca::Przedsiebiorca()
{

}

void Przedsiebiorca::Zapielnic(QString ImieSprzedawcy, QString NazwiskoSprzedawcy,
                               QString NazwaFirmySprzedawcy, unsigned long long int NIPSprzedawcy,
                               QString AdresSprzedawcy, QString NazwaBanku, QString KontoBankowe,
                               QString ImieNabywcy, QString NazwiskoNabywcy,
                               QString NazwaFirmyNabywcy, unsigned long long int NIPNabywcy,
                               QString AdresNabywcy, unsigned long long int NumerFaktury,
                               int Dzien, int Miesiac, int Rok, QString Nazwa1, QString Nazwa2,
                               QString Nazwa3, QString Nazwa4, QString Nazwa5, int Ilosci1,
                               int Ilosci2, int Ilosci3, int Ilosci4, int Ilosci5, double Cena1,
                               double Cena2, double Cena3, double Cena4, double Cena5,
                               unsigned long long int LP1, unsigned long long int LP2,
                               unsigned long long int LP3, unsigned long long int LP4,
                               unsigned long long int LP5)
{
    mDanePrzesiebiorcy.Imie = ImieSprzedawcy;
    mDanePrzesiebiorcy.Nazwisko = NazwiskoSprzedawcy;
    mDanePrzesiebiorcy.NazwaFirmy = NazwaFirmySprzedawcy;
    mDanePrzesiebiorcy.NIP = NIPSprzedawcy;
    mDanePrzesiebiorcy.Adres = AdresSprzedawcy;
    mNazwaBanku = NazwaBanku;
    mKontoBankowe = KontoBankowe;
    mDaneNabywcy.Imie = ImieNabywcy;
    mDaneNabywcy.Nazwisko = NazwiskoNabywcy;
    mDaneNabywcy.NazwaFirmy = NazwaFirmyNabywcy;
    mDaneNabywcy.Adres = AdresNabywcy;
    mDaneNabywcy.NIP = NIPNabywcy;
    mNumerFaktury = NumerFaktury;
    Dzien_Wystawienia = Dzien;
    Miesiac_Wystawienia = Miesiac;
    Rok_Wystawienia = Rok;
    if(Nazwa1.size() != 0)
    {
        if(Ilosci1 > 0)
        {
                mNazwy_Sprzedanych_Produktów.push_back(Nazwa1);
                mIlosci_Produktów.push_back(Ilosci1);
                mCene_Pojedyncze.push_back(Cena1);
                LP_Produtow.push_back(LP1);
        }
    }
    if(Nazwa2.size() != 0)
    {
        if(Ilosci2 >  0)
        {
            mNazwy_Sprzedanych_Produktów.push_back(Nazwa2);
            mIlosci_Produktów.push_back(Ilosci2);
            mCene_Pojedyncze.push_back(Cena2);
            LP_Produtow.push_back(LP2);
        }
    }
    if(Nazwa3.size() != 0)
    {
        if(Ilosci3 >  0)
        {
            mNazwy_Sprzedanych_Produktów.push_back(Nazwa3);
            mIlosci_Produktów.push_back(Ilosci3);
            mCene_Pojedyncze.push_back(Cena3);
            LP_Produtow.push_back(LP3);
        }
    }
    if(Nazwa4.size() != 0)
    {
        if(Ilosci4 >  0)
        {
            mNazwy_Sprzedanych_Produktów.push_back(Nazwa4);
            mIlosci_Produktów.push_back(Ilosci4);
            mCene_Pojedyncze.push_back(Cena4);
            LP_Produtow.push_back(LP4);
        }
    }
    if(Nazwa5.size() != 0)
    {
        if(Ilosci5 >  0)
        {
            mNazwy_Sprzedanych_Produktów.push_back(Nazwa5);
            mIlosci_Produktów.push_back(Ilosci5);
            mCene_Pojedyncze.push_back(Cena5);
            LP_Produtow.push_back(LP5);
        }
    }
}


void Przedsiebiorca::Pokaz(QListWidget* Widget)
{
    Widget->addItem(QString::number(mNumerFaktury) + " | " + QString::number(Dzien_Wystawienia) + "."
                    + QString::number(Miesiac_Wystawienia) + "." +
                    QString::number(Rok_Wystawienia));
}

unsigned long long int Przedsiebiorca::Return_Numer()
{
    return mNumerFaktury;
}

bool Przedsiebiorca::Sprawdz_Date(int Dzien, int Miesiac, int Rok)
{
    if(Dzien_Wystawienia == Dzien && Miesiac_Wystawienia == Miesiac && Rok_Wystawienia == Rok)
    {
        return true;
    }
    else {
        return false;
    }
}

void Przedsiebiorca::Pokaz(PokazFaktury* Dialog)
{
    Ui::PokazFaktury* ui = Dialog->ui;
    ui->NumerLabel + QString::number(mNumerFaktury);
    ui->DataLabel + (QString::number(Dzien_Wystawienia) + '.' +
                     QString::number(Miesiac_Wystawienia) + '.' +
                     QString::number(Rok_Wystawienia));
    ui->NIPSprzedawcyLabel + QString::number(mDanePrzesiebiorcy.NIP);
    ui->ImieSprzedawcyLabel + mDanePrzesiebiorcy.Imie;
    ui->NazwiskoSprzedawcyLabel + mDanePrzesiebiorcy.Nazwisko;
    ui->NazwaFirmySprzedawcy + mDanePrzesiebiorcy.NazwaFirmy;
    ui->AdresSprzedawcyLabel + mDanePrzesiebiorcy.Adres;
    ui->NIPNabywcyLabel + QString::number(mDaneNabywcy.NIP);
    ui->ImieNabywcyLabel + mDaneNabywcy.Imie;
    ui->NazwiskoNabywcyLabel + mDaneNabywcy.Nazwisko;
    ui->NazwaFirmyNabywcyLabel + mDaneNabywcy.NazwaFirmy;
    ui->AdresNabywcyLabel + mDaneNabywcy.Adres;
    for(unsigned long long int i : LP_Produtow)
    {
        Dialog->LPLabel.push_back(std::make_shared<QLabel>(QString::number(i)));
    }
    for(std::shared_ptr<QLabel> i : Dialog->LPLabel)
    {
        ui->VerticalLP->addWidget(i.get());
    }
    for (QString i : mNazwy_Sprzedanych_Produktów)
    {
        Dialog->NazwaLabel.push_back(std::make_shared<QLabel>(i));
    }
    for(std::shared_ptr<QLabel> i : Dialog->NazwaLabel)
    {
        ui->NazwaVertical->addWidget(i.get());
    }
    for (double i : mCene_Pojedyncze)
    {
        Dialog->CenaLabel.push_back(std::make_shared<QLabel>(QString::number(i)));
    }
    for(std::shared_ptr<QLabel> i : Dialog->CenaLabel)
    {
        ui->CenaVertical->addWidget(i.get());
    }
    for (int i : mIlosci_Produktów)
    {
        Dialog->IloscLabel.push_back(std::make_shared<QLabel>(QString::number(i)));
    }
    for(std::shared_ptr<QLabel> i : Dialog->IloscLabel)
    {
        ui->IloscVertical->addWidget(i.get());
    }
    for (int i = 0; i < mCene_Pojedyncze.size(); i++)
    {
        Dialog->WartoscLabel.push_back(
            std::make_shared<QLabel>(QString::number(mIlosci_Produktów[i] * mCene_Pojedyncze[i])));
    }
    for(std::shared_ptr<QLabel> i : Dialog->WartoscLabel)
    {
        ui->WartoscVertical->addWidget(i.get());
    }
    double suma = 0;
    for (int i = 0; i < mCene_Pojedyncze.size(); i++)
    {
        suma += (mCene_Pojedyncze[i] * mIlosci_Produktów[i]);
    }
    ui->RazemLabel + QString::number(suma);
    ui->BankLabel + mNazwaBanku;
    ui->NumerKontaLabel + mKontoBankowe;
}

void Przedsiebiorca::Zapis(std::fstream& plik)
{
    int typ = 13;
    plik << typ;
    plik << mDanePrzesiebiorcy.Imie;
    plik << mDanePrzesiebiorcy.Nazwisko;
    plik << mDanePrzesiebiorcy.NazwaFirmy;
    plik << mDanePrzesiebiorcy.NIP;
    plik << mDanePrzesiebiorcy.Adres;
    plik << mNazwaBanku;
    plik << mKontoBankowe;
    plik << mDaneNabywcy.Imie;
    plik << mDaneNabywcy.Nazwisko;
    plik << mDaneNabywcy.NazwaFirmy;
    plik << mDaneNabywcy.NIP;
    plik << mDaneNabywcy.Adres;
    plik << mNumerFaktury;
    plik << Dzien_Wystawienia;
    plik << Miesiac_Wystawienia;
    plik << Rok_Wystawienia;
    int typ_danych;
    for (QString Nazwa : mNazwy_Sprzedanych_Produktów)
    {
        typ_danych = 21;
        plik << typ_danych;
        plik << Nazwa;
    }
    for (int i : mIlosci_Produktów)
    {
        typ_danych = 22;
        plik << typ_danych;
        plik << i;
    }
    for (double i : mCene_Pojedyncze)
    {
        typ_danych = 23;
        plik << typ_danych;
        plik << i;
    }
    for (unsigned long long int i : LP_Produtow)
    {
        typ_danych = 24;
        plik << typ_danych;
        plik << i;
    }
    typ_danych = 0;
    plik << typ_danych;
}

void Przedsiebiorca::Odczyt(std::fstream& plik)
{
    plik >> mDanePrzesiebiorcy.Imie;
    plik >> mDanePrzesiebiorcy.Nazwisko;
    plik >> mDanePrzesiebiorcy.NazwaFirmy;
    plik >> mDanePrzesiebiorcy.NIP;
    plik >> mDanePrzesiebiorcy.Adres;
    plik >> mNazwaBanku;
    plik >> mKontoBankowe;
    plik >> mDaneNabywcy.Imie;
    plik >> mDaneNabywcy.Nazwisko;
    plik >> mDaneNabywcy.NazwaFirmy;
    plik >> mDaneNabywcy.NIP;
    plik >> mDaneNabywcy.Adres;
    plik >> mNumerFaktury;
    plik >> Dzien_Wystawienia;
    plik >> Miesiac_Wystawienia;
    plik >> Rok_Wystawienia;
    int typ;
    while (plik >> typ)
    {
        if (typ == 21)
        {
            QString Nazwa;
            plik >> Nazwa;
            mNazwy_Sprzedanych_Produktów.push_back(Nazwa);
//          plik >> typ;
        }
        else if (typ == 22)
        {
            int Ilosc;
            plik >> Ilosc;
            mIlosci_Produktów.push_back(Ilosc);
//          plik >> typ;
        }
        else if (typ == 23)
        {
            double Cena;
            plik >> Cena;
            mCene_Pojedyncze.push_back(Cena);
//          plik >> typ;
        }
        else if (typ == 24)
        {
            unsigned long long int LP;
            plik >> LP;
            LP_Produtow.push_back(LP);
        }
        else {
            break;
        }
    }
}
