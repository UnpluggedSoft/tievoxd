/*
 * File:   GPIOListener.h
 * Author: Jason Burgess <jason@notplugged.in>
 *
 * Created on August 16, 2015, 9:25 PM
 * $Id$
 */

#pragma once

#include <map>
#include "Listener.h"
#include "Event.h"

using namespace std;

typedef map<int, int> PinState;

class GPIOListener : public Listener {
public:
    GPIOListener();
    virtual ~GPIOListener();
    
    PinState Pins;
    IntEvent Events;
    
    void Run();
    void Setup();
private:

};
