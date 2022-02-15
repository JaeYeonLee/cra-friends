#pragma once
#include <string>
#include "employeeInfo.h"
#include "CommandParser.h"

#define MAX_READ_BUFFER_SIZE	(512)

using namespace std;

class EmployeeManagement {
public:
	int loadData(const char* filename) {
		fin = nullptr;
		fin = new FILE();
		freopen_s(&fin, filename, "r", stdin);
		if (nullptr == fin)
			return -1;

		char readBuffer[MAX_READ_BUFFER_SIZE];
		while (!(feof(fin))) {
			fgets(readBuffer, MAX_READ_BUFFER_SIZE, fin);
			if (readBuffer[0] != '\0')
				readLine.push_back(readBuffer);

			readBuffer[0] = '\0';
		}

		return (int)readLine.size();
	}

	int parseCommand(int lineIndex) {
		CommandParser* cp = new CommandParser();
		CommandType commandType = cp->parseData(readLine[lineIndex]);
		int result = 0;

		if (commandType == CommandType::ADD)
			EmployeeInfo* addInfo = new EmployeeInfo();
		else
			KeyInfo* keyInfo = new KeyInfo();

		switch (commandType) {
		case CommandType::ADD:
			result = cp->parseAddCommand(addInfo);
			break;
		case CommandType::MOD:
			result = cp->parseModifyCommand(keyInfo);
			break;
		case CommandType::SCH:
			result = cp->parseSearchCommand(keyInfo);
			break;
		case CommandType::DEL:
			result = cp->parseDeleteCommand(keyInfo);
			break;
		default:
			result = -1;
		}

		return result;
	}

	int runCommand(int lineIndex) {

		//DataManager* dm = new DataManager();

		//switch (commandType) {
		//case CommandType::ADD:
		//	result = dm->runAdd(addInfo);
		//	break;
		//case CommandType::MOD:
		//	result = dm->runModify(keyInfo);
		//	break;
		//case CommandType::SCH:
		//	result = dm->runSearch(keyInfo);
		//	break;
		//case CommandType::DEL:
		//	result = dm->runDelete(keyInfo);
		//	break;
		//default:
		//	result = -1;
		//}

		return 0;
	}

	int printResult(int lineIndex) {
		return 0;
	}

	EmployeeInfo* addInfo;
	KeyInfo* keyInfo;
	FILE* fin;
	vector<string> readLine;
};

