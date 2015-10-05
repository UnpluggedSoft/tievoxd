/* 
 * File:   ActionPlaySound.cpp
 * Author: Jason Burgess <jason@notplugged.in>
 * 
 * Created on October 3, 2015, 7:06 PM
 * $Id$
 */

// TODO: Make this one work.

#include "ActionPlaySound.h"
#include "Daemon.h"
#include "TIEVoxInfo.h"
#include "tievoxd.h"

ActionPlaySound::ActionPlaySound(libconfig::Setting *event)
    : Action(event) {
    string value;

    // TODO: Validate lookups
    // TODO: Validate data
    event->lookupValue("sound", value);
    ActionSound = Daemon::GetSound(value);
      
    if (event->lookupValue("sound_repeat", value)) {
        Repeat = TIEVoxInfo::SoundRepeats.find(value)->second;    
    } else {
        Repeat = SOUND_REPEAT_NONE; 
    }
        
    Side = SOUND_PLAY_BOTH;
    if (event->lookupValue("sound_side", value)) {
        if (value == "LEFT") {
            Side = SOUND_PLAY_LEFT;
        } else if (value == "RIGHT") {
            Side = SOUND_PLAY_RIGHT;
        }
    }        
}

ActionPlaySound::~ActionPlaySound() {
}
