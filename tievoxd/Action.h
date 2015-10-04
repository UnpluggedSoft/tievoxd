/* 
 * File:   Action.h
 * Author: Jason Burgess <jason@notplugged.in>
 *
 * Created on September 26, 2015, 11:06 PM
 * $Id$
 */

#ifndef ACTION_H
#define	ACTION_H

#include <libconfig.h++>
#include <string>

using namespace std;

class Action {
public:
    Action();
    Action(libconfig::Setting *event);
    virtual ~Action();
    
    string Type;
private:

};

#endif	/* ACTION_H */

