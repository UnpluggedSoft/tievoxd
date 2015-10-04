/* 
 * File:   Sound.cpp
 * Author: Jason Burgess <jason@notplugged.in>
 * 
 * Created on August 16, 2015, 9:22 PM
 * $Id$
 */

#include <libconfig.h++>
#include <string>
#include "Sound.h"
#include "tievoxd.h"
#include "TIEVoxInfo.h"

Sound::Sound() {
}

Sound::Sound(libconfig::Setting *sound)
{
    string value;

    // TODO: Validate lookups
    sound->lookupValue("title", Name);
    sound->lookupValue("file", FileName);

    sound->lookupValue("type", value);
    SoundType = TIEVoxInfo::SoundTypes[value];
    
    sound->lookupValue("repeat", value);
    RepeatType = TIEVoxInfo::SoundRepeatCounts[value];
    
    // TODO: Validate file exists
}

Sound::~Sound() {
}

bool Sound::Play() {
    return this->Play(SOUND_PLAY_BOTH);
}

bool Sound::Play(int side) {
    
}

bool Sound::Stop() {
    return this->Stop(true);
}

bool Sound::Stop(bool immediate) {
    
}