#pragma once
#include <list>
#include <unordered_map>
#include "employeeInfo.h"

using namespace std;

class SearchEngine {
public:
	list<EmployeeInfo*>* search(string key, unordered_map<string, list<EmployeeInfo*>>& hashTable);
	list<EmployeeInfo*>* search(int key, unordered_map<int, list<EmployeeInfo*>>& hashTable);
	list<EmployeeInfo*>* search(CERTI key, unordered_map<CERTI, list<EmployeeInfo*>>& hashTable);
	list<EmployeeInfo*>* search(CareerLevel key, unordered_map<CareerLevel, list<EmployeeInfo*>>& hashTable);
};
