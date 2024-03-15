#include "zmiana_ilosci.h"
#include "ui_zmiana_ilosci.h"
#include "cprodukt.h"
#include "mainwindow.h"
#include <QString>

Zmiana_Ilosci::Zmiana_Ilosci(QWidget *parent, cProdukt* aProdukt) :
    QDialog(parent),
    ui(new Ui::Zmiana_Ilosci), Produkt(aProdukt)
{
    ui->setupUi(this);
    if(Produkt != nullptr)
    {
        //ui->labelNawa + Produkt->Return_Name();
        ui->IloscEdit->setText(QString::number(Produkt->Return_Ilosc()));
    }
}

Zmiana_Ilosci::~Zmiana_Ilosci()
{
    delete ui;
}
