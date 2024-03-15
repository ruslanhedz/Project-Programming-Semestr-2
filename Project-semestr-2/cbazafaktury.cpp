#include "cbazafaktury.h"
#include "mainwindow.h"

cBazaFaktury::cBazaFaktury()
{
    Wezel = nullptr;
}

void cBazaFaktury::Dodac_Fakture(cFaktura* Faktura)
{
    cWezelFaktury* newWezel = new cWezelFaktury;
    newWezel->mNastepna = Wezel;
    newWezel->mFaktura = Faktura;
    Wezel = newWezel;
}

void cBazaFaktury::Pokaz_Liste(QListWidget* Widget)
{
    if(Wezel != nullptr)
    {
        cWezelFaktury* ptr = Wezel;
        while(ptr != nullptr)
        {
            ptr->mFaktura->Pokaz(Widget);
            ptr = ptr->mNastepna;
        }
    }
}

void cBazaFaktury::Ponowic_Liste(QListWidget* Widget)
{
    Widget->clear();
    cBazaFaktury::Pokaz_Liste(Widget);
}

void cBazaFaktury::Usunac_Fakture(int index)
{
    if(index == 0)
    {
        if(Wezel->mNastepna == nullptr)
        {
            delete Wezel->mFaktura;
            delete Wezel;
            Wezel = nullptr;
        }
        else {
            cWezelFaktury* ptr = Wezel;
            Wezel = Wezel->mNastepna;
            delete ptr->mFaktura;
            delete ptr;
        }
    }
    else {
        cWezelFaktury* ptr = Wezel;
        for(int i = 0 ; i < (index-1); i++)
        {
            ptr = ptr->mNastepna;
        }
        cWezelFaktury* ptr2 = ptr->mNastepna->mNastepna;
        delete ptr->mNastepna->mFaktura;
        delete ptr->mNastepna;
        ptr->mNastepna = ptr2;
    }
}

void cBazaFaktury::Znalezc_Fakture(unsigned long long int Numer, QListWidget* Widget)
{
    cWezelFaktury* ptr = Wezel;
    while (ptr != nullptr)
    {
        if(ptr->mFaktura->Return_Numer() == Numer)
        {
            ptr->mFaktura->Pokaz(Widget);
            break;
        }
        ptr = ptr->mNastepna;
    }
}

void cBazaFaktury::Znalezc_Fakture(int Dzien, int Miesiac, int Rok, QListWidget* Widget)
{
    cWezelFaktury* ptr = Wezel;
    while(ptr != nullptr)
    {
        if(ptr->mFaktura->Sprawdz_Date(Dzien, Miesiac, Rok))
        {
            ptr->mFaktura->Pokaz(Widget);
        }
        ptr = ptr->mNastepna;
    }
}

cFaktura* cBazaFaktury::Return_Faktura(int index)
{
    cWezelFaktury* ptr = Wezel;
    for (int i = 0; i < index; i++)
    {
        ptr = ptr->mNastepna;
    }
    return ptr->mFaktura;
}

cFaktura* cBazaFaktury::Return_Faktura_Numer(unsigned long long int Numer)
{
    cWezelFaktury* ptr = Wezel;
    while (ptr != nullptr)
    {
        if(ptr->mFaktura->Return_Numer() == Numer)
        {
            return ptr->mFaktura;
            break;
        }
        ptr = ptr->mNastepna;
    }
}

void cBazaFaktury::Zapis_Binarny(std::fstream* plik)
{
    cWezelFaktury* ptr = Wezel;
    while (ptr != nullptr)
    {
        ptr->mFaktura->Zapis(*plik);
        ptr = ptr->mNastepna;
    }
}

void cBazaFaktury::Odczyt_Binarny(std::fstream* plik)
{
    int typ;
    while (*plik >> typ)
    {
        if (typ == 13)
        {
            cFaktura* Faktura = new Przedsiebiorca;
            Faktura->Odczyt(*plik);
            this->Dodac_Fakture(Faktura);
        }
    }
}

cBazaFaktury::~cBazaFaktury()
{
    cWezelFaktury* ptr = Wezel;
    while(ptr != nullptr)
    {
        delete ptr->mFaktura;
        cWezelFaktury* ptr2 = ptr;
        ptr = ptr->mNastepna;
        delete ptr2;
    }
}
