#include <string>
#include "dataManager.h"

using namespace std;
EmployeeInfo DataManager::employeePool[MAX_EMPLOYEE];


void intmapAdd(unordered_map<int, list<EmployeeInfo*>>& hash, int id, int cnt)
{
	auto iter_string = hash.find(id);
	if (iter_string == hash.end())
		hash.insert({ id,	list<EmployeeInfo*> { &(DataManager::employeePool[cnt])} });
	else
		hash[id].push_back(&(DataManager::employeePool[cnt]));

}

void stringmapAdd(unordered_map<string, list<EmployeeInfo*>>& hash, string id, int cnt)
{
	auto iter_string = hash.find(id);
	if (iter_string == hash.end())
		hash.insert({ id,	list<EmployeeInfo*> { &(DataManager::employeePool[cnt])} });
	else
		hash[id].push_back(&(DataManager::employeePool[cnt]));

}

void certimapAdd(unordered_map<CERTI, list<EmployeeInfo*>>& hash, CERTI id, int cnt)
{
	auto iter_string = hash.find(id);
	if (iter_string == hash.end())
		hash.insert({ id,	list<EmployeeInfo*> { &(DataManager::employeePool[cnt])} });
	else
		hash[id].push_back(&(DataManager::employeePool[cnt]));

}

void carriergmapAdd(unordered_map<CareerLevel, list<EmployeeInfo*>>& hash, CareerLevel id, int cnt)
{
	auto iter = hash.find(id);
	if (iter == hash.end())
		hash.insert({ id,	list<EmployeeInfo*> { &(DataManager::employeePool[cnt])} });
	else
		hash[id].push_back(&(DataManager::employeePool[cnt]));

}



bool DataManager::addEmployee(EmployeeInfo employee) {
		
	employeePool[employeeCnt] = employee;
	auto iter = employeeNumMap.find(employee.employeeNum);
	if (iter == employeeNumMap.end())
		employeeNumMap.insert({ employee.employeeNum,	list<EmployeeInfo*> { &(employeePool[employeeCnt])} }); //employ number는 무조건 하나
	else
		return false;

	stringmapAdd(givenNameMap, employee.givenName, employeeCnt);
	stringmapAdd(familyNameMap, employee.familyName, employeeCnt);
	stringmapAdd(nameMap, employee.name, employeeCnt);

	carriergmapAdd(clMap, employee.cl, employeeCnt);
	intmapAdd(phoneNumMidMap, employee.phoneNumMid, employeeCnt);
	intmapAdd(phoneNumEndMap, employee.phoneNumEnd, employeeCnt);
	stringmapAdd(phoneNumMap, employee.phoneNum, employeeCnt);

	intmapAdd(birthYearMap, employee.birthYear, employeeCnt);
	intmapAdd(birthMonthMap, employee.birthMonth, employeeCnt);
	intmapAdd(birthDayMap, employee.birthDay, employeeCnt);
	intmapAdd(birthMap, employee.birth, employeeCnt);

	certimapAdd(certiMap, employee.certi, employeeCnt);

	employeeCnt++;
	return true;
}

void DataManager::initSearchKeyValues() {
	keyTable.insert({ "employeeNum", SearchKey::EMPLOYEENUM });
	keyTable.insert({ "name", SearchKey::NAME });
	keyTable.insert({ "givenName", SearchKey::GIVENNAME });
	keyTable.insert({ "familyName", SearchKey::FAMILYNAME });
	keyTable.insert({ "cl", SearchKey::CL });
	keyTable.insert({ "phoneNum", SearchKey::PHONENUM });
	keyTable.insert({ "phoneNumMid", SearchKey::PHONENUMMID });
	keyTable.insert({ "phoneNumEnd", SearchKey::PHONENUMEND });
	keyTable.insert({ "birthday", SearchKey::BIRTH });
	keyTable.insert({ "birthYear", SearchKey::BIRTHYEAR });
	keyTable.insert({ "birthMonth", SearchKey::BIRTHMOHTH });
	keyTable.insert({ "birthDay", SearchKey::BIRTHDAY });
	keyTable.insert({ "certi", SearchKey::CERTI });
}

#define CAST_INT(x) static_cast<int>( x )
#define CAST_CL(x) static_cast<CareerLevel>( x )
#define CAST_CERTI(x) static_cast<CERTI>( x )

CERTI getCerti(string certiString) {
	if (certiString == "ADV") return CERTI::ADV;
	if (certiString == "PRO") return CERTI::PRO;
	if (certiString == "EX") return CERTI::EX;
	return CERTI::NONE;
}

CareerLevel getCL(string clString) {
	if (clString.size() == 3 && clString.substr(0, 2) == "CL") {
		int level = stoi(clString.substr(2, 1)) - 1;
		return CAST_CL(level);
	}
}

int DataManager::schEmployee(KeyInfo keyinfo, OptionInfo optionInfo) {
	list<EmployeeInfo*>* searchResult = nullptr;

	switch (CAST_INT(keyTable[keyinfo.searchKey])) {
	case CAST_INT(SearchKey::EMPLOYEENUM):
		searchResult = searchEngine->search(stoi(keyinfo.searchKeyword), employeeNumMap);
		break;
	case CAST_INT(SearchKey::NAME):
		searchResult = searchEngine->search(keyinfo.searchKeyword, nameMap);
		break;
	case CAST_INT(SearchKey::GIVENNAME):
		searchResult = searchEngine->search(keyinfo.searchKeyword, givenNameMap);
		break;
	case CAST_INT(SearchKey::FAMILYNAME):
		searchResult = searchEngine->search(keyinfo.searchKeyword, familyNameMap);
		break;
	case CAST_INT(SearchKey::CL):
		searchResult = searchEngine->search(getCL(keyinfo.searchKeyword), clMap);
		break;
	case CAST_INT(SearchKey::PHONENUM):
		searchResult = searchEngine->search(keyinfo.searchKeyword, phoneNumMap);
		break;
	case CAST_INT(SearchKey::PHONENUMMID):
		searchResult = searchEngine->search(stoi(keyinfo.searchKeyword), phoneNumMidMap);
		break;
	case CAST_INT(SearchKey::PHONENUMEND):
		searchResult = searchEngine->search(stoi(keyinfo.searchKeyword), phoneNumEndMap);
		break;
	case CAST_INT(SearchKey::BIRTH):
		searchResult = searchEngine->search(stoi(keyinfo.searchKeyword), birthMap);
		break;
	case CAST_INT(SearchKey::BIRTHYEAR):
		searchResult = searchEngine->search(stoi(keyinfo.searchKeyword), birthYearMap);
		break;
	case CAST_INT(SearchKey::BIRTHMOHTH):
		searchResult = searchEngine->search(stoi(keyinfo.searchKeyword), birthMonthMap);
		break;
	case CAST_INT(SearchKey::BIRTHDAY):
		searchResult = searchEngine->search(stoi(keyinfo.searchKeyword), birthDayMap);
		break;
	case CAST_INT(SearchKey::CERTI):
		searchResult = searchEngine->search(CAST_CERTI(getCerti(keyinfo.searchKeyword)), certiMap);
		break;
}

	return printer->setResultData(CommandType::SCH, searchResult, optionInfo.enablePrint);
}