#include <stdbool.h>
#include <string.h>

#include "executors.h"
#include "../at.h"
#include "debug.h"
#include "net/netstack.h"
#include "dev/radio.h"

bool rssi_exec(char ** parameters) {
	radio_value_t val;
	if(NETSTACK_RADIO.get_value(RADIO_PARAM_POWER_MODE, &val)==RADIO_RESULT_OK) {
		if(val==RADIO_POWER_MODE_ON) {
			if(NETSTACK_RADIO.get_value(RADIO_PARAM_RSSI, &val)==RADIO_RESULT_OK) {
				putdec(val);
				putchar('\n');
				return true;
			}
		}
	}
	return false;
}
