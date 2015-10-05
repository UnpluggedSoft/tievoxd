/*
 * File:   ActionLED.h
 * Author: Jason Burgess <jason@notplugged.in>
 *
 * Created on October 5, 2015 2:00 AM
 * $Id$
 */

#pragma once

#include <wiringPi.h>
#include "Action.h"
#include "tievoxd.h"
#include "RPin.h"

using namespace std;

class ActionLED :
	public Action
{
public:
    ActionLED(libconfig::Setting *event);
    ~ActionLED();

    void Do();
    
    int Pin;
    int BlinkDelayOff;
    int BlinkDelayOn;
    int StopPin;
    int StopCondition;
    
    static void *Run(void *context);
    static void *Wait(void *context);
    
    void DoWait();
    
    void On();
    void ForceOff();
    void Off();
    void Off(bool stop);
    
    pthread_t Thread;
    pthread_t WThread;

private:
    int PinsSetup;
};

