#pragma once
#include <vector>
#include "employeeinfo.h"

using namespace std;

enum class CommandType {
	ADD = 0,
	MOD = 1,
	SCH = 2,
	DEL = 3,
	INVALID = 4,
};

enum class Option {
	NONE = 0,
	FIRST_YEAR = 1,
	MIDDLE_MONTH = 2,
	LAST_DAY = 3,
	PRINT = 4,
};

struct KeyInfo {
	string searchKey;
	string searchKeyword;
	string modifyKey;
	string modifyKeyword;
};

struct OptionInfo {
	Option enablePrint;
	Option searchOption;
};

class CommandParser {
public:
	CommandType parseData(string readLine);
	int parseOption(OptionInfo* option);
	int parseAddCommand(EmployeeInfo* addInfo);
	int parseModifyCommand(KeyInfo* keyInfo, OptionInfo* optionInfo);
	int parseDeleteCommand(KeyInfo* keyInfo, OptionInfo* optionInfo);
	int parseSearchCommand(KeyInfo* keyInfo, OptionInfo* optionInfo);

private:
	string getSearchKeyStr(string key, OptionInfo* optionInfo);
	vector<string> split(string text, char div);

	const string searchOptionKeyStr[3][4] = {
		{"name","name_First","name","name_Last"},
		{"phoneNum","phoneNum","phoneNum_Mid","phoneNum_End"},
		{"birthday","birthday_Year","birthday_Month","birthday_Day"}
	};
	CommandType commandType;
	FILE* fin;
	vector<string> parseLine;
};