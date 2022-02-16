#pragma once
#include <string>
#include <unordered_map>
#include "employeeInfo.h"
#include "CommandParser.h"
#include <list>
using namespace std;
#define MAX_EMPLOYEE 100000

class DataManager {
public:
	DataManager() {
		employeeCnt = 0;

		employeeNumMap.clear();
		employeeNumMap.reserve(MAX_EMPLOYEE);
		givenNameMap.clear();
		givenNameMap.reserve(MAX_EMPLOYEE);
		familyNameMap.clear();
		familyNameMap.reserve(MAX_EMPLOYEE);
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
		
	}

	static EmployeeInfo employeePool[MAX_EMPLOYEE];
	int employeeCnt = 0;

	unordered_map<int, list<EmployeeInfo*>> employeeNumMap;
	unordered_map<string, list<EmployeeInfo*>> givenNameMap;
	unordered_map<string, list<EmployeeInfo*>> familyNameMap;
	unordered_map<string, list<EmployeeInfo*>> nameMap;
	unordered_map<CareerLevel, list<EmployeeInfo*>> clMap;
	unordered_map<int, list<EmployeeInfo*>> phoneNumMidMap;
	unordered_map<int, list<EmployeeInfo*>> phoneNumEndMap;
	unordered_map<string, list<EmployeeInfo*>> phoneNumMap;
	unordered_map<int, list<EmployeeInfo*>> birthYearMap;
	unordered_map<int, list<EmployeeInfo*>> birthMonthMap;
	unordered_map<int, list<EmployeeInfo*>> birthDayMap;
	unordered_map<int, list<EmployeeInfo*>> birthMap;
	unordered_map<CERTI, list<EmployeeInfo*>> certiMap;

	bool addEmployee(EmployeeInfo employee);

	int delEmployee(KeyInfo keyinfo) {
		return 0;
	}
	int modEmployee(KeyInfo keyinfo) {
		return 0;
	}
	int schEmployee(KeyInfo keyinfo) {
		return 0;
	}
	void cmdCheck(CommandType cmd, EmployeeInfo& employeeinfo, KeyInfo& keyinfo) {

	}

};