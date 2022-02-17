#include "printer.h"
#include <sstream>

const string commandString[] = { "INVALID", "MOD", "SCH", "DEL" };
const string careerLevelString[] = { "CL1", "CL2", "CL3", "CL4" };
const string certiString[] = { "NONE", "ADV", "PRO", "EX" };

void Printer::setCommandString(string& dataString) {
	dataString = commandString[static_cast<int>(command)];
}

void Printer::addCommaData(string& dataString, string addString) {
	dataString += ",";
	dataString += addString;
}

string Printer::generateString(EmployeeInfo* data) {
	string dataString = "";
	setCommandString(dataString);

	stringstream stream;
	stream.width(8);
	stream.fill('0');
	stream << data->employeeNum;
	addCommaData(dataString, stream.str());

	addCommaData(dataString, data->name);
	addCommaData(dataString, careerLevelString[static_cast<int>(data->cl)]);
	addCommaData(dataString, data->phoneNum);
	addCommaData(dataString, to_string(data->birthday));
	addCommaData(dataString, certiString[static_cast<int>(data->certi)]);

	return dataString;
}

void Printer::generateFullString(map<int, EmployeeInfo*>* dataList) {
	int num = MAX_PRINT;
	for (auto iter = dataList->begin(); iter != dataList->end(); iter++) {
		resultString += generateString(iter->second);
		resultString += "\n";
		if (--num == 0) break;
	}
}

void Printer::generateFullString(int num) {
	setCommandString(resultString);
	addCommaData(resultString, to_string(num) + "\n");
}

void Printer::generateFullString() {
	setCommandString(resultString);
	addCommaData(resultString, "NONE\n");
}

int Printer::setResultData(CommandType cmd, map<int, EmployeeInfo*>* dataList, Option op) {
	if (cmd == CommandType::ADD) return -1;

	command = cmd;
	option = op;
	resultString = "";

	if (dataList == nullptr || dataList->size() == 0) {
		generateFullString();
		return 0;
	}

	if (option == Option::PRINT) {
		generateFullString(dataList);
		return dataList->size();
	}

	if (option == Option::NONE) {
		generateFullString(dataList->size());
		return dataList->size();
	}

	return -1;
}
