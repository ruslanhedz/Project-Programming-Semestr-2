#ifndef CBAZAFAKTURY_H
#define CBAZAFAKTURY_H
#include "cwezelfaktury.h"
#include <QListWidget>


class cBazaFaktury
{
    cWezelFaktury* Wezel;
public:
    cBazaFaktury();
    void Dodac_Fakture(cFaktura*);
    void Pokaz_Liste(QListWidget*);
    void Ponowic_Liste(QListWidget*);
    void Usunac_Fakture(int index);
    void Znalezc_Fakture(unsigned long long int, QListWidget*);
    void Znalezc_Fakture(int Dzien, int Miesiac, int Rok, QListWidget*);
    cFaktura* Return_Faktura(int index);
    cFaktura* Return_Faktura_Numer(unsigned long long int Numer);
    void Zapis_Binarny(std::fstream* plik);
    void Odczyt_Binarny(std::fstream* plik);
    ~cBazaFaktury();
};

#endif // CBAZAFAKTURY_H
