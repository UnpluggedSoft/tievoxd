/* 
 * File:   TIEVoxInfo.h
 * Author: Jason Burgess <jason@notplugged.in>
 *
 * Created on October 3, 2015, 2:35 PM
 * $Id$
 */

#pragma once

#include <string>
#include "tievoxd.h"

using namespace std;

/* Conversion variable types */
typedef map<string, int> FromKeyMap;
typedef map<int, string> ToKeyMap;
typedef map<string, FromKeyMap> FromKeySubMap;
typedef map<string, ToKeyMap> ToKeySubMap;

class TIEVoxInfo
{
public:
    /* Action, Sound and Event constants */
    const static string ActionTypes[];
    const static string EventTypes[];
    
    const static FromKeyMap SoundTypes;
    const static FromKeyMap SoundRepeats;
    
    const static ToKeyMap SoundRepeatCounts; 
    const static ToKeyMap SoundTypeNames;
    
    const static FromKeySubMap Events;
    const static ToKeySubMap EventNames;
};
