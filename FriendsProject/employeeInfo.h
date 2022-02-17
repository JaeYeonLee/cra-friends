#pragma once

#include <string>

using namespace std;

enum class CERTI {
	NONE = 0,
	ADV,
	PRO,
	EX
};

enum class CareerLevel {
	CL1 = 0,
	CL2,
	CL3,
	CL4,
};

enum class SearchKey {
	EMPLOYEENUM = 0,
	NAME,
	NAME_FIRST,
	NAME_LAST,
	CL,
	PHONENUM,
	PHONENUM_MID,
	PHONENUM_END,
	BIRTH,
	BIRTH_YEAR,
	BIRTH_MOHTH,
	BIRTH_DAY,
	CERTI,
	ERROR
};


class EmployeeInfo {
public:
	int employeeNum;
	string name_First;
	string name_Last;
	CareerLevel cl;
	int phoneNum_Mid;
	int phoneNum_End;
	int birthday_Year;
	int birthday_Month;
	int birthday_Day;
	CERTI certi;
	string name;
	string phoneNum;
	int birthday;
};
