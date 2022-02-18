#include <string>
#include "dataManager.h"


using namespace std;
EmployeeInfo DataManager::employeePool[MAX_EMPLOYEE];


void intmapAdd(unordered_map<int, priority_queue<EmployeeInfo*, vector<EmployeeInfo*>, Compare>>& hash, int id, int cnt)
{
	auto iter = hash.find(id);
	if (iter == hash.end())
	{
		priority_queue<EmployeeInfo*, vector<EmployeeInfo*>, Compare> pq_employee;
		pq_employee.push(&(DataManager::employeePool[cnt]));
		hash.insert({ id,	pq_employee });
	}
	else
		hash[id].push(&(DataManager::employeePool[cnt]));

}

void stringmapAdd(unordered_map<string, priority_queue<EmployeeInfo*, vector<EmployeeInfo*>, Compare>>& hash, string id, int cnt)
{
	auto iter = hash.find(id);
	if (iter == hash.end())
	{
		priority_queue<EmployeeInfo*, vector<EmployeeInfo*>, Compare> pq_employee;
		pq_employee.push(&(DataManager::employeePool[cnt]));
		hash.insert({ id,	pq_employee });
	}
	else
		hash[id].push(&(DataManager::employeePool[cnt]));

}

void certimapAdd(unordered_map<CERTI, priority_queue<EmployeeInfo*, vector<EmployeeInfo*>, Compare>>& hash, CERTI id, int cnt)
{
	auto iter = hash.find(id);
	if (iter == hash.end())
	{
		priority_queue<EmployeeInfo*, vector<EmployeeInfo*>, Compare> pq_employee;
		pq_employee.push(&(DataManager::employeePool[cnt]));
		hash.insert({ id,	pq_employee });
	}
	hash[id].push(&(DataManager::employeePool[cnt]));

}

void careermapAdd(unordered_map<CareerLevel, priority_queue<EmployeeInfo*, vector<EmployeeInfo*>, Compare>>& hash, CareerLevel id, int cnt)
{
	auto iter = hash.find(id);
	if (iter == hash.end())
	{
		priority_queue<EmployeeInfo*, vector<EmployeeInfo*>, Compare> pq_employee;
		pq_employee.push(&(DataManager::employeePool[cnt]));
		hash.insert({ id,	pq_employee });
	}
	hash[id].push(&(DataManager::employeePool[cnt]));

}



bool DataManager::addEmployee(EmployeeInfo employee) {
		
	employeePool[employeeCnt] = employee;
	auto iter = employeeNumMap.find(employee.employeeNum);
	if (iter == employeeNumMap.end())
	{
		priority_queue<EmployeeInfo*, vector<EmployeeInfo*>, Compare> pq_employee;
		pq_employee.push(&(DataManager::employeePool[employeeCnt]));
		employeeNumMap.insert({ employee.employeeNum,	pq_employee });
	}
	else
		return false;

	stringmapAdd(givenNameMap, employee.givenName, employeeCnt);
	stringmapAdd(familyNameMap, employee.familyName, employeeCnt);
	stringmapAdd(nameMap, employee.name, employeeCnt);

	careermapAdd(clMap, employee.cl, employeeCnt);
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

