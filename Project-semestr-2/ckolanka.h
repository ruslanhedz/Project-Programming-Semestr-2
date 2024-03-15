#ifndef CKOLANKA_H
#define CKOLANKA_H

#include "cprodukt.h"

class cKolanka : public cProdukt
{
private:
    QString mMaterial;
    double mSrednica;
    double mKat_Nachylenia;
    double mDlugosc;
public:
    cKolanka();
    cKolanka(unsigned long long int Lp, int Dostepna_Ilosc, int Ilosc_Na_Amazonie, QString Nazwa, QString Kategoria_Produktu,
             QString Producent, double Waga, QString Kolor, double Cena, double Vat, QString Material,
             double Srednica, double Kat_Nachylenia, double Dlugosc);
//    cProdukt* Copy();
    void Info_Produkt(Ui::ProduktInfo* ui, ProduktInfo* Widget);
//    QString typ();
    void Edytowanie_Produktu(Ui::DodanieNowegoProduktu* ui, DodanieNowegoProduktu* Widget);
    void Zapis_Binarny(std::fstream& plik);
    void Odczyt_Binarny(std::fstream& plik);
//    ~cKolanka();
};

#endif // CKOLANKA_H
