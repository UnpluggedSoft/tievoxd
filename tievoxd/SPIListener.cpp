/* 
 * File:   SPIListener.cpp
 * Author: Jason Burgess <jason@notplugged.in>
 * 
 * Created on September 26, 2015, 11:10 PM
 * $Id$
 */

#include <string>
#include <syslog.h>
#include <unistd.h>
#include <wiringPiSPI.h>
#include "SPIListener.h"
#include "Daemon.h"
#include "tievoxd.h"
#include "TIEVoxInfo.h"

SPIListener::SPIListener() {
}

SPIListener::~SPIListener() {
}

void SPIListener::Run()
{
    Setup();
	CheckRun();
 
    // Run until terminated
    while (1) {
        // Let the thread sleep for 1/10th of a second.
        usleep(LISTENER_SLEEP_DELAY);
        
        // Check each bus for a signal
        ResetBuffer();
        CheckSignal(SPI_BUS_CAR);

        ResetBuffer();
        CheckSignal(SPI_BUS_RF);
    }
}

void SPIListener::Setup()
{
    // Get Events
    EventSubMap eventsSPI = Daemon::EventList.find("SPI")->second;
    EventSubMap::iterator it;
    
    FromKeyMap events = TIEVoxInfo::Events.find("SPI")->second;
    int code;
    
    for (it = eventsSPI.begin(); it != eventsSPI.end(); ++it) {
        code = events.find(it->second.EventName)->second;
        
        // Add event to list by code
        Events[code] = it->second;
        
        // Setup car bus (16MHz)
        wiringPiSPISetup(SPI_BUS_CAR, 16000000);
        // Setup nRF24 bus (16MHz)
        wiringPiSPISetup(SPI_BUS_RF, 16000000);
    }
}

bool SPIListener::CheckSignal(int bus)
{
    // Trigger R/W
    wiringPiSPIDataRW(bus, buffer, SPI_BUFFER_LENGTH);
        
    // Check data in buffer
    bool received = false;
    for (int i = 0; i < SPI_BUFFER_LENGTH; ++i)
    {
        if (buffer[i] > 0)
        {
            received = true;
            IntEvent::const_iterator it = Events.find(buffer[i]);
            // Make sure it's valid
            if (it != Events.end())
            {
                // Trigger Event
                it->second.EventAction->Do();
            } else
            {
                syslog(LOG_NOTICE, "[SPI] Received unknown signal on bus %d: %d", bus, buffer[i]);
            }
        }
    }
    
    return received;
}

void SPIListener::ResetBuffer()
{
    for (int i = 0; i < SPI_BUFFER_LENGTH; ++i)
    {
        buffer[i] = 0;
    }
}