/*
 * File:   Listener.h
 * Author: Jason Burgess <jason@notplugged.in>
 *
 * Created on August 16, 2015, 9:23 PM
 * $Id$
 */

#pragma once

#include <pthread.h>

class Listener {
public:
    Listener();
    virtual ~Listener();

    virtual void Run();
    static void *SpawnAction(void *context);
private:
};
