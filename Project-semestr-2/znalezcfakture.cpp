#include "znalezcfakture.h"
#include "ui_znalezcfakture.h"
#include <QHBoxLayout>
#include <QLineEdit>
#include "cbazafaktury.h"
#include "pokazfaktury.h"

short int index_box = 0;

ZnalezcFakture::ZnalezcFakture(QWidget *parent, cBazaFaktury* aBazaFaktury) :
    QDialog(parent),
    ui(new Ui::ZnalezcFakture), BazaFaktury(aBazaFaktury)
{
    ui->setupUi(this);
    ui->LabelNumerAlboData->setText("Wpisz numer: ");
    NumerEdit = std::make_shared<QLineEdit>();
    ui->horizontalLayout_2->addWidget(NumerEdit.get());
}

ZnalezcFakture::~ZnalezcFakture()
{
    delete ui;
}




void ZnalezcFakture::on_comboBox_currentIndexChanged(int index)
{
    if(index_box != index)
    {
        if(index_box == 0)
        {
            NumerEdit.reset();
        }
        else {
            DzienEdit.reset();
            MiesiacEdit.reset();
            RokEdit.reset();
        }


        if(index == 0)
        {
            ui->LabelNumerAlboData->setText("Wpisz Numer: ");
            NumerEdit = std::make_shared<QLineEdit>();
            ui->horizontalLayout_2->addWidget(NumerEdit.get());
            index_box = index;
        }
        else {
            ui->LabelNumerAlboData->setText("Wpisz Date: ");
            DzienEdit = std::make_shared<QLineEdit>();
            DzienEdit->setPlaceholderText("Dzień");
            MiesiacEdit = std::make_shared<QLineEdit>();
            MiesiacEdit->setPlaceholderText("Miesiac");
            RokEdit = std::make_shared<QLineEdit>();
            RokEdit->setPlaceholderText("Rok");
            ui->horizontalLayout_2->addWidget(DzienEdit.get());
            ui->horizontalLayout_2->addWidget(MiesiacEdit.get());
            ui->horizontalLayout_2->addWidget(RokEdit.get());
            index_box = index;
        }
    }
}


void ZnalezcFakture::on_ZnajdzButton_clicked()
{
    ui->listWidget->clear();
    if(index_box == 0)
    {
        BazaFaktury->Znalezc_Fakture(NumerEdit->text().toULongLong(), ui->listWidget);
    }
    else {
        BazaFaktury->Znalezc_Fakture(DzienEdit->text().toInt(), MiesiacEdit->text().toInt(),
                                     RokEdit->text().toInt(), ui->listWidget);
    }
}


void ZnalezcFakture::on_listWidget_itemDoubleClicked(QListWidgetItem *item)
{
    QString text = item->text();
    QString Numer = "";
    int i = 0;
    while(text[i] != ' ')
    {
        Numer += text[i];
        i++;
    }
    std::shared_ptr<PokazFaktury> Pokaz_Faktury =
        std::make_shared<PokazFaktury>(nullptr,
                BazaFaktury->Return_Faktura_Numer(Numer.toULongLong()));
    Pokaz_Faktury->setModal(true);
    Pokaz_Faktury->exec();
}

