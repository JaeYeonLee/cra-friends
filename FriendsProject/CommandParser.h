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
		parseLine = split(readLine, ',');

		if (parseLine[0] == "ADD") commandType = CommandType::ADD;
		else if (parseLine[0] == "MOD") commandType = CommandType::MOD;
		else if (parseLine[0] == "SCH") commandType = CommandType::SCH;
		else if (parseLine[0] == "DEL") commandType = CommandType::DEL;
		else commandType = CommandType::INVALID;

		return commandType;
	}

	int parseAddCommand(EmployeeInfo* addInfo) {
		if (commandType != CommandType::ADD)
			return -1;

		addInfo->employeeNum = atoi(parseLine[4].c_str());

		vector<string> name_split = split(parseLine[5], ' ');
		if (2 != name_split.size())
			return -1;

		addInfo->name = parseLine[5];
		addInfo->givenName = name_split[0];
		addInfo->familyName = name_split[1];

		addInfo->cl = (CareerLevel)(atoi(parseLine[6].substr(2, 1).c_str()) - 1);
		if ((addInfo->cl < CareerLevel::CL1) || (addInfo->cl > CareerLevel::CL4))
			return -1;

		vector<string> phone_split = split(parseLine[7], '-');
		if (3 != phone_split.size())
			return -1;

		addInfo->phoneNum = parseLine[7];
		addInfo->phoneNumMid = atoi(phone_split[1].c_str());
		addInfo->phoneNumEnd = atoi(phone_split[2].c_str());

		// TODO: add birth invalid condition
		addInfo->birth = atoi(parseLine[8].c_str());
		addInfo->birthYear = atoi(parseLine[8].substr(0, 4).c_str());
		addInfo->birthMonth = atoi(parseLine[8].substr(4, 2).c_str());
		addInfo->birthDay = atoi(parseLine[8].substr(6, 2).c_str());

		string lastStr = parseLine[9].substr(0, (parseLine[9].length() - 1));
		if (lastStr == "ADV") addInfo->certi = CERTI::ADV;
		else if (lastStr == "PRO") addInfo->certi = CERTI::PRO;
		else if (lastStr == "EX") addInfo->certi = CERTI::EX;
		else return -1;

		return 0;
	}

	int parseModifyCommand(KeyInfo* keyInfo) {
		if (commandType != CommandType::MOD)
			return -1;

		keyInfo->searchKey = parseLine[4];
		keyInfo->searchKeyword = parseLine[5];
		keyInfo->modifyKey = parseLine[6];

		string lastStr = parseLine[7].substr(0, (parseLine[7].length() - 1));
		keyInfo->modifyKeyword = lastStr;

		return 0;
	}

	int parseDeleteCommand(KeyInfo* keyInfo) {
		if (commandType != CommandType::DEL)
			return -1;

		keyInfo->searchKey = parseLine[4];

		string lastStr = parseLine[5].substr(0, (parseLine[5].length() - 1));
		keyInfo->searchKeyword = lastStr;

		return 0;
	}

	int parseSearchCommand(KeyInfo* keyInfo) {
		if (commandType != CommandType::SCH)
			return -1;

		keyInfo->searchKey = parseLine[4];

		string lastStr = parseLine[5].substr(0, (parseLine[5].length() - 1));
		keyInfo->searchKeyword = lastStr;

		return 0;
	}

private:
	vector<string> split(string text, char div) {
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

	CommandType commandType;
	FILE* fin;
	vector<string> parseLine;
};