/* 
 * File:   RpinInfo.h
 * Author: Jason Burgess <jason@notplugged.in>
 *
 * Created on October 5, 2015 12:16 PM
 * $Id$
 */

#include "RPinInfo.h"
#include "RPin.h"

// Build data array
RPin RPinInfo::Pins[] = {
	RPin(1, PIN_NULL, PIN_NULL, PIN_NULL, PIN_TYPE_POWER, "+3.3VDC"),
	RPin(2, PIN_NULL, PIN_NULL, PIN_NULL, PIN_TYPE_POWER, "+5VDC"),
	RPin(3, 2, 8, PIN_PULL_HIGH, PIN_TYPE_I2C, "I2C1_SDA", "SDA1", ""),  
	RPin(4, PIN_NULL, PIN_NULL, PIN_NULL, PIN_TYPE_POWER, "+5VDC"),
	RPin(5, 3, 9, PIN_PULL_HIGH, PIN_TYPE_I2C, "I2C1_SCL", "SCL1", ""),  
	RPin(6, PIN_NULL, PIN_NULL, PIN_NULL, PIN_TYPE_GROUND, "GND"),
	RPin(7, 4, 7, PIN_PULL_HIGH, PIN_TYPE_GPIO, "GPIO_04"),
	RPin(8, 14, 15, PIN_PULL_LOW, PIN_TYPE_UART, "UART0_TXD", "TXD0", "TXD1"),
	RPin(9, PIN_NULL, PIN_NULL, PIN_NULL, PIN_TYPE_GROUND, "GND"),
	RPin(10, 15, 16, PIN_PULL_LOW, PIN_TYPE_UART, "UART0_RXD", "RXD0", "RXD1"),
	RPin(11, 17, 0, PIN_PULL_LOW, PIN_TYPE_GPIO, "GPIO_17", "", "RTS1"),
	RPin(12, 18, 1, PIN_PULL_LOW, PIN_TYPE_PWM, "GPIO_18", "PCM_CLK", "PWM0"),
	RPin(13, 27, 2, PIN_PULL_LOW, PIN_TYPE_GPIO, "GPIO_27"),
	RPin(14, PIN_NULL, PIN_NULL, PIN_NULL, PIN_TYPE_GROUND, "GND"),
	RPin(15, 22, 3, PIN_PULL_LOW, PIN_TYPE_GPIO, "GPIO_22"),
	RPin(16, 23, 4, PIN_PULL_LOW, PIN_TYPE_GPIO, "GPIO_23"),
	RPin(17, PIN_NULL, PIN_NULL, PIN_NULL, PIN_TYPE_POWER, "+3.3VDC"),
	RPin(18, 24, 5, PIN_PULL_LOW, PIN_TYPE_GPIO, "GPIO_24"),
	RPin(19, 10, 12, PIN_PULL_LOW, PIN_TYPE_SPI, "SPI0_MOSI", "SPI0_MOSI", ""),  
	RPin(20, PIN_NULL, PIN_NULL, PIN_NULL, PIN_TYPE_GROUND, "GND"),
	RPin(21, 9, 13, PIN_PULL_LOW, PIN_TYPE_SPI, "SPI0_MISO", "SPI0_MISO", ""),
	RPin(22, 25, 6, PIN_PULL_LOW, PIN_TYPE_GPIO, "GPIO_25"),
	RPin(23, 11, 14, PIN_PULL_LOW, PIN_TYPE_SPI, "SPI0_SCLK", "SPI0_SCLK", ""),  
	RPin(24, 8, 10, PIN_PULL_LOW, PIN_TYPE_SPI, "SPI0_CE0", "SPI0_CE0_N", ""),
	RPin(25, PIN_NULL, PIN_NULL, PIN_NULL, PIN_TYPE_GROUND, "GND"),
	RPin(26, 7, 11, PIN_PULL_HIGH, PIN_TYPE_SPI, "SPI0_CE1", "SPI0_CE1_N", ""),
	RPin(27, 0, PIN_NULL, PIN_PULL_HIGH, PIN_TYPE_GPIO, "I2C0_SD_EEPROM", "SDA0", ""),  
	RPin(28, 1, PIN_NULL, PIN_PULL_HIGH, PIN_TYPE_GPIO, "I2C0_SC_EEPROM", "SCL0", ""),  
	RPin(29, 5, 21, PIN_PULL_HIGH, PIN_TYPE_GPIO, "GPIO_5", "GPCLK1", "ARM_TDO"),  
	RPin(30, PIN_NULL, PIN_NULL, PIN_NULL, PIN_TYPE_GROUND, "GND"),
	RPin(31, 6, 22, PIN_PULL_HIGH, PIN_TYPE_GPIO, "GPIO_6", "GPCLK2", "ARM_RTCK"),  
	RPin(32, 12, 26, PIN_PULL_LOW, PIN_TYPE_GPIO, "GPIO_12", "PWM0", "ARM_TMS"),  
	RPin(33, 13, 23, PIN_PULL_LOW, PIN_TYPE_GPIO, "GPIO_13", "PWM1", "ARM_TCK"),
	RPin(34, PIN_NULL, PIN_NULL, PIN_NULL, PIN_TYPE_GROUND, "GND"),
	RPin(35, 19, 24, PIN_PULL_LOW, PIN_TYPE_GPIO, "GPIO_19", "PCM_FS", "PWM1"),
	RPin(36, 16, 27, PIN_PULL_LOW, PIN_TYPE_GPIO, "GPIO_16", "", "CTS1"),
	RPin(37, 26, 25, PIN_PULL_LOW, PIN_TYPE_GPIO, "GPIO_26"),
	RPin(38, 20, 28, PIN_PULL_LOW, PIN_TYPE_GPIO, "GPIO_20", "PCM_DIM", "GPCLK0"),
	RPin(39, PIN_NULL, PIN_NULL, PIN_NULL, PIN_TYPE_GROUND, "GND"),
	RPin(40, 21, 29, PIN_PULL_LOW, PIN_TYPE_GPIO, "GPIO_21", "PCM_DOUT", "GPCLK1")
};

void RPinInfo::SetupPins() {
	for (int i = 0; i < 40; ++i) {
		Pins[i].StartupPrepare();
	}    
}
