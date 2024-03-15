#ifndef ZMIANAILOSCI_H
#define ZMIANAILOSCI_H

#include <QDialog>
class cProdukt;

namespace Ui {
class ZmianaIlosci;
}

class ZmianaIlosci : public QDialog
{
    Q_OBJECT

public:
    explicit ZmianaIlosci(QWidget *parent = nullptr, cProdukt* Produkt = nullptr);
    ~ZmianaIlosci();

private slots:
    void on_ZmienButton_clicked();

private:
    Ui::ZmianaIlosci *ui;
    cProdukt* mProdukt;
};

#endif // ZMIANAILOSCI_H
