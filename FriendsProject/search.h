#pragma once
#include <list>
#include <unordered_map>
#include "employeeInfo.h"

using namespace std;

class SearchEngine {
public:
	const list<EmployeeInfo*> search(string key, unordered_multimap<string, int>& hashTable, unordered_map<int, EmployeeInfo*>& employeeInfoMap, string hash_name);
	const list<EmployeeInfo*> search(int key, unordered_multimap<int, int>& hashTable, unordered_map<int, EmployeeInfo*>& employeeInfoMap, string hash_name);
	const list<EmployeeInfo*> search(CERTI key, unordered_multimap<CERTI, int>& hashTable, unordered_map<int, EmployeeInfo*>& employeeInfoMap);
	const list<EmployeeInfo*> search(CareerLevel key, unordered_multimap<CareerLevel, int>& hashTable, unordered_map<int, EmployeeInfo*>& employeeInfoMap);

	list<EmployeeInfo*>* search(string key, unordered_map<string, list<EmployeeInfo*>>& hashTable);
	list<EmployeeInfo*>* search(int key, unordered_map<int, list<EmployeeInfo*>>& hashTable);
	list<EmployeeInfo*>* search(CERTI key, unordered_map<CERTI, list<EmployeeInfo*>>& hashTable);
	list<EmployeeInfo*>* search(CareerLevel key, unordered_map<CareerLevel, list<EmployeeInfo*>>& hashTable);
};
