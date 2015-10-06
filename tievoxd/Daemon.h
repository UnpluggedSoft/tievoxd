/*
 * File:   Daemon.h
 * Author: jason
 *
 * Created on September 30, 2015, 5:24 PM
 * $Id$
 */

#pragma once

#include <libconfig.h++>
#include <map>
#include <string>
#include <pthread.h>
#include "tievoxd.h"
#include "Event.h"
#include "GPIOListener.h"
#include "RPinInfo.h"
#include "Sound.h"
#include "SPIListener.h"
#include "TimerListener.h"

// Map Types
typedef map<string, Event> EventSubMap;
typedef map<string, EventSubMap> EventMap;
typedef map<string, Sound> SoundMap;

class Daemon {
public:
    Daemon();
    virtual ~Daemon();

    /* Methods */    
    int Run();
    
    static Event GetEvent(string type, string name);
    static Sound GetSound(string name);    
    
	/* Fields */
    static EventMap EventList;
    static SoundMap SoundList;

    /* Static Fields */
    static GPIOListener gpio;
    static SPIListener spi;
    static TimerListener timer;

    static pthread_t gpioThread;
    static pthread_t spiThread;
    static pthread_t timerThread;

    /* Configuration */
	static libconfig::Config Config;
	static string Version;
    
	static RPin RPinInfo[41];
private:
    static void SpawnListeners();
    static void LoadConfig();
    static void BuildEvents();
    static void BuildSounds();
    static void ValidateVersion();
    static void BuildEvent(libconfig::Setting *eventConfig);
    static void BuildSound(libconfig::Setting *soundConfig);
};