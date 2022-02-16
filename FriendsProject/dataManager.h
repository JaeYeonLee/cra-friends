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
		employeeNumMap.clear();
		givenNameMap.clear();
		familyNameMap.clear();
		clMap.clear();
		phoneNumMidMap.clear();
		phoneNumEndMap.clear();
		birthYearMap.clear();
		birthMonthMap.clear();
		birthDayMap.clear();
		certiMap.clear();
	}

	static EmployeeInfo employeePool[MAX_EMPLOYEE];
	int employeeCnt = 0;

	unordered_map<int, list<EmployeeInfo*>> employeeNumMap;
	unordered_map<string, list<EmployeeInfo*>> givenNameMap;
	unordered_map<string, list<EmployeeInfo*>> familyNameMap;
	unordered_map<CareerLevel, list<EmployeeInfo*>> clMap;
	unordered_map<int, list<EmployeeInfo*>> phoneNumMidMap;
	unordered_map<int, list<EmployeeInfo*>> phoneNumEndMap;
	unordered_map<int, list<EmployeeInfo*>> birthYearMap;
	unordered_map<int, list<EmployeeInfo*>> birthMonthMap;
	unordered_map<int, list<EmployeeInfo*>> birthDayMap;
	unordered_map<CERTI, list<EmployeeInfo*>> certiMap;
	
	bool addEmployee(EmployeeInfo employee) {
		return true;
	}
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

EmployeeInfo DataManager::employeePool[MAX_EMPLOYEE];