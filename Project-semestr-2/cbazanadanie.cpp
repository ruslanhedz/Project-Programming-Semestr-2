#include "cbazanadanie.h"
#include <QListWidget>
#include "mainwindow.h"

cBazaNadanie::cBazaNadanie()
{
    Wezel = nullptr;
}

void cBazaNadanie::Dodac_Nadanie(cNadanie* Nadanie)
{
    cWezelNadanie* ptr = new cWezelNadanie;
    ptr->mNadanie = Nadanie;
    ptr->mNastepne = Wezel;
    Wezel = ptr;
}

void cBazaNadanie::Pokaz_Liste(QListWidget* Widget)
{
    cWezelNadanie* ptr = Wezel;
    while(ptr != nullptr)
    {
        Widget->addItem("[" + QString::number(ptr->mNadanie->mLP_produktu) + "]" +
                        ptr->mNadanie->mNazwa_Produktu + " | " + "Ilość sztuk w nadaniu: " +
                        QString::number(ptr->mNadanie->mIlosc_Sztuk_w_nadaniu) + " | Adres nadanie: " +
                        ptr->mNadanie->mAdres_Nadania);
        ptr = ptr->mNastepne;
    }
}

void cBazaNadanie::Usunac_Nadanie(int index)
{
    if(index == 0)
    {
        if(Wezel->mNastepne == nullptr)
        {
            delete Wezel->mNadanie;
            delete Wezel;
            Wezel = nullptr;
        }
        else{
            cWezelNadanie* ptr = Wezel;
            Wezel = Wezel->mNastepne;
            delete ptr->mNadanie;
            delete ptr;
        }
    }
    else{
        cWezelNadanie* ptr = Wezel;
        for (int i = 0; i < index-1; i++)
        {
            ptr = ptr->mNastepne;
        }
        cWezelNadanie* ptr2 = ptr->mNastepne->mNastepne;
        delete ptr->mNastepne->mNadanie;
        delete ptr->mNastepne;
        ptr->mNastepne = ptr2;
    }
}

void cBazaNadanie::Ponowic_Liste(QListWidget* Widget)
{
    Widget->clear();
    cBazaNadanie::Pokaz_Liste(Widget);
}

cNadanie cBazaNadanie::Return_Nadanie(int index)
{
    cWezelNadanie* ptr = Wezel;
    for(int i = 0; i < index; i++)
    {
        ptr = ptr->mNastepne;
    }
    return *(ptr->mNadanie);
}

cNadanie* cBazaNadanie::Return_wsk_Nadanie(int index)
{
    cWezelNadanie* ptr = Wezel;
    for (int i = 0; i < index; i++)
    {
        ptr = ptr->mNastepne;
    }
    return ptr->mNadanie;
}

cBazaNadanie::~cBazaNadanie()
{
    cWezelNadanie* ptr = Wezel;
    while(ptr != nullptr)
    {
        delete ptr->mNadanie;
        cWezelNadanie* ptr2 = ptr;
        ptr = ptr->mNastepne;
        delete ptr2;
    }
}

void cBazaNadanie::Zapis_Binarny(std::fstream* plik)
{
    cWezelNadanie* ptr = Wezel;
    while(ptr != nullptr)
    {
        ptr->mNadanie->Zapisac(*plik);
        ptr = ptr->mNastepne;
    }
}

void cBazaNadanie::Odczyt_Binarny(std::fstream* plik)
{
    int typ;
    *plik >> typ;
    while(typ == 12)
    {
        cNadanie* Nadanie = new cNadanie;
        Nadanie->Odczyt(*plik);
        this->Dodac_Nadanie(Nadanie);
        *plik >> typ;
    }
}
