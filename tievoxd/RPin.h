/* 
 * File:   Rpin.h
 * Author: Jason Burgess <jason@notplugged.in>
 *
 * Created on October 4, 2015 10:06 PM
 * $Id$
 */

#pragma once

#include <string>
#include <wiringPi.h>

using namespace std;

#define PIN_TYPE_POWER          0x01
#define PIN_TYPE_GROUND         0x02
#define PIN_TYPE_GPIO           0x03
#define PIN_TYPE_PWM            0x04
#define PIN_TYPE_SPI            0x05
#define PIN_TYPE_I2C            0x06
#define PIN_TYPE_UART           0x07

#define PIN_NULL                -1

#define PIN_PULL_HIGH           0x01
#define PIN_PULL_LOW            0x00

class RPin
{
public:
    string Name;
    int Pin;
    int GPIO;
    int WPi;
    int Pull;
    int Type;
    string ALT0;
    string ALT5;
    
    RPin(int pin, int gpio, int wPi, int pull, int type, string name)
        : Pin(pin)
        , GPIO(gpio)
        , WPi(wPi)
        , Pull(pull)
        , Type(type)
        , Name(name)
        , ALT0("")
        , ALT5("") {
    }

    RPin(int pin, int gpio, int wPi, int pull, int type, string name, string alt0, string alt5)
        : Pin(pin)
        , GPIO(gpio)
        , WPi(wPi)
        , Pull(pull)
        , Type(type)
        , Name(name)
        , ALT0(alt0)
        , ALT5(alt5) {
    }
    
    ~RPin() {
    }
    
    /**
     * Perform initialization of pin if needed to make sure it's set up like we want.
     */
    void StartupPrepare() {
        switch (Type) {
        case PIN_TYPE_GPIO:
            // Turn off pull up/pull down by default
            pullUpDnControl(Pin, PUD_OFF);
            break;
        case PIN_TYPE_PWM:
            // Turn on PWM mode, if it isn't.
            pullUpDnControl(Pin, PUD_OFF);
            pinMode(Pin, PWM_OUTPUT);
        }
    }
    
    // TODO: See if we need some more helper functions here.
};

