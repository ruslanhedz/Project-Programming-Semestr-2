#include "cbazadostawa.h"
#include <QListWidget>
#include "cwezeldostawa.h"
#include "mainwindow.h"

cBazaDostawa::cBazaDostawa()
{
    Wezel = nullptr;
}

void cBazaDostawa::Dodac_Dostawe(cDostawa* Dostawa)
{
    cWezelDostawa* NowyWezel = new cWezelDostawa;
    NowyWezel->mNastepna = Wezel;
    NowyWezel->mDostawa = Dostawa;
    Wezel = NowyWezel;
}

void cBazaDostawa::Pokaz_Liste(QListWidget* Widget)
{
        cWezelDostawa* ptr = Wezel;
        while(ptr != nullptr)
        {
            Widget->addItem("[" + QString::number(ptr->mDostawa->mLP_Produktu) + "]" +
                        ptr->mDostawa->mNazwa_Produktu + "| Data dostawy: " +
                        QString::number(ptr->mDostawa->mDzien) + "." +
                        QString::number(ptr->mDostawa->mMiesiac) + "." +
                        QString::number(ptr->mDostawa->mRok) + "| Ilość sztuk: " +
                        QString::number(ptr->mDostawa->mIlosc));
            ptr = ptr->mNastepna;
        }
}

void cBazaDostawa::Usunac_Dostawe(int index)
{
    if(index == 0)
    {
        if(Wezel->mNastepna == nullptr)
        {
            delete Wezel->mDostawa;
            delete Wezel;
            Wezel = nullptr;
        }
        else {
            cWezelDostawa* ptr = Wezel->mNastepna;
            delete Wezel->mDostawa;
            delete Wezel;
            Wezel = ptr;
        }
    }
    else {
        cWezelDostawa* ptr = Wezel;
        for (int i = 0; i < index - 1; i++)
        {
            ptr = ptr->mNastepna;
        }
        cWezelDostawa* ptr2 = ptr->mNastepna->mNastepna;
        delete ptr->mNastepna->mDostawa;
        delete ptr->mNastepna;
        ptr->mNastepna = ptr2;
    }
}

void cBazaDostawa::Ponowic_Liste(QListWidget* Widget)
{
    Widget->clear();
    cBazaDostawa::Pokaz_Liste(Widget);
}

cDostawa cBazaDostawa::Return_Dostawa(int index)
{
    cWezelDostawa* ptr = Wezel;
    for (int i = 0; i < index; i++)
    {
        ptr = ptr->mNastepna;
    }
    return *(ptr->mDostawa);
}

cDostawa* cBazaDostawa::Return_wsk_Dostawa(int index)
{
    cWezelDostawa* ptr = Wezel;
    for (int i = 0; i < index; i++)
    {
        ptr = ptr->mNastepna;
    }
    return ptr->mDostawa;
}

cBazaDostawa::~cBazaDostawa()
{
    cWezelDostawa* ptr = Wezel;
    while(ptr != nullptr)
    {
        delete ptr->mDostawa;
        cWezelDostawa* ptr2 = ptr;
        ptr = ptr->mNastepna;
        delete ptr2;
    }
}

void cBazaDostawa::Zapis_Binarny(std::fstream* plik)
{
    cWezelDostawa* ptr = Wezel;
    while(ptr != nullptr)
    {
        ptr->mDostawa->Zapis(*plik);
        ptr = ptr->mNastepna;
    }
}

void cBazaDostawa::Odczyt_Binarny(std::fstream* plik)
{
    int typ;
    *plik >> typ;
    while(typ == 11)
    {
        cDostawa* Dostawa = new cDostawa;
        Dostawa->Odczyt(*plik);
        this->Dodac_Dostawe(Dostawa);
        *plik >> typ;
    }
}
