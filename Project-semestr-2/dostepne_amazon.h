#ifndef DOSTEPNE_AMAZON_H
#define DOSTEPNE_AMAZON_H

#include <QDialog>
#include <QListWidgetItem>
class cBaza;

namespace Ui {
class Dostepne_Amazon;
}

class Dostepne_Amazon : public QDialog
{
    Q_OBJECT

public:
    explicit Dostepne_Amazon(QWidget *parent = nullptr, cBaza* aBaza = nullptr);
    ~Dostepne_Amazon();

private slots:
    void on_ZmienicIloscButton_clicked();

    void on_EdytowacButton_clicked();

    void on_InfoButton_clicked();

    void on_listWidget_itemDoubleClicked(QListWidgetItem *item);

private:
    Ui::Dostepne_Amazon *ui;
    cBaza* BazaProdukty;
};

#endif // DOSTEPNE_AMAZON_H
