/*
 * help.c
 *
 *  Created on: 12.06.2018
 *      Author: steven
 */

#include <stdbool.h>
#include <string.h>
#include <stdio.h>

#include "executors.h"
#include "../at.h"
#include "debug.h"
#include "net/netstack.h"
bool help_exec(char ** parameters) {
	uint8_t i=0;
	at_command* commands;

	printf("AT command help:\n");
	commands=get_commands();

	while(commands[i].cmd_name!=NULL) {
		printf("%s+%s: %s \n", AT, commands[i].cmd_name, commands[i].description);
		i++;
	}
	return true;
}
