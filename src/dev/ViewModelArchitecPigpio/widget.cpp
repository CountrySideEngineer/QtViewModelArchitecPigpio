#include <QThread>
#include "widget.h"
#include "ui_widget.h"
#include "model/cgpio.h"
#include "model/cgpiomodel.h"
#include "view/cgpioview.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    this->mModel = new CGpioModel();

    CGpio* instance = CGpio::GetInstance();
    instance->SetModel(this->mModel);

    instance->SetMode(SAMPLE_GPIO_PIN, CGpio::GPIO_PIN_DIRECTION_INPUT);
    instance->SetIsr(SAMPLE_GPIO_PIN, CGpio::GPIO_INTERRUPT_DETECTION_EITHER_EDGE);

    this->ui->widget->setModel(this->mModel);

    printf("MainThreadId = %d\r\n", (int)QThread::currentThreadId());
}

Widget::~Widget()
{
    delete ui;
}
