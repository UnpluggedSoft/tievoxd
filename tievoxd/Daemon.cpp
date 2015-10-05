/*
 * File:   Daemon.cpp
 * Author: Jason Burgess <jason@notplugged.in>
 *
 * Created on September 30, 2015, 5:24 PM
 * $Id$
 */

#include <libconfig.h++>
#include <pthread.h>
#include <signal.h>
#include <string>
#include <syslog.h>
#include "Daemon.h"
#include "tievoxd.h"
#include "RPinInfo.h"

using namespace std;

Daemon::Daemon() {
    // Read configuration file
    LoadConfig();

    // Spawn listeners
    SpawnListeners();


}

Daemon::~Daemon() {
    // Kill listeners
    pthread_kill(gpioThread, SIGHUP);
    pthread_kill(spiThread, SIGHUP);
    pthread_kill(timerThread, SIGHUP);
    
    // Cleanup memory
    delete[] EventList;
    delete[] SoundList;
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
    SetupPinDefaults();
    
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
        EventList = new Event[count]();
    
        for (int i = 0; i < count; ++i) {
            BuildEvent(&eventConfig[i]);
        }
    } else if (eventConfig->isGroup()) {
        EventList = new Event[1];
        BuildEvent(eventConfig);
    }
}

void Daemon::BuildSounds() {
    libconfig::Setting *soundConfig;
    soundConfig = &Config.lookup("sounds");
    
    if (soundConfig->isArray()) {
        int count = soundConfig->getLength();
        SoundList = new Sound[count]();
    
        for (int i = 0; i < count; ++i) {
            BuildSound(&soundConfig[i]);
        }
    } else if (soundConfig->isGroup()) {
        SoundList = new Sound[1];
        BuildSound(soundConfig);
    }
}

void Daemon::ValidateVersion() {
    // Parse config version
    int major = 0;
    int minor = 0;
    string::size_type i, j;
    
    i = Version.find('.');
    major = stoi(Version.substr(0, i));
    j = Version.find('.', i + 1);
    minor = stoi(Version.substr(i + 1, j - i));
    
    // TODO: Compare against config version and daemon version
    
    
    syslog(LOG_INFO, "Configuration version info: %n, %n.", major, minor);
}


void Daemon::BuildEvent(libconfig::Setting *eventConfig) {
    EventList[eventCount++] = Event(eventConfig);
}

void Daemon::BuildSound(libconfig::Setting *soundConfig) {
    SoundList[soundCount++] = Sound(soundConfig);
}
