#pragma once
#include <list>
#include "CommandParser.h"

#define MAX_PRINT 5

class Printer {
private:
	void setCommandString(string& dataString);
	void addCommaData(string& dataString, string addString);
	string generateString(EmployeeInfo* dataList);
	void generateFullString(const list<EmployeeInfo*>* dataList);
	void generateFullString(int num);
	void generateFullString();
public:
	Printer() : command{ CommandType::INVALID }, option{Option::NONE} {
	}
	bool hasValidValue(CommandType cmd, Option opt) { return command == cmd && option == opt && !(resultString == ""); }
	string getResultString() { return resultString; }
	void printResult() { cout << resultString; }
	int setResultData(CommandType cmd, const list<EmployeeInfo*>* dataList, Option op);
private:
	CommandType command;
	Option option;
	string resultString;
};