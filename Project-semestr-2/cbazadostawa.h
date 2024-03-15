#ifndef CBAZADOSTAWA_H
#define CBAZADOSTAWA_H
#include "cwezeldostawa.h"
#include "cdostawa.h"
class QListWidget;

class cBazaDostawa
{
private:
    cWezelDostawa* Wezel;
public:
    cBazaDostawa();
    void Dodac_Dostawe(cDostawa*);
    void Pokaz_Liste(QListWidget*);
    void Usunac_Dostawe(int index);
    void Ponowic_Liste(QListWidget*);
    cDostawa Return_Dostawa(int index);
    cDostawa* Return_wsk_Dostawa(int index);
    void Zapis_Binarny(std::fstream* plik);
    void Odczyt_Binarny(std::fstream* plik);
    ~cBazaDostawa();
};

#endif // CBAZADOSTAWA_H
