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

#include "debug.h"
#include "executors/executors.h"
#include "at.h"

uint8_t op_mode= 0;
char* AT_DELIMITER = "+ ";
char* AT_OK = "OK";
char* AT_FAIL = "FAIL";
char* AT = "AT";

//AT Command registry
at_command commands[]= {
		#ifdef AT_DEBUG
		{
			"TEST",
			"Is test",
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

void parse_at(char* string) {
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
					putline(AT_OK);
				}
				else{
					putline(AT_FAIL);
				}
				return;
			}

			//Not a valid AT Command
			putchar('"');
			putstring(command_name);
			putline("\" is not a valid AT Command.");
		}
		else{
			//AT only is a test command
			putline(AT_OK);
		}
	}
}
