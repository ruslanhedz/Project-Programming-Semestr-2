#include "pokazfaktury.h"
#include "ui_pokazfaktury.h"
#include "przedsiebiorca.h"

PokazFaktury::PokazFaktury(QWidget *parent, cFaktura* aFaktura) :
    QDialog(parent),
    ui(new Ui::PokazFaktury), Faktura(aFaktura)
{
    ui->setupUi(this);
    Faktura->Pokaz(this);
}

PokazFaktury::~PokazFaktury()
{
    delete ui;
}
