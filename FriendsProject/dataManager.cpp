#include <string>
#include "dataManager.h"

using namespace std;
EmployeeInfo DataManager::employeePool[MAX_EMPLOYEE];

DataManager::DataManager() {
	employeeCnt = 0;
	initHashMap();

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

	this->printer = printer;
	searchEngine = new SearchEngine();
	initSearchKeyValues();
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

template <class T>
void DataManager::insertHashMap(T& targetKeyword, const T& modifyKeyword, const int& employeeNum, unordered_multimap<T, int>& hashMap) {
	if (targetKeyword != modifyKeyword)
		hashMap.insert({ modifyKeyword, employeeNum });
	targetKeyword = modifyKeyword;
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

template <class T>
void DataManager::searchHashMap(T searchKeyword, unordered_multimap<T, int>* hashMap, CommandType cmd, KeyInfo keyInfo) {
	auto keywordRange = hashMap->equal_range(searchKeyword);
	for (auto keyEmployeeNum = keywordRange.first; keyEmployeeNum != keywordRange.second; keyEmployeeNum++) {
		auto employeeInfo = employeeInfoMap.find(keyEmployeeNum->second);
		if (employeeInfo != employeeInfoMap.end()) {
			if (cmd == CommandType::DEL)
			{
				employeeInfo->second->isDelete = true;
				employeeInfoMap.erase(keyEmployeeNum->second);
			}
			else if (cmd == CommandType::MOD) modifyEmployeeInfo(employeeInfo->second, keyInfo, keyEmployeeNum->second);
		}
	}
	if (cmd == CommandType::DEL)
		hashMap->erase(searchKeyword);
}

void DataManager::editHashMap(CommandType cmd, KeyInfo keyInfo) {
	SearchKey keyType = getSearchKey(keyInfo.searchKey);

	unordered_multimap<int, int>* selectIntHash;
	unordered_multimap<string, int>* selectStringHash;

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

	editHashMap(CommandType::DEL, keyinfo);

	careermapAdd(clMap, employee.cl, employeeCnt);
	intmapAdd(phoneNumMidMap, employee.phoneNumMid, employeeCnt);
	intmapAdd(phoneNumEndMap, employee.phoneNumEnd, employeeCnt);
	stringmapAdd(phoneNumMap, employee.phoneNum, employeeCnt);

int DataManager::modEmployee(KeyInfo keyinfo, OptionInfo optioninfo) {
	map<int, EmployeeInfo*> search_result = GetResult(keyinfo);
	if (printer->setResultData(CommandType::MOD, &search_result, optioninfo.enablePrint) < 0)
		return -1;

	editHashMap(CommandType::MOD, keyinfo);

	return 0;
}

int DataManager::schEmployee(KeyInfo keyinfo, OptionInfo optioninfo) {
	map<int, EmployeeInfo*> search_result = GetResult(keyinfo);
	if (printer->setResultData(CommandType::SCH, &search_result, optioninfo.enablePrint) < 0)
		return -1;

	return 0;
}
