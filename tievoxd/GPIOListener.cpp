/* 
 * File:   GPIOListener.cpp
 * Author: Jason Burgess <jason@notplugged.in>
 * 
 * Created on August 16, 2015, 9:25 PM
 * $Id$
 */

#include <string>
#include <unistd.h>
#include <wiringPi.h>
#include "GPIOListener.h"
#include "Daemon.h"
#include "TIEVoxInfo.h"

GPIOListener::GPIOListener() {
}

GPIOListener::~GPIOListener() {
}

/**
 * Run the listener as a loop in the background
 */
void GPIOListener::Run()
{
    Setup();
    
    int state;
    PinState::iterator it;
    
    // Run until terminated
    while (1)
    {
        // Let the thread sleep for 1/10th of a second.
        usleep(100);
        
        // Check pin sets
        for (it = Pins.begin(); it != Pins.end(); ++it)
        {
            state = digitalRead(it->first);
           
            // Only trigger if it wasn't triggered last run.
            // TODO: rethink this for rapid fire trigger blasters
            if (state > 0 && it->second == 0)
            {
                // Trigger event
                Events.find(it->first)->second.EventAction->Do();
            }
            
            // Save state
            Pins[it->first] = state;
        }
    }
}

/**
 * Setup pins for GPIO events
 */
void GPIOListener::Setup()
{
    EventSubMap events = Daemon::EventList.find("GPIO")->second;
    FromKeyMap eventPins = TIEVoxInfo::Events.find("GPIO")->second;
    
    EventSubMap::iterator it;
    FromKeyMap::const_iterator pit;
    
    int pin;
    
    for (it = events.begin(); it != events.end(); ++it)
    {
        pin = eventPins.find(it->second.EventName)->second;

        // Setup pin for input.
        pinMode(pin, INPUT);
        
        // Add to pin list with current state
        Pins[pin] = digitalRead(pin);
        
        // Add event to list
        Events[pin] = it->second;
    }
}
