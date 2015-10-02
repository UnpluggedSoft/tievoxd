/*
 * File:   Sound.h
 * Author: jason
 *
 * Created on August 16, 2015, 9:22 PM
 */

#ifndef SOUND_H
#define	SOUND_H

#include <string>

using namespace std;

class Sound {
public:
    bool isRepeating;
    string fileName;

    Sound();
    Sound(char* fileName, bool repeat);
    virtual ~Sound();

    bool Play();
    bool Play(bool repeat);
    bool Stop();
    bool Stop(bool immediate);
private:
};

#endif	/* SOUND_H */

