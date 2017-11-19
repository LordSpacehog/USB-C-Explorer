/*
 * usb_pd_driver.h
 *
 * Created: 11/11/2017 23:55:25
 *  Author: jason
 */ 


#ifndef USB_PD_DRIVER_H_
#define USB_PD_DRIVER_H_

#include "usb_pd.h"

#include <stdint.h>

//#define CONFIG_USB_PD_CHROMEOS
//#define CONFIG_USB_PD_ALT_MODE

/* Default pull-up value on the USB-C ports when they are used as source. */
#define CONFIG_USB_PD_PULLUP TYPEC_RP_USB

#define PDO_FIXED_FLAGS (PDO_FIXED_DUAL_ROLE | PDO_FIXED_DATA_SWAP |\
PDO_FIXED_COMM_CAP)

typedef union {
	uint64_t val;
	struct {
		uint32_t lo;
		uint32_t hi;
		} le /* little endian words */;
	} timestamp_t;

uint32_t pd_task_set_event(uint32_t event, int wait_for_reply);
void pd_power_supply_reset(int port);

/* board specific type-C power constants */
/*
 * delay to turn on the power supply max is ~16ms.
 * delay to turn off the power supply max is about ~180ms.
 */
#define PD_POWER_SUPPLY_TURN_ON_DELAY  10000  /* us */
#define PD_POWER_SUPPLY_TURN_OFF_DELAY 20000 /* us */

// Get the current timestamp from the system timer.
timestamp_t get_time(void);

#endif /* USB_PD_DRIVER_H_ */