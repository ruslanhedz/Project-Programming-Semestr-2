#include "wszystkieprodukty.h"
#include "ui_wszystkieprodukty.h"
#include "dodanienowegoproduktu.h"
#include "cbaza.h"
#include "znalezcprodukt.h"
#include "produktinfo.h"
#include "ctasmy.h"
//#include "mainwindow.h"

WszystkieProdukty::WszystkieProdukty(QWidget *parent, cBaza* aBaza) :
    QDialog(parent),
    ui(new Ui::WszystkieProdukty)
{
    ui->setupUi(this);
    BazaProdukty = aBaza;
//    cProdukt* ptr = new cTasmy(1, 100000, 1, "1", "taśmy", "1", 1, "1", 1, 1, 1, 1, 1, "1");
//    cProdukt* ptr2 = new cTasmy(2, 100000, 1, "2", "taśmy", "1", 1, "1", 1, 1, 1, 1, 1, "1");
//    cProdukt* ptr3 = new cTasmy(3, 100000, 1, "3", "taśmy", "1", 1, "1", 1, 1, 1, 1, 1, "1");
//    cProdukt* ptr4 = new cTasmy(4, 100000, 1, "4", "taśmy", "1", 1, "1", 1, 1, 1, 1, 1, "1");
//    cProdukt* ptr5 = new cTasmy(5, 100000, 1, "5", "taśmy", "1", 1, "1", 1, 1, 1, 1, 1, "1");
//    BazaProdukty->Dodac_produkt(ptr);
//    BazaProdukty->Dodac_produkt(ptr2);
//    BazaProdukty->Dodac_produkt(ptr3);
//    BazaProdukty->Dodac_produkt(ptr4);
//    BazaProdukty->Dodac_produkt(ptr5);

    BazaProdukty->Pokaz(ui->listWidget);
}

WszystkieProdukty::~WszystkieProdukty()
{
    delete ui;
}

void WszystkieProdukty::on_DodacButton_clicked()
{
//    Dodanie_Produktu = new DodanieNowegoProduktu(nullptr, BazaProdukty);
//    Dodanie_Produktu->setModal(true);
//    Dodanie_Produktu->exec();
//    this->close();
//    this->deleteLater();
    std::shared_ptr<DodanieNowegoProduktu> Dodanie_Produktu = std::make_shared<DodanieNowegoProduktu>(nullptr, BazaProdukty);
    Dodanie_Produktu->setModal(true);
    Dodanie_Produktu->exec();
    this->close();
}


void WszystkieProdukty::on_UsunacButton_clicked()
{
    BazaProdukty->Usunac_Produkt(ui->listWidget->currentRow());
    BazaProdukty->Ponowic_Liste(ui->listWidget);
    //ui->pushButton_4->setText(QString::number(ui->listWidget->currentRow()));
}


void WszystkieProdukty::on_ZnalezcButton_clicked()
{
    std::shared_ptr<ZnalezcProdukt> Znalezc_Produkt = std::make_shared<ZnalezcProdukt>(nullptr, BazaProdukty);
    Znalezc_Produkt->setModal(true);
    Znalezc_Produkt->exec();
    this->close();
}


void WszystkieProdukty::on_listWidget_itemDoubleClicked(QListWidgetItem *item)
{
    cProdukt* Produkt;
    Produkt = BazaProdukty->Return_Produkt(ui->listWidget->currentRow());
    std::shared_ptr<ProduktInfo> Produkt_Information = std::make_shared<ProduktInfo>(nullptr, BazaProdukty, Produkt);
    Produkt_Information->setModal(true);
    Produkt_Information->exec();
    BazaProdukty->Ponowic_Liste(ui->listWidget);
}


void WszystkieProdukty::on_InfomacjaButton_clicked()
{
    cProdukt* Produkt;
    Produkt = BazaProdukty->Return_Produkt(ui->listWidget->currentRow());
    std::shared_ptr<ProduktInfo> Produkt_Information = std::make_shared<ProduktInfo>(nullptr, BazaProdukty, Produkt);
    Produkt_Information->setModal(true);
    Produkt_Information->exec();
}

