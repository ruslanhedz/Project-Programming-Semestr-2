#include "cbaza.h"
#include "ui_dostepne_produkty.h"
#include "ui_dostepne_amazon.h"
#include <QTableWidget>
#include "mainwindow.h"
#include "ctasmy.h"
#include "cbluza.h"
#include "chdd.h"
#include "ckolanka.h"
#include "csluchawki.h"
#include "ckoszulka.h"
#include "crecznik.h"
#include "cssd.h"

cBaza::cBaza()
{
    Wezel = nullptr;
}

void cBaza::Pokaz(QListWidget* widget)
{
    if(Wezel == nullptr)
    {
        return;
    }
    else{
        cWezel* ptr = Wezel;
        while(ptr != nullptr)
        {
            widget->addItem("[" + QString::number(ptr->Produkt->Return_LP())+ "]" + ptr->Produkt->Return_Name());
            ptr = ptr->mNastepny;
        }
    }
}

void cBaza::Dodac_produkt(cProdukt* ptr)
{
    cWezel* nowyWezel = new cWezel;
    nowyWezel->mNastepny = Wezel;
    nowyWezel->Produkt = ptr;
    Wezel = nowyWezel;
//    if(Wezel == nullptr)
//    {
//        Wezel = new cWezel;
//        Wezel->Produkt = ptr;
//    }
//    else{
//        cWezel* ptr2 = Wezel;
//        while(ptr2->mNastepny != nullptr)
//        {
//            ptr2 = ptr2->mNastepny;
//        }
//        cWezel* ptr3 = new cWezel;
//        ptr3->Produkt = ptr;
//        ptr3->mNastepny = nullptr;
//        ptr2->mNastepny = ptr3;
//    }
}

void cBaza::Usunac_Produkt(int index)
{
//    cWezel* ptr = Wezel;
//    for(int i = 0; i < (index - 2); i++)
//    {
//        ptr =  ptr->mNastepny;
//    }
//    cWezel* ptr2 = ptr->mNastepny;
//    cWezel* ptr3 = ptr2->mNastepny;
//    delete ptr2;
//    ptr->mNastepny = ptr3;
//    ptr3 = nullptr;
    if(index == 0)
    {
        if(Wezel->mNastepny == nullptr)
        {
            delete Wezel->Produkt;
            delete Wezel;
            Wezel = nullptr;
        }
        else {
            cWezel* ptr = Wezel;
            ptr = ptr->mNastepny;
            //delete Wezel->mNastepny;
            delete Wezel->Produkt;
            delete Wezel;
            Wezel = ptr;
        }
    }
    else {
        cWezel* ptr = Wezel;
        for (int i = 0; i < index - 1; i++)
        {
            ptr = ptr->mNastepny;
        }
        cWezel* ptr2 = ptr->mNastepny->mNastepny;
        delete ptr->mNastepny->Produkt;
        delete ptr->mNastepny;
        ptr->mNastepny = ptr2;
    }
}

void cBaza::Znalezc_LP(QListWidget* Widget, unsigned long long int lp)
{
    cWezel* ptr = Wezel;
    while(ptr != nullptr)
    {
        if(ptr->Produkt->Return_LP() == lp)
        {
            Widget->addItem("[" + QString::number(lp) + "]" + ptr->Produkt->Return_Name());
            break;
        }
        ptr = ptr->mNastepny;
    }
}

void cBaza::Znalezc_Nazwa(QListWidget* widget, QString Nazwa)
{
    cWezel* ptr = Wezel;
    while(ptr != nullptr)
    {
        if(ptr->Produkt->Return_Name() == Nazwa)
        {
            widget->addItem("[" + QString::number(ptr->Produkt->Return_LP()) + "]" + ptr->Produkt->Return_Name());
        }
        ptr = ptr->mNastepny;
    }
}

cProdukt* cBaza::Return_Produkt(int index)
{
    cWezel* ptr = Wezel;
    for (int i = 0; i <= index-1; i++)
    {
        ptr = ptr->mNastepny;
    }
    return ptr->Produkt;
}

void cBaza::Zamiana_Produktu(cProdukt* Produkt)
{
    cWezel* ptr = Wezel;
    while(ptr != nullptr)
    {
        if(Produkt->Return_LP() == ptr->Produkt->Return_LP())
        {
            delete ptr->Produkt;
            ptr->Produkt = Produkt;
            break;
        }
        ptr = ptr->mNastepny;
    }
}

void cBaza::Usunac_Produkt(cProdukt* Produkt)
{
    if (Wezel->mNastepny == 0 && Wezel->Produkt == Produkt)
    {
        delete Wezel;
    }
    else if(Wezel->Produkt == Produkt && Wezel->mNastepny != 0)
    {
        cWezel* ptr = Wezel->mNastepny;
        delete Wezel;
        Wezel = ptr;
    }
    else
    {
        cWezel* ptr = Wezel;
        while(ptr->mNastepny != 0)
        {
            if(ptr->mNastepny->Produkt == Produkt)
            {
                cWezel* ptr2 = ptr->mNastepny->mNastepny;
                delete ptr->mNastepny;
                ptr->mNastepny = ptr2;
                break;
            }
            ptr = ptr->mNastepny;
        }
    }

}

void cBaza::Pokaz_Dodstepne(Ui::Dostepne_Produkty* ui)
{
    cWezel* ptr = Wezel;
    while (ptr != nullptr)
    {
        if(ptr->Produkt != nullptr && ptr->Produkt->Return_Ilosc() != 0)
        {
            ui->listWidget->addItem("[" + QString::number(ptr->Produkt->Return_LP()) + "]" +
                                    ptr->Produkt->Return_Name() + "| Ilość: " +
                                    QString::number(ptr->Produkt->Return_Ilosc()));
        }
        ptr = ptr->mNastepny;
    }
}

cProdukt* cBaza::Return_Produkt(unsigned long long int LP)
{
    cProdukt* ptr2 = nullptr;
    cWezel* ptr = Wezel;
    while (ptr != nullptr)
    {
        if(ptr->Produkt->Return_LP() == LP)
        {
            ptr2 = ptr->Produkt;
            break;
        }
        ptr = ptr->mNastepny;
    }
    return ptr2;
}

void cBaza::Pokaz_Dostepne_Amazon(Ui::Dostepne_Amazon* ui)
{
    cWezel* ptr = Wezel;
    while(ptr != nullptr)
    {
        if(ptr->Produkt->Return_Ilosc_Amazon() != 0)
        {
            ui->listWidget->addItem("[" + QString::number(ptr->Produkt->Return_LP()) + "]" +
                                    ptr->Produkt->Return_Name() + "|" + " Ilość: " +
                                    QString::number(ptr->Produkt->Return_Ilosc_Amazon()));
        }
        ptr = ptr->mNastepny;
    }
}

bool cBaza::Sparwdz_LP(unsigned long long int liczba)
{
    bool var = 1;
    cWezel* ptr = Wezel;
    while (ptr != nullptr)
    {
        if(ptr->Produkt->Return_LP() == liczba)
        {
            var = 0;
            break;
        }
        ptr = ptr->mNastepny;
    }
    return var;
}

void cBaza::WypiszNazwy(QComboBox* Box)
{
    cWezel* ptr = Wezel;
    while (ptr != nullptr)
    {
        Box->addItem(ptr->Produkt->Return_Name());
        ptr = ptr->mNastepny;
    }
}

cBaza::~cBaza()
{
    cWezel* ptr = Wezel;
    while(ptr != nullptr)
    {
        delete ptr->Produkt;
        cWezel* ptr2 = ptr;
        ptr = ptr->mNastepny;
        delete ptr2;
    }
}

cProdukt* cBaza::Return_Produkt(QString Nazwa)
{
    cWezel* ptr = Wezel;
    while(ptr != nullptr)
    {
        if(ptr->Produkt->Return_Name() == Nazwa)
        {
            return ptr->Produkt;
            break;
        }
        ptr = ptr->mNastepny;
    }
}

void cBaza::Ponowic_Liste(QListWidget* Widget)
{
    Widget->clear();
    cBaza::Pokaz(Widget);
}

void cBaza::Zapis(std::fstream* plik)
{
    int Produkty = 10;
    *plik << Produkty;
    cWezel* ptr = Wezel;
    while(ptr != nullptr)
    {
        *plik << ptr->Produkt;
        ptr = ptr->mNastepny;
    }
}

void cBaza::Odczyt(std::fstream* plik)
{
    int typ;
    *plik >> typ;
    if (typ == 10)
    {
        *plik >> typ;
        while(typ <= 10)
        {
            if (typ == 1)
            {
                cProdukt* Produkt = new cProdukt;
                Produkt->Odczyt_Binarny(*plik);
                this->Dodac_produkt(Produkt);
            }
            else if(typ == 2)
            {
                cProdukt* Produkt = new cTasmy;
                Produkt->Odczyt_Binarny(*plik);
                this->Dodac_produkt(Produkt);
            }
            else if (typ == 3)
            {
                cProdukt* Produkt = new cBluza;
                Produkt->Odczyt_Binarny(*plik);
                this->Dodac_produkt(Produkt);
            }
            else if(typ == 4)
            {
                cProdukt* Produkt = new cHDD;
                Produkt->Odczyt_Binarny(*plik);
                this->Dodac_produkt(Produkt);
            }
            else if(typ == 5)
            {
                cProdukt* Produkt = new cKolanka;
                Produkt->Odczyt_Binarny(*plik);
                this->Dodac_produkt(Produkt);
            }
            else if(typ == 6)
            {
                cProdukt* Produkt = new cSluchawki;
                Produkt->Odczyt_Binarny(*plik);
                this->Dodac_produkt(Produkt);
            }
            else if(typ == 7)
            {
                cProdukt* Produkt = new cKoszulka;
                Produkt->Odczyt_Binarny(*plik);
                this->Dodac_produkt(Produkt);
            }
            else if(typ == 8)
            {
                cProdukt* Produkt = new cRecznik;
                Produkt->Odczyt_Binarny(*plik);
                this->Dodac_produkt(Produkt);
            }
            else if (typ == 9)
            {
                cProdukt* Produkt = new cSSD;
                Produkt->Odczyt_Binarny(*plik);
                this->Dodac_produkt(Produkt);
            }
            *plik >> typ;
        }
    }
}
