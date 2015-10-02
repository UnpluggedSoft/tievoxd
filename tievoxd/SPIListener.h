/*
 * File:   SPIListener.h
 * Author: jason
 *
 * Created on September 26, 2015, 11:10 PM
 */

#ifndef SPILISTENER_H
#define	SPILISTENER_H

#include "Listener.h"

class SPIListener : public Listener {
public:
    SPIListener();
    SPIListener(const SPIListener& orig);
    virtual ~SPIListener();
private:

};

#endif	/* SPILISTENER_H */

