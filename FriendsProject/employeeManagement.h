#pragma once
#include <string>
#include "employeeInfo.h"
#include "CommandParser.h"
#include "dataManager.h"

#define MAX_READ_BUFFER_SIZE	(512)

using namespace std;

class EmployeeManagement {
public:
	int testEM();
	int openFile(string inputfile, string outputfile);
	int loadData();
	int prepareCommand(int lineIndex);
	int runCommand();
	int printResult();

	vector<string> readLine;

private:
	DataManager* dm = new DataManager(&printer);
	Printer printer;
	CommandType commandType;
	EmployeeInfo* addInfo;
	KeyInfo* keyInfo;
	OptionInfo* optionInfo;
	FILE* fin;
	FILE* fout;
};

