#include "mainwindow.h"

#include <QApplication>
//#include "myapplication.h"
//#include "DefinitionsofBases.h"
#include "cbaza.h"
#include "cbazadostawa.h"
#include "cbazanadanie.h"
#include "cbazafaktury.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //MyApplication a(argc, argv);
    std::fstream file_baza;
//    file_baza.open("Baza.dat", std::ios::out | std::ios::binary);
    cBaza* Baza_Produkty = new cBaza;
    cBazaDostawa* Baza_Dostaw = new cBazaDostawa;
    cBazaNadanie* Baza_Nadan = new cBazaNadanie;
    cBazaFaktury* Baza_Faktur = new cBazaFaktury;
    MainWindow w(nullptr, Baza_Produkty, Baza_Dostaw, Baza_Nadan, Baza_Faktur, &file_baza);
    //w.setAttribute(Qt::WA_DeleteOnClose);
    //a.Baza_Produkty = new cBaza;
    w.show();
    return a.exec();
}
