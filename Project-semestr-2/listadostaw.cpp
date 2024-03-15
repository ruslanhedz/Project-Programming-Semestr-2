#include "listadostaw.h"
#include "ui_listadostaw.h"
#include "cbaza.h"
#include "dodacdostawe.h"
#include "cbazadostawa.h"
#include "cdostawa.h"

ListaDostaw::ListaDostaw(QWidget *parent, cBaza* aBaza, cBazaDostawa* aBazaDostawa) :
    QDialog(parent),
    ui(new Ui::ListaDostaw), BazaProdukty(aBaza), Baza_Dostawa(aBazaDostawa)
{
    ui->setupUi(this);
    Baza_Dostawa->Pokaz_Liste(ui->listWidget);
}

ListaDostaw::~ListaDostaw()
{
    delete ui;
}

void ListaDostaw::on_DodacButton_clicked()
{
    std::shared_ptr<DodacDostawe>DodanieDostawy =
        std::make_shared<DodacDostawe>(nullptr, BazaProdukty, Baza_Dostawa, nullptr);
    DodanieDostawy->setModal(true);
    DodanieDostawy->exec();
    this->close();
}


void ListaDostaw::on_UsunacButton_clicked()
{
    Baza_Dostawa->Usunac_Dostawe(ui->listWidget->currentRow());
    Baza_Dostawa->Ponowic_Liste(ui->listWidget);
}


void ListaDostaw::on_NaTaSamaDateButton_clicked()
{
    cDostawa* Dostawa = new cDostawa;
    *Dostawa = Baza_Dostawa->Return_Dostawa(ui->listWidget->currentRow());
    std::shared_ptr<DodacDostawe>DodanieDostawy =
        std::make_shared<DodacDostawe>(nullptr, BazaProdukty, Baza_Dostawa, Dostawa);
    DodanieDostawy->setModal(true);
    DodanieDostawy->exec();
    this->close();
}


void ListaDostaw::on_DostarczonaButton_clicked()
{
    cDostawa* Dostawa = Baza_Dostawa->Return_wsk_Dostawa(ui->listWidget->currentRow());
    cProdukt* Produkt = BazaProdukty->Return_Produkt(Dostawa->get_LP());
    Produkt->Dodac_odjac_Ilosc(Dostawa->get_Ilosc());
    Baza_Dostawa->Usunac_Dostawe(ui->listWidget->currentRow());
    Baza_Dostawa->Ponowic_Liste(ui->listWidget);
}

