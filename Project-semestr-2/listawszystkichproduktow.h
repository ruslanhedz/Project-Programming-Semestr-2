#ifndef LISTAWSZYSTKICHPRODUKTOW_H
#define LISTAWSZYSTKICHPRODUKTOW_H

#include <QMainWindow>

namespace Ui {
class ListaWszystkichProduktow;
}

class ListaWszystkichProduktow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ListaWszystkichProduktow(QWidget *parent = nullptr);
    ~ListaWszystkichProduktow();

private:
    Ui::ListaWszystkichProduktow *ui;
};

#endif // LISTAWSZYSTKICHPRODUKTOW_H
