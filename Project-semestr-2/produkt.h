#ifndef PRODUKT_H
#define PRODUKT_H
#include <QString>

class cProdukt
{
private:
    unsigned long long int mLp;
    QString mNazwa;
    double mWaga;
    QString mTyp_Produktu;
    double mCena;
    double mVat;
    QString mMaterial;
public:
    cProdukt();
};

#endif // PRODUKT_H
