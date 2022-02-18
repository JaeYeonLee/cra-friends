#include <iostream>
#include "employeeManagement.h"

using namespace std;

#define MAX_READ_BUFFER_SIZE	(512)

int EmployeeManagement::openFile(string inputfile, string outputfile) {
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

void EmployeeManagement::closeFile() {
	fflush(stdout);
	if (nullptr != fin) fclose(fin);
	if (nullptr != fout) fclose(fout);
	fin = nullptr;
	fout = nullptr;
}

int EmployeeManagement::loadData() {
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

int EmployeeManagement::prepareCommand(int lineIndex) {
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

int EmployeeManagement::runCommand() {
	switch (commandType) {
	case CommandType::ADD:
		return dm->addEmployee(*addInfo);
	case CommandType::MOD:
		return dm->modEmployee(*keyInfo, *optionInfo);
	case CommandType::SCH:
		return dm->schEmployee(*keyInfo, *optionInfo);
	case CommandType::DEL:
		return dm->delEmployee(*keyInfo, *optionInfo);
	default:
		return -1;
	}
}

void EmployeeManagement::printResult() {
	if (printer.hasValidValue(commandType, optionInfo->enablePrint))
		printer.printResult();
}

string EmployeeManagement::debugResult() {
	if (printer.hasValidValue(commandType, optionInfo->enablePrint))
		return printer.getResultString();
	else
		return "";
}
