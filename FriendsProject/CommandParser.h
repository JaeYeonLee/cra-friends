#pragma once

#include "employeeinfo.h"
#include <iostream>
#include <vector>

using namespace std;

enum class CommandType {
	ADD = 0,
	MOD = 1,
	SCH = 2,
	DEL = 3,
	INVALID = 4,
};

struct KeyInfo {
	string searchKey;
	string searchKeyword;
	string modifyKey;
	string modifyKeyword;
};

class CommandParser {
public:
	CommandType parseData(string readLine) {
		return CommandType::INVALID;
	}

	int parseAddCommand(EmployeeInfo* addInfo) {
		return 0;
	}

	int parseModifyCommand(KeyInfo* keyInfo) {
		return 0;
	}

	int parseDeleteCommand(KeyInfo* keyInfo) {
		return 0;
	}

	int parseSearchCommand(KeyInfo* keyInfo) {
		return 0;
	}
};