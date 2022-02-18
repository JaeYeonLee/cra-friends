#pragma once
#include <string>
#include <unordered_map>
#include "commandParser.h"
#include "search.h"
#include <list>
#include "search.h"
#include "printer.h"

using namespace std;
#define MAX_EMPLOYEE 100000

enum class DataType {
	INT = 0,
	STRING,
	CL,
	CERTI,
	ERROR
};

class DataManager {
public:
	DataManager() {
		employeeCnt = 0;

		employeeNumMap.clear();
		employeeNumMap.reserve(MAX_EMPLOYEE);
		NameFisrtMap.clear();
		NameFisrtMap.reserve(MAX_EMPLOYEE);
		NameLastMap.clear();
		NameLastMap.reserve(MAX_EMPLOYEE);
		clMap.clear();
		clMap.reserve(MAX_EMPLOYEE);
		phoneNumMidMap.clear();
		phoneNumMidMap.reserve(MAX_EMPLOYEE);
		phoneNumEndMap.clear();
		phoneNumEndMap.reserve(MAX_EMPLOYEE);
		birthYearMap.clear();
		birthYearMap.reserve(MAX_EMPLOYEE);
		birthMonthMap.clear();
		birthMonthMap.reserve(MAX_EMPLOYEE);
		birthDayMap.clear();
		birthDayMap.reserve(MAX_EMPLOYEE);
		certiMap.clear();
		certiMap.reserve(MAX_EMPLOYEE);

		searchEngine = new SearchEngine();
		initSearchKeyValues();
	}
	DataManager(Printer* p) {
		employeeCnt = 0;

		employeeNumMap.clear();
		employeeNumMap.reserve(MAX_EMPLOYEE);
		NameFisrtMap.clear();
		NameFisrtMap.reserve(MAX_EMPLOYEE);
		NameLastMap.clear();
		NameLastMap.reserve(MAX_EMPLOYEE);
		clMap.clear();
		clMap.reserve(MAX_EMPLOYEE);
		phoneNumMidMap.clear();
		phoneNumMidMap.reserve(MAX_EMPLOYEE);
		phoneNumEndMap.clear();
		phoneNumEndMap.reserve(MAX_EMPLOYEE);
		birthYearMap.clear();
		birthYearMap.reserve(MAX_EMPLOYEE);
		birthMonthMap.clear();
		birthMonthMap.reserve(MAX_EMPLOYEE);
		birthDayMap.clear();
		birthDayMap.reserve(MAX_EMPLOYEE);
		certiMap.clear();
		certiMap.reserve(MAX_EMPLOYEE);

		printer = p;
		searchEngine = new SearchEngine();
		initSearchKeyValues();
	}

	static EmployeeInfo employeePool[MAX_EMPLOYEE];
	int employeeCnt = 0;

	unordered_map<int, EmployeeInfo*> employeeInfoMap;

	unordered_multimap<int, int> employeeNumMap;
	unordered_multimap<string, int> NameFisrtMap;
	unordered_multimap<string, int> NameLastMap;
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

	SearchEngine* search_engine = new SearchEngine();

	unordered_multimap<int, int>* select_hash_int;
	unordered_multimap<string, int>* select_hash_string;
	string select_hash_name;

	unordered_map<string, SearchKey> keyTable;
	void initSearchKeyValues();

	int addEmployee(EmployeeInfo employee);
	CareerLevel getCL(string key);
	CERTI getCerti(string key);
	DataType getDataType(SearchKey key_type);
	SearchKey getSearchKey(string key);
	unordered_multimap<int, int>* getIntHashMap(SearchKey key_type);
	unordered_multimap<string, int>* getStringHashMap(SearchKey key_type);
	map<int, EmployeeInfo*> GetResult(KeyInfo keyinfo);
	void modifyEmployeeInfo(EmployeeInfo* employeeinfo, KeyInfo keyinfo, int employeeNum);
	void editHashMap(CommandType cmd, KeyInfo keyinfo);
	int delEmployee(KeyInfo keyinfo, OptionInfo optioninfo);
	int modEmployee(KeyInfo keyinfo, OptionInfo optioninfo);
	int schEmployee(KeyInfo keyinfo, OptionInfo optioninfo);

	Printer* printer;
	SearchEngine* searchEngine;
};