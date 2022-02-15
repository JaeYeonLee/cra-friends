#include <list>
#include <string>
#include "employeeInfo.h"

using namespace std;

class SearchEngine {
public:
	int add(int a, int b) { return a + b; }
	const list<EmployeeInfo*>* search(string key, unordered_map<string, list<EmployeeInfo*>> &hashTable) {
		return nullptr;
	}
	const list<EmployeeInfo*>* search(int key, unordered_map<int, list<EmployeeInfo*>> &hashTable) {
		return nullptr;
	}
	const list<EmployeeInfo*>* search(CERTI key, unordered_map<CERTI, list<EmployeeInfo*>> &hashTable) {
		return nullptr;
	}
};
