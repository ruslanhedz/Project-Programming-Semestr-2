#ifndef ZNALEZCPRODUKT_H
#define ZNALEZCPRODUKT_H

#include <QDialog>
class cBaza;
class QListWidgetItem;

namespace Ui {
class ZnalezcProdukt;
}

class ZnalezcProdukt : public QDialog
{
    Q_OBJECT

public:
    explicit ZnalezcProdukt(QWidget *parent = nullptr, cBaza* Baza_Produkty = nullptr);
    ~ZnalezcProdukt();

private slots:
    void on_ZnalezcButton_clicked();

    void on_listWidget_itemDoubleClicked(QListWidgetItem *item);

private:
    Ui::ZnalezcProdukt *ui;
    cBaza *Baza;
};

#endif // ZNALEZCPRODUKT_H
