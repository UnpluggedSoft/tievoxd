/* 
 * File:   tievoxd.h
 * Author: Jason Burgess <jason@notplugged.in>
 *
 * Created on August 16, 2015, 9:22 PM
 * $Id$
 */

#pragma once

#include <map>
#include <string>

using namespace std;

/* Version Information */
#define VERSION                         "0.1.0"
#define VERSION_MAJOR                   0
#define VERSION_MINOR                   1
#define VERSION_REVISION                0

/* Last version of config file to break backwards compatibility */ 
#define CONFIG_VERSION                  "0.0.0"
#define CONFIG_VERSION_MAJOR            0
#define CONFIG_VERSION_MINOR            0
#define CONFIG_VERSION_REVISION         0

/* Action Constants */
#define ACTION_TYPE_PLAY_SOUND          "PLAY_SOUND"
#define ACTION_TYPE_LED                 "LED"
#define ACTION_TYPE_SYSTEM              "SYSTEM"

/* Event Constants */
#define EVENT_TYPE_SPI                  "SPI"
#define EVENT_TYPE_GPIO                 "GPIO"
#define EVENT_TYPE_TIMER                "TIMER"

#define EVENT_SPI_DRIVER_AT_DOOR        0x01
#define EVENT_SPI_DRIVER_DETECTED       0x02
#define EVENT_SPI_PASSENGER_DETECTED    0x04

#define EVENT_SPI_DRIVER_AT_DOOR_NAME       "DRIVER_AT_DOOR"
#define EVENT_SPI_DRIVER_DETECTED_NAME      "DRIVER_DETECTED"
#define EVENT_SPI_PASSENGER_DETECTED_NAME   "PASSENGER_DETECTED"

/* GPIO Events use physical pin numbers */
#define EVENT_GPIO_PEDAL_PRESSED        29
#define EVENT_GPIO_LEFT_TRIGGER         15
#define EVENT_GPIO_RIGHT_TRIGGER        16
#define EVENT_GPIO_ACCESSORY_ON         37
#define EVENT_GPIO_POWER_SWITCH         4

#define EVENT_GPIO_PEDAL_PRESSED_NAME   "PEDAL_PRESSED"
#define EVENT_GPIO_LEFT_TRIGGER_NAME    "LEFT_TRIGGER"
#define EVENT_GPIO_RIGHT_TRIGGER_NAME   "RIGHT_TRIGGER"
#define EVENT_GPIO_ACCESSORY_ON_NAME    "ACCESSORY_ON"
#define EVENT_GPIO_POWER_SWITCH_NAME    "POWER"

// Values in seconds
#define EVENT_TIMER_MINUTELY            60
#define EVENT_TIMER_HOURLY              3600
#define EVENT_TIMER_DAILY               86400
#define EVENT_TIMER_WEEKLY              604800

#define EVENT_TIMER_MINUTELY_NAME       "MINUTE"
#define EVENT_TIMER_HOURLY_NAME         "HOUR"
#define EVENT_TIMER_DAILY_NAME          "DAY"
#define EVENT_TIMER_WEEKLY_NAME         "WEEK"

/* Sound Constants */
#define SOUND_TYPE_FOREGROUND           0x01
#define SOUND_TYPE_BACKGROUND           0x02
#define SOUND_TYPE_ALL                  0x03

#define SOUND_TYPE_FOREGROUND_NAME      "FOREGROUND"
#define SOUND_TYPE_BACKGROUND_NAME      "BACKGROUND"
#define SOUND_TYPE_ALL_NAME             "ALL"

#define SOUND_REPEAT_NONE               0x00
#define SOUND_REPEAT_ONCE               0x01
#define SOUND_REPEAT_FOREVER            0xFF

#define SOUND_REPEAT_NONE_NAME          "NO_REPEAT"
#define SOUND_REPEAT_ONCE_NAME          "REPEAT_ONCE"
#define SOUND_REPEAT_FOREVER_NAME       "REPEAT_FOREVER"

#define SOUND_PLAY_LEFT                 0x01
#define SOUND_PLAY_RIGHT                0x02
#define SOUND_PLAY_BOTH                 0x03
