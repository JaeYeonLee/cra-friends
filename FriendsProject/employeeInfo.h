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
	string givenName;
	string familyName;
	CareerLevel cl;
	int phoneNumMid;
	int phoneNumEnd;
	int birthYear;
	int birthMonth;
	int birthDay;
	CERTI certi;
	string name;
	string phoneNum;
	int birth;
};
