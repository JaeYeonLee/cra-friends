#pragma once
#include <vector>
#include "employeeinfo.h"

using namespace std;

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
	void parseOption(OptionInfo* option);
	int parseAddCommand(EmployeeInfo* addInfo);
	int parseModifyCommand(KeyInfo* keyInfo, OptionInfo* optionInfo);
	int parseDeleteCommand(KeyInfo* keyInfo, OptionInfo* optionInfo);
	int parseSearchCommand(KeyInfo* keyInfo, OptionInfo* optionInfo);

private:
	string getSearchKeyStr(string key, OptionInfo* optionInfo);
	vector<string> split(string text, char div);
	string removeLineFeedChar(string lastline);

	const string searchOptionKeyStr[3][4] = {
		{"name","name_First","name","name_Last"},
		{"phoneNum","phoneNum","phoneNum_Mid","phoneNum_End"},
		{"birthday","birthday_Year","birthday_Month","birthday_Day"}
	};

	const int requiredParamCount[4] = { 10,8,6,6 };
	CommandType commandType;
	vector<string> parseLine;
};