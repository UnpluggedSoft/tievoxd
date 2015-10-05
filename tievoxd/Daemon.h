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

class Daemon {
public:
	Daemon();
	virtual ~Daemon();

    /* Configuration */
	static libconfig::Config Config;
	static string Version;
    
    static RPin RPinInfo[41];
    
	/* Methods */    
	int Run();
    
	/* Fields */
	static Event *EventList;
	static Sound *SoundList;

	    /* Static Fields */
	static GPIOListener gpio;
	static SPIListener spi;
	static TimerListener timer;

	static pthread_t gpioThread;
	static pthread_t spiThread;
	static pthread_t timerThread;
    
private:
	void SpawnListeners();
	void LoadConfig();
	void BuildEvents();
	void BuildSounds();
	static void ValidateVersion();
	void BuildEvent(libconfig::Setting *eventConfig);
	void BuildSound(libconfig::Setting *arg1);
    
	int soundCount = 0;
	int eventCount = 0;
}