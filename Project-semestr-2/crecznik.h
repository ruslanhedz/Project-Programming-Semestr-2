#ifndef CRECZNIK_H
#define CRECZNIK_H

#include "cprodukt.h"

class cRecznik : public cProdukt
{
private:
    QString mMaterial;
    float mDlugosc;
    float mSzerokosc;
public:
    cRecznik();
    cRecznik(unsigned long long int Lp, int Dostepna_Ilosc, int Ilosc_Na_Amazonie, QString Nazwa, QString Kategoria_Produktu,
             QString Producent, double Waga, QString Kolor, double Cena, double Vat, QString Material,
             float Dlugosc, float Szerokosc);
//    cProdukt* Copy();
    void Info_Produkt(Ui::ProduktInfo* ui, ProduktInfo* Widget);
//    QString typ();
    void Edytowanie_Produktu(Ui::DodanieNowegoProduktu* ui, DodanieNowegoProduktu* Widget);
    void Zapis_Binarny(std::fstream& plik);
    void Odczyt_Binarny(std::fstream& plik);
//    ~cRecznik();
};

#endif // CRECZNIK_H
