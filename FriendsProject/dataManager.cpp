#include <string>
#include "dataManager.h"


using namespace std;
EmployeeInfo DataManager::employeePool[MAX_EMPLOYEE];


void intmapAdd(unordered_map<int, list<EmployeeInfo*>>& hash, int id, int cnt)
{
	auto iter_string = hash.find(id);
	if (iter_string == hash.end())
		hash.insert({ id,	list<EmployeeInfo*> { &(DataManager::employeePool[cnt])} });
	else
		hash[id].push_back(&(DataManager::employeePool[cnt]));

}

void stringmapAdd(unordered_map<string, list<EmployeeInfo*>>& hash, string id, int cnt)
{
	auto iter_string = hash.find(id);
	if (iter_string == hash.end())
		hash.insert({ id,	list<EmployeeInfo*> { &(DataManager::employeePool[cnt])} });
	else
		hash[id].push_back(&(DataManager::employeePool[cnt]));

}

void certimapAdd(unordered_map<CERTI, list<EmployeeInfo*>>& hash, CERTI id, int cnt)
{
	auto iter_string = hash.find(id);
	if (iter_string == hash.end())
		hash.insert({ id,	list<EmployeeInfo*> { &(DataManager::employeePool[cnt])} });
	else
		hash[id].push_back(&(DataManager::employeePool[cnt]));

}

void carriergmapAdd(unordered_map<CareerLevel, list<EmployeeInfo*>>& hash, CareerLevel id, int cnt)
{
	auto iter = hash.find(id);
	if (iter == hash.end())
		hash.insert({ id,	list<EmployeeInfo*> { &(DataManager::employeePool[cnt])} });
	else
		hash[id].push_back(&(DataManager::employeePool[cnt]));

}



bool DataManager::addEmployee(EmployeeInfo employee) {

	employeePool[employeeCnt] = employee;
	int employeenumber = employee.employeeNum;
	if (employee.employeeNum >= 0 && employee.employeeNum < 22000000) {
		employeenumber = employee.employeeNum + 100000000;
	}

	auto iter = employeeInfoMap.find(employeenumber);
	if (iter != employeeInfoMap.end()) {
		return false;
	}

	employeeInfoMap.insert({ employeenumber, &employeePool[employeeCnt] });

	employeeNumMap.insert({ employee.employeeNum, employeenumber });
	givenNameMap.insert({ employee.givenName, employeenumber });
	familyNameMap.insert({ employee.familyName, employeenumber });
	nameMap.insert({ employee.name, employeenumber });
	clMap.insert({ employee.cl , employeenumber });
	phoneNumMidMap.insert({ employee.phoneNumMid, employeenumber });
	phoneNumEndMap.insert({ employee.phoneNumEnd, employeenumber });
	phoneNumMap.insert({ employee.phoneNum, employeenumber });
	birthYearMap.insert({ employee.birthYear, employeenumber });
	birthMonthMap.insert({ employee.birthMonth, employeenumber });
	birthDayMap.insert({ employee.birthDay, employeenumber });
	birthMap.insert({ employee.birth, employeenumber });
	certiMap.insert({ employee.certi, employeenumber });

	employeeCnt++;
	return true;
}

