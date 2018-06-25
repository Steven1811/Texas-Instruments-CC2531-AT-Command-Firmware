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

#include "executors.h"
#include "../at.h"
#include "debug.h"

#include <contiki-net.h>

#define INPUT_DATABUF_LEN 256
#define OUTPUT_DATABUF_LEN 256

struct tcp_socket tcp_sock;

uint8_t* input_databuffer;
uint8_t* output_databuffer;
uip_ip6addr_t test_ip;

int data_callback(struct tcp_socket *s, void *ptr,const uint8_t *input_data_ptr, int input_data_len) {
	printf("Data Callback!\n");
	//Print Received Data
	return 0;
}

void event_callback(struct tcp_socket *s, void *ptr, tcp_socket_event_t event) {
	printf("Event Callback!\n");
	//Print Event
}

bool send_exec (char ** parameters) {
	//MALLOC! Needs freeing
	input_databuffer = (uint8_t*) malloc(INPUT_DATABUF_LEN * (sizeof(uint8_t)));
	output_databuffer = (uint8_t*) malloc(OUTPUT_DATABUF_LEN * (sizeof(uint8_t)));


	uip_ip6addr(&test_ip, 0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF);

	if(tcp_socket_register(&tcp_sock, NULL, input_databuffer, INPUT_DATABUF_LEN, output_databuffer, OUTPUT_DATABUF_LEN, &data_callback, &event_callback)==1) {
		printf("Socket Register ok\n");
		if(tcp_socket_connect(&tcp_sock, &test_ip, 80)==1) {
			printf("Socket Connect ok\n");
			if(tcp_socket_send(&tcp_sock, "Hello World!", 13)!=-1) {
				printf("Socket Send ok\n");
				return true;
			}
			else{
				printf("Socket Send failure\n");
			}
		}
		else {
			printf("Socket Connect failure\n");
		}
	}
	else{
		printf("Socket couldn't get registered!\n");
		return false;
	}
	printf("Unregistering Socket\n");
	tcp_socket_unregister(&tcp_sock);
	return false;
}
