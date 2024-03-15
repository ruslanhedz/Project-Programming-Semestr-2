#ifndef ZNALEZCFAKTURE_H
#define ZNALEZCFAKTURE_H

#include <QDialog>
class QLineEdit;
class cBazaFaktury;
class QListWidgetItem;

namespace Ui {
class ZnalezcFakture;
}

class ZnalezcFakture : public QDialog
{
    Q_OBJECT

public:
    explicit ZnalezcFakture(QWidget *parent = nullptr, cBazaFaktury* aBazaFaktury = nullptr);
    ~ZnalezcFakture();

private slots:

    void on_comboBox_currentIndexChanged(int index);

    void on_ZnajdzButton_clicked();

    void on_listWidget_itemDoubleClicked(QListWidgetItem *item);

private:
    Ui::ZnalezcFakture *ui;
    std::shared_ptr<QLineEdit>NumerEdit;
    std::shared_ptr<QLineEdit>DzienEdit;
    std::shared_ptr<QLineEdit>MiesiacEdit;
    std::shared_ptr<QLineEdit>RokEdit;
    cBazaFaktury* BazaFaktury;
};

#endif // ZNALEZCFAKTURE_H
