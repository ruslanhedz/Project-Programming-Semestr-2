#ifndef CSSD_H
#define CSSD_H
#include "cprodukt.h"

class cSSD : public cProdukt
{
private:
    int mPojemnosc;
    double mSzybkosc_Odczytu;
    double mSzybkosc_Zapisu;
    QString mTyp_SATA;
public:
    cSSD();
    cSSD(unsigned long long int Lp, int Dostepna_Ilosc, int Ilosc_Na_Amazonie, QString Nazwa, QString Kategoria_Produktu,
         QString Producent, double Waga, QString Kolor, double Cena, double Vat, int Pojemnosc,
         double Szybkosc_Odczytu, double Szybkosc_Zapisu, QString Typ_SATA);
//    cProdukt* Copy();
    void Info_Produkt(Ui::ProduktInfo* ui, ProduktInfo* Widget);
//    QString typ();
    void Edytowanie_Produktu(Ui::DodanieNowegoProduktu* ui, DodanieNowegoProduktu* Widget);
    void Zapis_Binarny(std::fstream& plik);
    void Odczyt_Binarny(std::fstream& plik);
//    ~cSSD();
};

#endif // CSSD_H
