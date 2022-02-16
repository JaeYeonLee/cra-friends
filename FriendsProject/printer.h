#include <list>
#include "CommandParser.h"

class Printer {
private:
	void setCommandString(string& dataString);
	void addCommaData(string& dataString, string addString);
	string generateString(EmployeeInfo* dataList);
	void generateFullString(list<EmployeeInfo*>* dataList);
	void generateFullString(int num);
	void generateFullString();
public:
	string getResultString() { return resultString; }
	void printResult() { cout << resultString; }
	int setResultData(CommandType cmd, list<EmployeeInfo*>* dataList, Option op);
private:
	CommandType command;
	Option option;
	string resultString;
};