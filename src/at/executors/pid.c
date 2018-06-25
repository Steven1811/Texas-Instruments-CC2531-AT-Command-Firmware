/*
 * pid.c
 *
 *  Created on: 24.06.2018
 *      Author: steven
 */
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include "executors.h"
#include "../at.h"
#include "debug.h"
#include "net/netstack.h"
#include "dev/radio.h"

bool pid_exec (char ** parameters) {
	radio_value_t pan_id;
	if(parameters[0] != NULL) {
		pan_id = atoi(parameters[0]);
		if(NETSTACK_RADIO.set_value(RADIO_PARAM_PAN_ID, pan_id) == RADIO_RESULT_OK) {
			printf("Set PAN_ID to: 0x%X\n", pan_id);
			return true;
		}
	}
	else{
		if(NETSTACK_RADIO.get_value(RADIO_PARAM_PAN_ID, &pan_id)==RADIO_RESULT_OK) {
			printf("0x%X\n", pan_id);
			return true;
		}
	}
	return false;
}
