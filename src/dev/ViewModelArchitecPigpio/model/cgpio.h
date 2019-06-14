#ifndef CGPIO_H
#define CGPIO_H
#include <iostream>
#include "cgpiomodel.h"
#include "pigpio.h"

#define GPIO_PIN_02         (2)
#define GPIO_PIN_26         (26)
#define SAMPLE_GPIO_PIN     (GPIO_PIN_26)

class CGpio
{
public:
    enum {
        GPIO_PIN_DIRECTION_INPUT = PI_INPUT,
        GPIO_PIN_DIRECTION_OUTPUT = PI_OUTPUT,
    };
    enum {
        GPIO_INTERRUPT_DETECTION_RISING_EDGE = RISING_EDGE,
        GPIO_INTERRUPT_DETECTION_FALLING_EDGE = FALLING_EDGE,
        GPIO_INTERRUPT_DETECTION_EITHER_EDGE = EITHER_EDGE,
    };

public:
    static CGpio* GetInstance();
    static void Interrupt(int pin, int level, uint32_t tick);

protected:
    explicit CGpio();
    ~CGpio();

public:
    void SetMode(uint8_t pin, uint8_t mode);
    void SetIsr(uint8_t pin, uint8_t mode);
    void SetModel(CGpioModel* model);

    CGpioModel* GetModel(void) const { return  this->mModel; }

protected:
    static void Initialize();
    static void Finalize() {}

protected:
    static CGpio* mInstance;

protected:
    CGpioModel* mModel;
};

#endif // CGPIO_H
