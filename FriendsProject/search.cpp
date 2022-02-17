#include "search.h"

const list<EmployeeInfo*> SearchEngine::search(string key, unordered_multimap<string, int>& hashTable, unordered_map<int, EmployeeInfo*>& employeeInfoMap, string hash_name) {
	list<EmployeeInfo*> result;
 
	if (hashTable.find(key) == hashTable.end()) return result;
	
	auto range = hashTable.equal_range(key);
	for (auto it = range.first; it != range.second;) {
		if (employeeInfoMap.find(it->second) != employeeInfoMap.end()) {
			if (hash_name == "givenNameMap") {
				if (employeeInfoMap.find(it->second)->second->name_First != key) {
					hashTable.erase(it++);
					continue;
				}
				result.push_back(employeeInfoMap[it->second]);
			}
			else if (hash_name == "familyNameMap") {
				if (employeeInfoMap.find(it->second)->second->name_Last != key) {
					hashTable.erase(it++);
					continue;
				}
				result.push_back(employeeInfoMap[it->second]);
			}
			else if (hash_name == "nameMap") {
				if (employeeInfoMap.find(it->second)->second->name != key) {
					hashTable.erase(it++);
					continue;
				}
				result.push_back(employeeInfoMap[it->second]);
			}
			else if (hash_name == "phoneNumMap") {
				if (employeeInfoMap.find(it->second)->second->phoneNum != key) {
					hashTable.erase(it++);
					continue;
				}
				result.push_back(employeeInfoMap[it->second]);
			}
		}
		it++;
	}
	return result;
}
const list<EmployeeInfo*> SearchEngine::search(int key, unordered_multimap<int, int>& hashTable, unordered_map<int, EmployeeInfo*>& employeeInfoMap, string hash_name) {
	list<EmployeeInfo*> result;
	if (hashTable.find(key) == hashTable.end()) return result;
	auto range = hashTable.equal_range(key);
	for (auto it = range.first; it != range.second;) {
		if (employeeInfoMap.find(it->second) != employeeInfoMap.end()) {
			if (hash_name == "employeeNumMap") {
				if (employeeInfoMap.find(it->second)->second->employeeNum != key) {
					hashTable.erase(it++);
					continue;
				}
				result.push_back(employeeInfoMap[it->second]);
			}
			else if (hash_name == "phoneNumMidMap") {
				if (employeeInfoMap.find(it->second)->second->phoneNum_Mid != key) {
					hashTable.erase(it++);
					continue;
				}
				result.push_back(employeeInfoMap[it->second]);
			}
			else if (hash_name == "phoneNumEndMap") {
				if (employeeInfoMap.find(it->second)->second->phoneNum_End != key) {
					hashTable.erase(it++);
					continue;
				}
				result.push_back(employeeInfoMap[it->second]);
			}
			else if (hash_name == "birthYearMap") {
				if (employeeInfoMap.find(it->second)->second->birthday_Year != key) {
					hashTable.erase(it++);
					continue;
				}
				result.push_back(employeeInfoMap[it->second]);
			}
			else if (hash_name == "birthMonthMap") {
				if (employeeInfoMap.find(it->second)->second->birthday_Month != key) {
					hashTable.erase(it++);
					continue;
				}
				result.push_back(employeeInfoMap[it->second]);
			}
			else if (hash_name == "birthDayMap") {
				if (employeeInfoMap.find(it->second)->second->birthday_Day != key) {
					hashTable.erase(it++);
					continue;
				}
				result.push_back(employeeInfoMap[it->second]);
			}
			else if (hash_name == "birthMap") {
				if (employeeInfoMap.find(it->second)->second->birthday != key) {
					hashTable.erase(it++);
					continue;
				}
				result.push_back(employeeInfoMap[it->second]);
			}
		}
		it++;
	}
	return result;
}
const list<EmployeeInfo*> SearchEngine::search(CERTI key, unordered_multimap<CERTI, int>& hashTable, unordered_map<int, EmployeeInfo*>& employeeInfoMap) {
	list<EmployeeInfo*> result;
	if (hashTable.find(key) == hashTable.end()) return result;
	auto range = hashTable.equal_range(key);
	for (auto it = range.first; it != range.second;) {
		if (employeeInfoMap.find(it->second) != employeeInfoMap.end()) {
			if (employeeInfoMap.find(it->second)->second->certi != key) {
				hashTable.erase(it++);
				continue;
			}
			result.push_back(employeeInfoMap[it->second]);
		}
		it++;
	}
	return result;
}
const list<EmployeeInfo*> SearchEngine::search(CareerLevel key, unordered_multimap<CareerLevel, int>& hashTable, unordered_map<int, EmployeeInfo*>& employeeInfoMap) {
	list<EmployeeInfo*> result;
	if (hashTable.find(key) == hashTable.end()) return result;
	auto range = hashTable.equal_range(key);
	for (auto it = range.first; it != range.second;) {
		if (employeeInfoMap.find(it->second) != employeeInfoMap.end()) {
			if (employeeInfoMap.find(it->second)->second->cl != key) {
				hashTable.erase(it++);
				continue;
			}
			result.push_back(employeeInfoMap[it->second]);
		}
		it++;
	}
	return result;
}

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
