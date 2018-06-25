/*
 * ch.c
 *
 *  Created on: 24.06.2018
 *      Author: steven
 */


#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "executors.h"
#include "../at.h"
#include "debug.h"
#include "net/netstack.h"
#include "dev/radio.h"

bool ch_exec (char ** parameters) {
	radio_value_t channel;
	if(parameters[0] != NULL) {
		channel = atoi(parameters[0]);
		if(NETSTACK_RADIO.set_value(RADIO_PARAM_CHANNEL, channel) == RADIO_RESULT_OK) {
			printf("Set Channel to: %d\n", channel);
			return true;
		}
	}
	else{
		if(NETSTACK_RADIO.get_value(RADIO_PARAM_CHANNEL, &channel)==RADIO_RESULT_OK) {
			printf("%d\n", channel);
			return true;
		}
	}
	return false;
}
