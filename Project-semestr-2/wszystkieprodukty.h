#ifndef WSZYSTKIEPRODUKTY_H
#define WSZYSTKIEPRODUKTY_H

#include <QDialog>
#include <memory>
class DodanieNowegoProduktu;
class cBaza;
class ZnalezcProdukt;
class QListWidgetItem;
class ProduktInfo;
class MainWindow;

namespace Ui {
class WszystkieProdukty;
}

class WszystkieProdukty : public QDialog
{
    Q_OBJECT

public:
    explicit WszystkieProdukty(QWidget *parent = nullptr, cBaza* aBaza = nullptr);
    ~WszystkieProdukty();

private slots:
    void on_DodacButton_clicked();

    void on_UsunacButton_clicked();

    void on_ZnalezcButton_clicked();

    void on_listWidget_itemDoubleClicked(QListWidgetItem *item);

    void on_InfomacjaButton_clicked();

private:
    Ui::WszystkieProdukty *ui;
    cBaza* BazaProdukty;
//    DodanieNowegoProduktu* Dodanie_Produktu;
//    std::shared_ptr<DodanieNowegoProduktu> Dodanie_Produktu;
//    std::shared_ptr<ZnalezcProdukt> Znalezc_Produkt;
//    std::shared_ptr<ProduktInfo> Produkt_Information;
//    ZnalezcProdukt* Znalezc_Produkt;
//    ProduktInfo* Produkt_Information;
};

#endif // WSZYSTKIEPRODUKTY_H
