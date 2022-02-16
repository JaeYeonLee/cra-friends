#include <list>
#include <unordered_map>
#include "employeeInfo.h"

using namespace std;

class SearchEngine {
public:
	const list<EmployeeInfo*>* search(string key, unordered_map<string, list<EmployeeInfo*>>& hashTable);
	const list<EmployeeInfo*>* search(int key, unordered_map<int, list<EmployeeInfo*>>& hashTable);
	const list<EmployeeInfo*>* search(CERTI key, unordered_map<CERTI, list<EmployeeInfo*>>& hashTable);
	const list<EmployeeInfo*>* search(CareerLevel key, unordered_map<CareerLevel, list<EmployeeInfo*>>& hashTable);
};
