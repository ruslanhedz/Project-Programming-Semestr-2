#include "dodanienowegoproduktu.h"
#include "cbaza.h"
#include "cprodukt.h"
#include "ctasmy.h"
#include "cbluza.h"
#include "chdd.h"
#include "ckolanka.h"
#include "csluchawki.h"
#include "ckoszulka.h"
#include "crecznik.h"
#include "cssd.h"
#include <cstdlib>
#include <ctime>
#include <string>

DodanieNowegoProduktu::DodanieNowegoProduktu(QWidget *parent, cBaza* aBaza, cProdukt* Produkt) :
    QDialog(parent),
    ui(new Ui::DodanieNowegoProduktu)
{
    ui->setupUi(this);
    BazaProdukty = aBaza;
    if(Produkt != nullptr)
    {
        ui->EditLP->setEnabled(false);
        ui->pushButton->setText("Edytuj");
        Produkt->Edytowanie_Produktu(ui, this);
    }
    else{
        ui->lineEditKategoria->setText("taśmy");
        ui->lineEditKategoria->setEnabled(false);
        Dlugosc = std::make_shared<QLabel>();
        Dlugosc->setText("Dlugość");
        Szerokosc = std::make_shared<QLabel>("Szerokość");
        Grubosc = std::make_shared<QLabel>("Grubość");
        Funkcja = std::make_shared<QLabel>("Funkcja");
        DlugoscEdit = std::make_shared<QLineEdit>();
        SzerokoscEdit = std::make_shared<QLineEdit>();
        GruboscEdit = std::make_shared<QLineEdit>();
        FunkcjaEdit = std::make_shared<QLineEdit>();
        ui->formLayout->addRow(Dlugosc.get(), DlugoscEdit.get());
        ui->formLayout->addRow(Szerokosc.get(), SzerokoscEdit.get());
        ui->formLayout->addRow(Grubosc.get(), GruboscEdit.get());
        ui->formLayout->addRow(Funkcja.get(), FunkcjaEdit.get());
        index_var = 0;
    }
    connect(ui->ZgenerujLP, &QPushButton::clicked, this, &DodanieNowegoProduktu::on_ZgenerujLP_clicked);
}

DodanieNowegoProduktu::~DodanieNowegoProduktu()
{
    delete ui;
}

void DodanieNowegoProduktu::on_TypProduktu_currentIndexChanged(int index)
{
    if(index != index_var)
    {
        if (index_var != 8)
        {
            if (index_var == 0)
            {
                Dlugosc.reset();
                Szerokosc.reset();
                Grubosc.reset();
                Funkcja.reset();
                DlugoscEdit.reset();
                SzerokoscEdit.reset();
                GruboscEdit.reset();
                FunkcjaEdit.reset();
            }
            else if (index_var == 1)
            {
                Rozmiar.reset();
                Material.reset();
                RozmiarEdit.reset();
                MaterialEdit.reset();
            }
            else if (index_var == 2)
            {
                Pojemnosc.reset();
                Szybkosc_Odczytu.reset();
                Szybkosc_Zapisu.reset();
                Typ_SATA.reset();
                Format_Dysku.reset();
                PojemnoscEdit.reset();
                Szybkosc_OdczytuEdit.reset();
                Szybkosc_ZapisuEdit.reset();
                Typ_SATAEdit.reset();
                Format_DyskuEdit.reset();
            }
            else if (index_var == 3)
            {
                Material.reset();
                Srednica.reset();
                Kat_Nachylenia.reset();
                Dlugosc.reset();
                MaterialEdit.reset();
                SrednicaEdit.reset();
                Kat_NachyleniaEdit.reset();
                DlugoscEdit.reset();
            }
            else if (index_var == 4)
            {
                Typ_Zlacza.reset();
                Ilosc_Godzin_Pracy.reset();
                Typ_ZlaczaBox.reset();
                Ilosc_Godzin_PracyEdit.reset();
            }
            else if (index_var == 5)
            {
                Rozmiar.reset();
                Material.reset();
                RozmiarEdit.reset();
                MaterialEdit.reset();
            }
            else if (index_var == 6)
            {
                Material.reset();
                Dlugosc.reset();
                Szerokosc.reset();
                MaterialEdit.reset();
                DlugoscEdit.reset();
                SzerokoscEdit.reset();
            }
            else if (index_var == 7)
            {
                Pojemnosc.reset();
                Szybkosc_Odczytu.reset();
                Szybkosc_Zapisu.reset();
                Typ_SATA.reset();
                PojemnoscEdit.reset();
                Szybkosc_OdczytuEdit.reset();
                Szybkosc_ZapisuEdit.reset();
                Typ_SATAEdit.reset();
            }
        }


        if(index == 0)
        {
            ui->lineEditKategoria->setText("taśmy");
            ui->lineEditKategoria->setEnabled(false);
            Dlugosc = std::make_shared<QLabel>();
            Dlugosc->setText("Dlugość(m)");
            Szerokosc = std::make_shared<QLabel>();
            Szerokosc->setText("Szerokość(mm)");
            Grubosc = std::make_shared<QLabel>();
            Grubosc->setText("Grubość(mm)");
            Funkcja = std::make_shared<QLabel>();
            Funkcja->setText("Funkcja taśmy");
            DlugoscEdit = std::make_shared<QLineEdit>();
            SzerokoscEdit = std::make_shared<QLineEdit>();
            GruboscEdit = std::make_shared<QLineEdit>();
            FunkcjaEdit = std::make_shared<QLineEdit>();
            ui->formLayout->addRow(Dlugosc.get(), DlugoscEdit.get());
            ui->formLayout->addRow(Szerokosc.get(), SzerokoscEdit.get());
            ui->formLayout->addRow(Grubosc.get(), GruboscEdit.get());
            ui->formLayout->addRow(Funkcja.get(), FunkcjaEdit.get());
            index_var = 0;
        }
        else if(index == 1)
        {
            ui->lineEditKategoria->setText("bluzy");
            ui->lineEditKategoria->setEnabled(false);
            Rozmiar = std::make_shared<QLabel>();
            Rozmiar->setText("Rozmiar");
            Material = std::make_shared<QLabel>();
            Material->setText("Material");
            RozmiarEdit = std::make_shared<QLineEdit>();
            MaterialEdit = std::make_shared<QLineEdit>();
            ui->formLayout->addRow(Rozmiar.get(), RozmiarEdit.get());
            ui->formLayout->addRow(Material.get(), MaterialEdit.get());
            index_var = 1;
        }
        else if(index == 2)
        {
            ui->lineEditKategoria->setText("HDD");
            ui->lineEditKategoria->setEnabled(false);
            Pojemnosc = std::make_shared<QLabel>();
            Pojemnosc->setText("Pojemność(liczna całkowita)");
            Szybkosc_Odczytu = std::make_shared<QLabel>();
            Szybkosc_Odczytu->setText("Szybkość Odczytu(Mb/s)");
            Szybkosc_Zapisu = std::make_shared<QLabel>();
            Szybkosc_Zapisu->setText("Szybkość Zapisu(Mb/s)");
            Typ_SATA = std::make_shared<QLabel>();
            Typ_SATA->setText("Typ SATA");
            Format_Dysku = std::make_shared<QLabel>();
            Format_Dysku->setText("Format dysku");
            PojemnoscEdit = std::make_shared<QLineEdit>();
            Szybkosc_OdczytuEdit = std::make_shared<QLineEdit>();
            Szybkosc_ZapisuEdit = std::make_shared<QLineEdit>();
            Typ_SATAEdit = std::make_shared<QLineEdit>();
            Format_DyskuEdit = std::make_shared<QLineEdit>();
            ui->formLayout->addRow(Pojemnosc.get(), PojemnoscEdit.get());
            ui->formLayout->addRow(Szybkosc_Odczytu.get(), Szybkosc_OdczytuEdit.get());
            ui->formLayout->addRow(Szybkosc_Zapisu.get(), Szybkosc_ZapisuEdit.get());
            ui->formLayout->addRow(Typ_SATA.get(), Typ_SATAEdit.get());
            ui->formLayout->addRow(Format_Dysku.get(), Format_DyskuEdit.get());
            index_var = 2;
        }
        else if(index == 3)
        {
            ui->lineEditKategoria->setText("kolanka");
            ui->lineEditKategoria->setEnabled(false);
            Material = std::make_shared<QLabel>();
            Material->setText("Material");
            Srednica = std::make_shared<QLabel>();
            Srednica->setText("Srednica(mm)");
            Kat_Nachylenia = std::make_shared<QLabel>();
            Kat_Nachylenia->setText("Kąt Nachylenia");
            Dlugosc = std::make_shared<QLabel>();
            Dlugosc->setText("Długość(cm)");
            MaterialEdit = std::make_shared<QLineEdit>();
            SrednicaEdit = std::make_shared<QLineEdit>();
            Kat_NachyleniaEdit = std::make_shared<QLineEdit>();
            DlugoscEdit = std::make_shared<QLineEdit>();
            ui->formLayout->addRow(Material.get(), MaterialEdit.get());
            ui->formLayout->addRow(Srednica.get(), SrednicaEdit.get());
            ui->formLayout->addRow(Kat_Nachylenia.get(), Kat_NachyleniaEdit.get());
            ui->formLayout->addRow(Dlugosc.get(), DlugoscEdit.get());
            index_var = 3;
        }
        else if (index == 4)
        {
            ui->lineEditKategoria->setText("słuchawki");
            ui->lineEditKategoria->setEnabled(false);
            Typ_Zlacza = std::make_shared<QLabel>();
            Typ_Zlacza->setText("Typ złącza");
            Ilosc_Godzin_Pracy = std::make_shared<QLabel>();
            Ilosc_Godzin_Pracy->setText("Ilość godzin pracy");
            Typ_ZlaczaBox = std::make_shared<QComboBox>();
            Typ_ZlaczaBox->addItem("Bezprzewodowe");
            Typ_ZlaczaBox->addItem("Przewodowe");
            Ilosc_Godzin_PracyEdit = std::make_shared<QLineEdit>();
            ui->formLayout->addRow(Typ_Zlacza.get(), Typ_ZlaczaBox.get());
            ui->formLayout->addRow(Ilosc_Godzin_Pracy.get(), Ilosc_Godzin_PracyEdit.get());
            index_var = 4;
        }
        else if (index == 5)
        {
            ui->lineEditKategoria->setText("koszulki");
            ui->lineEditKategoria->setEnabled(false);
            Rozmiar = std::make_shared<QLabel>();
            Rozmiar->setText("Rozmiar");
            Material = std::make_shared<QLabel>();
            Material->setText("Material");
            RozmiarEdit = std::make_shared<QLineEdit>();
            MaterialEdit = std::make_shared<QLineEdit>();
            ui->formLayout->addRow(Rozmiar.get(), RozmiarEdit.get());
            ui->formLayout->addRow(Material.get(), MaterialEdit.get());
            index_var = 5;
        }
        else if(index == 6)
        {
            ui->lineEditKategoria->setText("ręczniki");
            ui->lineEditKategoria->setEnabled(false);
            Material = std::make_shared<QLabel>();
            Material->setText("Material");
            Dlugosc = std::make_shared<QLabel>();
            Dlugosc->setText("Długość(cm)");
            Szerokosc = std::make_shared<QLabel>();
            Szerokosc->setText("Szerokość(cm)");
            MaterialEdit = std::make_shared<QLineEdit>();
            DlugoscEdit = std::make_shared<QLineEdit>();
            SzerokoscEdit = std::make_shared<QLineEdit>();
            ui->formLayout->addRow(Material.get(), MaterialEdit.get());
            ui->formLayout->addRow(Dlugosc.get(), DlugoscEdit.get());
            ui->formLayout->addRow(Szerokosc.get(), SzerokoscEdit.get());
            index_var = 6;
        }
        else if(index == 7)
        {
            ui->lineEditKategoria->setText("SSD");
            ui->lineEditKategoria->setEnabled(false);
            Pojemnosc = std::make_shared<QLabel>();
            Pojemnosc->setText("Pojemnosc(liczba całkowita)");
            Szybkosc_Odczytu = std::make_shared<QLabel>();
            Szybkosc_Odczytu->setText("Szybkość odczytu(Mb/s)");
            Szybkosc_Zapisu = std::make_shared<QLabel>();
            Szybkosc_Zapisu->setText("Szybkość zapisu(Mb/s)");
            Typ_SATA = std::make_shared<QLabel>();
            Typ_SATA->setText("Typ SATA");
            PojemnoscEdit = std::make_shared<QLineEdit>();
            Szybkosc_OdczytuEdit = std::make_shared<QLineEdit>();
            Szybkosc_ZapisuEdit = std::make_shared<QLineEdit>();
            Typ_SATAEdit = std::make_shared<QLineEdit>();
            ui->formLayout->addRow(Pojemnosc.get(), PojemnoscEdit.get());
            ui->formLayout->addRow(Szybkosc_Odczytu.get(), Szybkosc_OdczytuEdit.get());
            ui->formLayout->addRow(Szybkosc_Zapisu.get(), Szybkosc_ZapisuEdit.get());
            ui->formLayout->addRow(Typ_SATA.get(), Typ_SATAEdit.get());
            index_var = 7;
        }
        else {
            index_var = -1;
            ui->lineEditKategoria->clear();
            ui->lineEditKategoria->setEnabled(true);
        }
    }
}

void DodanieNowegoProduktu::on_pushButton_clicked()
{
    if((ui->EditLP->text()).toULongLong() == 0)
    {
        QMessageBox::critical(this, "Błąd liczbowy", "Liczba Podatkowa nie może być mniejsza lub równa 0, być"
                                             " liczbą zmiennoprzecinkową albo jest błąd w napisaniu liczby.");
        return;
    }
    if(ui->EditLP->isEnabled())
    {
        if(!(BazaProdukty->Sparwdz_LP(ui->EditLP->text().toULongLong())))
        {
            QMessageBox::critical(this, "Instniejący LP", "Wpisałeś juz istniejąca w bazie liczbe podatkową");
            return;
        }
    }
    if((ui->lineEditDostepnaIlosc->text()).toInt() < 0)
    {
        QMessageBox::critical(this, "Błąd liczbowy", "Liczba produktów nie może być mniejsza od 0, być"
                                       " liczbą zmiennoprzecinkową albo jest błąd w napisaniu liczby.");
        return;
    }
    else if ((ui->lineEditWaga->text()).toDouble() < 0)
    {
        QMessageBox::critical(this, "Błąd liczbowy", "Waga produktu nie może być ujemna "
                                                     "albo jest błąd w napisaniu liczby.");
        return;
    }
    else if ((ui->lineEditCena->text()).toDouble() <= 0)
    {
        QMessageBox::critical(this, "Błąd liczbowy", "Cena produktu nie może być mniejsza lub równa 0 "
                                                     "albo jest błąd w napisaniu liczby.");
        return;
    }
    else if ((ui->lineEditVat->text()).toDouble() <= 0)
    {
        QMessageBox::critical(this, "Błąd liczbowy", "Podatek VAT nie może być mniejszy lub równy 0 "
                                                     "albo jest błąd w napisaniu liczby.");
        return;
    }
    if(ui->TypProduktu->currentIndex() == 0)
    {
        if ((DlugoscEdit->text()).toDouble() <= 0)
        {
            QMessageBox::critical(this, "Błąd liczbowy", "Dlugość nie może być mniejsza lub równa 0 "
                                                         "albo jest błąd w napisaniu liczby.");
            return;
        }
        else if((SzerokoscEdit->text()).toDouble() <= 0)
        {
            QMessageBox::critical(this, "Błąd liczbowy", "Szerokość nie może być mniejsza lub równa 0 "
                                                         "albo jest błąd w napisaniu liczby.");
            return;
        }
        else if((GruboscEdit->text()).toDouble() <= 0)
        {
            QMessageBox::critical(this, "Błąd liczbowy", "Grubość nie może być mniejsza lub równa 0 "
                                                         "albo jest błąd w napisaniu liczby.");
            return;
        }
        mProdukt = new cTasmy((ui->EditLP->text()).toULongLong(),
                              (ui->lineEditDostepnaIlosc->text()).toInt(), (ui->lineEditIloscnaamazonie->text()).toInt(), ui->EditNazwa->text(),
                             ui->lineEditKategoria->text(), ui->lineEditProducent->text(),
                             (ui->lineEditWaga->text()).toDouble(), ui->lineEditKolor->text(),
                             (ui->lineEditCena->text()).toDouble(), (ui->lineEditVat->text()).toDouble(),
                             (DlugoscEdit->text()).toDouble(), (SzerokoscEdit->text()).toDouble(),
                             (GruboscEdit->text()).toDouble(), FunkcjaEdit->text());
    }
    else if (ui->TypProduktu->currentIndex() == 1)
    {
        mProdukt = new cBluza((ui->EditLP->text()).toULongLong(),
                             (ui->lineEditDostepnaIlosc->text()).toUInt(), (ui->lineEditIloscnaamazonie->text()).toInt(), ui->EditNazwa->text(),
                             ui->lineEditKategoria->text(), ui->lineEditProducent->text(),
                             (ui->lineEditWaga->text()).toDouble(), ui->lineEditKolor->text(),
                             (ui->lineEditCena->text()).toDouble(), (ui->lineEditVat->text()).toDouble(),
                             RozmiarEdit->text(), MaterialEdit->text());
    }
    else if(ui->TypProduktu->currentIndex() == 2)
    {
       if ((PojemnoscEdit->text()).toInt() <= 0)
       {
           QMessageBox::critical(this, "Błąd liczbowy", "Pojemność nie może być mniejsza lub równa 0, być"
                                          " liczbą zmiennoprzecinkową albo jest błąd w napisaniu liczby.");
           return;
       }
       else if ((Szybkosc_OdczytuEdit->text()).toDouble() <= 0)
       {
           QMessageBox::critical(this, "Błąd liczbowy", "Szybkość odczytu nie może być mniejsza lub równa 0 "
                                                        "albo jest błąd w napisaniu liczby.");
           return;
       }
       else if ((Szybkosc_ZapisuEdit->text()).toDouble() <= 0)
       {
           QMessageBox::critical(this, "Błąd liczbowy", "Szybkość zapisu nie może być mniejsza lub równa 0 "
                                                        "albo jest błąd w napisaniu liczby.");
           return;
       }
       else if ((Format_DyskuEdit->text()).toDouble() <= 0)
       {
           QMessageBox::critical(this, "Błąd liczbowy", "Format dysku nie może być mniejszym lub równym 0 "
                                                        "albo jest błąd w napisaniu liczby.");
           return;
       }
       mProdukt = new cHDD((ui->EditLP->text()).toULongLong(),
                          (ui->lineEditDostepnaIlosc->text()).toUInt(), (ui->lineEditIloscnaamazonie->text()).toInt(), ui->EditNazwa->text(),
                          ui->lineEditKategoria->text(), ui->lineEditProducent->text(),
                          (ui->lineEditWaga->text()).toDouble(), ui->lineEditKolor->text(),
                          (ui->lineEditCena->text()).toDouble(), (ui->lineEditVat->text()).toDouble(),
                          (PojemnoscEdit->text()).toInt(), (Szybkosc_OdczytuEdit->text()).toDouble(),
                          (Szybkosc_ZapisuEdit->text()).toDouble(), Typ_SATAEdit->text(),
                          (Format_DyskuEdit->text()).toDouble());
    }
    else if (ui->TypProduktu->currentIndex() == 3)
    {
        if ((SrednicaEdit->text()).toDouble() <= 0)
        {
            QMessageBox::critical(this, "Błąd liczbowy", "Średnica nie może być mniejsza lub równa 0 "
                                                         "albo jest błąd w napisaniu liczby.");
            return;
        }
        else if((Kat_NachyleniaEdit->text()).toDouble() < 0)
        {
            QMessageBox::critical(this, "Błąd liczbowy", "Kąt Nachylenia nie może być mniejszym od 0 "
                                                         "albo jest błąd w napisaniu liczby.");
            return;
        }
        else if((DlugoscEdit->text()).toDouble() <= 0)
        {
            QMessageBox::critical(this, "Błąd liczbowy", "Dlugość nie może być mniejsza lub równa 0 "
                                                         "albo jest błąd w napisaniu liczby.");
            return;
        }
        mProdukt = new cKolanka((ui->EditLP->text()).toULongLong(),
                               (ui->lineEditDostepnaIlosc->text()).toUInt(), (ui->lineEditIloscnaamazonie->text()).toInt(), ui->EditNazwa->text(),
                               ui->lineEditKategoria->text(), ui->lineEditProducent->text(),
                               (ui->lineEditWaga->text()).toDouble(), ui->lineEditKolor->text(),
                               (ui->lineEditCena->text()).toDouble(), (ui->lineEditVat->text()).toDouble(),
                               MaterialEdit->text(), (SrednicaEdit->text()).toDouble(), (Kat_NachyleniaEdit->text()).toDouble(),
                               (DlugoscEdit->text()).toDouble());
    }
    else if (ui->TypProduktu->currentIndex() == 4)
    {
        if (Typ_ZlaczaBox->currentText() == Typ_ZlaczaBox->itemText(1))
        {
            Ilosc_Godzin_PracyEdit->text() = 0;
        }
        else if((Typ_ZlaczaBox->currentText() == Typ_ZlaczaBox->itemText(0)) && ((Ilosc_Godzin_PracyEdit->text()).toDouble() <= 0))
        {
            QMessageBox::critical(this, "Błąd liczbowy", "Ilość godzin pracy nie może być mniejsza lub równa 0 "
                                                         "albo jest błąd w napisaniu liczby.");
            return;
        }
        mProdukt = new cSluchawki((ui->EditLP->text()).toULongLong(),
                                 (ui->lineEditDostepnaIlosc->text()).toUInt(), (ui->lineEditIloscnaamazonie->text()).toInt(), ui->EditNazwa->text(),
                                 ui->lineEditKategoria->text(), ui->lineEditProducent->text(),
                                 (ui->lineEditWaga->text()).toDouble(), ui->lineEditKolor->text(),
                                 (ui->lineEditCena->text()).toDouble(), (ui->lineEditVat->text()).toDouble(),
                                 Typ_ZlaczaBox->currentText(), (Ilosc_Godzin_PracyEdit->text()).toDouble());
    }
    else if (ui->TypProduktu->currentIndex() == 5)
    {
        mProdukt = new cKoszulka((ui->EditLP->text()).toULongLong(),
                                (ui->lineEditDostepnaIlosc->text()).toUInt(), (ui->lineEditIloscnaamazonie->text()).toInt(), ui->EditNazwa->text(),
                                ui->lineEditKategoria->text(), ui->lineEditProducent->text(),
                                (ui->lineEditWaga->text()).toDouble(), ui->lineEditKolor->text(),
                                (ui->lineEditCena->text()).toDouble(), (ui->lineEditVat->text()).toDouble(),
                                RozmiarEdit->text(), MaterialEdit->text());
    }
    else if (ui->TypProduktu->currentIndex() == 6)
    {
        if ((DlugoscEdit->text()).toFloat() <= 0)
        {
            QMessageBox::critical(this, "Błąd liczbowy", "Długość nie może być mniejsza lub równa 0 "
                                                         "albo jest błąd w napisaniu liczby.");
            return;
        }
        else if ((SzerokoscEdit->text()).toFloat() <= 0)
        {
            QMessageBox::critical(this, "Błąd liczbowy", "Szerokość nie może być mniejsza lub równa 0 "
                                                         "albo jest błąd w napisaniu liczby.");
            return;
        }
        mProdukt = new cRecznik((ui->EditLP->text()).toULongLong(),
                               (ui->lineEditDostepnaIlosc->text()).toUInt(), (ui->lineEditIloscnaamazonie->text()).toInt(), ui->EditNazwa->text(),
                               ui->lineEditKategoria->text(), ui->lineEditProducent->text(),
                               (ui->lineEditWaga->text()).toDouble(), ui->lineEditKolor->text(),
                               (ui->lineEditCena->text()).toDouble(), (ui->lineEditVat->text()).toDouble(),
                               MaterialEdit->text(), (DlugoscEdit->text()).toFloat(),
                               (SzerokoscEdit->text()).toFloat());
    }
    else if (ui->TypProduktu->currentIndex() == 7)
    {
        if ((PojemnoscEdit->text()).toInt() <= 0)
        {
            QMessageBox::critical(this, "Błąd liczbowy", "Pojemność nie może być mniejsza lub równa 0 być"
                                          " liczbą zmiennoprzecinkową albo jest błąd w napisaniu liczby.");
            return;
        }
        else if ((Szybkosc_OdczytuEdit->text()).toDouble() <= 0)
        {
            QMessageBox::critical(this, "Błąd liczbowy", "Szybkość odczytu nie może być mniejsza lub równa 0 "
                                                         "albo jest błąd w napisaniu liczby.");
            return;
        }
        else if ((Szybkosc_ZapisuEdit->text()).toDouble() <= 0)
        {
            QMessageBox::critical(this, "Błąd liczbowy", "Szybkość zapisu nie może być mniejsza lub równa 0 "
                                                         "jest błąd w napisaniu liczby.");
            return;
        }
        mProdukt = new cSSD((ui->EditLP->text()).toULongLong(),
                          (ui->lineEditDostepnaIlosc->text()).toUInt(), (ui->lineEditIloscnaamazonie->text()).toInt(), ui->EditNazwa->text(),
                          ui->lineEditKategoria->text(), ui->lineEditProducent->text(),
                          (ui->lineEditWaga->text()).toDouble(), ui->lineEditKolor->text(),
                          (ui->lineEditCena->text()).toDouble(), (ui->lineEditVat->text()).toDouble(),
                           (PojemnoscEdit->text()).toInt(), (Szybkosc_OdczytuEdit->text()).toDouble(),
                           (Szybkosc_ZapisuEdit->text()).toDouble(), Typ_SATAEdit->text());
    }
    else
    {
        mProdukt = new cProdukt((ui->EditLP->text()).toULongLong(),
                               (ui->lineEditDostepnaIlosc->text()).toUInt(), (ui->lineEditIloscnaamazonie->text()).toInt(), ui->EditNazwa->text(),
                               ui->lineEditKategoria->text(), ui->lineEditProducent->text(),
                               (ui->lineEditWaga->text()).toDouble(), ui->lineEditKolor->text(),
                               (ui->lineEditCena->text()).toDouble(), (ui->lineEditVat->text()).toDouble());
    }
    if(ui->EditLP->isEnabled() == 0)
    {
        BazaProdukty->Zamiana_Produktu(mProdukt);
        this->close();
    }
    else {
        BazaProdukty->Dodac_produkt(mProdukt);
        this->close();
    }
}



//void DodanieNowegoProduktu::on_ZgenerujLP_clicked()
//{
//    ui->labelLP->setText("hajdhl");
//    bool var = 0;
//    unsigned long long int i;
//    while(var == 0)
//    {
//        std::srand((unsigned)time(0));
//        std::string random_num = "";
//        random_num = std::to_string((rand() % 17) + 1);
//        for (int i = 0; i < 3; i++)
//        {
//            random_num += std::to_string((rand() % 999999) + 1);
//        }
//        i = std::stoull(random_num);
//        var = BazaProdukty->Sparwdz_LP(i);
//    }
//    ui->EditLP->setText(QString::number(i));
//}


void DodanieNowegoProduktu::on_ZgenerujLP_clicked()
{
    bool var = 0;
    unsigned long long int i;
    while(var == 0)
    {
        std::srand((unsigned)time(0));
        std::string random_num = "";
        random_num = std::to_string((rand() % 17) + 1);
        for (int i = 0; i < 3; i++)
        {
            random_num += std::to_string((rand() % 999999) + 1);
        }
        i = std::stoull(random_num);
        var = BazaProdukty->Sparwdz_LP(i);
    }
    ui->EditLP->setText(QString::number(i));
}

