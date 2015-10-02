/*
 * File:   Daemon.h
 * Author: jason
 *
 * Created on September 30, 2015, 5:24 PM
 * $Id$
 */

#ifndef DAEMON_H
#define	DAEMON_H

#include <string>
#include <pthread.h>
#include "tievoxd.h"
#include "GPIOListener.h"
#include "SPIListener.h"
#include "TimerListener.h"

class Daemon {
public:
    Daemon();
    virtual ~Daemon();

    /* Action, Sound and Event constants */
    const static string ActionTypes[];
    const static string EventTypes[];
    
    const static FromKeyMap SoundTypes;
    
    const static ToKeyMap SoundRepeatCounts; 
    const static ToKeyMap SoundTypeNames;
    
    
    const static FromKeySubMap Events;
    const static ToKeySubMap EventNames;
    
    /* Methods */    
    int Run();
    
    /* Fields */

    /* Static Fields */
    static GPIOListener gpio;
    static SPIListener spi;
    static TimerListener timer;

    static pthread_t gpioThread;
    static pthread_t spiThread;
    static pthread_t timerThread;
    
private:
	void SpawnListeners();
};

#endif	/* DAEMON_H */

