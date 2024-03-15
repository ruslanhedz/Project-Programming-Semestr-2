#ifndef DODACNADANIE_H
#define DODACNADANIE_H

#include <QDialog>
class cBaza;
class cBazaNadanie;
class cNadanie;

namespace Ui {
class DodacNadanie;
}

class DodacNadanie : public QDialog
{
    Q_OBJECT

public:
    explicit DodacNadanie(QWidget *parent = nullptr, cBaza* aBaza = nullptr,
                          cBazaNadanie* aBazaNadan = nullptr, cNadanie* Nadanie = nullptr);
    ~DodacNadanie();

private slots:
    void on_comboBox_currentIndexChanged(int index);

    void on_pushButton_clicked();

private:
    Ui::DodacNadanie *ui;
    cBaza* BazaProdukty;
    cBazaNadanie* Baza_Nadan;
};

#endif // DODACNADANIE_H
