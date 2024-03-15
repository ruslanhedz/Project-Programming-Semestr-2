#include "cdostawa.h"
#include <QLineEdit>
#include "mainwindow.h"
#include <fstream>

cDostawa::cDostawa()
{}

cDostawa::cDostawa(QString Nazawa, QString Typ, unsigned long long int LP, int Dzien, int Miesiac,
                   int Rok, int Ilosc) : mNazwa_Produktu(Nazawa), mTyp_Produktu(Typ),
    mLP_Produktu(LP), mDzien(Dzien), mMiesiac(Miesiac), mRok(Rok), mIlosc(Ilosc)
{

}

cDostawa& cDostawa::operator=(const cDostawa& ptr)
{
//    if(this == &ptr)
//    {
//        return *this;
//    }

    mDzien = ptr.mDzien;
    mMiesiac = ptr.mMiesiac;
    mRok = ptr.mRok;
    return *this;
}

void cDostawa::get_data(QLineEdit* Dzien, QLineEdit* Miesiac, QLineEdit* Rok)
{
    Dzien->setText(QString::number(mDzien));
    Miesiac->setText(QString::number(mMiesiac));
    Rok->setText(QString::number(mRok));
}

void cDostawa::take_dane(int Ilosc, QString Nazwa, QString Typ, unsigned long long int LP)
{
    mIlosc = Ilosc;
    mNazwa_Produktu = Nazwa;
    mTyp_Produktu = Typ;
    mLP_Produktu = LP;
}

unsigned long long int cDostawa::get_LP()
{
    return mLP_Produktu;
}

int cDostawa::get_Ilosc()
{
    return mIlosc;
}

void cDostawa::Zapis(std::fstream& plik)
{
    int typ = 11;
    plik << typ;
    plik << mDzien;
    plik << mMiesiac;
    plik << mRok;
    plik << mIlosc;
    plik << mTyp_Produktu;
    plik << mNazwa_Produktu;
    plik << mLP_Produktu;
}

void cDostawa::Odczyt(std::fstream& plik)
{
    plik >> mDzien;
    plik >> mMiesiac;
    plik >> mRok;
    plik >> mIlosc;
    plik >> mTyp_Produktu;
    plik >> mNazwa_Produktu;
    plik >> mLP_Produktu;
}
