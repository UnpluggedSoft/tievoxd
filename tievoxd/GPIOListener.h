/*
 * File:   GPIOListener.h
 * Author: Jason Burgess <jason@notplugged.in>
 *
 * Created on August 16, 2015, 9:25 PM
 * $Id$
 */

#ifndef GPIOLISTENER_H
#define	GPIOLISTENER_H

#include "Listener.h"

class GPIOListener : public Listener {
public:
    GPIOListener();
    virtual ~GPIOListener();
    
    void Run();
    void SetupPins();
private:

};

#endif	/* GPIOLISTENER_H */

