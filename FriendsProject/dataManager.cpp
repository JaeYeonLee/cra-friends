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
	int employeenumber = employee.employeeNum;
	if (employee.employeeNum >= 0 && employee.employeeNum < 22000000) {
		employeenumber = employee.employeeNum + 100000000;
	}

	auto iter = employeeInfoMap.find(employeenumber);
	if (iter != employeeInfoMap.end()) {
		return false;
	}

	employeeInfoMap.insert({ employeenumber, &employeePool[employeeCnt] });

	employeeNumMap.insert({ employee.employeeNum, employeenumber });
	NameFisrtMap.insert({ employee.name_First, employeenumber });
	NameLastMap.insert({ employee.name_Last, employeenumber });
	nameMap.insert({ employee.name, employeenumber });
	clMap.insert({ employee.cl , employeenumber });
	phoneNumMidMap.insert({ employee.phoneNum_Mid, employeenumber });
	phoneNumEndMap.insert({ employee.phoneNum_End, employeenumber });
	phoneNumMap.insert({ employee.phoneNum, employeenumber });
	birthYearMap.insert({ employee.birthday_Year, employeenumber });
	birthMonthMap.insert({ employee.birthday_Month, employeenumber });
	birthDayMap.insert({ employee.birthday_Day, employeenumber });
	birthMap.insert({ employee.birthday, employeenumber });
	certiMap.insert({ employee.certi, employeenumber });

	employeeCnt++;
	return true;
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

#define CAST_INT(x) static_cast<int>( x )
#define CAST_CL(x) static_cast<CareerLevel>( x )
#define CAST_CERTI(x) static_cast<CERTI>( x )

CareerLevel DataManager::getCL(string key) {
	if (key == "CL1") return CareerLevel::CL1;
	else if (key == "CL2") return CareerLevel::CL2;
	else if (key == "CL3") return CareerLevel::CL3;
	else if (key == "CL4") return CareerLevel::CL4;
}

CERTI DataManager::getCerti(string key) {
	if (key == "ADV") return CERTI::ADV;
	else if (key == "PRO") return CERTI::PRO;
	else if (key == "EX") return CERTI::EX;
	else return CERTI::NONE;
}

DataType DataManager::getDataType(SearchKey key_type) {
	switch (key_type)
	{
	case SearchKey::EMPLOYEENUM:
	case SearchKey::PHONENUM_MID:
	case SearchKey::PHONENUM_END:
	case SearchKey::BIRTH:
	case SearchKey::BIRTH_YEAR:
	case SearchKey::BIRTH_MOHTH:
	case SearchKey::BIRTH_DAY:
		return DataType::INT;
		break;
	case SearchKey::NAME:
	case SearchKey::NAME_FIRST:
	case SearchKey::NAME_LAST:
	case SearchKey::PHONENUM:
		return DataType::STRING;
		break;
	case SearchKey::CL:
		return DataType::CL;
		break;
	case SearchKey::CERTI:
		return DataType::CERTI;
		break;
	case SearchKey::ERROR:
		return DataType::ERROR;
		break;
	}
}

unordered_multimap<int, int>* DataManager::getIntHashMap(SearchKey key_type) {
	switch (key_type)
	{
	case SearchKey::EMPLOYEENUM:
		return &employeeNumMap;
		break;
	case SearchKey::PHONENUM_MID:
		return &phoneNumMidMap;
		break;
	case SearchKey::PHONENUM_END:
		return &phoneNumEndMap;
		break;
	case SearchKey::BIRTH:
		return &birthMap;
		break;
	case SearchKey::BIRTH_YEAR:
		return &birthYearMap;
		break;
	case SearchKey::BIRTH_MOHTH:
		return &birthMonthMap;
		break;
	case SearchKey::BIRTH_DAY:
		return &birthDayMap;
		break;
	default:
		return nullptr;
		break;
	}
}
unordered_multimap<string, int>* DataManager::getStringHashMap(SearchKey key_type) {
	switch (key_type)
	{
	case SearchKey::NAME:
		return &nameMap;
		break;
	case SearchKey::NAME_FIRST:
		return &NameFisrtMap;
		break;
	case SearchKey::NAME_LAST:
		return &NameLastMap;
		break;
	case SearchKey::PHONENUM:
		return &phoneNumMap;
		break;
	default:
		return nullptr;
		break;
	}
}

const list<EmployeeInfo*> DataManager::GetResult(KeyInfo keyinfo) {
	SearchKey key_type = getSearchKey(keyinfo.searchKey);
	DataType data_type = getDataType(key_type);
	switch (data_type)
	{
	case DataType::INT:
		return search_engine->search(stoi(keyinfo.searchKeyword), getIntHashMap(key_type), employeeInfoMap, key_type);
	case DataType::STRING:
		return search_engine->search(keyinfo.searchKeyword, getStringHashMap(key_type), employeeInfoMap, key_type);
	case DataType::CL:
		return search_engine->search(getCL(keyinfo.searchKeyword), &clMap, employeeInfoMap);
	case DataType::CERTI:
		return search_engine->search(getCerti(keyinfo.searchKeyword), &certiMap, employeeInfoMap);
	}
}
void DataManager::modifyEmployeeInfo(EmployeeInfo* employeeinfo, KeyInfo keyinfo, int employeeNum) {
	SearchKey key_type = getSearchKey(keyinfo.modifyKey);
	int idx1 = 0, idx2 = 0;
	switch (key_type)
	{
	case SearchKey::EMPLOYEENUM:
		break;
	case SearchKey::NAME:
		employeeinfo->name = keyinfo.modifyKeyword;
		idx1 = keyinfo.modifyKeyword.find(' ');
		employeeinfo->name_First = keyinfo.modifyKeyword.substr(0, idx1);
		employeeinfo->name_Last = keyinfo.modifyKeyword.substr(idx1 + 1);
		nameMap.insert({ employeeinfo->name, employeeNum });
		NameFisrtMap.insert({ employeeinfo->name_First, employeeNum });
		NameLastMap.insert({ employeeinfo->name_Last, employeeNum });
		break;
	case SearchKey::CL:
		employeeinfo->cl = getCL(keyinfo.modifyKeyword);
		clMap.insert({ employeeinfo->cl, employeeNum });
		break;
	case SearchKey::PHONENUM:
		employeeinfo->phoneNum = keyinfo.modifyKeyword;
		idx1 = keyinfo.modifyKeyword.find('-', 0);
		idx2 = keyinfo.modifyKeyword.find('-', idx1 + 1);
		employeeinfo->phoneNum_Mid = stoi(keyinfo.modifyKeyword.substr(idx1 + 1, idx2 - idx1));
		employeeinfo->phoneNum_End = stoi(keyinfo.modifyKeyword.substr(idx2 + 1));
		phoneNumMap.insert({ employeeinfo->phoneNum, employeeNum });
		phoneNumMidMap.insert({ employeeinfo->phoneNum_Mid, employeeNum });
		phoneNumEndMap.insert({ employeeinfo->phoneNum_End, employeeNum });
		break;
	case SearchKey::BIRTH:
		employeeinfo->birthday = stoi(keyinfo.modifyKeyword);
		employeeinfo->birthday_Year = stoi(keyinfo.modifyKeyword.substr(0, 4));
		employeeinfo->birthday_Month = stoi(keyinfo.modifyKeyword.substr(4, 2));
		employeeinfo->birthday_Day = stoi(keyinfo.modifyKeyword.substr(6, 2));
		birthMap.insert({ employeeinfo->birthday , employeeNum });
		birthYearMap.insert({ employeeinfo->birthday_Year , employeeNum });
		birthMonthMap.insert({ employeeinfo->birthday_Month , employeeNum });
		birthDayMap.insert({ employeeinfo->birthday_Day , employeeNum });
		break;
	case SearchKey::CERTI:
		employeeinfo->certi = getCerti(keyinfo.modifyKeyword);
		certiMap.insert({ employeeinfo->certi , employeeNum });
		break;
	case SearchKey::ERROR:
		break;
	default:
		break;
	}
}
void DataManager::editHashMap(CommandType cmd, KeyInfo keyinfo) {
	SearchKey key_type = getSearchKey(keyinfo.searchKey);
	switch (getDataType(key_type))
	{
	case DataType::INT:
		select_hash_int = getIntHashMap(key_type);
		{
			auto range = select_hash_int->equal_range(stoi(keyinfo.searchKeyword));
			for (auto it = range.first; it != range.second; it++) {
				auto iter = employeeInfoMap.find(it->second);
				if (iter != employeeInfoMap.end()) {
					if (cmd == CommandType::DEL)
					{
						iter->second->isDelete = true;
						//employeeInfoMap.erase(it->second);

					}
					else if (cmd == CommandType::MOD) modifyEmployeeInfo(iter->second, keyinfo, it->second);
				}
			}
			if (cmd == CommandType::DEL)
				select_hash_int->erase(stoi(keyinfo.searchKeyword));
		}
		break;
	case DataType::STRING:
		select_hash_string = getStringHashMap(key_type);
		{
			auto range = select_hash_string->equal_range(keyinfo.searchKeyword);
			for (auto it = range.first; it != range.second; it++) {
				auto iter = employeeInfoMap.find(it->second);
				if (iter != employeeInfoMap.end()) {
					if (cmd == CommandType::DEL)
					{
						iter->second->isDelete = true;

					}
					else if (cmd == CommandType::MOD) modifyEmployeeInfo(iter->second, keyinfo, it->second);
				}
			}
			if (cmd == CommandType::DEL)
				select_hash_string->erase(keyinfo.searchKeyword);
		}
		break;
	case DataType::CL:
	{
		auto range = clMap.equal_range(getCL(keyinfo.searchKeyword));
		for (auto it = range.first; it != range.second; it++) {
			auto iter = employeeInfoMap.find(it->second);
			if (iter != employeeInfoMap.end()) {
				if (cmd == CommandType::DEL)
				{
					iter->second->isDelete = true;

				}
				else if (cmd == CommandType::MOD) modifyEmployeeInfo(iter->second, keyinfo, it->second);
			}
		}
		if (cmd == CommandType::DEL)
			clMap.erase(getCL(keyinfo.searchKeyword));
	}
	break;
	case DataType::CERTI:
	{
		auto range = certiMap.equal_range(getCerti(keyinfo.searchKeyword));

		for (auto it = certiMap.equal_range(getCerti(keyinfo.searchKeyword)).first; it != certiMap.equal_range(getCerti(keyinfo.searchKeyword)).second; it++) {
			auto iter = employeeInfoMap.find(it->second);
			if (iter != employeeInfoMap.end()) {
				if (cmd == CommandType::DEL)
				{
						iter->second->isDelete = true;

				}
				else if (cmd == CommandType::MOD) modifyEmployeeInfo(iter->second, keyinfo, it->second);
			}
		}
		if (cmd == CommandType::DEL)
			certiMap.erase(getCerti(keyinfo.searchKeyword));
	}
	break;
	default:
		break;
	}
}
bool DataManager::delEmployee(KeyInfo keyinfo, OptionInfo optioninfo) {
	const list<EmployeeInfo*> search_result = GetResult(keyinfo);
	printer->setResultData(CommandType::DEL, &search_result, optioninfo.enablePrint);
	editHashMap(CommandType::DEL, keyinfo);
	return true;
}
bool DataManager::modEmployee(KeyInfo keyinfo, OptionInfo optioninfo) {
	const list<EmployeeInfo*> search_result = GetResult(keyinfo);
	printer->setResultData(CommandType::MOD, &search_result, optioninfo.enablePrint);
	editHashMap(CommandType::MOD, keyinfo);
	return true;
}
bool DataManager::schEmployee(KeyInfo keyinfo, OptionInfo optioninfo) {
	const list<EmployeeInfo*> search_result = GetResult(keyinfo);
	printer->setResultData(CommandType::SCH, &search_result, optioninfo.enablePrint);
	return true;
}
