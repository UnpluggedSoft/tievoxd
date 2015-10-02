/**
 * File:   tievoxd.cpp
 * Author: Jason Burgess <jason@notplugged.in>
 *
 *
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

    Daemon daemon = new Daemon();
    return daemon.Run();
}

