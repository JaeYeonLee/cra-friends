#include <string>
#include "dataManager.h"

using namespace std;
EmployeeInfo DataManager::employeePool[MAX_EMPLOYEE];

DataManager::DataManager() {
	employeeCnt = 0;
	initHashMap();

	searchEngine = new SearchEngine();
	initSearchKeyValues();
}
DataManager::DataManager(Printer *printer) {
	employeeCnt = 0;
	initHashMap();

	this->printer = printer;
	searchEngine = new SearchEngine();
	initSearchKeyValues();
}

int DataManager::addEmployee(EmployeeInfo employee) {

	employeePool[employeeCnt] = employee;

	int employeeNumber = employee.employeeNum;
	if (employee.employeeNum >= EMPLOYEE_NUM_00 && employee.employeeNum < EMPLOYEE_NUM_MAX) {
		employeeNumber = employee.employeeNum + EMPLOYEE_NUM_OFFSET;
	}

	auto iter = employeeInfoMap.find(employeeNumber);
	if (iter != employeeInfoMap.end()) {
		return -1;
	}

	employeeInfoMap.insert({ employeeNumber, &employeePool[employeeCnt] });
	employeeNumMap.insert({ employee.employeeNum, employeeNumber });
	nameFisrtMap.insert({ employee.name_First, employeeNumber });
	nameLastMap.insert({ employee.name_Last, employeeNumber });
	nameMap.insert({ employee.name, employeeNumber });
	clMap.insert({ employee.cl , employeeNumber });
	phoneNumMidMap.insert({ employee.phoneNum_Mid, employeeNumber });
	phoneNumEndMap.insert({ employee.phoneNum_End, employeeNumber });
	phoneNumMap.insert({ employee.phoneNum, employeeNumber });
	birthYearMap.insert({ employee.birthday_Year, employeeNumber });
	birthMonthMap.insert({ employee.birthday_Month, employeeNumber });
	birthDayMap.insert({ employee.birthday_Day, employeeNumber });
	birthMap.insert({ employee.birthday, employeeNumber });
	certiMap.insert({ employee.certi, employeeNumber });

	employeeCnt++;
	return 0;
}

SearchKey DataManager::getSearchKey(string key) {
	auto it = keyTable.find(key);
	if (it == keyTable.end()) {
		return SearchKey::ERROR;
	}
	return it->second;
}

void DataManager::initSearchKeyValues() {
	keyTable.insert({ "employeeNum", SearchKey::EMPLOYEENUM });
	keyTable.insert({ "name", SearchKey::NAME });
	keyTable.insert({ "name_First", SearchKey::NAME_FIRST });
	keyTable.insert({ "name_Last", SearchKey::NAME_LAST });
	keyTable.insert({ "cl", SearchKey::CL });
	keyTable.insert({ "phoneNum", SearchKey::PHONENUM });
	keyTable.insert({ "phoneNum_Mid", SearchKey::PHONENUM_MID });
	keyTable.insert({ "phoneNum_End", SearchKey::PHONENUM_END });
	keyTable.insert({ "birthday", SearchKey::BIRTH });
	keyTable.insert({ "birthday_Year", SearchKey::BIRTH_YEAR });
	keyTable.insert({ "birthday_Month", SearchKey::BIRTH_MOHTH });
	keyTable.insert({ "birthday_Day", SearchKey::BIRTH_DAY });
	keyTable.insert({ "certi", SearchKey::CERTI });
}
void DataManager::initHashMap() {
	employeeNumMap.clear();
	employeeNumMap.reserve(MAX_EMPLOYEE);
	nameFisrtMap.clear();
	nameFisrtMap.reserve(MAX_EMPLOYEE);
	nameLastMap.clear();
	nameLastMap.reserve(MAX_EMPLOYEE);
	nameMap.clear();
	nameMap.reserve(MAX_EMPLOYEE);
	clMap.clear();
	clMap.reserve(MAX_EMPLOYEE);
	phoneNumMidMap.clear();
	phoneNumMidMap.reserve(MAX_EMPLOYEE);
	phoneNumEndMap.clear();
	phoneNumEndMap.reserve(MAX_EMPLOYEE);
	phoneNumMap.clear();
	phoneNumMap.reserve(MAX_EMPLOYEE);
	birthYearMap.clear();
	birthYearMap.reserve(MAX_EMPLOYEE);
	birthMonthMap.clear();
	birthMonthMap.reserve(MAX_EMPLOYEE);
	birthDayMap.clear();
	birthDayMap.reserve(MAX_EMPLOYEE);
	birthMap.clear();
	birthMap.reserve(MAX_EMPLOYEE);
	certiMap.clear();
	certiMap.reserve(MAX_EMPLOYEE);
}
CareerLevel DataManager::getCL(string key) {
	if (key == "CL1") return CareerLevel::CL1;
	else if (key == "CL2") return CareerLevel::CL2;
	else if (key == "CL3") return CareerLevel::CL3;
	else if (key == "CL4") return CareerLevel::CL4;
	return CareerLevel::NONE;
}
CERTI DataManager::getCerti(string key) {
	if (key == "ADV") return CERTI::ADV;
	else if (key == "PRO") return CERTI::PRO;
	else if (key == "EX") return CERTI::EX;
	return CERTI::NONE;
}
DataType DataManager::getDataType(SearchKey keyType) {
	switch (keyType)
	{
	case SearchKey::EMPLOYEENUM:
	case SearchKey::PHONENUM_MID:
	case SearchKey::PHONENUM_END:
	case SearchKey::BIRTH:
	case SearchKey::BIRTH_YEAR:
	case SearchKey::BIRTH_MOHTH:
	case SearchKey::BIRTH_DAY:
		return DataType::INT;
	case SearchKey::NAME:
	case SearchKey::NAME_FIRST:
	case SearchKey::NAME_LAST:
	case SearchKey::PHONENUM:
		return DataType::STRING;
	case SearchKey::CL:
		return DataType::CL;
	case SearchKey::CERTI:
		return DataType::CERTI;
	case SearchKey::ERROR:
		return DataType::ERROR;
	}
	return DataType::ERROR;
}
unordered_map<int, EmployeeInfo*>* DataManager::getEmployeeInfoMap() {
	return &employeeInfoMap;
}
unordered_multimap<int, int>* DataManager::getIntHashMap(SearchKey keyType) {
	switch (keyType)
	{
	case SearchKey::EMPLOYEENUM:
		return &employeeNumMap;
	case SearchKey::PHONENUM_MID:
		return &phoneNumMidMap;
	case SearchKey::PHONENUM_END:
		return &phoneNumEndMap;
	case SearchKey::BIRTH:
		return &birthMap;
	case SearchKey::BIRTH_YEAR:
		return &birthYearMap;
	case SearchKey::BIRTH_MOHTH:
		return &birthMonthMap;
	case SearchKey::BIRTH_DAY:
		return &birthDayMap;
	default:
		return nullptr;
	}
}
unordered_multimap<string, int>* DataManager::getStringHashMap(SearchKey keyType) {
	switch (keyType)
	{
	case SearchKey::NAME:
		return &nameMap;
	case SearchKey::NAME_FIRST:
		return &nameFisrtMap;
	case SearchKey::NAME_LAST:
		return &nameLastMap;
	case SearchKey::PHONENUM:
		return &phoneNumMap;
	default:
		return nullptr;
	}
}
unordered_multimap<CareerLevel, int>* DataManager::getClHashMap() {
	return &clMap;
}
unordered_multimap<CERTI, int>* DataManager::getCertiHashMap() {
	return &certiMap;
}

map<int, EmployeeInfo*> DataManager::GetResult(KeyInfo keyInfo) {
	SearchKey keyType = getSearchKey(keyInfo.searchKey);
	DataType dataType = getDataType(keyType);
	switch (dataType)
	{
	case DataType::INT:
		return searchEngine->search(stoi(keyInfo.searchKeyword), getIntHashMap(keyType), employeeInfoMap, keyType);
	case DataType::STRING:
		return searchEngine->search(keyInfo.searchKeyword, getStringHashMap(keyType), employeeInfoMap, keyType);
	case DataType::CL:
		return searchEngine->search(getCL(keyInfo.searchKeyword), &clMap, employeeInfoMap);
	case DataType::CERTI:
		return searchEngine->search(getCerti(keyInfo.searchKeyword), &certiMap, employeeInfoMap);
	}
}

template <class T>
void DataManager::insertHashMap(T& targetKeyword, const T& modifyKeyword, const int& employeeNum, unordered_multimap<T, int>& hashMap) {
	if (targetKeyword != modifyKeyword)
		hashMap.insert({ modifyKeyword, employeeNum });
	targetKeyword = modifyKeyword;
}

void DataManager::modifyEmployeeInfo(EmployeeInfo* employeeInfo, KeyInfo keyInfo, int employeeNum) {
	SearchKey keyType = getSearchKey(keyInfo.modifyKey);
	size_t idx1 = 0, idx2 = 0;
	switch (keyType)
	{
	case SearchKey::NAME:
		idx1 = keyInfo.modifyKeyword.find(' ');
		insertHashMap(employeeInfo->name, keyInfo.modifyKeyword, employeeNum, nameMap);
		insertHashMap(employeeInfo->name_First, keyInfo.modifyKeyword.substr(0, idx1), employeeNum, nameFisrtMap);
		insertHashMap(employeeInfo->name_Last, keyInfo.modifyKeyword.substr(idx1 + 1), employeeNum, nameLastMap);
		break;
	case SearchKey::CL:
		insertHashMap(employeeInfo->cl, getCL(keyInfo.modifyKeyword), employeeNum, clMap);
		break;
	case SearchKey::PHONENUM:
		idx1 = keyInfo.modifyKeyword.find('-', 0);
		idx2 = keyInfo.modifyKeyword.find('-', idx1 + 1);
		insertHashMap(employeeInfo->phoneNum, keyInfo.modifyKeyword, employeeNum, phoneNumMap);
		insertHashMap(employeeInfo->phoneNum_Mid, stoi(keyInfo.modifyKeyword.substr(idx1 + 1, idx2 - idx1)), employeeNum, phoneNumMidMap);
		insertHashMap(employeeInfo->phoneNum_End, stoi(keyInfo.modifyKeyword.substr(idx2 + 1)), employeeNum, phoneNumEndMap);
		break;
	case SearchKey::BIRTH:
		insertHashMap(employeeInfo->birthday, stoi(keyInfo.modifyKeyword), employeeNum, birthMap);
		insertHashMap(employeeInfo->birthday_Year, stoi(keyInfo.modifyKeyword.substr(0, 4)), employeeNum, birthYearMap);
		insertHashMap(employeeInfo->birthday_Month, stoi(keyInfo.modifyKeyword.substr(4, 2)), employeeNum, birthMonthMap);
		insertHashMap(employeeInfo->birthday_Day, stoi(keyInfo.modifyKeyword.substr(6, 2)), employeeNum, birthDayMap);
		break;
	case SearchKey::CERTI:
		insertHashMap(employeeInfo->certi, getCerti(keyInfo.modifyKeyword), employeeNum, certiMap);
		break;
	default:
		break;
	}
}

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

	switch (getDataType(keyType))
	{
	case DataType::INT:
		selectIntHash = getIntHashMap(keyType);
		searchHashMap(stoi(keyInfo.searchKeyword), selectIntHash, cmd, keyInfo);
		break;
	case DataType::STRING:
		selectStringHash = getStringHashMap(keyType);
		searchHashMap(keyInfo.searchKeyword, selectStringHash, cmd, keyInfo);
		break;
	case DataType::CL:
		searchHashMap(getCL(keyInfo.searchKeyword), &clMap, cmd, keyInfo);
		break;
	case DataType::CERTI:
		searchHashMap(getCerti(keyInfo.searchKeyword), &certiMap, cmd, keyInfo);
		break;
	}
}

int DataManager::delEmployee(KeyInfo keyinfo, OptionInfo optioninfo) {
	map<int, EmployeeInfo*> search_result = GetResult(keyinfo);
	if (printer->setResultData(CommandType::DEL, &search_result, optioninfo.enablePrint) < 0)
		return -1;

	editHashMap(CommandType::DEL, keyinfo);

	return 0;
}

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
