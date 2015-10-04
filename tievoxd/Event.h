/*
 * File:   Event.h
 * Author: Jason Burgess <jason@notplugged.in>
 *
 * Created on August 16, 2015, 9:23 PM
 * $Id$
 */

#pragma once

#include <libconfig.h++>
#include <string>
#include "Action.h"
#include "EventOptions.h"

using namespace std;

class Event {
public:
    Event();
    Event(libconfig::Setting *event);
    virtual ~Event();
    void GetOptions(libconfig::Setting *eventConfig);

    string Name;
    string Type;
    string EventName;
    
    Action *EventAction;
private:

};
