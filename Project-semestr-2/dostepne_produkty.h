#ifndef DOSTEPNE_PRODUKTY_H
#define DOSTEPNE_PRODUKTY_H

#include <QDialog>
class cBaza;
class ZmianaIlosci;
class ProduktInfo;
class QListWidgetItem;
//class

namespace Ui {
class Dostepne_Produkty;
}

class Dostepne_Produkty : public QDialog
{
    Q_OBJECT

public:
    explicit Dostepne_Produkty(QWidget *parent = nullptr, cBaza* aBaza = nullptr);
    ~Dostepne_Produkty();


private:
    Ui::Dostepne_Produkty *ui;
    cBaza* BazaProdukty;
    void on_clicked_zmianaIlosci();
    void on_clicked_Edytowac();
    void on_clicked_InfoProdukt();
//    void on_doubleClicked_ListWidget(QListWidgetItem *item);

private slots:
    void on_doubleClicked_ListWidget(QListWidgetItem *item);

};

#endif // DOSTEPNE_PRODUKTY_H
