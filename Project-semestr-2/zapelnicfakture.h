#ifndef ZAPELNICFAKTURE_H
#define ZAPELNICFAKTURE_H

#include <QDialog>
class QLabel;
class cBaza;
class cBazaFaktury;
class QLineEdit;
#include <QComboBox>

namespace Ui {
class ZapelnicFakture;
}

class ZapelnicFakture : public QDialog
{
    Q_OBJECT

public:
    explicit ZapelnicFakture(QWidget *parent = nullptr, cBaza* aBaza = nullptr,
                             cBazaFaktury* aBazaFaktury = nullptr);
    ~ZapelnicFakture();

private:
    Ui::ZapelnicFakture *ui;
    cBaza* BazaProdukty;
    cBazaFaktury* BazaFaktury;
private slots:
    void on_LP1Edit_editingFinished();
    void on_LP2Edit_editingFinished();
    void on_LP3Edit_editingFinished();
    void on_LP4Edit_editingFinished();
    void on_LP5Edit_editingFinished();
    void on_Nazwa1Box_currentIndexChanged(int index);
    void on_Nazwa2Box_currentIndexChanged(int index);
    void on_Nazwa3Box_currentIndexChanged(int index);
    void on_Nazwa4Box_currentIndexChanged(int index);
    void on_Nazwa5Box_currentIndexChanged(int index);
    void on_Ilosc1Edit_editingFinished();
    void on_Ilosc2Edit_editingFinished();
    void on_Ilosc3Edit_editingFinished();
    void on_Ilosc4Edit_editingFinished();
    void on_Ilosc5Edit_editingFinished();
    void on_ObliczycButton_clicked();
    void on_ZapisacButton_clicked();
};

#endif // ZAPELNICFAKTURE_H
