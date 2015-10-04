/*
 * File:   GPIOListener.h
 * Author: Jason Burgess <jason@notplugged.in>
 *
 * Created on August 16, 2015, 9:25 PM
 * $Id$
 */

#pragma once

#include "Listener.h"

class GPIOListener : public Listener {
public:
    GPIOListener();
    virtual ~GPIOListener();
    
    void Run();
    void SetupPins();
private:

};
