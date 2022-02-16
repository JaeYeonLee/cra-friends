#include <list>
#include "CommandParser.h"

class Printer {
private:
	string getFullDataString(EmployeeInfo* dataList);
public:
	string getResultString() { return resultString; }
	void printResult() { cout << resultString; }
	int setResultData(CommandType cmd, list<EmployeeInfo*>* dataList, Option op);
private:
	CommandType command;
	Option option;
	string resultString;
};