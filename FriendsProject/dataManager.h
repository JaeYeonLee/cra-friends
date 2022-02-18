#pragma once
#include <string>
#include <unordered_map>
#include "CommandParser.h"
#include "search.h"
#include <list>
#include "search.h"
#include "printer.h"

using namespace std;
#define MAX_EMPLOYEE 100000
#define EMPLOYEE_NUM_00 0
#define EMPLOYEE_NUM_MAX 22000000
#define EMPLOYEE_NUM_OFFSET 100000000

enum class DataType {
	INT = 0,
	STRING,
	CL,
	CERTI,
	ERROR
};

class DataManager {
private:
	int employeeCnt = 0;

	unordered_map<int, EmployeeInfo*> employeeInfoMap;

	unordered_multimap<int, int> employeeNumMap;
	unordered_multimap<string, int> nameFisrtMap;
	unordered_multimap<string, int> nameLastMap;
	unordered_multimap<string, int> nameMap;
	unordered_multimap<CareerLevel, int> clMap;
	unordered_multimap<int, int> phoneNumMidMap;
	unordered_multimap<int, int> phoneNumEndMap;
	unordered_multimap<string, int> phoneNumMap;
	unordered_multimap<int, int> birthYearMap;
	unordered_multimap<int, int> birthMonthMap;
	unordered_multimap<int, int> birthDayMap;
	unordered_multimap<int, int> birthMap;
	unordered_multimap<CERTI, int> certiMap;

	SearchEngine* searchEngine;
	Printer* printer;

	unordered_map<string, SearchKey> keyTable;
public:
	static EmployeeInfo employeePool[MAX_EMPLOYEE];
	DataManager();
	DataManager(Printer* printer);


	void initSearchKeyValues();
	void initHashMap();
	int addEmployee(EmployeeInfo employee);
	CareerLevel getCL(string key);
	CERTI getCerti(string key);
	DataType getDataType(SearchKey keyType);
	SearchKey getSearchKey(string key);
	unordered_map<int, EmployeeInfo*>* getEmployeeInfoMap();
	unordered_multimap<int, int>* getIntHashMap(SearchKey keyType);
	unordered_multimap<string, int>* getStringHashMap(SearchKey keyType);
	unordered_multimap<CareerLevel, int>* getClHashMap();
	unordered_multimap<CERTI, int>* getCertiHashMap();
	map<int, EmployeeInfo*> GetResult(KeyInfo keyinfo);

	template <class T>
	void insertHashMap(T& targetKeyword, const T& modifyKeyword, const int& employeeNum, unordered_multimap<T, int>& hashMap);
	void modifyEmployeeInfo(EmployeeInfo* employeeinfo, KeyInfo keyinfo, int employeeNum);

	template <class T>
	void searchHashMap(T searchKeyword, unordered_multimap<T, int>* hashMap, CommandType cmd, KeyInfo keyInfo);
	void editHashMap(CommandType cmd, KeyInfo keyinfo);
	int delEmployee(KeyInfo keyinfo, OptionInfo optioninfo);
	int modEmployee(KeyInfo keyinfo, OptionInfo optioninfo);
	int schEmployee(KeyInfo keyinfo, OptionInfo optioninfo);

};