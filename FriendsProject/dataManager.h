#pragma once
#include <string>
#include <unordered_map>
#include "CommandParser.h"
#include "search.h"
#include <list>
#include "search.h"
#include "printer.h"

using namespace std;
#define MAX_EMPLOYEE 100000

enum class DataType {
	INT = 0,
	STRING,
	CL,
	CERTI,
	ERROR
};
enum class HashType {
	EMPLOYEEUMMAP = 0,
	GIVENNAMEMAP,
	FAMILYNAMEMAP,
	NAMEMAP,
	CLMAP,
	PHONENUMMIDMAP,
	PHONENUMENDMAP,
	PHONENUMMAP,
	BIRTHYEARMAP,
	BIRTHMONTHMAP,
	BIRTHDAYMAP,
	BIRTHMAP,
	CERTIMAP
};
enum class SearchKey {
	EMPLOYEENUM = 0,
	NAME,
	GIVENNAME,
	FAMILYNAME,
	CL,
	PHONENUM,
	PHONENUMMID,
	PHONENUMEND,
	BIRTH,
	BIRTHYEAR,
	BIRTHMOHTH,
	BIRTHDAY,
	CERTI
};

class DataManager {
public:
	DataManager() {
		employeeCnt = 0;

		employeeNumMap.clear();
		employeeNumMap.reserve(MAX_EMPLOYEE);
		givenNameMap.clear();
		givenNameMap.reserve(MAX_EMPLOYEE);
		familyNameMap.clear();
		familyNameMap.reserve(MAX_EMPLOYEE);
		clMap.clear();
		clMap.reserve(MAX_EMPLOYEE);
		phoneNumMidMap.clear();
		phoneNumMidMap.reserve(MAX_EMPLOYEE);
		phoneNumEndMap.clear();
		phoneNumEndMap.reserve(MAX_EMPLOYEE);
		birthYearMap.clear();
		birthYearMap.reserve(MAX_EMPLOYEE);
		birthMonthMap.clear();
		birthMonthMap.reserve(MAX_EMPLOYEE);
		birthDayMap.clear();
		birthDayMap.reserve(MAX_EMPLOYEE);
		certiMap.clear();
		certiMap.reserve(MAX_EMPLOYEE);

		searchEngine = new SearchEngine();
		initSearchKeyValues();
	}
	DataManager(Printer* p) {
		employeeCnt = 0;

		employeeNumMap.clear();
		employeeNumMap.reserve(MAX_EMPLOYEE);
		givenNameMap.clear();
		givenNameMap.reserve(MAX_EMPLOYEE);
		familyNameMap.clear();
		familyNameMap.reserve(MAX_EMPLOYEE);
		clMap.clear();
		clMap.reserve(MAX_EMPLOYEE);
		phoneNumMidMap.clear();
		phoneNumMidMap.reserve(MAX_EMPLOYEE);
		phoneNumEndMap.clear();
		phoneNumEndMap.reserve(MAX_EMPLOYEE);
		birthYearMap.clear();
		birthYearMap.reserve(MAX_EMPLOYEE);
		birthMonthMap.clear();
		birthMonthMap.reserve(MAX_EMPLOYEE);
		birthDayMap.clear();
		birthDayMap.reserve(MAX_EMPLOYEE);
		certiMap.clear();
		certiMap.reserve(MAX_EMPLOYEE);

		printer = p;
		searchEngine = new SearchEngine();
		initSearchKeyValues();
	}

	static EmployeeInfo employeePool[MAX_EMPLOYEE];
	int employeeCnt = 0;

	unordered_map<int, EmployeeInfo*> employeeInfoMap;

	unordered_multimap<int, int> employeeNumMap;
	unordered_multimap<string, int> givenNameMap;
	unordered_multimap<string, int> familyNameMap;
	unordered_multimap<string, int> nameMap;
	unordered_multimap<CareerLevel, int> clMap;
	unordered_multimap<int, int> phoneNumMidMap;
	unordered_multimap<int, int> phoneNumEndMap;
	unordered_multimap<string, int> phoneNumMap;
	unordered_multimap<int, int> birthYearMap;
	unordered_multimap<int, int> birthMonthMap;
	unordered_multimap<int, int> birthDayMap;
	unordered_multimap<int, int> birthMap;
	unordered_multimap<CERTI, int> certiMap;

	SearchEngine* search_engine = new SearchEngine();

	unordered_multimap<int, int>* select_hash_int;
	unordered_multimap<string, int>* select_hash_string;
	string select_hash_name;

	unordered_map<string, SearchKey> keyTable;
	void initSearchKeyValues();

	bool addEmployee(EmployeeInfo employee);
	CareerLevel getCL(string key) {
		if (key == "CL1") return CareerLevel::CL1;
		else if (key == "CL2") return CareerLevel::CL2;
		else if (key == "CL3") return CareerLevel::CL3;
		else if (key == "CL4") return CareerLevel::CL4;
	}

	CERTI getCerti(string key) {
		if (key == "ADV") return CERTI::ADV;
		else if (key == "PRO") return CERTI::PRO;
		else if (key == "EX") return CERTI::EX;
		else return CERTI::NONE;
	}

	DataType getDataType(string key, Option option) {
		if (key == "employeeNum" || key == "birthday") {
			return DataType::INT;
		}
		else if (key == "name") {
			return DataType::STRING;
		}
		else if (key == "cl") {
			return DataType::CL;
		}
		else if (key == "phoneNum") {
			switch (option)
			{
			case Option::NONE:
				return DataType::STRING;
			case Option::MIDDLE_MONTH:
			case Option::LAST_DAY:
				return DataType::INT;
			default:
				cout << "Error :: Invalid option" << endl;
				return DataType::ERROR;
			}
		}
		else if (key == "certi") {
			return DataType::CERTI;
		}
		cout << "Error :: Invalid key" << endl;
		return DataType::ERROR;
	}

	void getHashType(string key, Option option) {
		if (key == "employeeNum") {
			select_hash_name = "employeeNumMap";
		}
		else if (key == "phoneNum") {
			switch (option)
			{
			case Option::MIDDLE_MONTH:
				select_hash_name = "phoneNumMidMap";
				break;
			case Option::LAST_DAY:
				select_hash_name = "phoneNumEndMap";
				break;
			default:
				break;
			}
		}
		else if (key == "birthday") {
			switch (option)
			{
			case Option::NONE:
				select_hash_name = "birthMap";
				break;
			case Option::FIRST_YEAR:
				select_hash_name = "birthYearMap";
				break;
			case Option::MIDDLE_MONTH:
				select_hash_name = "birthMonthMap";
				break;
			case Option::LAST_DAY:
				select_hash_name = "birthDayMap";
				break;
			default:
				break;
			}
		}
		else if (key == "employeeNum") {
			select_hash_name = "employeeNumMap";
		}
		else if (key == "phoneNum") {
			switch (option)
			{
			case Option::MIDDLE_MONTH:
				select_hash_name = "phoneNumMidMap";
				break;
			case Option::LAST_DAY:
				select_hash_name = "phoneNumEndMap";
				break;
			default:
				break;
			}
		}
		else if (key == "birthday") {
			switch (option)
			{
			case Option::NONE:
				select_hash_name = "birthMap";
				break;
			case Option::FIRST_YEAR:
				select_hash_name = "birthYearMap";
				break;
			case Option::MIDDLE_MONTH:
				select_hash_name = "birthMonthMap";
				break;
			case Option::LAST_DAY:
				select_hash_name = "birthDayMap";
				break;
			default:
				break;
			}
		}

	}
	unordered_multimap<int, int>& getIntHashMap(string key, Option option) {
		if (key == "employeeNum") {
			return employeeNumMap;
		}
		else if (key == "phoneNum") {
			switch (option)
			{
			case Option::MIDDLE_MONTH:
				return phoneNumMidMap;
			case Option::LAST_DAY:
				return phoneNumEndMap;
			default:
				break;
			}
		}
		else if (key == "birthday") {
			switch (option)
			{
			case Option::NONE:
				return birthMap;
			case Option::FIRST_YEAR:
				return birthYearMap;
			case Option::MIDDLE_MONTH:
				return birthMonthMap;
			case Option::LAST_DAY:
				return birthDayMap;
			default:
				break;
			}
		}
	}
	unordered_multimap<string, int>& getStringHashMap(string key, Option option) {
		if (key == "name") {
			switch (option) {
			case Option::FIRST_YEAR:
				return givenNameMap;
			case Option::LAST_DAY:
				return familyNameMap;
			case Option::NONE:
				return nameMap;
			default:
				break;
			}
		}
		else if (key == "phoneNum") {
			return phoneNumMap;
		}
	}

	const list<EmployeeInfo*> GetResult(KeyInfo keyinfo, Option option) {
		DataType data_type = getDataType(keyinfo.searchKey, option);
		getHashType(keyinfo.searchKey, option);
		switch (data_type)
		{
		case DataType::INT:
			return search_engine->search(stoi(keyinfo.searchKeyword), getIntHashMap(keyinfo.searchKey, option), employeeInfoMap, select_hash_name);
		case DataType::STRING:
			return search_engine->search(keyinfo.searchKeyword, getStringHashMap(keyinfo.searchKey, option), employeeInfoMap, select_hash_name);
		case DataType::CL:
			return search_engine->search(getCL(keyinfo.searchKeyword), clMap, employeeInfoMap);
		case DataType::CERTI:
			return search_engine->search(getCerti(keyinfo.searchKeyword), certiMap, employeeInfoMap);
		}
	}
	void modifyEmployeeInfo(EmployeeInfo* employeeinfo, KeyInfo keyinfo, int employeeNum) {
		if (keyinfo.modifyKey == "name") {
			employeeinfo->name = keyinfo.modifyKeyword;
			int idx = keyinfo.modifyKeyword.find(' ');
			employeeinfo->name_First = keyinfo.modifyKeyword.substr(0, idx);
			employeeinfo->name_Last = keyinfo.modifyKeyword.substr(idx + 1);

			nameMap.insert({ employeeinfo->name, employeeNum });
			givenNameMap.insert({ employeeinfo->name_First, employeeNum });
			familyNameMap.insert({ employeeinfo->name_Last, employeeNum });
		}
		else if (keyinfo.modifyKey == "cl") {
			employeeinfo->cl = getCL(keyinfo.modifyKeyword);

			clMap.insert({ employeeinfo->cl, employeeNum });
		}
		else if (keyinfo.modifyKey == "phoneNum") {
			employeeinfo->phoneNum = keyinfo.modifyKeyword;
			int idx1 = keyinfo.modifyKeyword.find('-', 0);
			int idx2 = keyinfo.modifyKeyword.find('-', idx1 + 1);
			employeeinfo->phoneNum_Mid = stoi(keyinfo.modifyKeyword.substr(idx1 + 1, idx2 - idx1));
			employeeinfo->phoneNum_End = stoi(keyinfo.modifyKeyword.substr(idx2 + 1));

			phoneNumMap.insert({ employeeinfo->phoneNum, employeeNum });
			phoneNumMidMap.insert({ employeeinfo->phoneNum_Mid, employeeNum });
			phoneNumEndMap.insert({ employeeinfo->phoneNum_End, employeeNum });
		}
		else if (keyinfo.modifyKey == "birthday") {
			employeeinfo->birthday = stoi(keyinfo.modifyKeyword);
			employeeinfo->birthday_Year = stoi(keyinfo.modifyKeyword.substr(0, 4));
			employeeinfo->birthday_Month = stoi(keyinfo.modifyKeyword.substr(4, 2));
			employeeinfo->birthday_Day = stoi(keyinfo.modifyKeyword.substr(6, 2));

			birthMap.insert({ employeeinfo->birthday , employeeNum });
			birthYearMap.insert({ employeeinfo->birthday_Year , employeeNum });
			birthMonthMap.insert({ employeeinfo->birthday_Month , employeeNum });
			birthDayMap.insert({ employeeinfo->birthday_Day , employeeNum });
		}
		else if (keyinfo.modifyKey == "certi") {
			employeeinfo->certi = getCerti(keyinfo.modifyKeyword);

			certiMap.insert({ employeeinfo->certi , employeeNum });
		}
	}
	void editHashMap(CommandType cmd, KeyInfo keyinfo, Option option) {
		switch (getDataType(keyinfo.searchKey, option))
		{
		case DataType::INT:
			select_hash_int = &getIntHashMap(keyinfo.searchKey, option);
			{
				auto range = select_hash_int->equal_range(stoi(keyinfo.searchKeyword));
				for (auto it = range.first; it != range.second; it++) {
					auto iter = employeeInfoMap.find(it->second);
					if (iter != employeeInfoMap.end()) {
						if (cmd == CommandType::DEL) employeeInfoMap.erase(it->second);
						else if (cmd == CommandType::MOD) modifyEmployeeInfo(iter->second, keyinfo, it->second);
					}
				}
				if (cmd == CommandType::DEL)
					select_hash_int->erase(stoi(keyinfo.searchKeyword));
			}
			break;
		case DataType::STRING:
			select_hash_string = &getStringHashMap(keyinfo.searchKey, option);
			{
				auto range = select_hash_string->equal_range(keyinfo.searchKeyword);
				for (auto it = range.first; it != range.second; it++) {
					auto iter = employeeInfoMap.find(it->second);
					if (iter != employeeInfoMap.end()) {
						if (cmd == CommandType::DEL) employeeInfoMap.erase(it->second);
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
					if (cmd == CommandType::DEL) employeeInfoMap.erase(it->second);
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
					if (cmd == CommandType::DEL) employeeInfoMap.erase(it->second);
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
	bool delEmployee(KeyInfo keyinfo, OptionInfo optioninfo) {
		const list<EmployeeInfo*> search_result = GetResult(keyinfo, optioninfo.searchOption);
		editHashMap(CommandType::DEL, keyinfo, optioninfo.searchOption);
		return true;
	}
	bool modEmployee(KeyInfo keyinfo, OptionInfo optioninfo) {
		const list<EmployeeInfo*> search_result = GetResult(keyinfo, optioninfo.searchOption);
		editHashMap(CommandType::MOD, keyinfo, optioninfo.searchOption);
		return true;
	}
	bool schEmployee(KeyInfo keyinfo, OptionInfo optioninfo) {
		const list<EmployeeInfo*> search_result = GetResult(keyinfo, optioninfo.searchOption);
		return true;
	}

	Printer* printer;
	SearchEngine* searchEngine;
};
