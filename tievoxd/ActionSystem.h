/*
 * File:   ActionSystem.h
 * Author: Jason Burgess <jason@notplugged.in>
 *
 * Created on October 5, 2015 7:26 AM
 * $Id$
 */

#pragma once

#include <libconfig.h++>
#include <string>
#include "Action.h"

class ActionSystem :
	public Action
{
public:
	ActionSystem(libconfig::Setting event);
	~ActionSystem();
    
    void Do();
    
	string Command;
};

