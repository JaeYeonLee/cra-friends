#include <string>
#include <unordered_map>

using namespace std;

enum class CareerLevel {
	CL1,
	CL2,
	CL3,
	CL4
};

enum class CERTI {
	NONE = 0,
	ADV,
	PRO,
	EX
};

class EmployeeInfo {
public:
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
