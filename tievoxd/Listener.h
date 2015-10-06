/*
 * File:   Listener.h
 * Author: Jason Burgess <jason@notplugged.in>
 *
 * Created on August 16, 2015, 9:23 PM
 * $Id$
 */

#pragma once

#include <map>
#include <pthread.h>
#include "Event.h"

// Time to sleep between checks in milliseconds
#define LISTENER_SLEEP_DELAY        100

typedef map<int, Event> IntEvent;

class Listener {
public:
    Listener();
    virtual ~Listener();

    IntEvent Events;
    
    virtual void Run();
    virtual void Setup();
    
    void CheckRun();
    
    static void *SpawnAction(void *context);
private:
};
