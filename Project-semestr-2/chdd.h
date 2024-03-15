#ifndef CHDD_H
#define CHDD_H

#include "cprodukt.h"

class cHDD : public cProdukt
{
private:
    int mPojemnosc;
    double mSzybkosc_Odczytu;
    double mSzybkosc_Zapisu;
    QString mTyp_SATA;
    double mFormat_Dysku;
public:
    cHDD();
    cHDD(unsigned long long int Lp, int Dostepna_Ilosc, int Ilosc_Na_Amazonie, QString Nazwa, QString Kategoria_Produktu,
         QString Producent, double Waga, QString Kolor, double Cena, double Vat, int Pojemnosc,
         double Szybkosc_Odczytu, double Szybkosc_Zapisu, QString Typ_SATA, double Format_Dysku);
//    cProdukt* Copy();
    void Info_Produkt(Ui::ProduktInfo* ui, ProduktInfo* Widget);
//    QString typ();
    void Edytowanie_Produktu(Ui::DodanieNowegoProduktu* ui, DodanieNowegoProduktu* Widget);
    void Zapis_Binarny(std::fstream& plik);
    void Odczyt_Binarny(std::fstream& plik);
//    ~cHDD();
};

#endif // CHDD_H
