/**
 * \file
 *         An AT-style serial terminal to connect to 6LoWPAN networks
 *         See at/at.h for commands
 * \author
 *         Tobias Kolb
 *         Steven Bradley
 */
//Process for doing something. In this case blinking LEDs and outputting non-at-commands.
//The main AT_Process is happening via at/at_process.c

#include <stdio.h>

#include "contiki.h"
#include "dev/leds.h"
#include "debug.h"
#include "at/at.h"

static struct etimer et;
extern process_event_t serial_non_at_event_message;

PROCESS(cc2531_6lowpan_at_terminal_process, "cc2531 AT Terminal");
AUTOSTART_PROCESSES(&cc2531_6lowpan_at_terminal_process, &at_process); // @suppress("Unused variable declaration in file scope")

PROCESS_THREAD(cc2531_6lowpan_at_terminal_process, ev, data) {
	PROCESS_BEGIN();

	while (1) {
		PROCESS_WAIT_EVENT();
		if (ev == serial_non_at_event_message) {
			printf("Received non AT-Command: %s\n", data);
		}
	}
	PROCESS_END();
}
