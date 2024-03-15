#ifndef CBAZA_H
#define CBAZA_H

#include "cwezel.h"
#include <QListWidget>
#include "dostepne_produkty.h"
#include "dostepne_amazon.h"
#include <QComboBox>


class cBaza
{
protected:
    cWezel* Wezel;
public:
    cBaza();
    void Dodac_produkt(cProdukt* ptr);
    void Pokaz(QListWidget* widget);
    void Pokaz_dostepne();
    //void Usunac_Produkt(unsigned long long int);
    void Usunac_Produkt(int index);
    void Usunac_Produkt(cProdukt* Produkt);
    void Znalezc_LP(QListWidget* widget, unsigned long long int);
    void Znalezc_Nazwa(QListWidget* wisget, QString Nazwa);
    cProdukt* Return_Produkt(int index);
    cProdukt* Return_Produkt(unsigned long long int LP);
    cProdukt* Return_Produkt(QString Nazwa);
    void Zamiana_Produktu(cProdukt* Produkt);
    void Pokaz_Dodstepne(Ui::Dostepne_Produkty* ui);
    void Pokaz_Dostepne_Amazon(Ui::Dostepne_Amazon* ui);
    bool Sparwdz_LP(unsigned long long int);
    void WypiszNazwy(QComboBox*);
    void Ponowic_Liste(QListWidget* Widget);
    void Zapis(std::fstream* plik);
    void Odczyt(std::fstream* plik);
    ~cBaza();
};

#endif // CBAZA_H
