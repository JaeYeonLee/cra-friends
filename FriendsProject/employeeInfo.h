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
