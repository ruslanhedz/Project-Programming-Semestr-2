#include "zmianailosci.h"
#include "ui_zmianailosci.h"
#include "mainwindow.h"
#include "cprodukt.h"
#include <QMessageBox>

ZmianaIlosci::ZmianaIlosci(QWidget *parent, cProdukt* Produkt) :
    QDialog(parent),
    ui(new Ui::ZmianaIlosci), mProdukt(Produkt)
{
    ui->setupUi(this);
    ui->NazwaLabel + mProdukt->Return_Name();
    ui->lineEdit->setText(QString::number(Produkt->Return_Ilosc()));
}

ZmianaIlosci::~ZmianaIlosci()
{
    delete ui;
}

void ZmianaIlosci::on_ZmienButton_clicked()
{
    if(ui->lineEdit->text().toInt() < 0)
    {
        QMessageBox::critical(this, "Błąd w zapisie ilości", "Źle wpisałeś liczbę!!!");
        return;
    }
    mProdukt->Zmnien_ilosc(ui->lineEdit->text().toInt());
    this->close();
}

