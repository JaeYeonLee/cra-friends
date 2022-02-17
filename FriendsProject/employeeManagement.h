#pragma once
#include <string>
#include "employeeInfo.h"
#include "CommandParser.h"
#include "dataManager.h"
#include <iostream>

#define MAX_READ_BUFFER_SIZE	(512)

using namespace std;

class EmployeeManagement {
public:
	int openFile(string inputfile, string outputfile) {
		if (inputfile.empty())
			return -1;

		fin = nullptr;
		fin = new FILE();
		freopen_s(&fin, inputfile.c_str(), "r", stdin);
		if (nullptr == fin)
			return -1;

		if (!outputfile.empty()) {
			fout = nullptr;
			fout = new FILE();
			freopen_s(&fout, outputfile.c_str(), "w", stdout);
			if (nullptr == fout)
				return -1;
		}
		else {
			cout << "debug output mode" << endl;
		}

		return 0;
	}

	int loadData() {
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

	int prepareCommand(int lineIndex) {
		CommandParser* cp = new CommandParser();
		addInfo = new EmployeeInfo();
		keyInfo = new KeyInfo();
		optionInfo = new OptionInfo();

		commandType = cp->parseData(readLine[lineIndex]);
		cp->parseOption(optionInfo);

		switch (commandType) {
		case CommandType::ADD:
			return cp->parseAddCommand(addInfo);
		case CommandType::MOD:
			return cp->parseModifyCommand(keyInfo, optionInfo);
		case CommandType::SCH:
			return cp->parseSearchCommand(keyInfo, optionInfo);
		case CommandType::DEL:
			return cp->parseDeleteCommand(keyInfo, optionInfo);
		default:
			return -1;
		}
	}

	int runCommand() {

		bool result;
		switch (commandType) {
		case CommandType::ADD:
			result = dm->addEmployee(*addInfo);
			break;
		case CommandType::MOD:
			result = dm->modEmployee(*keyInfo, *optionInfo);
			break;
		case CommandType::SCH:
			result = dm->schEmployee(*keyInfo, *optionInfo);
			break;
		case CommandType::DEL:
			result = dm->delEmployee(*keyInfo, *optionInfo);
			break;
		default:
			result = true;
		}

		return 0;
	}

	int printResult() {
		if (printer.hasValidValue(commandType, optionInfo->enablePrint))
			printer.printResult();
		return 0;
	}

	Printer printer;
	DataManager* dm = new DataManager(&printer);
	CommandType commandType;
	EmployeeInfo* addInfo;
	KeyInfo* keyInfo;
	OptionInfo* optionInfo;
	FILE* fin;
	FILE* fout;
	vector<string> readLine;
};

