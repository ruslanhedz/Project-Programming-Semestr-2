#ifndef LISTAFAKTUR_H
#define LISTAFAKTUR_H

#include <QDialog>
class cBaza;
class cBazaFaktury;
class QListWidgetItem;

namespace Ui {
class ListaFaktur;
}

class ListaFaktur : public QDialog
{
    Q_OBJECT

public:
    explicit ListaFaktur(QWidget *parent = nullptr, cBaza* aBaza = nullptr,
                         cBazaFaktury* aBazaFaktury = nullptr);
    ~ListaFaktur();

private slots:
    void on_ZapelnicFaktureButton_clicked();

    void on_UsunacFaktureButton_clicked();

    void on_ZnalezcButton_clicked();

    void on_PokazButton_clicked();

    void on_listWidget_itemDoubleClicked(QListWidgetItem *item);

private:
    Ui::ListaFaktur *ui;
    cBaza* BazaProdukty;
    cBazaFaktury* BazaFaktury;
};

#endif // LISTAFAKTUR_H
