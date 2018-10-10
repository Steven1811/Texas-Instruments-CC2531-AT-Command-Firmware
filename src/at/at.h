
/*
 * at.h
 *
 *  Created on: 10.06.2018
 *      Author: steven
 */

#ifndef ATPARSER_H_
#define ATPARSER_H_

#include <stdbool.h>
#include "contiki.h"

#define MAX_PARAM_COUNT 8
#define AT_TYPE_NULL 0
#define AT_TYPE_INT 1
#define AT_TYPE_STRING 2
#define AT_TYPE_IPV6 3

extern process_event_t serial_non_at_event_message; //Used for passing thru non-at commands to other processes
extern char* AT_OK;
extern char* AT;

typedef struct {
	char* cmd_name;
	char* description;
	bool (*executor)(char **);
} at_command;

at_command* get_commands();

PROCESS_NAME(at_process); //Process handle

#endif /* ATPARSER_H_ */
