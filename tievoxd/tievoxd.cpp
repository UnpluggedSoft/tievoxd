/**
 * File:   tievoxd.cpp
 * Author: Jason Burgess <jason@notplugged.in>
 *
 * Created on August 16, 2015, 9:22 PM
 * $Id$
 */

#include "Daemon.h"

/**
 *
 * @param argc
 * @param argv
 * @return
 */
int main(int argc, char** argv) {

    // TODO: Check for foreground flag

    Daemon *daemon = new Daemon();
    return daemon->Run();
}

