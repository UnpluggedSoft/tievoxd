/*
 * File:   Daemon.h
 * Author: jason
 *
 * Created on September 30, 2015, 5:24 PM
 */

#ifndef DAEMON_H
#define	DAEMON_H

#include "GPIOListener.h"
#include "TimerListener.h"
#include "SPIListener.h"
#include <pthread.h>

class Daemon {
public:
    Daemon();
    virtual ~Daemon();

    int Run();

    static GPIOListener gpio;
    static SPIListener spi;
    static TimerListener timer;

    static pthread_t gpioThread;
    static pthread_t spiThread;
    static pthread_t timerThread;
private:
	pthread_t SpawnListener(Listener *listener);
    static void *SpawnAction(void *arg);
};

#endif	/* DAEMON_H */

