/*
 * txpwr.c
 *
 *  Created on: 12.06.2018
 *      Author: steven
 */

/**
 * Allowed TX_Power states
static const output_config_t output_power[] = {
  {  5, 0xF5 }, // 4.5
  {  3, 0xE5 }, // 2.5
  {  1, 0xD5 },
  {  0, 0xC5 }, // -0.5
  { -1, 0xB5 }, // -1.5
  { -3, 0xA5 },
  { -4, 0x95 },
  { -6, 0x85 },
  { -8, 0x75 },
  {-10, 0x65 },
  {-12, 0x55 },
  {-14, 0x45 },
  {-16, 0x35 },
  {-18, 0x25 },
  {-20, 0x15 },
  {-22, 0x05 },
  {-28, 0x05 }, // TXCTRL must be set to 0x09
};
**/

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "../at.h"
#include "debug.h"
#include "executors.h"

#include "net/netstack.h"

bool txpwr_exec(char ** parameters) {
	radio_value_t txpower;
	if (parameters[0] != NULL) {
		txpower = atoi(parameters[0]);
		if (NETSTACK_RADIO.set_value(RADIO_PARAM_TXPOWER, txpower)
				== RADIO_RESULT_OK) {
			printf("Set TXPOWER to: %d\n", txpower);
			return true;
		}
	}
	else{
		if(NETSTACK_RADIO.get_value(RADIO_PARAM_TXPOWER, &txpower)==RADIO_RESULT_OK) {
			printf("%d\n", txpower);
			return true;
		}
	}
	return false;
}
