/* 
 * File:   TIEVoxInfo.h
 * Author: Jason Burgess <jason@notplugged.in>
 *
 * Created on October 3, 2015, 2:35 PM
 * $Id$
 */

#ifndef TIEVOXINFO_H
#define TIEVOXINFO_H

#include <string>
#include "tievoxd.h"

using namespace std;

class TIEVoxInfo
{
public:
    /* Action, Sound and Event constants */
    const static string ActionTypes[];
    const static string EventTypes[];
    
    const static FromKeyMap SoundTypes;
    
    const static ToKeyMap SoundRepeatCounts; 
    const static ToKeyMap SoundTypeNames;
    
    const static FromKeySubMap Events;
    const static ToKeySubMap EventNames;
};

#endif