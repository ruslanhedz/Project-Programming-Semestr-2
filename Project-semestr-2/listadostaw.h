#ifndef LISTADOSTAW_H
#define LISTADOSTAW_H

#include <QDialog>
class cBaza;
class cBazaDostawa;

namespace Ui {
class ListaDostaw;
}

class ListaDostaw : public QDialog
{
    Q_OBJECT

public:
    explicit ListaDostaw(QWidget *parent = nullptr, cBaza* aBaza = nullptr, cBazaDostawa* aBazaDostawa = nullptr);
    ~ListaDostaw();

private slots:

    void on_DodacButton_clicked();

    void on_UsunacButton_clicked();

    void on_NaTaSamaDateButton_clicked();

    void on_DostarczonaButton_clicked();

private:
    Ui::ListaDostaw *ui;
    cBaza* BazaProdukty;
    cBazaDostawa* Baza_Dostawa;
};

#endif // LISTADOSTAW_H
