#include "pch.h"
#include "../FriendsProject/employeeInfo.h"
#include "../FriendsProject/del.cpp"

struct DeleteTestInOut {
	DeleteInfo info;
	int expectedReturnValue;
};

TEST(DelActionTest, DeleteEmployee_CL) {

	DeleteTestInOut InOut[] = {
		{{ "cl","CL1" }, DEL_MATCH_KEYWORD},
		{{ "cl","CL2" }, DEL_MATCH_KEYWORD},
		{{ "cl","CL3" }, DEL_MATCH_KEYWORD},
		{{ "cl","CL4" }, DEL_MATCH_KEYWORD},
		{{ "cl","" }, NULL_KEYWORD},
		{{ "cl","CL0" }, NOT_MATCH_KEYWORD},
		{{ "cl","CCL1" }, NOT_MATCH_KEYWORD},
		{{ "cl","CL11" }, NOT_MATCH_KEYWORD},
	};

	int test_len = sizeof(InOut) / sizeof(DeleteTestInOut);
	for (int i = 0; i < test_len; i++) {
		EXPECT_EQ(DeleteEmployee(&(InOut[i].info)), InOut[i].expectedReturnValue);
	}
}

TEST(DelActionTest, DeleteEmployee_Num) {

	DeleteTestInOut InOut[] = {
		{{ "employeeNum","07052553" }, DEL_MATCH_KEYWORD},
		{{ "employeeNum","" }, NULL_KEYWORD},
		{{ "employeeNum","07052554" }, NOT_MATCH_KEYWORD},
		{{ "employeeNum","007052553" }, NOT_MATCH_KEYWORD},
		{{ "employeeNum","070525533" }, NOT_MATCH_KEYWORD},
	};

	int test_len = sizeof(InOut) / sizeof(DeleteTestInOut);
	for (int i = 0; i < test_len; i++) {
		EXPECT_EQ(DeleteEmployee(&(InOut[i].info)), InOut[i].expectedReturnValue);
	}
}


TEST(DelActionTest, DeleteEmployee_Birthday) {

	DeleteTestInOut InOut[] = {
		{{ "birthday","19811118" }, DEL_MATCH_KEYWORD},
		{{ "birthday","" }, NULL_KEYWORD},
		{{ "birthday","19811119" }, NOT_MATCH_KEYWORD},
		{{ "birthday","198111188" }, NOT_MATCH_KEYWORD},
		{{ "birthday","119811118" }, NOT_MATCH_KEYWORD},
	};

	int test_len = sizeof(InOut) / sizeof(DeleteTestInOut);
	for (int i = 0; i < test_len; i++) {
		EXPECT_EQ(DeleteEmployee(&(InOut[i].info)), InOut[i].expectedReturnValue);
	}
}

TEST(DelActionTest, DeleteEmployee_phone) {

	DeleteTestInOut InOut[] = {
		{{ "phoneNum","010-9291-4846" }, DEL_MATCH_KEYWORD},
		{{ "phoneNum","" }, NULL_KEYWORD},
		{{ "phoneNum","010-9291-4847" }, NOT_MATCH_KEYWORD},
		{{ "phoneNum","010-9291-48466" }, NOT_MATCH_KEYWORD},
		{{ "phoneNum","0010-9291-4846" }, NOT_MATCH_KEYWORD},
	};

	int test_len = sizeof(InOut) / sizeof(DeleteTestInOut);
	for (int i = 0; i < test_len; i++) {
		EXPECT_EQ(DeleteEmployee(&(InOut[i].info)), InOut[i].expectedReturnValue);
	}
}

TEST(DelActionTest, DeleteEmployee_certi) {

	DeleteTestInOut InOut[] = {
		{{ "certi","ADV" }, DEL_MATCH_KEYWORD},
		{{ "certi","PRO" }, DEL_MATCH_KEYWORD},
		{{ "certi","EX" }, DEL_MATCH_KEYWORD},
		{{ "certi","" }, NULL_KEYWORD},
		{{ "certi","IM" }, NOT_MATCH_KEYWORD},
		{{ "certi","AADV" }, NOT_MATCH_KEYWORD},
		{{ "certi","EXX" }, NOT_MATCH_KEYWORD},
	};

	int test_len = sizeof(InOut) / sizeof(DeleteTestInOut);
	for (int i = 0; i < test_len; i++) {
		EXPECT_EQ(DeleteEmployee(&(InOut[i].info)), InOut[i].expectedReturnValue);
	}
}

TEST(DelActionTest, DeleteEmployee_name) {

	DeleteTestInOut InOut[] = {
		{{ "name","WHEEJIN KIM" }, DEL_MATCH_KEYWORD},
		{{ "name","" }, NULL_KEYWORD},
		{{ "name","WHEEJIN PARK" }, NOT_MATCH_KEYWORD},
		{{ "name","WHEEJIN KIMM" }, NOT_MATCH_KEYWORD},
		{{ "name","WWHEEJIN KIM" }, NOT_MATCH_KEYWORD},
		{{ "name","WHEEJINKIM" }, NOT_MATCH_KEYWORD},
		{{ "name","WHEE JIN KIM" }, NOT_MATCH_KEYWORD},
	};

	int test_len = sizeof(InOut) / sizeof(DeleteTestInOut);
	for (int i = 0; i < test_len; i++) {
		EXPECT_EQ(DeleteEmployee(&(InOut[i].info)), InOut[i].expectedReturnValue);
	}
}