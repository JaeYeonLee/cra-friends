#pragma once
#include <string>
#include "employeeInfo.h"
#include "CommandParser.h"
#include "dataManager.h"

using namespace std;

class EmployeeManagement {
public:
	int openFile(string inputfile, string outputfile);
	int loadData();
	int prepareCommand(int lineIndex);
	int runCommand();
	int printResult();
	string debugResult();

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

