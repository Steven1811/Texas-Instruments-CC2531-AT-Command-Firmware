
/*
 * at.h
 *
 *  Created on: 10.06.2018
 *      Author: steven
 */

/**
 * CommandList
 * AT
 * 	Description: Is a test Command to see, if the Serial connection is ready
 * 	Response: "OK"
 * 	Parameters: -
 * AT+RST:
 * 	Description: Resets the CC2531 Controller
 * 	Response: "OK"
 * 	Parameters: -
 * AT+SPWR
 * 	Description: Sets the Radio TX Power
 * 	Response: "OK/FAIL"
 * 	Parameters:
 * 		<power> An integer from 0x00 to 0xFF
 * AT+SCH
 * 	Description: Sets the radio channel of the Device
 * 	Response: "OK/FAIL"
 * 	Parameters:
 * 		<IEE 802.15.4 channel> An integer from 0x0B between 0x1A
 ** AT+SAD
 ** 	Description: Sets the PAN_ID of the device
 ** 	Response: "OK/FAIL"
 ** 	Parameters:
 ** 		<PAN> An 16-Bit integer from 0x0000-0xFFFF
 * AT+OP
 * 	Description: Sets the device into operation mode. Serial input will be transmitted and received radio data will be printed out.
 * 	Response: "OK/FAIL"
 * 	Parameters: -
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
