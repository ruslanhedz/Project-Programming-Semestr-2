#ifndef CBLUZA_H
#define CBLUZA_H

#include "cprodukt.h"
//class DodanieNowegoProduktu;
//#include "dodanienowegoproduktu.h"

class cBluza : public cProdukt
{
private:
    QString mRozmiar;
    QString mMaterial;
public:
    cBluza();
    cBluza(unsigned long long int Lp, int Dostepna_Ilosc, int Ilosc_Na_Amazonie, QString Nazwa, QString Kategoria_Produktu,
           QString Producent, double Waga, QString Kolor, double Cena, double Vat, QString Rozmiar,
           QString Material);
//    cProdukt* Copy();
    void Info_Produkt(Ui::ProduktInfo* ui, ProduktInfo* Widget);
//    QString typ();
    void Edytowanie_Produktu(Ui::DodanieNowegoProduktu* ui, DodanieNowegoProduktu* Widget);
    void Zapis_Binarny(std::fstream& plik);
    void Odczyt_Binarny(std::fstream& plik);
//    ~cBluza();
};

#endif // CBLUZA_H
