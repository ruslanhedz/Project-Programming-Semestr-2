#ifndef POKAZFAKTURY_H
#define POKAZFAKTURY_H

#include <QDialog>
#include <vector>
#include <QLabel>
class cFaktura;
class Przedsiebiorca;

namespace Ui {
class PokazFaktury;
}

class PokazFaktury : public QDialog
{
    Q_OBJECT

public:
    explicit PokazFaktury(QWidget *parent = nullptr, cFaktura* aFaktura = nullptr);
    ~PokazFaktury();
    friend cFaktura;
    friend Przedsiebiorca;

private:
    Ui::PokazFaktury *ui;
    cFaktura* Faktura;
    std::vector<std::shared_ptr<QLabel>>LPLabel;
    std::vector<std::shared_ptr<QLabel>>NazwaLabel;
    std::vector<std::shared_ptr<QLabel>>IloscLabel;
    std::vector<std::shared_ptr<QLabel>>CenaLabel;
    std::vector<std::shared_ptr<QLabel>>WartoscLabel;
};

#endif // POKAZFAKTURY_H
