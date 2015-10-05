/* 
 * File:   TIEVoxInfo.h
 * Author: Jason Burgess <jason@notplugged.in>
 *
 * Created on October 3, 2015, 2:35 PM
 * $Id$
 */

#include <string>
#include "tievoxd.h"
#include "TIEVoxInfo.h"

using namespace std;

/* Constant helper variables */
const string TIEVoxInfo::ActionTypes[] = {ACTION_TYPE_PLAY_SOUND, ACTION_TYPE_LED};
const string TIEVoxInfo::EventTypes[] = {EVENT_TYPE_GPIO, EVENT_TYPE_SPI, EVENT_TYPE_TIMER}; 

const FromKeyMap::value_type stx[] = {
    make_pair(SOUND_TYPE_FOREGROUND_NAME, SOUND_TYPE_FOREGROUND),
    make_pair(SOUND_TYPE_BACKGROUND_NAME, SOUND_TYPE_BACKGROUND),
    make_pair(SOUND_TYPE_ALL_NAME, SOUND_TYPE_ALL)
};

const FromKeyMap TIEVoxInfo::SoundTypes(stx, stx + sizeof stx / sizeof stx[0]);

const ToKeyMap::value_type stnx[] = { 
    make_pair(SOUND_TYPE_FOREGROUND, SOUND_TYPE_FOREGROUND_NAME),
    make_pair(SOUND_TYPE_BACKGROUND, SOUND_TYPE_BACKGROUND_NAME),
    make_pair(SOUND_TYPE_ALL, SOUND_TYPE_ALL_NAME)
};

const ToKeyMap TIEVoxInfo::SoundTypeNames(stnx, stnx + sizeof stnx / sizeof stnx[0]);

const FromKeyMap::value_type srcnx[] = { 
    make_pair(SOUND_REPEAT_NONE, SOUND_REPEAT_NONE_NAME),
    make_pair(SOUND_REPEAT_ONCE, SOUND_REPEAT_ONCE_NAME),
    make_pair(SOUND_REPEAT_FOREVER, SOUND_REPEAT_FOREVER_NAME)
};

const FromKeyMap TIEVoxInfo::SoundRepeats(srcnx, srcnx + sizeof srcnx / sizeof srcnx[0]);

const ToKeyMap::value_type srcx[] = { 
    make_pair(SOUND_REPEAT_NONE_NAME, SOUND_REPEAT_NONE),
    make_pair(SOUND_REPEAT_ONCE_NAME, SOUND_REPEAT_ONCE),
    make_pair(SOUND_REPEAT_FOREVER_NAME, SOUND_REPEAT_FOREVER)
};

const ToKeyMap TIEVoxInfo::SoundRepeatCounts(srcx, srcx + sizeof srcx / sizeof srcx[0]);

const FromKeyMap::value_type espix[] = { 
    make_pair(EVENT_SPI_DRIVER_AT_DOOR_NAME, EVENT_SPI_DRIVER_AT_DOOR),
    make_pair(EVENT_SPI_DRIVER_DETECTED_NAME, EVENT_SPI_DRIVER_DETECTED),
    make_pair(EVENT_SPI_PASSENGER_DETECTED_NAME, EVENT_SPI_PASSENGER_DETECTED)
};

const FromKeyMap spiEvents(espix, espix + sizeof espix / sizeof espix[0]);

const FromKeyMap::value_type gpiox[] = { 
    make_pair(EVENT_GPIO_ACCESSORY_ON_NAME, EVENT_GPIO_ACCESSORY_ON),
    make_pair(EVENT_GPIO_LEFT_TRIGGER_NAME, EVENT_GPIO_LEFT_TRIGGER),
    make_pair(EVENT_GPIO_PEDAL_PRESSED_NAME, EVENT_GPIO_PEDAL_PRESSED),
    make_pair(EVENT_GPIO_RIGHT_TRIGGER_NAME, EVENT_GPIO_RIGHT_TRIGGER),
    make_pair(EVENT_GPIO_POWER_SWITCH_NAME, EVENT_GPIO_POWER_SWITCH)
};

const FromKeyMap gpioEvents(gpiox, gpiox + sizeof gpiox / sizeof gpiox[0]);

const FromKeyMap::value_type timerx[] = { 
    make_pair(EVENT_TIMER_MINUTELY_NAME, EVENT_TIMER_MINUTELY),
    make_pair(EVENT_TIMER_HOURLY_NAME, EVENT_TIMER_HOURLY),
    make_pair(EVENT_TIMER_DAILY_NAME, EVENT_TIMER_DAILY),
    make_pair(EVENT_TIMER_WEEKLY_NAME, EVENT_TIMER_WEEKLY)
};

const FromKeyMap timerEvents(timerx, timerx + sizeof timerx / sizeof timerx[0]);

const FromKeySubMap::value_type ex[] = { 
    make_pair(EVENT_TYPE_GPIO, gpioEvents),
    make_pair(EVENT_TYPE_SPI, spiEvents),
    make_pair(EVENT_TYPE_TIMER, timerEvents)
};

const FromKeySubMap TIEVoxInfo::Events(ex, ex + sizeof ex / sizeof ex[0]);
