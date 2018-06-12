/**
 * \file
 *         An AT-style serial terminal to connect to 6LoWPAN networks
 *         See at/at.h for commands
 * \author
 *         Tobias Kolb
 *         Steven Bradley
 */

#include <stdint.h>
#include <string.h>
#include <stdlib.h>

#include "contiki.h"
#include "dev/leds.h"
#include "debug.h"

#include "at/at.h"

/*---------------------------------------------------------------------------*/
static struct etimer et;
/*---------------------------------------------------------------------------*/
PROCESS(cc2531_6lowpan_at_terminal_process, "cc2531 AT Terminal");
AUTOSTART_PROCESSES(&cc2531_6lowpan_at_terminal_process); // @suppress("Unused variable declaration in file scope")
extern process_event_t serial_line_event_message;
/*---------------------------------------------------------------------------*/
PROCESS_THREAD(cc2531_6lowpan_at_terminal_process, ev, data) {
	PROCESS_BEGIN();
	etimer_set(&et, CLOCK_SECOND/2);
	while (1) {
		PROCESS_WAIT_EVENT();

		if (ev == PROCESS_EVENT_TIMER) {
			leds_blink();
			etimer_reset(&et);
		} else if (ev == serial_line_event_message) {
			parse_at((char *) data);
		}
	}
	PROCESS_END();
}
