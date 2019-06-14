#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "model/cgpiomodel.h"

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

protected:
    CGpioModel* mModel;

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
