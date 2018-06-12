/*
 * reset.c
 *
 *  Created on: 12.06.2018
 *      Author: steven
 */

#include <stdbool.h>
#include <string.h>

#include "../at.h"
#include "debug.h"
#include "executors.h"
#include "dev/watchdog.h"

bool reset_exec(char ** parameters) {
	putline(AT_OK);
	watchdog_reboot();
	return true; //Never reached anyway
}
