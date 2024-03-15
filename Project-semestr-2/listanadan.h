#ifndef LISTANADAN_H
#define LISTANADAN_H

#include <QDialog>
class cBaza;
class cBazaNadanie;

namespace Ui {
class ListaNadan;
}

class ListaNadan : public QDialog
{
    Q_OBJECT

public:
    explicit ListaNadan(QWidget *parent = nullptr, cBaza* aBaza = nullptr, cBazaNadanie* aBazaNadan = nullptr);
    ~ListaNadan();

private slots:
    void on_DodacNadanieButton_clicked();

    void on_UsunacNadanieButton_clicked();

    void on_DodacNaTaSamaDateIAdressButton_clicked();

    void on_DodacNaTaSamaDateButton_clicked();

    void on_DodacNaTenSamAdressButton_clicked();

    void on_NadaneButton_clicked();

private:
    Ui::ListaNadan *ui;
    cBaza* BazaProdukty;
    cBazaNadanie* Baza_Nadan;
};

#endif // LISTANADAN_H
