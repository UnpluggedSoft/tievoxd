/* 
 * File:   Action.h
 * Author: Jason Burgess <jason@notplugged.in>
 *
 * Created on September 26, 2015, 11:06 PM
 * $Id$
 */

#pragma once

#include <libconfig.h++>
#include <string>

using namespace std;

class Action {
public:
    Action();
    Action(libconfig::Setting *event);
    virtual ~Action();
    
    virtual void Do();
    
    string Type;
private:

};
