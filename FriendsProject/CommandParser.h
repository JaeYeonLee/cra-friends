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
	int loadData(const char* filename) {
		return -1;
	}

	int getDataLineCount() {
		return 0;
	}

	CommandType parseData(int lineIndex) {
		return CommandType::INVALID;
	}

	EmployeeInfo* parseAddCommand() {
		addInfo = new EmployeeInfo();
		return addInfo;
	}

	KeyInfo* parseModifyCommand() {
		keyInfo = new KeyInfo();
		return keyInfo;
	}

	KeyInfo* parseDeleteCommand() {
		keyInfo = new KeyInfo();
		return keyInfo;
	}

	KeyInfo* parseSearchCommand() {
		keyInfo = new KeyInfo();
		return keyInfo;
	}

private:
	EmployeeInfo* addInfo;
	KeyInfo* keyInfo;
	FILE* fin;
};