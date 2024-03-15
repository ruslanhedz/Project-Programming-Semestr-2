#include "listafaktur.h"
#include "ui_listafaktur.h"
#include "cbaza.h"
#include "cbazafaktury.h"
#include "zapelnicfakture.h"
#include "znalezcfakture.h"
#include "pokazfaktury.h"

ListaFaktur::ListaFaktur(QWidget *parent, cBaza* aBaza, cBazaFaktury* aBazaFaktury) :
    QDialog(parent),
    ui(new Ui::ListaFaktur), BazaProdukty(aBaza), BazaFaktury(aBazaFaktury)
{
    ui->setupUi(this);
    BazaFaktury->Pokaz_Liste(ui->listWidget);
}

ListaFaktur::~ListaFaktur()
{
    delete ui;
}

void ListaFaktur::on_ZapelnicFaktureButton_clicked()
{
    std::shared_ptr<ZapelnicFakture>Zapelnic_Fakture =
        std::make_shared<ZapelnicFakture>(nullptr, BazaProdukty, BazaFaktury);
    Zapelnic_Fakture->setModal(true);
    Zapelnic_Fakture->exec();
    this->close();
}


void ListaFaktur::on_UsunacFaktureButton_clicked()
{
    BazaFaktury->Usunac_Fakture(ui->listWidget->currentRow());
    BazaFaktury->Ponowic_Liste(ui->listWidget);
}

void ListaFaktur::on_ZnalezcButton_clicked()
{
    std::shared_ptr<ZnalezcFakture>Znalezc_Fakture =
        std::make_shared<ZnalezcFakture>(nullptr, BazaFaktury);
    Znalezc_Fakture->setModal(true);
    Znalezc_Fakture->exec();
}


void ListaFaktur::on_PokazButton_clicked()
{
    std::shared_ptr<PokazFaktury> Pokaz_Faktury =
        std::make_shared<PokazFaktury>(nullptr,
                     BazaFaktury->Return_Faktura(ui->listWidget->currentRow()));
    Pokaz_Faktury->setModal(true);
    Pokaz_Faktury->exec();
}


void ListaFaktur::on_listWidget_itemDoubleClicked(QListWidgetItem *item)
{
    std::shared_ptr<PokazFaktury> Pokaz_Faktury =
        std::make_shared<PokazFaktury>(nullptr,
                            BazaFaktury->Return_Faktura(ui->listWidget->currentRow()));
    Pokaz_Faktury->setModal(true);
    Pokaz_Faktury->exec();
}

