#pragma once
#include <string>
#include "employeeInfo.h"
#include "CommandParser.h"

using namespace std;

class EmployeeManagement {
public:
	int loadData(const char* filename) {
		return -1;
	}

	int parseCommand(int lineIndex) {
		return 0;
	}

	int runCommand(int lineIndex) {
		return 0;
	}

	int printResult(int lineIndex) {
		return 0;
	}

	vector<string> readLine;
};
