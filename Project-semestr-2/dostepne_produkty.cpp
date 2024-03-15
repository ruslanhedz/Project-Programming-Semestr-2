#include "dostepne_produkty.h"
#include "ui_dostepne_produkty.h"
#include "cbaza.h"
#include <QListWidgetItem>
//#include "zmiana_ilosci.h"
#include "zmianailosci.h"
#include "produktinfo.h"

Dostepne_Produkty::Dostepne_Produkty(QWidget *parent, cBaza* aBaza) :
    QDialog(parent), BazaProdukty(aBaza),
    ui(new Ui::Dostepne_Produkty)
{
    ui->setupUi(this);
    BazaProdukty->Pokaz_Dodstepne(ui);
    connect(ui->ZmienicIloscButton, &QPushButton::clicked, this, &Dostepne_Produkty::on_clicked_zmianaIlosci);
    connect(ui->EdytowacButton, &QPushButton::clicked, this, &Dostepne_Produkty::on_clicked_Edytowac);
    connect(ui->InfoButton, &QPushButton::clicked, this, &Dostepne_Produkty::on_clicked_InfoProdukt);
    connect(ui->listWidget, SIGNAL(itemDoubleClicked(QListWidgetItem*)), this, SLOT(on_doubleClicked_ListWidget(QListWidgetItem*)));
   }

void Dostepne_Produkty::on_clicked_zmianaIlosci()
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
    std::shared_ptr<ZmianaIlosci> Zmiana_Ilosci = std::make_shared<ZmianaIlosci>(nullptr, Produkt);
    Zmiana_Ilosci->setModal(true);
    Zmiana_Ilosci->exec();
    this->close();
}

void Dostepne_Produkty::on_clicked_Edytowac()
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
    std::shared_ptr<DodanieNowegoProduktu> Edytowanie_Produktu =
        std::make_shared<DodanieNowegoProduktu>(nullptr, BazaProdukty, Produkt);
    Edytowanie_Produktu->setModal(true);
    Edytowanie_Produktu->exec();
    this->close();
}

void Dostepne_Produkty::on_clicked_InfoProdukt()
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
    std::shared_ptr<ProduktInfo> Produkt_Info = std::make_shared<ProduktInfo>(nullptr, BazaProdukty, Produkt);
    Produkt_Info->setModal(true);
    Produkt_Info->exec();
    this->close();
}

void Dostepne_Produkty::on_doubleClicked_ListWidget(QListWidgetItem *item)
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
    std::shared_ptr<ZmianaIlosci> Zmiana_Ilosci = std::make_shared<ZmianaIlosci>(nullptr, Produkt);
    Zmiana_Ilosci->setModal(true);
    Zmiana_Ilosci->exec();
    this->close();
}

Dostepne_Produkty::~Dostepne_Produkty()
{
    delete ui;
}
