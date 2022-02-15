#include <string>

using namespace std;

enum DelReturnType {
	DEL_MATCH_KEYWORD = 1,
	DEL_INVALID = 0,
	NULL_KEYWORD = -1,
	NOT_MATCH_KEYWORD = -2,
};

struct DeleteInfo {
	string key;
	string keyword;
};

int DeleteEmployee(DeleteInfo* info) {
	return (int)DEL_INVALID;
}
