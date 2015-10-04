/*
 * File:   Sound.h
 * Author: Jason Burgess <jason@notplugged.in>
 *
 * Created on August 16, 2015, 9:22 PM
 * $Id$
 */

#pragma once

#include <libconfig.h++>
#include <string>

using namespace std;

class Sound {
public:
    Sound();
    Sound(libconfig::Setting *sound);
    virtual ~Sound();

    string Name;
    string FileName;
    int SoundType;
    int RepeatType;
    
    bool Play();
    bool Play(int side);
    bool Stop();
    bool Stop(bool immediate);
private:
};
