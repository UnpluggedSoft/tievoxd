/*
 * File:   ActionSystem.h
 * Author: Jason Burgess <jason@notplugged.in>
 *
 * Created on October 5, 2015 7:26 AM
 * $Id$
 */

#include <libconfig.h++>
#include <string>
#include <stdlib.h>
#include "ActionSystem.h"

ActionSystem::ActionSystem(libconfig::Setting *event) {
    event->lookupValue("command", Command);    
}

ActionSystem::~ActionSystem() { }

void ActionSystem::Do()
{
    system(Command.c_str());
}