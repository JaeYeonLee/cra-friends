#include <iostream>
#include "CommandParser.h"

using namespace std;

CommandType CommandParser::parseData(string readLine) {
	parseLine = split(readLine, ',');

	if (parseLine[0] == "ADD") commandType = CommandType::ADD;
	else if (parseLine[0] == "MOD") commandType = CommandType::MOD;
	else if (parseLine[0] == "SCH") commandType = CommandType::SCH;
	else if (parseLine[0] == "DEL") commandType = CommandType::DEL;
	else commandType = CommandType::INVALID;

	return commandType;
}

int CommandParser::parseOption(OptionInfo* option) {
	if (parseLine[1] == "-p")
		option->enablePrint = Option::PRINT;
	else
		option->enablePrint = Option::NONE;

	if (parseLine[2] == "-f") option->searchOption = Option::FIRST_YEAR;
	else if (parseLine[2] == "-l") option->searchOption = Option::LAST_DAY;
	else if (parseLine[2] == "-m") option->searchOption = Option::MIDDLE_MONTH;
	else if (parseLine[2] == "-y") option->searchOption = Option::FIRST_YEAR;
	else if (parseLine[2] == "-m") option->searchOption = Option::MIDDLE_MONTH;
	else if (parseLine[2] == "-d") option->searchOption = Option::LAST_DAY;
	else option->searchOption = Option::NONE;

	return 0;
}

int CommandParser::parseAddCommand(EmployeeInfo* addInfo) {
	if (commandType != CommandType::ADD)
		return -1;

	addInfo->employeeNum = atoi(parseLine[4].c_str());

	vector<string> name_split = split(parseLine[5], ' ');
	if (2 != name_split.size())
		return -1;

	addInfo->name = parseLine[5];
	addInfo->name_First = name_split[0];
	addInfo->name_Last = name_split[1];

	addInfo->cl = (CareerLevel)(atoi(parseLine[6].substr(2, 1).c_str()) - 1);
	if ((addInfo->cl < CareerLevel::CL1) || (addInfo->cl > CareerLevel::CL4))
		return -1;

	vector<string> phone_split = split(parseLine[7], '-');
	if (3 != phone_split.size())
		return -1;

	addInfo->phoneNum = parseLine[7];
	addInfo->phoneNum_Mid = atoi(phone_split[1].c_str());
	addInfo->phoneNum_End = atoi(phone_split[2].c_str());

	// TODO: add birth invalid condition
	addInfo->birthday = atoi(parseLine[8].c_str());
	addInfo->birthday_Year = atoi(parseLine[8].substr(0, 4).c_str());
	addInfo->birthday_Month = atoi(parseLine[8].substr(4, 2).c_str());
	addInfo->birthday_Day = atoi(parseLine[8].substr(6, 2).c_str());

	string lastStr = parseLine[9].substr(0, (parseLine[9].length() - 1));
	if (lastStr == "ADV") addInfo->certi = CERTI::ADV;
	else if (lastStr == "PRO") addInfo->certi = CERTI::PRO;
	else if (lastStr == "EX") addInfo->certi = CERTI::EX;
	else return -1;

	return 0;
}

int CommandParser::parseModifyCommand(KeyInfo* keyInfo, OptionInfo* optionInfo) {
	if (commandType != CommandType::MOD)
		return -1;


	keyInfo->searchKey = getSearchKeyStr(parseLine[4], optionInfo);
	keyInfo->searchKeyword = parseLine[5];
	keyInfo->modifyKey = parseLine[6];

	string lastStr = parseLine[7].substr(0, (parseLine[7].length() - 1));
	keyInfo->modifyKeyword = lastStr;

	return 0;
}

int CommandParser::parseDeleteCommand(KeyInfo* keyInfo, OptionInfo* optionInfo) {
	if (commandType != CommandType::DEL)
		return -1;

	keyInfo->searchKey = getSearchKeyStr(parseLine[4], optionInfo);

	string lastStr = parseLine[5].substr(0, (parseLine[5].length() - 1));
	keyInfo->searchKeyword = lastStr;

	return 0;
}

int CommandParser::parseSearchCommand(KeyInfo* keyInfo, OptionInfo* optionInfo) {
	if (commandType != CommandType::SCH)
		return -1;

	keyInfo->searchKey = getSearchKeyStr(parseLine[4], optionInfo);

	string lastStr = parseLine[5].substr(0, (parseLine[5].length() - 1));
	keyInfo->searchKeyword = lastStr;

	return 0;
}

string CommandParser::getSearchKeyStr(string key, OptionInfo* optionInfo) {
	if ((optionInfo->searchOption < Option::NONE) || (optionInfo->searchOption >= Option::PRINT))
		return key;

	string searchKeyStr = key;
	if (key == "name")
		searchKeyStr = searchOptionKeyStr[0][(int)optionInfo->searchOption];
	else if (key == "phoneNum")
		searchKeyStr = searchOptionKeyStr[1][(int)optionInfo->searchOption];
	else if (key == "birthday")
		searchKeyStr = searchOptionKeyStr[2][(int)optionInfo->searchOption];

	return searchKeyStr;
}

vector<string> CommandParser::split(string text, char div) {
	vector<string> result;
	text.push_back(div);
	int a = 0, b = 0;
	while (1) {
		b = (int)text.find(div, a);
		if (b == -1) break;

		string temp = text.substr(a, b - a);
		result.push_back(temp);

		a = b + 1;
	}

	return result;
}