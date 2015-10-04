/*
 * File:   Event.cpp
 * Author: Jason Burgess <jason@notplugged.in>
 *
 * Created on August 16, 2015, 9:23 PM
 * $Id$
 */

#include <libconfig.h++>
#include <string>
#include "Event.h"
#include "Action.h"

Event::Event() {
}

Event::Event(libconfig::Setting *event)
{
    string value;

    // TODO: Validate lookups
    event->lookupValue("title", Name);
    event->lookupValue("type", Type);
    event->lookupValue("name", EventName);
    
    EventAction = new Action(event);

    // TODO: Validate data   
}

Event::~Event() {
    delete EventAction;
}

