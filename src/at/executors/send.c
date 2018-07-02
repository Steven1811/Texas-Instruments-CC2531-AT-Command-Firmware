/*
 * send.c
 *
 *  Created on: 24.06.2018
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

bool udp_connection_active=false;
struct simple_udp_connection udp_connection;
uip_ip6addr_t target_ip;

uint16_t convertHexStrToWord(char* string) {
	uint16_t retval=0;
	uint8_t byte=0;
	while(*string) {
	    byte = *string++;

    	if(byte >= 'a' && byte<= 'f') byte= byte - 'a' + 10;
    	else if(byte >= 'A' && byte<= 'F') byte= byte - 'A' + 10;
    	else if(byte >= '0' && byte<= '9') byte= byte - '0';
    	retval = (retval << 4) | (byte & 0xF);
	}

	return retval;
}

void parseIPv6String(char * string) {
	uint8_t i=1;
	uint16_t octets[8];

	char * token = strtok(string, ":");
	octets[0]=convertHexStrToWord(token); //First token call

	for(i=1;i<8 && token!=NULL;i++) {
		token = strtok(NULL, ":");
		octets[i]=convertHexStrToWord(token);
	}

	uip_ip6addr(&target_ip, octets[0], octets[1], octets[2], octets[3], octets[4], octets[5], octets[6], octets[7]);
}

void udp_callback(struct simple_udp_connection *c,const uip_ipaddr_t *source_addr,uint16_t source_port,const uip_ipaddr_t *dest_addr,uint16_t dest_port,const uint8_t *data, uint16_t datalen) {
	uint16_t i=0;
	printf("Received UDP Data:\n");
	printf("Source IP: ");
	uip_debug_ipaddr_print(source_addr);
	putchar('\n');
	printf("Source Port: %hu\n", source_port);
	printf("Destination IP: ");
	uip_debug_ipaddr_print(dest_addr);
	putchar('\n');
	printf("Destination Port: %hu\n", dest_port);
	printf("Data Length: %hu byte(s)\n", datalen);
	printf("Data Contents: ");
	for(i=0;i<datalen;i++) {
		putchar(data[i]);
	}
	printf("\nEnd of Data\n");
}

bool send_exec (char ** parameters) {
	uint16_t i=0;
	uint16_t localPort=atoi(parameters[1]);
	uint16_t destPort=atoi(parameters[2]);
	parseIPv6String(parameters[0]);

	//Register new connection if first called
	if(!udp_connection_active) {
		if(simple_udp_register(&udp_connection, localPort, NULL , destPort, &udp_callback)) {
			//Register success
			#ifdef AT_DEBUG
				printf("UDP_Register OK!\n");
			#endif
				udp_connection_active=true;
		}
		else{
			//On Register fail
			#ifdef AT_DEBUG
				printf("UDP_Register Fail!\n");
			#endif
			return false;
		}
	}
#ifdef AT_DEBUG
	else{
		printf("UDP_Connection already set up and ready for transfer.\n");
	}
#endif

	//Send data
	simple_udp_sendto(&udp_connection, parameters[3], strlen(parameters[3]) + 1, &target_ip);
	#ifdef AT_DEBUG
		printf("Sent \"%s\" with size %zu to ", parameters[3], strlen(parameters[3]) + 1);
		uip_debug_ipaddr_print(&target_ip);
		printf(" to Port %hu from Port %hu\n", localPort, destPort);
	#endif
	return true;
}
