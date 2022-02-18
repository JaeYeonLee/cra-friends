#pragma once
#include <string>
#include <unordered_map>
#include "employeeInfo.h"
#include "CommandParser.h"
#include <queue>
using namespace std;
#define MAX_EMPLOYEE 100000

struct Compare
{
	bool operator()(EmployeeInfo* A, EmployeeInfo* B)
	{
		int a_num = A->employeeNum;
		int b_num = B->employeeNum;
		if (a_num < 22000000)
			a_num += 100000000;
		if (b_num < 22000000)
			b_num += 100000000;
		return a_num > b_num;
	}
};


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
		nameMap.clear();
		nameMap.reserve(MAX_EMPLOYEE);
		clMap.clear();
		clMap.reserve(MAX_EMPLOYEE);
		phoneNumMidMap.clear();
		phoneNumMidMap.reserve(MAX_EMPLOYEE);
		phoneNumEndMap.clear();
		phoneNumEndMap.reserve(MAX_EMPLOYEE);
		phoneNumMap.clear();
		phoneNumMap.reserve(MAX_EMPLOYEE);
		birthYearMap.clear();
		birthYearMap.reserve(MAX_EMPLOYEE);
		birthMonthMap.clear();
		birthMonthMap.reserve(MAX_EMPLOYEE);
		birthDayMap.clear();
		birthDayMap.reserve(MAX_EMPLOYEE);
		birthMap.clear();
		birthMap.reserve(MAX_EMPLOYEE);
		certiMap.clear();
		certiMap.reserve(MAX_EMPLOYEE);
		
	}

	static EmployeeInfo employeePool[MAX_EMPLOYEE];
	int employeeCnt = 0;

	unordered_map<int, priority_queue<EmployeeInfo*, vector<EmployeeInfo*>, Compare>> employeeNumMap;
	unordered_map<string, priority_queue<EmployeeInfo*, vector<EmployeeInfo*>, Compare>> givenNameMap;
	unordered_map<string, priority_queue<EmployeeInfo*, vector<EmployeeInfo*>, Compare>> familyNameMap;
	unordered_map<string, priority_queue<EmployeeInfo*, vector<EmployeeInfo*>, Compare>> nameMap;
	unordered_map<CareerLevel, priority_queue<EmployeeInfo*, vector<EmployeeInfo*>, Compare>> clMap;
	unordered_map<int, priority_queue<EmployeeInfo*, vector<EmployeeInfo*>, Compare>> phoneNumMidMap;
	unordered_map<int, priority_queue<EmployeeInfo*, vector<EmployeeInfo*>, Compare>> phoneNumEndMap;
	unordered_map<string, priority_queue<EmployeeInfo*, vector<EmployeeInfo*>, Compare>> phoneNumMap;
	unordered_map<int, priority_queue<EmployeeInfo*, vector<EmployeeInfo*>, Compare>> birthYearMap;
	unordered_map<int, priority_queue<EmployeeInfo*, vector<EmployeeInfo*>, Compare>> birthMonthMap;
	unordered_map<int, priority_queue<EmployeeInfo*, vector<EmployeeInfo*>, Compare>> birthDayMap;
	unordered_map<int, priority_queue<EmployeeInfo*, vector<EmployeeInfo*>, Compare>> birthMap;
	unordered_map<CERTI, priority_queue<EmployeeInfo*, vector<EmployeeInfo*>, Compare>> certiMap;

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