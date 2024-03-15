#ifndef CDOSTAWA_H
#define CDOSTAWA_H
#include <QString>
class cBazaDostawa;
class QLineEdit;

class cDostawa
{
private:
    int mDzien;
    int mMiesiac;
    int mRok;
    int mIlosc;
    QString mTyp_Produktu;
    QString mNazwa_Produktu;
    unsigned long long int mLP_Produktu;
public:
    cDostawa();
    cDostawa(QString Nazawa, QString Typ, unsigned long long int LP, int Dzien, int Miesiac,
             int Rok, int Ilosc);
    friend cBazaDostawa;
    //void operator = (cDostawa* ptr);
    cDostawa& operator = (const cDostawa& ptr);
    void get_data(QLineEdit* Dzien, QLineEdit* Miesiac, QLineEdit* Rok);
    void take_dane(int Ilosc, QString Nazwa, QString Typ, unsigned long long int LP);
    unsigned long long int get_LP();
    int get_Ilosc();
    void Zapis(std::fstream& plik);
    void Odczyt(std::fstream& plik);
};

#endif // CDOSTAWA_H
