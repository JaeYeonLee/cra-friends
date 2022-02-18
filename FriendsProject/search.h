#pragma once
#include <list>
#include <unordered_map>
#include <map>
#include "employeeInfo.h"

using namespace std;

class SearchEngine {
public:
	map<int, EmployeeInfo*> search(string key, unordered_multimap<string, int>* hashTable, unordered_map<int, EmployeeInfo*>& employeeInfoMap, SearchKey key_type);
	map<int, EmployeeInfo*> search(int key, unordered_multimap<int, int>* hashTable, unordered_map<int, EmployeeInfo*>& employeeInfoMap, SearchKey key_type);
	map<int, EmployeeInfo*> search(CERTI key, unordered_multimap<CERTI, int>* hashTable, unordered_map<int, EmployeeInfo*>& employeeInfoMap);
	map<int, EmployeeInfo*> search(CareerLevel key, unordered_multimap<CareerLevel, int>* hashTable, unordered_map<int, EmployeeInfo*>& employeeInfoMap);

	const list<EmployeeInfo*>* search(string key, unordered_map<string, list<EmployeeInfo*>>& hashTable);
	const list<EmployeeInfo*>* search(int key, unordered_map<int, list<EmployeeInfo*>>& hashTable);
	const list<EmployeeInfo*>* search(CERTI key, unordered_map<CERTI, list<EmployeeInfo*>>& hashTable);
	const list<EmployeeInfo*>* search(CareerLevel key, unordered_map<CareerLevel, list<EmployeeInfo*>>& hashTable);
};
