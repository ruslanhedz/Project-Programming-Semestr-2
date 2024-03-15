#ifndef MYAPPLICATION_H
#define MYAPPLICATION_H

#include <QApplication>
#include "cbaza.h"

class MyApplication : public QApplication
{
public:
    MyApplication(int argc, char *argv[]);
    ~MyApplication();
    static cBaza Baza_Produkty;
};

#endif // MYAPPLICATION_H
