/*
 * at.c
 *
 *  Created on: 10.06.2018
 *      Author: steven
 */

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

#include "contiki.h"
#include "debug.h"
#include "executors/executors.h"
#include "at.h"

uint8_t op_mode= 0;
char* AT_DELIMITER = "+ ";
char* AT_OK = "OK\n";
char* AT_FAIL = "FAI\nL";
char* AT = "AT";

PROCESS(at_process, "at_process");
extern process_event_t serial_line_event_message;
process_event_t serial_non_at_event_message;

//AT Command registry
at_command commands[]= {
		#ifdef AT_DEBUG
		{
			"TEST",
			"Paramter test",
			&test_exec
		},
		#endif
		{
			"RST",
			"Resets the device",
			&reset_exec
		},
		{
			"RSSI",
			"Returns the current Radio signal strength indicator (RSSI)",
			&rssi_exec

		},
		{
			"TXPWR",
			"[POWER(-28 TO 5)]Returns or sets the TXPower",
			&txpwr_exec
		},
		{
			"PID",
			"[PID(0-65535)] Returns or sets the PAN_ID",
			&pid_exec
		},
		{
			"CH",
			"[CHANNEL(11-26)] Returns or sets the Channel",
			&ch_exec
		},
		{
			"SEND",
			"Sends UDP packet data to an IPv6 address",
			&send_exec
		},
		{
			"LOCIP",
			"Shows you the current local unicast IP",
			&locip_exec
		},
		{
			"LISTEN",
			"Listens to inbound connections",
			&listen_exec
		},
		{
			"LED",
			"Toggles the LED",
			&led_exec
		},
		{
			"HELP",
			"Prints out this help",
			&help_exec
		},
		{
				NULL
		}
};

at_command* fetch_command(char *string) {
	uint8_t i;
	for(i=0;i<(sizeof(commands)/sizeof(at_command));i++) {
		if(strcmp(string,commands[i].cmd_name)==0) {
			return &commands[i];
		}
	}
	return NULL;
}

at_command* get_commands() {
	return commands;
}

bool is_at(char* string) {
	if (strncmp(string, AT, strlen(AT)) == 0) {
		return true;
	}
	return false;
}

void fetch_parameters(char *token, char** parameters) {
	uint8_t param_count=0;

	while (token!=NULL && param_count < MAX_PARAM_COUNT) {
		parameters[param_count]=(char *)malloc(strlen(token) +1);
		parameters[param_count]=token;
		token=strtok(NULL, AT_DELIMITER);
		param_count++;
	}
	parameters[param_count]=NULL;
}

bool parse_at(char* string) {
	char *command_name=NULL;
	char *parameters[MAX_PARAM_COUNT];
	uint8_t i=0;
	at_command* at_command_struc;

	//Check if first 2 letters start with AT
	if (is_at(string)) {

		//Parse command name and parameters
		char *token = strtok(string+strlen(AT), AT_DELIMITER);
		command_name=token;
		token=strtok(NULL, AT_DELIMITER); //Artificial push to remove the name
		fetch_parameters(token, parameters);

		//Is AT+?
		if(command_name!=NULL) {

			//Check through the AT_Command registry
			at_command_struc = fetch_command(command_name);
			if(at_command_struc!=NULL) {
				if(at_command_struc->executor(parameters)) {
					printf(AT_OK);
				}
				else{
					printf(AT_FAIL);
				}
				return true;
			}

			//Not a valid AT Command
			printf("\"%s\" is not a valid AT-Command", command_name);
			return true;
		}
		else{
			//AT only is a test command
			printf(AT_OK);
			return true;
		}
	}
	return false;
}

//Main AT Command process
PROCESS_THREAD(at_process, ev, data) {
	PROCESS_BEGIN();
	serial_non_at_event_message = process_alloc_event(); //Allocate new global event to the process manager
	while (1) {
		PROCESS_WAIT_EVENT();
		if (ev == serial_line_event_message) {
			if(!(parse_at((char *) data))) {
				//Pass through serial_line_event_message if non-at-command was received via serial_non_at_event_message
				process_post(PROCESS_BROADCAST, serial_non_at_event_message, data);
			}
		}
	}
	PROCESS_END();
}
