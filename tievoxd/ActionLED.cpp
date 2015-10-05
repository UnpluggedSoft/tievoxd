/*
 * File:   ActionLED.cpp
 * Author: Jason Burgess <jason@notplugged.in>
 *
 * Created on October 5, 2015 2:00 AM
 * $Id$
 */

#include <libconfig.h++>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <wiringPi.h>
#include "ActionLED.h"
#include "RPin.h"

ActionLED::ActionLED(libconfig::Setting *event)
    : Action(event) {
    // Defaults:
    BlinkDelayOff = 0;
    BlinkDelayOn = 0;
    StopPin = PIN_NULL;
    StopCondition = PIN_PULL_LOW;
    PinsSetup = false;
        
    event->lookupValue("pin", Pin);
    event->lookupValue("blink_on", BlinkDelayOn);
    event->lookupValue("blink_off", BlinkDelayOff);
    event->lookupValue("stop_condition", StopCondition);
    event->lookupValue("stop_pin", StopPin);
    
    // Set Pin modes.
    pinMode(Pin, OUTPUT);
    if (StopPin > PIN_NULL) {
        pinMode(StopPin, INPUT);
    }
}

ActionLED::~ActionLED() { }

void * ActionLED::Run(void *context) {
    ((ActionLED *)context)->On();
}

void *ActionLED::Wait(void *context) {
    ((ActionLED*)context)->DoWait();
}

void ActionLED::Do() {
    // Run in separate thread if needed
    if (BlinkDelayOn > 0 || BlinkDelayOff > 0 || StopPin > PIN_NULL) {
        pthread_create(&Thread, NULL, &ActionLED::Run, this);
    } else {
        On();
    }
}

void ActionLED::On() {
    
    // Turn on LED
    digitalWrite(Pin, 1);

    // Setup Stop Pin
    if (!PinsSetup) {
        if (StopPin > PIN_NULL) {
            // Setup pins for interrupt
            char *stopCommand;
            if (StopCondition) {
                sprintf(stopCommand, "gpio edge %d falling", StopPin);
                system(stopCommand);
            
            } else {
                sprintf(stopCommand, "gpio edge %d rising", StopPin);
                system(stopCommand);
            }
            
            // Setup interrupt wait function 
            pthread_create(&WThread, NULL, &ActionLED::Wait, this);
        }
        PinsSetup = true;
    }
    
    if (BlinkDelayOff > 0) {
        usleep(BlinkDelayOff);
        Off();
    }
}

void ActionLED::ForceOff() {
    Off(true);
}

void ActionLED::Off() {
    Off(false);
}

void ActionLED::Off(bool stop) {
    // Turn off LED
    digitalWrite(Pin, 0);
    
    if (!stop && BlinkDelayOn) {
        usleep(BlinkDelayOn);
        On();
    }
}

void ActionLED::DoWait() {
    waitForInterrupt(StopPin, -1);
    ForceOff();
    pthread_exit(NULL);
}
