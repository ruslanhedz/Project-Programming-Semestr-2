#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <memory.h>
#include <fstream>
class DodanieNowegoProduktu;
class cBaza;
class QLabel;
class LayoutClass;
class QWidget;
class WszystkieProdukty;
class Dostepne_Produkty;
class QLineEdit;
class cBazaDostawa;
class cBazaNadanie;
class cBazaFaktury;
class cProdukt;
//class Dostepne_Amazon;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr, cBaza* aBaza = nullptr,
               cBazaDostawa* aBazaDostawa = nullptr, cBazaNadanie* aBazaNadan = nullptr,
               cBazaFaktury* aBazaFaktury = nullptr, std::fstream* file = nullptr);
    ~MainWindow();
    //DodanieNowegoProduktu* Dodanie_EdycjaProduktu;

private slots:

//    void on_Listaproduktow_clicked();


    void on_ListaproduktowButton_clicked();

    void on_Listadostepnych_clicked();

    void on_ListaAmazon_clicked();

    void on_ListaDostaw_clicked();

    void on_ListaNadan_clicked();

    void on_WypelnicFakture_clicked();

    void on_BazaFaktur_clicked();

    void on_ZapisacButton_clicked();

private:
    Ui::MainWindow *ui;
    cBaza* bazaProdukty;
    cBazaDostawa* Baza_Dostawa;
    cBazaNadanie* Baza_Nadan;
    cBazaFaktury* Baza_Faktur;
    std::fstream* file_baza;
    //std::shared_ptr<Dostepne_Amazon>Dostepne_Na_Amazonie;
};

//void operator+= (QLabel* a, QString b);
void operator + (QLabel* a, QString b);

void operator + (QLabel* a, QChar b);

//std::fstream operator << (std::fstream file, cProdukt* ptr);
std::fstream& operator << (std::fstream& file, int& a);
std::fstream& operator << (std::fstream& file, unsigned long long int& a);
std::fstream& operator << (std::fstream& file, QString& a);
std::fstream& operator << (std::fstream& file, double& a);
std::fstream& operator << (std::fstream& file, float& a);
std::fstream& operator << (std::fstream& file, cProdukt* Produkt);
std::fstream& operator >> (std::fstream& file, int& a);
std::fstream& operator >> (std::fstream& file, unsigned long long int& a);
std::fstream& operator >> (std::fstream& file, QString& a);
std::fstream& operator >> (std::fstream& file, double& a);
std::fstream& operator >> (std::fstream& file, float& a);

#endif // MAINWINDOW_H
