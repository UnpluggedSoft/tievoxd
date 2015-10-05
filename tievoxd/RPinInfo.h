/* 
 * File:   RpinInfo.h
 * Author: Jason Burgess <jason@notplugged.in>
 *
 * Created on October 4, 2015 10:21 PM
 * $Id$
 */

#pragma once

#include "RPin.h"

class RPinInfo
{
public:
    static RPin Pins[];
    static void SetupPins();
};