#ifndef DODACDOSTAWE_H
#define DODACDOSTAWE_H

#include <QDialog>
class cBaza;
class cBazaDostawa;
class cDostawa;

namespace Ui {
class DodacDostawe;
}

class DodacDostawe : public QDialog
{
    Q_OBJECT

public:
    explicit DodacDostawe(QWidget *parent = nullptr, cBaza* aBaza = nullptr,
                          cBazaDostawa* aBazaDostawa = nullptr, cDostawa* Dostawa = nullptr);
    ~DodacDostawe();

private slots:
    void on_comboBox_currentIndexChanged(int index);

    void on_pushButton_clicked();

private:
    Ui::DodacDostawe *ui;
    cBaza* BazaProdukty;
    cBazaDostawa* Baza_Dostawy;
};

#endif // DODACDOSTAWE_H
