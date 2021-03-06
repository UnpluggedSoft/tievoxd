/*
 * File:   Daemon.cpp
 * Author: Jason Burgess <jason@notplugged.in>
 *
 * Created on September 30, 2015, 5:24 PM
 * $Id$
 */

#include <libconfig.h++>
#include <string>
#include <pthread.h>
#include <signal.h>
#include <stdlib.h>
#include <syslog.h>
#include "Daemon.h"
#include "tievoxd.h"
#include "RPinInfo.h"

using namespace std;

EventMap Daemon::EventList;
SoundMap Daemon::SoundList;

/* Static Fields */
GPIOListener Daemon::gpio;
SPIListener Daemon::spi;
TimerListener Daemon::timer;

pthread_t Daemon::gpioThread;
pthread_t Daemon::spiThread;
pthread_t Daemon::timerThread;

    /* Configuration */
libconfig::Config Daemon::Config;
string Daemon::Version = "0.0.0";
    

Daemon::Daemon() {
    // Read configuration file
    LoadConfig();

    // Spawn listeners
    SpawnListeners();
}

Daemon::~Daemon() {
    // Kill listeners
    if (gpioThread > 0) {
        pthread_kill(gpioThread, SIGSTOP);
    }
    if (spiThread > 0) {
        pthread_kill(spiThread, SIGSTOP);
    }
    if (timerThread > 0) {
        pthread_kill(timerThread, SIGSTOP);
    }   
    // TODO: Cleanup memory
}

int Daemon::Run() {

    return 0;
}

void Daemon::SpawnListeners() {
    int result;
    
    // TODO: Check results for problems.
    result = pthread_create(&gpioThread, NULL, &GPIOListener::SpawnAction, &gpio);
    
    result = pthread_create(&spiThread, NULL, &SPIListener::SpawnAction, &spi);
    
    result = pthread_create(&timerThread, NULL, &TimerListener::SpawnAction, &timer);
}

void Daemon::LoadConfig() {
    try {
        Config.setIncludeDir("/etc");
        Config.readFile("/etc/tievox.conf");
    } catch (libconfig::FileIOException e) {
        syslog(LOG_CRIT, "Failed to open tievox.conf. Exiting...");
        exit(EXIT_FAILURE);
    }
    
    if (!Config.lookupValue("version", Version)) {
        // Failed to load version number in config
        Version = "0.0.0";
    }
    
    // Ensure configuration version is compatible
    ValidateVersion();
    
    // Setup Pins
    RPinInfo::SetupPins();
    
    // Create sounds (Must happen before BuildEvents
    BuildSounds();

                // Create events
    BuildEvents();    
}

void Daemon::BuildEvents() {
    libconfig::Setting *eventConfig;
    eventConfig = &Config.lookup("events");
    
    if (eventConfig->isArray()) {
        int count = eventConfig->getLength();
        
        for (int i = 0; i < count; ++i) {
            BuildEvent(&eventConfig[i]);
        }
    } else if (eventConfig->isGroup()) {
        BuildEvent(eventConfig);
    }
}

void Daemon::BuildSounds() {
    libconfig::Setting *soundConfig;
    soundConfig = &Config.lookup("sounds");
    
    if (soundConfig->isArray()) {
        int count = soundConfig->getLength();
        
        for (int i = 0; i < count; ++i) {
            BuildSound(&soundConfig[i]);
        }
    } else if (soundConfig->isGroup()) {
        BuildSound(soundConfig);
    }
}

void Daemon::ValidateVersion() {
    // Parse config version
    int major = 0;
    int minor = 0;
    string::size_type i, j;
    string majorStr, minorStr;
    
    i = Version.find('.');
    majorStr = Version.substr(0, i);
    major = atoi(majorStr.c_str());
    
    j = Version.find('.', i + 1);
    minorStr = Version.substr(i + 1, j - i);
    minor = atoi(minorStr.c_str());
    
    // TODO: Compare against config version and daemon version
    
    syslog(LOG_INFO, "Configuration version info: %d, %d.", major, minor);
}

void Daemon::BuildEvent(libconfig::Setting *eventConfig) {
    Event event = Event(eventConfig);
    EventList[event.Type][event.Name] = event;
}

void Daemon::BuildSound(libconfig::Setting *soundConfig) {
    Sound sound = Sound(soundConfig);
    SoundList[sound.Name] = sound;
}

Event Daemon::GetEvent(string type, string name) {
    EventMap::const_iterator git = EventList.find(type);
    if (git == Daemon::EventList.end()) {
        return NULL;
    }
    
    EventSubMap::const_iterator eit = (*git).second.find(name);
    if (eit == (*git).second.end()) {
        return NULL;
    }
    
    return (*eit).second;
}


Sound Daemon::GetSound(string name) {
    SoundMap::const_iterator sit = SoundList.find(name);
    if (sit == SoundList.end()) {
        return NULL;
    }
    
    return (*sit).second;
}
