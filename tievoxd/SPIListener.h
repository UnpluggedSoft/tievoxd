/*
 * File:   SPIListener.h
 * Author: Jason Burgess <jason@notplugged.in>
 *
 * Created on September 26, 2015, 11:10 PM
 * $Id$
 */

#pragma once

#include "Listener.h"

// Should only need a small buffer for now.
#define SPI_BUFFER_LENGTH       32

class SPIListener : public Listener {
public:
    SPIListener();
    virtual ~SPIListener();
  
    IntEvent Events;
    
    void Run();
    void Setup();
    
    bool CheckSignal(int bus);
    void ResetBuffer();
private:
    unsigned char buffer[SPI_BUFFER_LENGTH];
};
