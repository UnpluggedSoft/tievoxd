/* 
 * File:   Rpin.cpp
 * Author: Jason Burgess <jason@notplugged.in>
 *
 * Created on October 4, 2015 10:06 PM
 * $Id$
 */

#include <string>
#include <wiringPi.h>
#include "RPin.h"

using namespace std;

RPin::RPin(int pin, int gpio, int wPi, int pull, int type, string name)
    : Pin(pin)
    , GPIO(gpio)
    , WPi(wPi)
    , Pull(pull)
    , Type(type)
    , Name(name)
    , ALT0("")
    , ALT5("") {
}

RPin::RPin(int pin, int gpio, int wPi, int pull, int type, string name, string alt0, string alt5)
    : Pin(pin)
    , GPIO(gpio)
    , WPi(wPi)
    , Pull(pull)
    , Type(type)
    , Name(name)
    , ALT0(alt0)
    , ALT5(alt5) {
}
    
RPin::~RPin() {
}
    
/**
 * Perform initialization of pin if needed to make sure it's set up like we want.
 */
void RPin::StartupPrepare() {
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