#ifndef CSLUCHAWKI_H
#define CSLUCHAWKI_H

#include "cprodukt.h"

class cSluchawki : public cProdukt
{
private:
    QString mTyp_Zlacza;
    double mIlosc_Godzin_Pracy;
public:
    cSluchawki();
    cSluchawki(unsigned long long int Lp, int Dostepna_Ilosc, int Ilosc_Na_Amazonie, QString Nazwa, QString Kategoria_Produktu,
               QString Producent, double Waga, QString Kolor, double Cena, double Vat,
               QString Typ_Zlacza, double Ilosc_Godzin_Pracy);
//    cProdukt* Copy();
    void Info_Produkt(Ui::ProduktInfo* ui, ProduktInfo* Widget);
//    QString typ();
    void Edytowanie_Produktu(Ui::DodanieNowegoProduktu* ui, DodanieNowegoProduktu* Widget);
    void Zapis_Binarny(std::fstream& plik);
    void Odczyt_Binarny(std::fstream& plik);
//    ~cSluchawki();
};

#endif // CSLUCHAWKI_H
