/*
 * File:   Event.h
 * Author: Jason Burgess <jason@notplugged.in>
 *
 * Created on August 16, 2015, 9:23 PM
 * $Id$
 */

#ifndef EVENT_H
#define	EVENT_H

#include <string>
#include "Action.h"
#include "EventOptions.h"

using namespace std;

class Event {
public:
    Event();
    virtual ~Event();
protected:
    string name;
    Action action;
    EventOptions options;
private:

};

#endif	/* EVENT_H */

