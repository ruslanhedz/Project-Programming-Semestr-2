#ifndef CTASMY_H
#define CTASMY_H

#include "cprodukt.h"

class cTasmy : public cProdukt
{
private:
    double mDlugosc;
    double mSzerokosc;
    double mGrubosc;
    QString mFunkcja;
public:
    cTasmy();
    cTasmy(unsigned long long int Lp, int Dostepna_Ilosc, int Ilosc_Na_Amazonie, QString Nazwa, QString Kategoria_Produktu,
           QString Producent, double Waga, QString Kolor, double Cena, double Vat, double Dlugosc,
           double Szerokosc, double Grubosc, QString Funkcja);
//    cProdukt* Copy();
    void Info_Produkt(Ui::ProduktInfo* ui, ProduktInfo* Widget);
//    QString typ();
    void Edytowanie_Produktu(Ui::DodanieNowegoProduktu* ui, DodanieNowegoProduktu* Widget);
    void Zapis_Binarny(std::fstream& plik);
    void Odczyt_Binarny(std::fstream& plik);
//    ~cTasmy();
};

#endif // CTASMY_H
