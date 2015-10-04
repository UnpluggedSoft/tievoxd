/**
 * File:   tievoxd.cpp
 * Author: Jason Burgess <jason@notplugged.in>
 *
 * Created on August 16, 2015, 9:22 PM
 * $Id$
 */

#include <syslog.h>
#include <wiringPi.h>
#include "Daemon.h"

/**
 *
 * @param argc
 * @param argv
 * @return
 */
int main(int argc, char** argv) {
    // Setup logging
    openlog("tievox", LOG_PERROR | LOG_PID | LOG_CONS, LOG_DAEMON);
    
    // Setup wiringPi, using physical pin numbers.
    wiringPiSetupPhys();

    // TODO: Check for foreground flag

    Daemon *daemon = new Daemon();
    return daemon->Run();
    
    // Cleanup after ourselves
    closelog();
}

