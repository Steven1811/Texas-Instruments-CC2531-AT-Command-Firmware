/*
 * send.c
 *
 *  Created on: 27.06.2018
 *      Author: steven
 */
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>

#include "executors.h"
#include "../at.h"
#include "debug.h"
#include "net/ip/uip-debug.h"
#include "net/ip/uip.h"
#include "net/ipv6/uip-ds6.h"
#include <contiki-net.h>

uip_ds6_addr_t *local_ip_addr;
uip_ip6addr_t addr;

//Retrieves Local Unicast Link address
bool locip_exec (char ** parameters) {
	local_ip_addr = uip_ds6_get_link_local(ADDR_PREFERRED);
	if(local_ip_addr!=NULL) {
		uip_debug_ipaddr_print(&local_ip_addr->ipaddr);
		putchar('\n');
		return true;
	}
	return false;
}
