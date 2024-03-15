#include "znalezcprodukt.h"
#include "ui_znalezcprodukt.h"
#include "cbaza.h"
#include "produktinfo.h"

ZnalezcProdukt::ZnalezcProdukt(QWidget *parent, cBaza* Baza_Produkty) :
    QDialog(parent),
    ui(new Ui::ZnalezcProdukt)
{
    ui->setupUi(this);
    Baza = Baza_Produkty;
}

ZnalezcProdukt::~ZnalezcProdukt()
{
    delete ui;
}

void ZnalezcProdukt::on_ZnalezcButton_clicked()
{
    ui->listWidget->clear();
    if(ui->comboBox->currentIndex() == 0)
    {
        Baza->Znalezc_LP(ui->listWidget, (ui->ZnalezcLineEdit->text()).toULongLong());
    }
    else {
        Baza->Znalezc_Nazwa(ui->listWidget, ui->ZnalezcLineEdit->text());
    }
}


void ZnalezcProdukt::on_listWidget_itemDoubleClicked(QListWidgetItem *item)
{
    QString LP = "";
    int i = 1;
    while(ui->listWidget->currentItem()->text()[i] != ']')
    {
        LP+=ui->listWidget->currentItem()->text()[i];
        i++;
    }
    cProdukt* Produkt = Baza->Return_Produkt(LP.toULongLong());
    std::shared_ptr<ProduktInfo> Produkt_Info =
        std::make_shared<ProduktInfo>(nullptr, Baza, Produkt);
    Produkt_Info->setModal(true);
    Produkt_Info->exec();

}

