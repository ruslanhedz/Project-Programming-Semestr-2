#ifndef CWEZELFAKTURY_H
#define CWEZELFAKTURY_H
#include "przedsiebiorca.h"

class cWezelFaktury
{
public:
    cFaktura *mFaktura;
    cWezelFaktury* mNastepna;
    cWezelFaktury();
};

#endif // CWEZELFAKTURY_H
