#include "listawszystkichproduktow.h"
#include "ui_listawszystkichproduktow.h"

ListaWszystkichProduktow::ListaWszystkichProduktow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ListaWszystkichProduktow)
{
    ui->setupUi(this);

}

ListaWszystkichProduktow::~ListaWszystkichProduktow()
{
    delete ui;
}
