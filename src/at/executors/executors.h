/*
 * executor.h
 *
 *  Created on: 12.06.2018
 *      Author: steven
 */

#ifndef AT_EXECUTORS_EXECUTORS_H_
#define AT_EXECUTORS_EXECUTORS_H_
#include <stdbool.h>
#include <string.h>

bool help_exec(char ** parameters);
bool reset_exec(char ** parameters);
bool test_exec(char ** parameters);
#endif /* AT_EXECUTORS_EXECUTORS_H_ */