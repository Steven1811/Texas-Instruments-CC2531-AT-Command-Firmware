
/*
 * at.h
 *
 *  Created on: 10.06.2018
 *      Author: steven
 */

#ifndef ATPARSER_H_
#define ATPARSER_H_
#include <stdbool.h>

#define MAX_PARAM_COUNT 8
#define putline(string) {putstring(string); putchar('\n');}
#define AT_TYPE_NULL 0
#define AT_TYPE_INT 1
#define AT_TYPE_STRING 2
#define AT_TYPE_IPV6 3

typedef struct {
	char* cmd_name;
	char* description;
	bool (*executor)(char **);
} at_command;

extern char* AT_OK;
extern char* AT;

void parse_at(char* string);
at_command* get_commands();

#endif /* ATPARSER_H_ */
