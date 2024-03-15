#ifndef ZMIENICILOSCAMAZON_H
#define ZMIENICILOSCAMAZON_H

#include <QDialog>
class cProdukt;

namespace Ui {
class ZmienicIloscAmazon;
}

class ZmienicIloscAmazon : public QDialog
{
    Q_OBJECT

public:
    explicit ZmienicIloscAmazon(QWidget *parent = nullptr, cProdukt* Produkt = nullptr);
    ~ZmienicIloscAmazon();

private slots:
    void on_ZmienicButton_clicked();

private:
    Ui::ZmienicIloscAmazon *ui;
    cProdukt* mProdukt;
};

#endif // ZMIENICILOSCAMAZON_H
