#include <string>

using namespace std;

enum CERTI {
	NONE = 0,
	ADV,
	PRO,
	EX
};

class EmployeeInfo {
	int employeeNum;
	string givenName;
	string familyName;
	int cl;
	int phoneNumMid;
	int phoneNumEnd;
	int birthYear;
	int birthMonth;
	int birthDay;
	CERTI certi;
};
