#ifndef PRODUKTINFO_H
#define PRODUKTINFO_H

#include <QDialog>
class cProdukt;
class QLabel;
class DodanieNowegoProduktu;
class cBaza;

namespace Ui {
class ProduktInfo;
}

class ProduktInfo : public QDialog
{
    Q_OBJECT

public:
    explicit ProduktInfo(QWidget *parent = nullptr, cBaza* aBaza = nullptr, cProdukt* Produkt = nullptr);
    ~ProduktInfo();
    std::shared_ptr<QLabel> Dlugosc;
    std::shared_ptr<QLabel> Szerokosc;
    std::shared_ptr<QLabel> Grubosc;
    std::shared_ptr<QLabel> Funkcja;
    std::shared_ptr<QLabel> Rozmiar;
    std::shared_ptr<QLabel> Material;
    std::shared_ptr<QLabel> Pojemnosc;
    std::shared_ptr<QLabel> Szybkosc_Odczytu;
    std::shared_ptr<QLabel> Szybkosc_Zapisu;
    std::shared_ptr<QLabel> Typ_SATA;
    std::shared_ptr<QLabel> Format_Dysku;
    std::shared_ptr<QLabel> Srednica;
    std::shared_ptr<QLabel> Kat_Nachylenia;
    std::shared_ptr<QLabel> Typ_Zlacza;
    std::shared_ptr<QLabel> Ilosc_Godzin_Pracy;
    void on_Ususnac_clicked();

private slots:

    void on_EdytowacButton_clicked();

private:
    Ui::ProduktInfo *ui;
    cProdukt* mProdukt;
    DodanieNowegoProduktu* Edytowanie_Produktu;
    cBaza* BazaProdukty;
};

#endif // PRODUKTINFO_H
