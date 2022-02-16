#include <list>
#include "CommandParser.h"

class Printer {
private:
	string getFullDataString(list<EmployeeInfo*> dataList);
public:
	string printResultwithOption(CommandType cmd, list<EmployeeInfo*>* dataList);
	string printResultwithoutOption(CommandType cmd, int num);
};