#include <iostream>
#include <assert.h>
#include <QThread>
#include "cgpio.h"

using namespace std;

CGpio* CGpio::mInstance = nullptr;

/**
 * @brief CGpio::CGpio
 */
CGpio::CGpio() {}

/**
 * @brief CGpio::~CGpio
 */
CGpio::~CGpio() {
    gpioTerminate();
}

/**
 * @brief CGpio::Initialize Initialize CGpio object.
 *        In this method, the library libpigpio is initialized.
 */
void CGpio::Initialize()
{
    if (gpioInitialise() < 0) {
        cout << "gpioInitialise() failed." << endl;
    } else {
        if (nullptr == CGpio::mInstance) {
            CGpio::mInstance = new CGpio();
        }
    }
}

/**
 * @brief CGpio::GetInstance    Returns the instance of CGpio object, the SINGLETON object.
 * @return  Pointer to instance of CGpio.
 */
CGpio* CGpio::GetInstance()
{
    if (nullptr == CGpio::mInstance) {
        CGpio::Initialize();
    }
    return CGpio::mInstance;
}

void CGpio::SetModel(CGpioModel *model)
{
    assert(nullptr != model);

    this->mModel = model;
}

void CGpio::SetMode(uint8_t pin, uint8_t mode)
{
    gpioSetMode(pin, mode);
    if (GPIO_PIN_DIRECTION_OUTPUT == mode) {
        gpioWrite(pin, PI_LOW);
    }
}

void CGpio::SetIsr(uint8_t pin, uint8_t mode)
{
    gpioISRFunc_t isrFunc = CGpio::Interrupt;
    gpioSetISRFunc(pin, mode, 0, isrFunc);
}

void CGpio::Interrupt(int pin, int level, uint32_t tick)
{
    Q_UNUSED(tick);

    printf("CGpio::Interrupt called : ThreadId = %d\r\n", (int)QThread::currentThreadId());

    CGpio* instance = CGpio::GetInstance();

    CGpioModel* model = instance->GetModel();
    model->setGpioData(pin, level);
}


