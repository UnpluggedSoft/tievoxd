/*
 * File:   TimerListener.cpp
 * Author: Jason Burgess <jason@notplugged.in>
 *
 * Created on September 26, 2015, 11:12 PM
 * $Id$
 */

#include <pthread.h>
#include <signal.h>
#include <string>
#include "TimerListener.h"
#include "Daemon.h"
#include "TIEVoxInfo.h"
#include "tievoxd.h"

using namespace std;

TimerListener::TimerListener()
    : Listener() {
}

TimerListener::~TimerListener() {
    // Kill timer threads
    TimerThreadList::iterator it;
    for (it = Threads.begin(); it != Threads.end(); ++it) {
        pthread_kill(it->second, SIGQUIT);
    }
}

void TimerListener::Run() {
    Setup();
    CheckRun();
    
    // Create timer threads
    
    // Wait for kill signal to controls timer threads later
}

void TimerListener::Setup() {
    // Get Events
    EventSubMap eventsTimer = Daemon::EventList.find("TIMER")->second;
    EventSubMap::iterator it;
    
    FromKeyMap events = TIEVoxInfo::Events.find("TIMER")->second;    
    int code;
    
    for (it = eventsTimer.begin(); it != eventsTimer.end(); ++it) {
        code = events.find(it->second.EventName)->second;
        
        // Add event to list by code
        Events[code] = it->second;
    }
}