#pragma once

#include <iostream>
#include "employeeInfo.h"
#include "employeeManagement.h"
#include "CommandParser.h"

using namespace std;

int main(void) {
	EmployeeManagement* em = new EmployeeManagement();
	int data_size = em->loadData("../FriendsProject/input_20_20.txt");
	if (data_size < 0) return -1;

	int result = 0;
	for (int i = 0; i < data_size; i++) {
		result = em->parseCommand(i);
		if (result < 0) continue;

		result = em->runCommand(i);
		if (result < 0) continue;

		result = em->printResult(i);
		if (result < 0) continue;
	}

	return 0;
}