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
#include "ActionPlaySound.h"
#include "ActionLED.h"

Event::Event() {
}

Event::Event(libconfig::Setting *event)
{
    string actionName;

    // TODO: Validate lookups
    // TODO: Validate data   
    event->lookupValue("title", Name);
    event->lookupValue("type", Type);
    event->lookupValue("name", EventName);
    
    event->lookupValue("action", actionName);
    // TODO: Add other action types
    if (actionName == "PLAY_SOUND")
    {
        EventAction = new ActionPlaySound(event);
    }
    
    EventAction = new Action(event);

}

Event::~Event() {
    delete EventAction;
}

