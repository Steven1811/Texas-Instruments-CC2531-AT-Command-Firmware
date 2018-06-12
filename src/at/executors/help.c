/*
 * help.c
 *
 *  Created on: 12.06.2018
 *      Author: steven
 */

#include <stdbool.h>
#include <string.h>

#include "executors.h"
#include "../at.h"
#include "debug.h"

bool help_exec(char ** parameters) {
	uint8_t i=0;
	at_command* commands;

	putline("AT command help:");
	commands=get_commands();


	while(commands[i].cmd_name!=NULL) {
		putchar('\t');
		putstring(AT);
		putchar('+');
		putstring(commands[i].cmd_name);
		putstring(": ");
		putline(commands[i].description)
		i++;
	}
	return true;
}
