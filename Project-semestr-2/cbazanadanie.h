#ifndef CBAZANADANIE_H
#define CBAZANADANIE_H
#include "cwezelnadanie.h"
class QListWidget;
class cNadanie;

class cBazaNadanie
{
private:
    cWezelNadanie* Wezel;
public:
    cBazaNadanie();
    void Dodac_Nadanie(cNadanie*);
    void Pokaz_Liste(QListWidget*);
    void Usunac_Nadanie(int index);
    void Ponowic_Liste(QListWidget*);
    cNadanie Return_Nadanie(int index);
    cNadanie* Return_wsk_Nadanie(int index);
    void Zapis_Binarny(std::fstream* plik);
    void Odczyt_Binarny(std::fstream* plik);
    ~cBazaNadanie();
};

#endif // CBAZANADANIE_H
