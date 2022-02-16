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
	auto iter = employeeNumMap.find(employee.employeeNum);
	if (iter == employeeNumMap.end())
		employeeNumMap.insert({ employeeCnt,	list<EmployeeInfo*> { &(employeePool[employeeCnt])} }); //employ number는 무조건 하나
	else
		return false;

	stringmapAdd(givenNameMap, employee.givenName, employeeCnt);
	stringmapAdd(familyNameMap, employee.familyName, employeeCnt);
	stringmapAdd(nameMap, employee.name, employeeCnt);

	carriergmapAdd(clMap, employee.cl, employeeCnt);
	intmapAdd(phoneNumMidMap, employee.phoneNumMid, employeeCnt);
	intmapAdd(phoneNumEndMap, employee.phoneNumEnd, employeeCnt);
	stringmapAdd(phoneNumMap, employee.phoneNum, employeeCnt);

	intmapAdd(birthYearMap, employee.birthYear, employeeCnt);
	intmapAdd(birthMonthMap, employee.birthMonth, employeeCnt);
	intmapAdd(birthDayMap, employee.birthDay, employeeCnt);
	intmapAdd(birthMap, employee.birth, employeeCnt);

	certimapAdd(certiMap, employee.certi, employeeCnt);

	employeeCnt++;
	return true;
}

