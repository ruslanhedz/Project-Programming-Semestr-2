#ifndef LAYOUTCLASS_H
#define LAYOUTCLASS_H
#include <QLayout>
class QWidget;

class LayoutClass
{
private:
    QLayout* Layout;
public:
    LayoutClass(QLayout* layout);
    LayoutClass& operator<<(QWidget* item)
    {
        Layout->addWidget(item);
        return *this;
    }
};

#endif // LAYOUTCLASS_H
