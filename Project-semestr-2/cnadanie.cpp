#include "cnadanie.h"
#include <QLineEdit>
#include "mainwindow.h"

cNadanie::cNadanie()
{
    mDzien = 0;
    mMiesiac = 0;
    mRok = 0;
}

cNadanie::cNadanie(QString Nazwa, unsigned long long int LP, int Ilosc, QString Adres, int Dzien,
                   int Miesiac, int Rok)
{
    mNazwa_Produktu = Nazwa;
    mLP_produktu = LP;
    mIlosc_Sztuk_w_nadaniu = Ilosc;
    mAdres_Nadania = Adres;
    mDzien = Dzien;
    mMiesiac = Miesiac;
    mRok = Rok;
}

cNadanie& cNadanie::operator=(const cNadanie& ptr)
{
    mDzien = ptr.mDzien;
    mMiesiac = ptr.mMiesiac;
    mRok = ptr.mRok;
    mAdres_Nadania = ptr.mAdres_Nadania;
    return *this;
}

bool cNadanie::Sprawdz_Adres()
{
    if(mAdres_Nadania.size() != 0)
    {
        return true;
    }
    else return false;
}

bool cNadanie::Sprawdz_Date()
{
    if(mDzien != 0)
    {
        return true;
    }
    else return false;
}

void cNadanie::get_dane(QLineEdit* Dzien, QLineEdit* Miesiac, QLineEdit* Rok, QLineEdit* Adres)
{
    Dzien->setText(QString::number(mDzien));
    Miesiac->setText(QString::number(mMiesiac));
    Rok->setText(QString::number(mRok));
    Adres->setText(mAdres_Nadania);
}

void cNadanie::get_dane(QLineEdit* Dzien, QLineEdit* Miesiac, QLineEdit* Rok)
{
    Dzien->setText(QString::number(mDzien));
    Miesiac->setText(QString::number(mMiesiac));
    Rok->setText(QString::number(mRok));
}

void cNadanie::get_dane(QLineEdit* Adres)
{
    Adres->setText(mAdres_Nadania);
}

void cNadanie::take_dane(QString Nazwa, unsigned long long int LP, int Ilosc)
{
    mNazwa_Produktu = Nazwa;
    mLP_produktu = LP;
    mIlosc_Sztuk_w_nadaniu = Ilosc;
}

void cNadanie::take_dane(QString Nazwa, unsigned long long int LP, int Ilosc, int Dzien, int Miesiac, int Rok)
{
    mNazwa_Produktu = Nazwa;
    mLP_produktu = LP;
    mIlosc_Sztuk_w_nadaniu = Ilosc;
    mDzien = Dzien;
    mMiesiac = Miesiac;
    mRok = Rok;
}
void cNadanie::take_dane(QString Nazwa, unsigned long long int LP, int Ilosc, QString Adres)
{
    mNazwa_Produktu = Nazwa;
    mLP_produktu = LP;
    mIlosc_Sztuk_w_nadaniu = Ilosc;
    mAdres_Nadania = Adres;
}

int cNadanie::Return_Dzien()
{
    return mDzien;
}

int cNadanie::Return_Miesiac()
{
    return mMiesiac;
}

int cNadanie::Return_Rok()
{
    return mRok;
}

QString cNadanie::Return_Adres()
{
    return mAdres_Nadania;
}

void cNadanie::take_dane(int Dzien, int Miesiac, int Rok)
{
    mDzien = Dzien;
    mMiesiac = Miesiac;
    mRok = Rok;
}

void cNadanie::take_dane(QString Adres)
{
    mAdres_Nadania = Adres;
}

unsigned long long int cNadanie::get_LP()
{
    return mLP_produktu;
}

int cNadanie::Return_Ilosc()
{
    return mIlosc_Sztuk_w_nadaniu;
}

void cNadanie::Zapisac(std::fstream& plik)
{
    int typ = 12;
    plik << typ;
    plik << mNazwa_Produktu;
    plik << mLP_produktu;
    plik << mIlosc_Sztuk_w_nadaniu;
    plik << mAdres_Nadania;
    plik << mDzien;
    plik << mMiesiac;
    plik << mRok;
}

void cNadanie::Odczyt(std::fstream& plik)
{
    plik >> mNazwa_Produktu;
    plik >> mLP_produktu;
    plik >> mIlosc_Sztuk_w_nadaniu;
    plik >> mAdres_Nadania;
    plik >> mDzien;
    plik >> mMiesiac;
    plik >> mRok;
}
