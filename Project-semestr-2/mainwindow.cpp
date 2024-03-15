#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "wszystkieprodukty.h"
#include "dostepne_produkty.h"
#include "dostepne_amazon.h"
#include "listadostaw.h"
#include "cbazadostawa.h"
#include "listanadan.h"
#include "zapelnicfakture.h"
#include "listafaktur.h"
#include "cprodukt.h"
#include "cbaza.h"
#include <fstream>
#include "cbazanadanie.h"
#include "cbazafaktury.h"
//#include "layoutclass.h"

MainWindow::MainWindow(QWidget *parent, cBaza* aBaza, cBazaDostawa* aBazaDostawa,
                       cBazaNadanie* aBazaNadan, cBazaFaktury* aBazaFaktury,
                       std::fstream* file)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow), Baza_Dostawa(aBazaDostawa), Baza_Nadan(aBazaNadan),
    Baza_Faktur(aBazaFaktury), file_baza(file)
{
    ui->setupUi(this);
    bazaProdukty = aBaza;
    file_baza->open("D:/Projekt II semestr/Projektversion1/Baza.dat", std::ios::in | std::ios::binary);
    bazaProdukty->Odczyt(file_baza);
    Baza_Dostawa->Odczyt_Binarny(file_baza);
    Baza_Nadan->Odczyt_Binarny(file_baza);
    Baza_Faktur->Odczyt_Binarny(file_baza);
    file_baza->close();
//    connect(ui->ListaproduktowButton, &QPushButton::clicked, this, &MainWindow::on_Listaproduktow_clicked);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete bazaProdukty;
    delete Baza_Dostawa;
    delete Baza_Nadan;
    delete Baza_Faktur;
}


void operator + (QLabel* a, QString b)
{
    a->setText(a->text() + b);
}

void operator + (QLabel* a, QChar b)
{
    a->setText(a->text() + b);
}

void MainWindow::on_ListaproduktowButton_clicked()
{
    std::shared_ptr<WszystkieProdukty>Wszystkie_Produkty = std::make_shared<WszystkieProdukty>(nullptr, bazaProdukty);
    Wszystkie_Produkty->setModal(true);
    Wszystkie_Produkty->exec();
}


void MainWindow::on_Listadostepnych_clicked()
{
    std::shared_ptr<Dostepne_Produkty>DostepneProdukty = std::make_shared<Dostepne_Produkty>(nullptr, bazaProdukty);
    DostepneProdukty->setModal(true);
    DostepneProdukty->exec();
}


void MainWindow::on_ListaAmazon_clicked()
{
    std::shared_ptr<Dostepne_Amazon>Dostepne_Na_Amazonie = std::make_shared<Dostepne_Amazon>(nullptr, bazaProdukty);
    Dostepne_Na_Amazonie->setModal(true);
    Dostepne_Na_Amazonie->exec();
}


void MainWindow::on_ListaDostaw_clicked()
{
    std::shared_ptr<ListaDostaw>Lista_Dostaw =
        std::make_shared<ListaDostaw>(nullptr, bazaProdukty, Baza_Dostawa);
    Lista_Dostaw->setModal(true);
    Lista_Dostaw->exec();
}


void MainWindow::on_ListaNadan_clicked()
{
    std::shared_ptr<ListaNadan>Lista_Nadan =
        std::make_shared<ListaNadan>(nullptr, bazaProdukty, Baza_Nadan);
    Lista_Nadan->setModal(true);
    Lista_Nadan->exec();
}


void MainWindow::on_WypelnicFakture_clicked()
{
    std::shared_ptr<ZapelnicFakture> Zapelnic_Fakture =
        std::make_shared<ZapelnicFakture>(nullptr, bazaProdukty, Baza_Faktur);
    Zapelnic_Fakture->setModal(true);
    Zapelnic_Fakture->exec();
}


void MainWindow::on_BazaFaktur_clicked()
{
    std::shared_ptr<ListaFaktur> Lista_Faktur =
        std::make_shared<ListaFaktur>(nullptr, bazaProdukty, Baza_Faktur);
    Lista_Faktur->setModal(true);
    Lista_Faktur->exec();
}

//std::fstream operator << (std::fstream file, int a);
//std::fstream operator << (std::fstream file, unsigned long long int a);
//std::fstream operator << (std::fstream file, QString a);
//std::fstream operator << (std::fstream file, double a);
//std::fstream operator << (std::fstream file, float a);

std::fstream& operator << (std::fstream& file, int& a)
{
    file.write(reinterpret_cast<const char*>(&a), sizeof(int));
    return file;
}

std::fstream& operator << (std::fstream& file, unsigned long long int& a)
{
    file.write(reinterpret_cast<const char*>(&a), sizeof(unsigned long long int));
    return file;
}

std::fstream& operator << (std::fstream& file, QString& a)
{
    int asize = a.toStdString().size();
    file.write(reinterpret_cast<const char*>(&asize), sizeof(int));
    file.write(a.toStdString().data(), a.toStdString().size());
    return file;
}

std::fstream& operator << (std::fstream& file, double& a)
{
    file.write(reinterpret_cast<const char*>(&a), sizeof(double));
    return file;
}

std::fstream& operator << (std::fstream& file, float& a)
{
    file.write(reinterpret_cast<const char*>(&a), sizeof(float));
    return file;
}

std::fstream& operator << (std::fstream& file, cProdukt* Produkt)
{
    Produkt->Zapis_Binarny(file);
    return file;
}

//std::fstream& operator >> (std::fstream& file, int& a);
//std::fstream& operator >> (std::fstream& file, unsigned long long int& a);
//std::fstream& operator >> (std::fstream& file, QString& a);
//std::fstream& operator >> (std::fstream& file, double& a);
//std::fstream& operator >> (std::fstream& file, float& a);

std::fstream& operator >> (std::fstream& file, int& a)
{
    file.read(reinterpret_cast<char*>(&a), sizeof(int));
    return file;
}

std::fstream& operator >> (std::fstream& file, unsigned long long int& a)
{
    file.read(reinterpret_cast<char*>(&a), sizeof(unsigned long long int));
    return file;
}

std::fstream& operator >> (std::fstream& file, QString& a)
{
    int asize;
    file.read(reinterpret_cast<char*>(&asize), sizeof(int));
    std::string line;
    line.resize(asize);
    file.read(&line[0], line.size());
    a = QString::fromStdString(line);
    return file;
}

std::fstream& operator >> (std::fstream& file, double& a)
{
    file.read(reinterpret_cast<char*>(&a), sizeof(double));
    return file;
}

std::fstream& operator >> (std::fstream& file, float& a)
{
    file.read(reinterpret_cast<char*>(&a), sizeof(float));
    return file;
}

void MainWindow::on_ZapisacButton_clicked()
{
    file_baza->open("D:/Projekt II semestr/Projektversion1/Baza.dat", std::ios::out | std::ios::binary);
    bazaProdukty->Zapis(file_baza);
    int Dostawy = 11;
    *file_baza << Dostawy;
    Baza_Dostawa->Zapis_Binarny(file_baza);
    int Nadanie = 12;
    *file_baza << Nadanie;
    Baza_Nadan->Zapis_Binarny(file_baza);
    int Faktura = 13;
    *file_baza << Faktura;
    Baza_Faktur->Zapis_Binarny(file_baza);
    file_baza->close();
}

