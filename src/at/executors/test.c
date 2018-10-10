/*
 * test.c
 *
 *  Created on: 12.06.2018
 *      Author: steven
 */

#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include <stdio.h>

#include "../at.h"
#include "debug.h"
#include "executors.h"

bool test_exec(char ** parameters) {
	uint8_t i=0;
	putstring("Executor Params:\n");
	while(parameters[i]!=NULL) {
		putdec(i);
		putstring(": ");
		printf(parameters[i]);
		i++;
	}
	return true;
}
