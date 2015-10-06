/*
 * File:   Listener.cpp
 * Author: Jason Burgess <jason@notplugged.in>
 *
 * Created on August 16, 2015, 9:23 PM
 * $Id$
 */

#include <pthread.h>
#include "Listener.h"

Listener::Listener() {
}

Listener::~Listener() {
}

void Listener::Run() {
    pthread_exit(NULL);
}

void Listener::Setup() {
}

/**
  * Make sure we have events before wasting cycles
  */
void Listener::CheckRun() {
    if (Events.size() == 0) {
        pthread_exit(NULL);
    }
}

void *Listener::SpawnAction(void *context) {
    ((Listener *)context)->Run();
}
