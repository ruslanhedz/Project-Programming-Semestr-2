#include "zmieniciloscamazon.h"
#include "ui_zmieniciloscamazon.h"
#include "cbaza.h"
#include "cprodukt.h"
#include "mainwindow.h"

ZmienicIloscAmazon::ZmienicIloscAmazon(QWidget *parent, cProdukt* Produkt) :
    QDialog(parent),
    ui(new Ui::ZmienicIloscAmazon), mProdukt(Produkt)
{
    ui->setupUi(this);
    ui->labelNazwa + mProdukt->Return_Name();
    ui->lineEdit->setText(QString::number(mProdukt->Return_Ilosc_Amazon()));
}

ZmienicIloscAmazon::~ZmienicIloscAmazon()
{
    delete ui;
}

void ZmienicIloscAmazon::on_ZmienicButton_clicked()
{
    mProdukt->Zmien_Ilosc_Amazon((ui->lineEdit->text()).toInt());
    this->close();
}

