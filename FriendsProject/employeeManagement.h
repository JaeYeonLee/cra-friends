#pragma once
#include <string>
#include "employeeInfo.h"
#include "commandParser.h"
#include "dataManager.h"

using namespace std;

class EmployeeManagement {
public:
	int openFile(string inputfile, string outputfile);
	void closeFile();
	int loadData();
	int prepareCommand(int lineIndex);
	int runCommand();
	void printResult();
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

