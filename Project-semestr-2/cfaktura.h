#ifndef CFAKTURA_H
#define CFAKTURA_H
#include <QString>
#include <QListWidget>
#include "pokazfaktury.h"

class Osoba_Przedsiebiorcza
{
public:
    QString Imie;
    QString Nazwisko;
    QString NazwaFirmy;
    unsigned long long int NIP;
    QString Adres;
};

//struct Dane
//{
//    QString Imie;
//    QString Nazwisko;
//    QString NazwaFirmy;
//    unsigned long long int NIP;
//    QString Adres;
//};

class cFaktura
{
protected:
    Osoba_Przedsiebiorcza mDaneNabywcy;
    unsigned long long int mNumerFaktury;
    int Dzien_Wystawienia;
    int Miesiac_Wystawienia;
    int Rok_Wystawienia;
    std::vector<QString>mNazwy_Sprzedanych_Produktów;
    std::vector<int>mIlosci_Produktów;
    std::vector<double>mCene_Pojedyncze;
    std::vector<unsigned long long int>LP_Produtow;
public:
    cFaktura();
    virtual void Zapielnic(QString ImieSprzedawcy, QString NazwiskoSprzedawcy,
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
                           unsigned long long int LP5) = 0;
    virtual void Pokaz(QListWidget* Widget) = 0;
    virtual unsigned long long int Return_Numer() = 0;
    virtual bool Sprawdz_Date(int Dzien, int Miesiac, int Rok) = 0;
    virtual void Pokaz(PokazFaktury* Dialog) = 0;
    virtual void Zapis(std::fstream& plik) = 0;
    virtual void Odczyt(std::fstream& plik) = 0;
};

#endif // CFAKTURA_H
