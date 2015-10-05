/* 
 * File:   ActionPlaySound.cpp
 * Author: Jason Burgess <jason@notplugged.in>
 * 
 * Created on October 3, 2015, 7:06 PM
 * $Id$
 */

#pragma once

#include <libconfig.h++>
#include "Action.h"
#include "Sound.cpp"

class ActionPlaySound :
	public Action
{
public:
    ActionPlaySound(libconfig::Setting *event);
    ~ActionPlaySound();
    
    Sound Sound;
    int Repeat;
    int Side; 
};
