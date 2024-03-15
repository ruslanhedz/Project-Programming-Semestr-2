#ifndef CWEZELNADANIE_H
#define CWEZELNADANIE_H
#include "cnadanie.h"

class cWezelNadanie
{
public:
    cNadanie* mNadanie;
    cWezelNadanie* mNastepne;
    cWezelNadanie();
};

#endif // CWEZELNADANIE_H
