#ifndef CKOSZULKA_H
#define CKOSZULKA_H

#include "cprodukt.h"

class cKoszulka : public cProdukt
{
private:
    QString mRozmiar;
    QString mMaterial;
public:
    cKoszulka();
    cKoszulka(unsigned long long int Lp, int Dostepna_Ilosc, int Ilosc_Na_Amazonie, QString Nazwa, QString Kategoria_Produktu,
              QString Producent, double Waga, QString Kolor, double Cena, double Vat, QString Rozmiar,
              QString Material);
//    cProdukt* Copy();
    void Info_Produkt(Ui::ProduktInfo* ui, ProduktInfo* Widget);
//    QString typ();
    void Edytowanie_Produktu(Ui::DodanieNowegoProduktu* ui, DodanieNowegoProduktu* Widget);
    void Zapis_Binarny(std::fstream& plik);
    void Odczyt_Binarny(std::fstream& plik);
//    ~cKoszulka();
};

#endif // CKOSZULKA_H
