#include "dodacnadanie.h"
#include "ui_dodacnadanie.h"
#include "cbaza.h"
#include "cbazanadanie.h"
#include "cnadanie.h"
#include "mainwindow.h"
#include <ctime>
#include <windows.h>
#include <winbase.h>
#include "cprodukt.h"

cNadanie* newNadanie = nullptr;

DodacNadanie::DodacNadanie(QWidget *parent, cBaza* aBaza, cBazaNadanie* aBazaNadan,
                           cNadanie* Nadanie) :
    QDialog(parent),
    ui(new Ui::DodacNadanie), BazaProdukty(aBaza), Baza_Nadan(aBazaNadan)
{
    ui->setupUi(this);
    BazaProdukty->WypiszNazwy(ui->comboBox);
    if(Nadanie != nullptr)
    {
        newNadanie = Nadanie;
        if(newNadanie->Sprawdz_Adres() && newNadanie->Sprawdz_Date())
        {
            newNadanie->get_dane(ui->LineEditDzien, ui->LineEditMiesiac, ui->LineEditRok,
                                 ui->LineEditAdres);
            ui->LineEditDzien->setEnabled(false);
            ui->LineEditMiesiac->setEnabled(false);
            ui->LineEditRok->setEnabled(false);
            ui->LineEditAdres->setEnabled(false);
        }
        else if (newNadanie->Sprawdz_Adres())
        {
            newNadanie->get_dane(ui->LineEditAdres);
            ui->LineEditAdres->setEnabled(false);
        }
        else if (newNadanie->Sprawdz_Date())
        {
            newNadanie->get_dane(ui->LineEditDzien, ui->LineEditMiesiac, ui->LineEditRok);
            ui->LineEditDzien->setEnabled(false);
            ui->LineEditMiesiac->setEnabled(false);
            ui->LineEditRok->setEnabled(false);
        }
    }
}

DodacNadanie::~DodacNadanie()
{
    delete ui;
}

void DodacNadanie::on_comboBox_currentIndexChanged(int index)
{
    ui->LPGeneral->setText(
        QString::number(BazaProdukty->Return_Produkt(ui->comboBox->currentText())->Return_LP()));
}


void DodacNadanie::on_pushButton_clicked()
{
    cProdukt* Produkt = BazaProdukty->Return_Produkt(ui->comboBox->currentText());
    if (Produkt->Return_Ilosc() < ui->LineEditIlosc->text().toInt())
    {
        QMessageBox::critical(this, "Błąd w ilości", "Nie można wysłać więcej sztuk niż "
                                                     "jest dostępne w magazynie");
        return;
    }
    if(ui->LineEditDzien->isEnabled() && ui->LineEditAdres->isEnabled())
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
        newNadanie = new cNadanie(ui->comboBox->currentText(),
                                  ui->LPGeneral->text().toULongLong(),
                                  ui->LineEditIlosc->text().toInt(),
                                  ui->LineEditAdres->text(), Dzien, Miesiac, Rok);
        Baza_Nadan->Dodac_Nadanie(newNadanie);
        this->close();
    }
    else if(!ui->LineEditDzien->isEnabled() && !ui->LineEditAdres->isEnabled())
    {
        newNadanie->take_dane(ui->comboBox->currentText(), ui->LPGeneral->text().toULongLong(),
                              ui->LineEditIlosc->text().toInt());
        Baza_Nadan->Dodac_Nadanie(newNadanie);
        this->close();
    }
    else if(!ui->LineEditDzien->isEnabled())
    {
        newNadanie->take_dane(ui->comboBox->currentText(), ui->LPGeneral->text().toULongLong(),
                              ui->LineEditIlosc->text().toInt(), ui->LineEditAdres->text());
        Baza_Nadan->Dodac_Nadanie(newNadanie);
        this->close();
    }
    else if (!ui->LineEditAdres->isEnabled())
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
        newNadanie->take_dane(ui->comboBox->currentText(), ui->LPGeneral->text().toULongLong(),
                              ui->LineEditIlosc->text().toInt(), ui->LineEditDzien->text().toInt(),
                              ui->LineEditMiesiac->text().toInt(), ui->LineEditRok->text().toInt());
        Baza_Nadan->Dodac_Nadanie(newNadanie);
        this->close();
    }
}

