/*
 * File:   Daemon.cpp
 * Author: jason
 *
 * Created on September 30, 2015, 5:24 PM
 */

#include "Daemon.h"
#include <pthread.h>
#include <signal.h>
#include <string>

using namespace std;

Daemon::Daemon() {
    // Read configuration file

	// Create & Spawn listeners
    Daemon::gpio = new GPIOListener();
    Daemon::timer = new TimerListener();
    Daemon::spi = new SPIListener();
    
    gpioThread = SpawnListener("GPIO");

    	// Create events

}

Daemon::~Daemon() {
    // Kill listeners
    pthread_kill(gpioThread, SIGHUP);
    pthread_kill(spiThread, SIGHUP);
    pthread_kill(timerThread, SIGHUP);
}

int Daemon::Run() {

}

pthread_t Daemon::SpawnListener(Listener *listener) {
    pthread_t thread;
    
    int result = pthread_create(&thread, PTHREAD_CREATE_JOINABLE, Daemon::SpawnAction, (void *)listener);
    
    return thread;
}

void *Daemon::SpawnAction(void *arg) {
    string type = *(string *)arg;
    Listener *listener;
        
    if (type == "GPIO")
    {
        listener = &Daemon::gpio;
    }
    else if (type == "SPI")
    {
        listener = &Daemon::spi;    
    }
    else if (type == "timer")
    {
        listener = &Daemon::timer;
        
    }
    
    listener->Run();
    
    pthread_exit(NULL);
}