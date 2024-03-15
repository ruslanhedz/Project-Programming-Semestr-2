#include "listanadan.h"
#include "ui_listanadan.h"
#include "cbazanadanie.h"
#include "dodacnadanie.h"
#include "cnadanie.h"
#include "cprodukt.h"
#include "cbaza.h"

ListaNadan::ListaNadan(QWidget *parent, cBaza* aBaza, cBazaNadanie* aBazaNadan) :
    QDialog(parent),
    ui(new Ui::ListaNadan), BazaProdukty(aBaza), Baza_Nadan(aBazaNadan)
{
    ui->setupUi(this);
    Baza_Nadan->Pokaz_Liste(ui->listWidget);
}

ListaNadan::~ListaNadan()
{
    delete ui;
}

void ListaNadan::on_DodacNadanieButton_clicked()
{
    std::shared_ptr<DodacNadanie>Dodac_Nadanie = std::make_shared<DodacNadanie>(nullptr,
                                                              BazaProdukty, Baza_Nadan, nullptr);
    Dodac_Nadanie->setModal(true);
    Dodac_Nadanie->exec();
    this->close();
}


void ListaNadan::on_UsunacNadanieButton_clicked()
{
    Baza_Nadan->Usunac_Nadanie(ui->listWidget->currentRow());
    Baza_Nadan->Ponowic_Liste(ui->listWidget);
}


void ListaNadan::on_DodacNaTaSamaDateIAdressButton_clicked()
{
    cNadanie* Nadanie = new cNadanie;
    *Nadanie = Baza_Nadan->Return_Nadanie(ui->listWidget->currentRow());
    std::shared_ptr<DodacNadanie>Dodac_Nadanie =
        std::make_shared<DodacNadanie>(nullptr, BazaProdukty, Baza_Nadan, Nadanie);
    Dodac_Nadanie->setModal(true);
    Dodac_Nadanie->exec();
    this->close();
}

void ListaNadan::on_DodacNaTaSamaDateButton_clicked()
{
    cNadanie* Nadanie = new cNadanie;
    cNadanie* ptr = Baza_Nadan->Return_wsk_Nadanie(ui->listWidget->currentRow());
    Nadanie->take_dane(ptr->Return_Dzien(), ptr->Return_Miesiac(), ptr->Return_Rok());
    std::shared_ptr<DodacNadanie>Dodac_Nadanie =
        std::make_shared<DodacNadanie>(nullptr, BazaProdukty, Baza_Nadan, Nadanie);
    Dodac_Nadanie->setModal(true);
    Dodac_Nadanie->exec();
    this->close();
}
void ListaNadan::on_DodacNaTenSamAdressButton_clicked()
{
    cNadanie* Nadanie = new cNadanie;
    cNadanie* ptr = Baza_Nadan->Return_wsk_Nadanie(ui->listWidget->currentRow());
    Nadanie->take_dane(ptr->Return_Adres());
    std::shared_ptr<DodacNadanie>Dodac_Nadanie =
        std::make_shared<DodacNadanie>(nullptr, BazaProdukty, Baza_Nadan, Nadanie);
    Dodac_Nadanie->setModal(true);
    Dodac_Nadanie->exec();
    this->close();
}

void ListaNadan::on_NadaneButton_clicked()
{
    cNadanie* Nadanie = Baza_Nadan->Return_wsk_Nadanie(ui->listWidget->currentRow());
    cProdukt* Produkt = BazaProdukty->Return_Produkt(Nadanie->get_LP());
    Produkt->Dodac_odjac_Ilosc(Nadanie->Return_Ilosc() * (-1));
    Produkt->Dodac_Ilosc_Na_Amazonie(Nadanie->Return_Ilosc());
    Baza_Nadan->Usunac_Nadanie(ui->listWidget->currentRow());
    Baza_Nadan->Ponowic_Liste(ui->listWidget);
}

