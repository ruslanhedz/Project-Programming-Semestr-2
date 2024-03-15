#ifndef CNADANIE_H
#define CNADANIE_H
#include <QString>
class cBazaNadanie;
class QLineEdit;

class cNadanie
{
private:
    QString mNazwa_Produktu;
    unsigned long long int mLP_produktu;
    int mIlosc_Sztuk_w_nadaniu;
    QString mAdres_Nadania;
    int mDzien;
    int mMiesiac;
    int mRok;
public:
    cNadanie();
    cNadanie(QString Nazwa, unsigned long long int LP, int Ilosc, QString Adres, int Dzien,
             int Miesiac, int Rok);
    friend cBazaNadanie;
    cNadanie& operator = (const cNadanie &ptr);
    bool Sprawdz_Date();
    bool Sprawdz_Adres();
    int Return_Dzien();
    int Return_Miesiac();
    int Return_Rok();
    QString Return_Adres();
    void get_dane(QLineEdit* Dzien, QLineEdit* Miesiac, QLineEdit* Rok, QLineEdit* Adres);
    void get_dane(QLineEdit* Dzien, QLineEdit* Miesiac, QLineEdit* Rok);
    void get_dane(QLineEdit* Adres);
    void take_dane(QString Nazwa, unsigned long long int LP, int Ilosc);
    void take_dane(QString Nazwa, unsigned long long int LP, int Ilosc, int Dzien, int Miesiac, int Rok);
    void take_dane(QString Nazwa, unsigned long long int LP, int Ilosc, QString Adres);
    void take_dane(int Dzien, int Miesiac, int Rok);
    void take_dane(QString Adres);
    unsigned long long int get_LP();
    int Return_Ilosc();
    void Zapisac(std::fstream& plik);
    void Odczyt(std::fstream& plik);
};

#endif // CNADANIE_H
