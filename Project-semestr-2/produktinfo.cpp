#include "produktinfo.h"
#include "ui_produktinfo.h"
#include "cprodukt.h"
#include "dodanienowegoproduktu.h"
#include "cbaza.h"

ProduktInfo::ProduktInfo(QWidget *parent, cBaza* aBaza, cProdukt* Produkt) :
    QDialog(parent), mProdukt(Produkt),
    ui(new Ui::ProduktInfo)
{
    ui->setupUi(this);
    BazaProdukty = aBaza;
    mProdukt->Info_Produkt(ui, this);
    connect(ui->UsunacButton, &QPushButton::clicked, this, &ProduktInfo::on_Ususnac_clicked);
}

ProduktInfo::~ProduktInfo()
{
    delete ui;
}

void ProduktInfo::on_EdytowacButton_clicked()
{
    this->close();
    Edytowanie_Produktu = new DodanieNowegoProduktu(nullptr, BazaProdukty, mProdukt);
    Edytowanie_Produktu->setModal(true);
    Edytowanie_Produktu->exec();
}

void ProduktInfo::on_Ususnac_clicked()
{
    BazaProdukty->Usunac_Produkt(mProdukt);
    this->close();
}

