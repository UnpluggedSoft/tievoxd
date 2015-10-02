/* 
 * File:   Sound.cpp
 * Author: Jason Burgess <jason@notplugged.in>
 * 
 * Created on August 16, 2015, 9:22 PM
 */

#include "Sound.h"

Sound::Sound() {
}

Sound::Sound(char* fileName, bool repeat) {
    this->fileName = fileName;
    this->isRepeating = repeat;
}

Sound::~Sound() {
}

bool Sound::Play() {
    return this->Play(false);
}

bool Sound::Play(bool repeat) {
    this->isRepeating = repeat;
}

bool Sound::Stop() {
    return this->Stop(true);
}

bool Sound::Stop(bool immediate) {
    
}