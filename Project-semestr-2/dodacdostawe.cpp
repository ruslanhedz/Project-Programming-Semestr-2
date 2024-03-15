#include "dodacdostawe.h"
#include "ui_dodacdostawe.h"
#include "cbaza.h"
#include "mainwindow.h"
#include "cdostawa.h"
#include <QString>
#include "cbazadostawa.h"
#include <ctime>
#include <windows.h>
#include <winbase.h>
#include <QMessageBox>
#include "cdostawa.h"

cDostawa* newDostawa;

DodacDostawe::DodacDostawe(QWidget *parent, cBaza* aBaza, cBazaDostawa* aBazaDostawa, cDostawa* Dostawa) :
    QDialog(parent),
    ui(new Ui::DodacDostawe), BazaProdukty(aBaza), Baza_Dostawy(aBazaDostawa)
{
    ui->setupUi(this);
    newDostawa = nullptr;
    BazaProdukty->WypiszNazwy(ui->comboBox);
    if (Dostawa != nullptr)
    {
        newDostawa = Dostawa;
        Dostawa->get_data(ui->LineEditDzien, ui->LineEditMiesiac, ui->LineEditRok);
        ui->LineEditDzien->setEnabled(false);
        ui->LineEditMiesiac->setEnabled(false);
        ui->LineEditRok->setEnabled(false);
    }
}

DodacDostawe::~DodacDostawe()
{
    delete ui;
}

void DodacDostawe::on_comboBox_currentIndexChanged(int index)
{
    cProdukt* ptr = BazaProdukty->Return_Produkt(ui->comboBox->currentText());
    ui->LPGeneral->setText(QString::number(ptr->Return_LP()));
    ui->TypGeneral->setText(ptr->Return_Typ());
}

void DodacDostawe::on_pushButton_clicked()
{
    if (newDostawa == nullptr)
    {
        SYSTEMTIME data_z_windows;
        GetLocalTime(&data_z_windows);
        int Dzien = ui->LineEditDzien->text().toInt();
        int Miesiac = ui->LineEditMiesiac->text().toInt();
        int Rok = ui->LineEditRok->text().toInt();
        if((Rok < data_z_windows.wYear) ||  ((Miesiac < data_z_windows.wMonth) && (Rok == data_z_windows.wYear))
            || ((Rok == data_z_windows.wYear) && (Miesiac == data_z_windows.wMonth) && (Dzien < data_z_windows.wDay))
            || (Miesiac > 12))
        {
            QMessageBox::critical(this, "Źle  wpisałeś datę", "Nie można zapłanować dostawę na"
                      " datę wcześniejszą niż dzisiaj albo wpisałeś nie istniejący miesiąc");
            return;
        }
        if(!(((Rok % 4 == 0) && (Rok % 100 != 0)) || (Rok % 400 == 0)))
        {
            if(Miesiac == 2)
            {
                if((Dzien >= 29) || (Dzien < 1))
                {
                    QMessageBox::critical(this, "Źle wpisałeś datę", "Takiego dnia miesiąca nie istnieje");
                    return;
                }
            }
        }
        if(Miesiac == 2 && Dzien >= 30)
        {
            QMessageBox::critical(this, "Źle wpisałeś datę", "Takiego dnia miesiąca nie istnieje");
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
        if (ui->LineEditIlosc->text().toInt() <= 0)
        {
            QMessageBox::critical(this, "Źle wpisałeś ilość", "Ilość produktów w dostawie nie"
                                                              " może być mniejsza lub równa 0");
        }
        newDostawa = new cDostawa(ui->comboBox->currentText(), ui->TypGeneral->text(),
                                     ui->LPGeneral->text().toULongLong(),
                                     Dzien, Miesiac, Rok, ui->LineEditIlosc->text().toInt());
        Baza_Dostawy->Dodac_Dostawe(newDostawa);
        this->close();
    }
    else {
        newDostawa->take_dane(ui->LineEditIlosc->text().toInt(), ui->comboBox->currentText(),
                              ui->TypGeneral->text(), ui->LPGeneral->text().toULongLong());
        Baza_Dostawy->Dodac_Dostawe(newDostawa);
        this->close();
    }
}

