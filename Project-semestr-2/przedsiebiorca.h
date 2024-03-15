#ifndef PRZEDSIEBIORCA_H
#define PRZEDSIEBIORCA_H

#include "cfaktura.h"

class Przedsiebiorca : public cFaktura
{
    Osoba_Przedsiebiorcza mDanePrzesiebiorcy;
    QString mNazwaBanku;
    QString mKontoBankowe;
public:
    Przedsiebiorca();
    void Zapielnic(QString ImieSprzedawcy, QString NazwiskoSprzedawcy,
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
                   unsigned long long int LP5);
    void Pokaz(QListWidget* Widget);
    unsigned long long int Return_Numer();
    bool Sprawdz_Date(int Dzien, int Miesiac, int Rok);
    void Pokaz(PokazFaktury* Dialog);
    void Zapis(std::fstream& plik);
    void Odczyt(std::fstream& plik);
};

#endif // PRZEDSIEBIORCA_H
