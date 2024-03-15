#include "dostepne_amazon.h"
#include "ui_dostepne_amazon.h"
#include "cbaza.h"
#include "zmieniciloscamazon.h"
#include "dodanienowegoproduktu.h"
#include "produktinfo.h"

Dostepne_Amazon::Dostepne_Amazon(QWidget *parent, cBaza* aBaza) :
    QDialog(parent),
    ui(new Ui::Dostepne_Amazon), BazaProdukty(aBaza)
{
    ui->setupUi(this);
    BazaProdukty->Pokaz_Dostepne_Amazon(ui);
}

Dostepne_Amazon::~Dostepne_Amazon()
{
    delete ui;
}

void Dostepne_Amazon::on_ZmienicIloscButton_clicked()
{
    QString line = ui->listWidget->currentItem()->text();
    QString LP = "";
    int i = 1;
    while (line[i] != ']')
    {
        LP += line[i];
        i++;
    }
    unsigned long long int uLP = LP.toULongLong();
    cProdukt* Produkt = BazaProdukty->Return_Produkt(uLP);
    std::shared_ptr<ZmienicIloscAmazon>Zmienic_Ilosc =
        std::make_shared<ZmienicIloscAmazon>(nullptr, Produkt);
    Zmienic_Ilosc->setModal(true);
    Zmienic_Ilosc->exec();
    this->close();
}


void Dostepne_Amazon::on_EdytowacButton_clicked()
{
    QString line = ui->listWidget->currentItem()->text();
    QString LP = "";
    int i = 1;
    while (line[i] != ']')
    {
        LP += line[i];
        i++;
    }
    unsigned long long int uLP = LP.toULongLong();
    cProdukt* Produkt = BazaProdukty->Return_Produkt(uLP);
    std::shared_ptr<DodanieNowegoProduktu>Edytowac_Produkt =
        std::make_shared<DodanieNowegoProduktu>(nullptr, BazaProdukty, Produkt);
    Edytowac_Produkt->setModal(true);
    Edytowac_Produkt->exec();
    this->close();
}


void Dostepne_Amazon::on_InfoButton_clicked()
{
    QString line = ui->listWidget->currentItem()->text();
    QString LP = "";
    int i = 1;
    while (line[i] != ']')
    {
        LP += line[i];
        i++;
    }
    unsigned long long int uLP = LP.toULongLong();
    cProdukt* Produkt = BazaProdukty->Return_Produkt(uLP);
    std::shared_ptr<ProduktInfo>Produkt_Info =
        std::make_shared<ProduktInfo>(nullptr, BazaProdukty, Produkt);
    Produkt_Info->setModal(true);
    Produkt_Info->exec();
    this->close();
}


void Dostepne_Amazon::on_listWidget_itemDoubleClicked(QListWidgetItem *item)
{
    QString line = ui->listWidget->currentItem()->text();
    QString LP = "";
    int i = 1;
    while (line[i] != ']')
    {
        LP += line[i];
        i++;
    }
    unsigned long long int uLP = LP.toULongLong();
    cProdukt* Produkt = BazaProdukty->Return_Produkt(uLP);
    std::shared_ptr<ZmienicIloscAmazon>Zmienic_Ilosc =
        std::make_shared<ZmienicIloscAmazon>(nullptr, Produkt);
    Zmienic_Ilosc->setModal(true);
    Zmienic_Ilosc->exec();
    this->close();
}

