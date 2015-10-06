/*
 * File:   TimerListener.h
 * Author: Jason Burgess <jason@notplugged.in>
 *
 * Created on September 26, 2015, 11:12 PM
 * $Id$
 */

#pragma once

#include <map>
#include <pthread.h>
#include "Listener.h"
#include "Event.h"

typedef map<string, pthread_t> TimerThreadList;

class TimerListener : public Listener {
public:
    TimerListener();
    virtual ~TimerListener();
    
    TimerThreadList Threads;
    
    void Run();
    void Setup();
private:

};
