#include <iostream>
#include "CommandParser.h"

using namespace std;

#define CP_COMMAND_INDEX          (0)
#define CP_OPTION1_INDEX          (1)
#define CP_OPTION2_INDEX          (2)
#define CP_OPTION3_INDEX          (3)
#define CP_ADD_EMPLOYEENUM_INDEX  (4)
#define CP_ADD_NAME_INDEX         (5)
#define CP_ADD_CL_INDEX           (6)
#define CP_ADD_PHONE_INDEX        (7)
#define CP_ADD_BIRTH_INDEX        (8)
#define CP_ADD_CERTI_INDEX        (9)

#define CP_SEARCH_KEY_INDEX       (4)
#define CP_SEARCH_KEYWORD_INDEX   (5)
#define CP_MODIFY_KEY_INDEX       (6)
#define CP_MODIFY_KEYWORD_INDEX   (7)

#define CP_INVALID_EMPLOYEENUM    (100000000)
#define CP_NAME_MAX_LENGTH        (15)
#define CP_NAME_SPLIT_NUM         (2)
#define CP_PHONE_MAX_LENGTH       (13)
#define CP_PHONE_SPLIT_NUM        (3)
#define CP_PHONE_FIRST_STR        "010"
#define CP_BIRTH_MAX_LENGTH       (8)

CommandType CommandParser::parseData(string readLine) {
	parseLine = split(readLine, ',');

	if (parseLine[CP_COMMAND_INDEX] == "ADD") commandType = CommandType::ADD;
	else if (parseLine[CP_COMMAND_INDEX] == "MOD") commandType = CommandType::MOD;
	else if (parseLine[CP_COMMAND_INDEX] == "SCH") commandType = CommandType::SCH;
	else if (parseLine[CP_COMMAND_INDEX] == "DEL") commandType = CommandType::DEL;
	else commandType = CommandType::INVALID;

	if(parseLine.size() != requiredParamCount[(int)commandType]) commandType = CommandType::INVALID;

	return commandType;
}

void CommandParser::parseOption(OptionInfo* option) {
	if (parseLine[CP_OPTION1_INDEX] == "-p")
		option->enablePrint = Option::PRINT;
	else
		option->enablePrint = Option::NONE;

	if (parseLine[CP_OPTION2_INDEX] == "-f") option->searchOption = Option::FIRST_YEAR;
	else if (parseLine[CP_OPTION2_INDEX] == "-l") option->searchOption = Option::LAST_DAY;
	else if (parseLine[CP_OPTION2_INDEX] == "-m") option->searchOption = Option::MIDDLE_MONTH;
	else if (parseLine[CP_OPTION2_INDEX] == "-y") option->searchOption = Option::FIRST_YEAR;
	else if (parseLine[CP_OPTION2_INDEX] == "-m") option->searchOption = Option::MIDDLE_MONTH;
	else if (parseLine[CP_OPTION2_INDEX] == "-d") option->searchOption = Option::LAST_DAY;
	else option->searchOption = Option::NONE;
}

int CommandParser::parseAddCommand(EmployeeInfo* addInfo) {
	if (commandType != CommandType::ADD) return -1;

	addInfo->employeeNum = atoi(parseLine[CP_ADD_EMPLOYEENUM_INDEX].c_str());
	if ((0 > addInfo->employeeNum) || (CP_INVALID_EMPLOYEENUM <= addInfo->employeeNum)) return -1;

	if (CP_NAME_MAX_LENGTH < parseLine[CP_ADD_NAME_INDEX].length()) return -1;
	addInfo->name = parseLine[CP_ADD_NAME_INDEX];

	vector<string> name_split = split(parseLine[CP_ADD_NAME_INDEX], ' ');
	if (CP_NAME_SPLIT_NUM != name_split.size()) return -1;
	addInfo->name_First = name_split[0];
	addInfo->name_Last = name_split[1];

	addInfo->cl = (CareerLevel)(atoi(parseLine[CP_ADD_CL_INDEX].substr(2, 1).c_str()) - 1);
	if ((addInfo->cl < CareerLevel::CL1) || (addInfo->cl > CareerLevel::CL4)) return -1;

	if (CP_PHONE_MAX_LENGTH != parseLine[CP_ADD_PHONE_INDEX].length()) return -1;
	addInfo->phoneNum = parseLine[CP_ADD_PHONE_INDEX];

	vector<string> phone_split = split(parseLine[CP_ADD_PHONE_INDEX], '-');
	if (CP_PHONE_SPLIT_NUM != phone_split.size()) return -1;
	if (CP_PHONE_FIRST_STR != phone_split[0]) return -1;
	addInfo->phoneNum_Mid = atoi(phone_split[1].c_str());
	addInfo->phoneNum_End = atoi(phone_split[2].c_str());

	if (CP_BIRTH_MAX_LENGTH != parseLine[CP_ADD_BIRTH_INDEX].length()) return -1;
	addInfo->birthday = atoi(parseLine[CP_ADD_BIRTH_INDEX].c_str());
	addInfo->birthday_Year = atoi(parseLine[CP_ADD_BIRTH_INDEX].substr(0, 4).c_str());
	addInfo->birthday_Month = atoi(parseLine[CP_ADD_BIRTH_INDEX].substr(4, 2).c_str());
	if ((1 > addInfo->birthday_Month) || (12 < addInfo->birthday_Month)) return -1;
	addInfo->birthday_Day = atoi(parseLine[CP_ADD_BIRTH_INDEX].substr(6, 2).c_str());
	if ((1 > addInfo->birthday_Day) || (31 < addInfo->birthday_Day)) return -1;

	string lastStr = removeLineFeedChar(parseLine[CP_ADD_CERTI_INDEX]);
	if (lastStr == "ADV") addInfo->certi = CERTI::ADV;
	else if (lastStr == "PRO") addInfo->certi = CERTI::PRO;
	else if (lastStr == "EX") addInfo->certi = CERTI::EX;
	else return -1;

	return 0;
}

int CommandParser::parseModifyCommand(KeyInfo* keyInfo, OptionInfo* optionInfo) {
	if (commandType != CommandType::MOD)
		return -1;

	keyInfo->searchKey = getSearchKeyStr(parseLine[CP_SEARCH_KEY_INDEX], optionInfo);
	keyInfo->searchKeyword = parseLine[CP_SEARCH_KEYWORD_INDEX];

	keyInfo->modifyKey = parseLine[CP_MODIFY_KEY_INDEX];
	keyInfo->modifyKeyword = removeLineFeedChar(parseLine[CP_MODIFY_KEYWORD_INDEX]);

	return 0;
}

int CommandParser::parseDeleteCommand(KeyInfo* keyInfo, OptionInfo* optionInfo) {
	if (commandType != CommandType::DEL)
		return -1;

	keyInfo->searchKey = getSearchKeyStr(parseLine[CP_SEARCH_KEY_INDEX], optionInfo);
	keyInfo->searchKeyword = removeLineFeedChar(parseLine[CP_SEARCH_KEYWORD_INDEX]);

	return 0;
}

int CommandParser::parseSearchCommand(KeyInfo* keyInfo, OptionInfo* optionInfo) {
	if (commandType != CommandType::SCH)
		return -1;

	keyInfo->searchKey = getSearchKeyStr(parseLine[CP_SEARCH_KEY_INDEX], optionInfo);
	keyInfo->searchKeyword = removeLineFeedChar(parseLine[CP_SEARCH_KEYWORD_INDEX]);

	return 0;
}

string CommandParser::getSearchKeyStr(string key, OptionInfo* optionInfo) {
	if ((optionInfo->searchOption <= Option::NONE) || (optionInfo->searchOption >= Option::PRINT))
		return key;

	if (key == "name")
		return searchOptionKeyStr[0][(int)optionInfo->searchOption];
	else if (key == "phoneNum")
		return searchOptionKeyStr[1][(int)optionInfo->searchOption];
	else if (key == "birthday")
		return searchOptionKeyStr[2][(int)optionInfo->searchOption];
	else
		return key;
}

string CommandParser::removeLineFeedChar(string lastline) {
	return lastline.substr(0, (lastline.length() - 1));
}

vector<string> CommandParser::split(string text, char div) {
	vector<string> result;
	text.push_back(div);

	int startpos = 0;
	int findpos = 0;

	while (1) {
		findpos = (int)text.find(div, startpos);
		if (findpos == -1) break;

		result.push_back(text.substr(startpos, ((size_t)findpos - startpos)));
		startpos = findpos + 1;
	}

	return result;
}