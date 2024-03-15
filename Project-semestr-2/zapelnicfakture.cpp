#include "zapelnicfakture.h"
#include "ui_zapelnicfakture.h"
#include <QLabel>
#include "cbaza.h"
#include <QMessageBox>
#include "przedsiebiorca.h"
#include <ctime>
#include <windows.h>
#include <winbase.h>
#include "cbazafaktury.h"


ZapelnicFakture::ZapelnicFakture(QWidget *parent, cBaza* aBaza, cBazaFaktury* aBazaFaktury) :
    QDialog(parent),
    ui(new Ui::ZapelnicFakture), BazaProdukty(aBaza), BazaFaktury(aBazaFaktury)
{
    ui->setupUi(this);
    BazaProdukty->WypiszNazwy(ui->Nazwa1Box);
    BazaProdukty->WypiszNazwy(ui->Nazwa2Box);
    BazaProdukty->WypiszNazwy(ui->Nazwa3Box);
    BazaProdukty->WypiszNazwy(ui->Nazwa4Box);
    BazaProdukty->WypiszNazwy(ui->Nazwa5Box);
    ui->DzienLineEdit->setText("10");
    ui->MiesiacLineEdit->setText("6");
    ui->RokLineEdit->setText("2023");
    ui->NIPSprzedawcyLineEdit->setText("43714827");
    ui->NIPNabywcyLineEdit->setText("73291794");
    ui->ImieSprzedawcyLineEdit->setText("Imie 1");
    ui->ImieNabywcyLineEdit->setText("Imie 2");
    ui->NazwiskoSprzedawcyLineEdit->setText("Nazwisko 1");
    ui->NazwiskoNabywcyLineEdit->setText("Nazwisko 2");
    ui->NazwaFirmySprzedawcyLineEdit->setText("Firma 1");
    ui->NazwaFirmyNabywcyLineEdit->setText("Firma 2");
    ui->AdresSprzedawcyLineEdit->setText("Adres 1");
    ui->AdresNabywcyLineEdit->setText("Adres 2");
    ui->LP1Edit->setText("1");
    ui->LP2Edit->setText("2");
    ui->LP3Edit->setText("3");
    ui->LP4Edit->setText("4");
    ui->LP5Edit->setText("5");
    ui->Ilosc1Edit->setText("10");
    ui->Ilosc2Edit->setText("15");
    ui->Ilosc3Edit->setText("20");
    ui->Ilosc4Edit->setText("25");
    ui->Ilosc5Edit->setText("30");
    ui->BankLineEdit->setText("Santander");
    ui->NumerKontaLineEdit->setText("4783209740397");
}

ZapelnicFakture::~ZapelnicFakture()
{
    delete ui;
}

void ZapelnicFakture::on_LP1Edit_editingFinished()
{
    unsigned long long int LP = ui->LP1Edit->text().toULongLong();
    if(BazaProdukty->Sparwdz_LP(LP))
    {
        QMessageBox::critical(this, "LP", "Nie istnieje produktu z danym LP w bazie!!!");
        return;
    }
    else {
        cProdukt* Produkt = BazaProdukty->Return_Produkt(LP);
        ui->Nazwa1Box->setCurrentText(Produkt->Return_Name());
        ui->Cena1Label->setText(QString::number(Produkt->Return_Cena()));
    }
}


void ZapelnicFakture::on_LP2Edit_editingFinished()
{
    unsigned long long int LP = ui->LP2Edit->text().toULongLong();
    if(BazaProdukty->Sparwdz_LP(LP))
    {
        QMessageBox::critical(this, "LP", "Nie istnieje produktu z danym LP w bazie!!!");
        return;
    }
    else {
        cProdukt* Produkt = BazaProdukty->Return_Produkt(LP);
        ui->Nazwa2Box->setCurrentText(Produkt->Return_Name());
        ui->Cena2Label->setText(QString::number(Produkt->Return_Cena()));
    }
}


void ZapelnicFakture::on_LP3Edit_editingFinished()
{
    unsigned long long int LP = ui->LP3Edit->text().toULongLong();
    if(BazaProdukty->Sparwdz_LP(LP))
    {
        QMessageBox::critical(this, "LP", "Nie istnieje produktu z danym LP w bazie!!!");
        return;
    }
    else {
        cProdukt* Produkt = BazaProdukty->Return_Produkt(LP);
        ui->Nazwa3Box->setCurrentText(Produkt->Return_Name());
        ui->Cena3Label->setText(QString::number(Produkt->Return_Cena()));
    }
}


void ZapelnicFakture::on_LP4Edit_editingFinished()
{
    unsigned long long int LP = ui->LP4Edit->text().toULongLong();
    if(BazaProdukty->Sparwdz_LP(LP))
    {
        QMessageBox::critical(this, "LP", "Nie istnieje produktu z danym LP w bazie!!!");
        return;
    }
    else {
        cProdukt* Produkt = BazaProdukty->Return_Produkt(LP);
        ui->Nazwa4Box->setCurrentText(Produkt->Return_Name());
        ui->Cena4Label->setText(QString::number(Produkt->Return_Cena()));
    }
}


void ZapelnicFakture::on_LP5Edit_editingFinished()
{
    unsigned long long int LP = ui->LP5Edit->text().toULongLong();
    if(BazaProdukty->Sparwdz_LP(LP))
    {
        QMessageBox::critical(this, "LP", "Nie istnieje produktu z danym LP w bazie!!!");
        return;
    }
    else {
        cProdukt* Produkt = BazaProdukty->Return_Produkt(LP);
        ui->Nazwa5Box->setCurrentText(Produkt->Return_Name());
        ui->Cena5Label->setText(QString::number(Produkt->Return_Cena()));
    }
}



void ZapelnicFakture::on_Ilosc1Edit_editingFinished()
{
    ui->Wartosc1Label->setText(QString::number(ui->Ilosc1Edit->text().toInt() * ui->Cena1Label->text().toDouble()));
}


void ZapelnicFakture::on_Ilosc2Edit_editingFinished()
{
    ui->Wartosc2Label->setText(QString::number(ui->Ilosc2Edit->text().toInt() * ui->Cena2Label->text().toDouble()));
}


void ZapelnicFakture::on_Ilosc3Edit_editingFinished()
{
    ui->Wartosc3Label->setText(QString::number(ui->Ilosc3Edit->text().toInt() * ui->Cena3Label->text().toDouble()));
}


void ZapelnicFakture::on_Ilosc4Edit_editingFinished()
{
    ui->Wartosc4Label->setText(QString::number(ui->Ilosc4Edit->text().toInt() * ui->Cena4Label->text().toDouble()));
}


void ZapelnicFakture::on_Ilosc5Edit_editingFinished()
{
    ui->Wartosc5Label->setText(QString::number(ui->Ilosc5Edit->text().toInt() * ui->Cena5Label->text().toDouble()));
}


void ZapelnicFakture::on_ObliczycButton_clicked()
{
    double suma = 0;
    if(ui->Wartosc1Label->text().size() != 0)
    {
        suma += ui->Wartosc1Label->text().toDouble();
    }
    if(ui->Wartosc2Label->text().size() != 0)
    {
        suma += ui->Wartosc2Label->text().toDouble();
    }
    if(ui->Wartosc3Label->text().size() != 0)
    {
        suma += ui->Wartosc3Label->text().toDouble();
    }
    if(ui->Wartosc4Label->text().size() != 0)
    {
        suma += ui->Wartosc4Label->text().toDouble();
    }
    if(ui->Wartosc5Label->text().size() != 0)
    {
        suma += ui->Wartosc5Label->text().toDouble();
    }
    ui->LabelRazem->setText(QString::number(suma));
}


void ZapelnicFakture::on_ZapisacButton_clicked()
{
    int Dzien = ui->DzienLineEdit->text().toInt();
    int Miesiac = ui->MiesiacLineEdit->text().toInt();
    int Rok = ui->RokLineEdit->text().toInt();
    if(Dzien <= 0)
    {
        QMessageBox::critical(this, "Błąd w zapisie dnia", "Dzien nie może byc mniejszym lub równym 0");
        return;
    }
    if (!((Rok % 4 == 0 && Rok % 10 != 0) || (Rok % 400 == 0)))
    {
        if(Miesiac == 2 && Dzien >= 29)
        {
            QMessageBox::critical(this, "Błąd w zapisie daty", "Danego dnia miesiąca nie istenieje!!!");
            return;
        }
    }
    if(Miesiac == 2 && Dzien > 29)
    {
        QMessageBox::critical(this, "Błąd w zapisie daty", "Danego dnia miesiaca nie istnieje!!!");
        return;
    }
    if(Miesiac == 4 || Miesiac == 6 || Miesiac == 9 || Miesiac == 11)
    {
        if(Dzien > 30 || Dzien < 1)
        {
            QMessageBox::critical(this, "Źle wpisałeś datę", "Takiego dnia miesiąca nie istnieje");
            return;
        }
    }
    else if(Dzien > 31 || Dzien < 1)
    {
        QMessageBox::critical(this, "Źle wpisałeś datę", "Takiego dnia miesiąca nie istnieje");
        return;
    }
    cFaktura* Faktura = new Przedsiebiorca;
    Faktura->Zapielnic(ui->ImieSprzedawcyLineEdit->text(), ui->NazwiskoSprzedawcyLineEdit->text(),
                       ui->NazwaFirmySprzedawcyLineEdit->text(),
                       ui->NIPSprzedawcyLineEdit->text().toULongLong(),
                       ui->AdresSprzedawcyLineEdit->text(), ui->BankLineEdit->text(),
                       ui->NumerKontaLineEdit->text(), ui->ImieNabywcyLineEdit->text(),
                       ui->NazwiskoNabywcyLineEdit->text(),
                       ui->NazwaFirmyNabywcyLineEdit->text(),
                       ui->NIPNabywcyLineEdit->text().toULongLong(),
                       ui->AdresNabywcyLineEdit->text(),
                       ui->NumerFakturyLineEdit->text().toULongLong(),
                       Dzien, Miesiac, Rok, ui->Nazwa1Box->currentText(),
                       ui->Nazwa2Box->currentText(), ui->Nazwa3Box->currentText(),
                       ui->Nazwa4Box->currentText(), ui->Nazwa5Box->currentText(),
                       ui->Ilosc1Edit->text().toInt(), ui->Ilosc2Edit->text().toInt(),
                       ui->Ilosc3Edit->text().toInt(), ui->Ilosc4Edit->text().toInt(),
                       ui->Ilosc5Edit->text().toInt(), ui->Cena1Label->text().toDouble(),
                       ui->Cena2Label->text().toDouble(), ui->Cena3Label->text().toDouble(),
                       ui->Cena4Label->text().toDouble(), ui->Cena5Label->text().toDouble(),
                       ui->LP1Edit->text().toULongLong(), ui->LP2Edit->text().toULongLong(),
                       ui->LP3Edit->text().toULongLong(), ui->LP4Edit->text().toULongLong(),
                       ui->LP5Edit->text().toULongLong());
    BazaFaktury->Dodac_Fakture(Faktura);
    this->close();
}


void ZapelnicFakture::on_Nazwa1Box_currentIndexChanged(int index)
{
    cProdukt* Produkt = BazaProdukty->Return_Produkt(ui->Nazwa1Box->currentText());
    ui->LP1Edit->setText(QString::number(Produkt->Return_LP()));
    ui->Cena1Label->setText(QString::number(Produkt->Return_Cena()));
}


void ZapelnicFakture::on_Nazwa2Box_currentIndexChanged(int index)
{
    cProdukt* Produkt = BazaProdukty->Return_Produkt(ui->Nazwa2Box->currentText());
    ui->LP2Edit->setText(QString::number(Produkt->Return_LP()));
    ui->Cena2Label->setText(QString::number(Produkt->Return_Cena()));
}


void ZapelnicFakture::on_Nazwa3Box_currentIndexChanged(int index)
{
    cProdukt* Produkt = BazaProdukty->Return_Produkt(ui->Nazwa3Box->currentText());
    ui->LP3Edit->setText(QString::number(Produkt->Return_LP()));
    ui->Cena3Label->setText(QString::number(Produkt->Return_Cena()));
}


void ZapelnicFakture::on_Nazwa4Box_currentIndexChanged(int index)
{
    cProdukt* Produkt = BazaProdukty->Return_Produkt(ui->Nazwa4Box->currentText());
    ui->LP4Edit->setText(QString::number(Produkt->Return_LP()));
    ui->Cena4Label->setText(QString::number(Produkt->Return_Cena()));
}


void ZapelnicFakture::on_Nazwa5Box_currentIndexChanged(int index)
{
    cProdukt* Produkt = BazaProdukty->Return_Produkt(ui->Nazwa5Box->currentText());
    ui->LP5Edit->setText(QString::number(Produkt->Return_LP()));
    ui->Cena5Label->setText(QString::number(Produkt->Return_Cena()));
}

