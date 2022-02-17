#include "search.h"

map<int, EmployeeInfo*> SearchEngine::search(string key, unordered_multimap<string, int>* hashTable, unordered_map<int, EmployeeInfo*>& employeeInfoMap, SearchKey key_type) {
	map<int, EmployeeInfo*> result;

	if (hashTable->find(key) == hashTable->end()) return result;

	auto range = hashTable->equal_range(key);
	for (auto it = range.first; it != range.second;) {
		if (employeeInfoMap.find(it->second) != employeeInfoMap.end()) {
			if (employeeInfoMap.find(it->second)->second->isDelete)
			{
				hashTable->erase(it++);
				continue;
			}
			switch (key_type)
			{
			case SearchKey::NAME:
				if (employeeInfoMap.find(it->second)->second->name != key) {
					hashTable->erase(it++);
					continue;
				}
				result.insert({ it->second, employeeInfoMap[it->second] });
				break;
			case SearchKey::NAME_FIRST:
				if (employeeInfoMap.find(it->second)->second->name_First != key) {
					hashTable->erase(it++);
					continue;
				}
				result.insert({ it->second, employeeInfoMap[it->second] });
				break;
			case SearchKey::NAME_LAST:
				if (employeeInfoMap.find(it->second)->second->name_Last != key) {
					hashTable->erase(it++);
					continue;
				}
				result.insert({ it->second, employeeInfoMap[it->second] });
				break;
			case SearchKey::PHONENUM:
				if (employeeInfoMap.find(it->second)->second->phoneNum != key) {
					hashTable->erase(it++);
					continue;
				}
				result.insert({ it->second, employeeInfoMap[it->second] });
				break;
			default:
				break;
			}
		}
		it++;
	}
	return result;
}
map<int, EmployeeInfo*> SearchEngine::search(int key, unordered_multimap<int, int>* hashTable, unordered_map<int, EmployeeInfo*>& employeeInfoMap, SearchKey key_type) {
	map<int, EmployeeInfo*> result;
	if (hashTable->find(key) == hashTable->end()) return result;
	auto range = hashTable->equal_range(key);
	for (auto it = range.first; it != range.second;) {
		if (employeeInfoMap.find(it->second) != employeeInfoMap.end()) {
			if (employeeInfoMap.find(it->second)->second->isDelete)
			{
				hashTable->erase(it++);
				continue;
			}

			switch (key_type)
			{
			case SearchKey::EMPLOYEENUM:
				if (employeeInfoMap.find(it->second)->second->employeeNum != key) {
					hashTable->erase(it++);
					continue;
				}
				result.insert({ it->second, employeeInfoMap[it->second] });
				break;
			case SearchKey::PHONENUM_MID:
				if (employeeInfoMap.find(it->second)->second->phoneNum_Mid != key) {
					hashTable->erase(it++);
					continue;
				}
				result.insert({ it->second, employeeInfoMap[it->second] });
				break;
			case SearchKey::PHONENUM_END:
				if (employeeInfoMap.find(it->second)->second->phoneNum_End != key) {
					hashTable->erase(it++);
					continue;
				}
				result.insert({ it->second, employeeInfoMap[it->second] });
				break;
			case SearchKey::BIRTH:
				if (employeeInfoMap.find(it->second)->second->birthday != key) {
					hashTable->erase(it++);
					continue;
				}
				result.insert({ it->second, employeeInfoMap[it->second] });
				break;
			case SearchKey::BIRTH_YEAR:
				if (employeeInfoMap.find(it->second)->second->birthday_Year != key) {
					hashTable->erase(it++);
					continue;
				}
				result.insert({ it->second, employeeInfoMap[it->second] });
				break;
			case SearchKey::BIRTH_MOHTH:
				if (employeeInfoMap.find(it->second)->second->birthday_Month != key) {
					hashTable->erase(it++);
					continue;
				}
				result.insert({ it->second, employeeInfoMap[it->second] });
				break;
			case SearchKey::BIRTH_DAY:
				if (employeeInfoMap.find(it->second)->second->birthday_Day != key) {
					hashTable->erase(it++);
					continue;
				}
				result.insert({ it->second, employeeInfoMap[it->second] });
				break;
			default:
				break;
			}
		}
		it++;
	}
	return result;
}
map<int, EmployeeInfo*> SearchEngine::search(CERTI key, unordered_multimap<CERTI, int>* hashTable, unordered_map<int, EmployeeInfo*>& employeeInfoMap) {
	map<int, EmployeeInfo*> result;
	if (hashTable->find(key) == hashTable->end()) return result;
	auto range = hashTable->equal_range(key);
	for (auto it = range.first; it != range.second;) {
		if (employeeInfoMap.find(it->second) != employeeInfoMap.end()) {
			if (employeeInfoMap.find(it->second)->second->isDelete)
			{
				hashTable->erase(it++);
				continue;
			}
			if (employeeInfoMap.find(it->second)->second->certi != key) {
				hashTable->erase(it++);
				continue;
			}
			result.insert({ it->second, employeeInfoMap[it->second] });
		}
		it++;
	}
	return result;
}
map<int, EmployeeInfo*> SearchEngine::search(CareerLevel key, unordered_multimap<CareerLevel, int>* hashTable, unordered_map<int, EmployeeInfo*>& employeeInfoMap) {
	map<int, EmployeeInfo*> result;
	if (hashTable->find(key) == hashTable->end()) return result;
	auto range = hashTable->equal_range(key);
	for (auto it = range.first; it != range.second;) {
		if (employeeInfoMap.find(it->second) != employeeInfoMap.end()) {
			if (employeeInfoMap.find(it->second)->second->isDelete)
			{
				hashTable->erase(it++);
				continue;
			}
			if (employeeInfoMap.find(it->second)->second->cl != key) {
				hashTable->erase(it++);
				continue;
			}
			result.insert({ it->second, employeeInfoMap[it->second] });
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
