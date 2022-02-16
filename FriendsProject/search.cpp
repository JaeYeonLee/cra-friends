#include "search.h"

const list<EmployeeInfo*>* SearchEngine::search(string key, unordered_map<string, list<EmployeeInfo*>>& hashTable) {
	auto result = hashTable.find(key);
	if (result == hashTable.end()) return nullptr;
	return &result->second;
}
const list<EmployeeInfo*>* SearchEngine::search(int key, unordered_map<int, list<EmployeeInfo*>>& hashTable) {
	auto result = hashTable.find(key);
	if (result == hashTable.end()) return nullptr;
	return &result->second;
}
const list<EmployeeInfo*>* SearchEngine::search(CERTI key, unordered_map<CERTI, list<EmployeeInfo*>>& hashTable) {
	auto result = hashTable.find(key);
	if (result == hashTable.end()) return nullptr;
	return &result->second;
}
const list<EmployeeInfo*>* SearchEngine::search(CareerLevel key, unordered_map<CareerLevel, list<EmployeeInfo*>>& hashTable) {
	auto result = hashTable.find(key);
	if (result == hashTable.end()) return nullptr;
	return &result->second;
}