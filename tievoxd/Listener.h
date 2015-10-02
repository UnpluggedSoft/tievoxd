/*
 * File:   Listener.h
 * Author: Jason Burgess <jason@notplugged.in>
 *
 * Created on August 16, 2015, 9:23 PM
 * $Id$
 */

#ifndef LISTENER_H
#define	LISTENER_H

#include <pthread.h>

class Listener {
public:
    Listener();
    virtual ~Listener();

    virtual void Run();
    static void *SpawnAction(void *context);
private:
};

#endif	/* LISTENER_H */

