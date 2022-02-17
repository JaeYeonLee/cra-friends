#include "pch.h"
#include "../FriendsProject/employeeInfo.h"
#include "../FriendsProject/dataManager.h"

void input_test_data(DataManager* data_manager) { // test iuput data for cmd run
	data_manager->addEmployee({ 00000000, "KILDONG", "HONG", CareerLevel::CL1, 1234, 5678, 1999, 12, 31, CERTI::ADV, "KILDONG HONG", "010-1234-5678", 19991231 });
	data_manager->addEmployee({ 00000001, "DONGKIL", "KIM", CareerLevel::CL2, 8765, 4321, 2000, 01, 01, CERTI::PRO, "DONGKIL KIM", "010-8765-4321", 20000101 });
	data_manager->addEmployee({ 00000002, "KILDONG", "HONG", CareerLevel::CL1, 1234, 5678, 1999, 12, 31, CERTI::ADV, "KILDONG HONG", "010-1234-5678", 19991231 });
	data_manager->addEmployee({ 00000003, "DONGKIL", "KIM", CareerLevel::CL2, 8765, 4321, 2000, 01, 01, CERTI::PRO, "DONGKIL KIM", "010-8765-4321", 20000101 });
	data_manager->addEmployee({ 00000004, "KILDONG", "HONG", CareerLevel::CL1, 1234, 5678, 1999, 12, 31, CERTI::ADV, "KILDONG HONG", "010-1234-5678", 19991231 });
}

TEST(dataManagerTest, AddEmployeeTest_RedundancyTest) {
	DataManager* data_manager = new DataManager();

	EXPECT_TRUE(data_manager->addEmployee({ 00000000, "KILDONG", "HONG", CareerLevel::CL1, 1234, 5678, 1999, 12, 31, CERTI::ADV, "KILDONG HONG", "010-1234-5678", 19991231 }));
	EXPECT_TRUE(data_manager->addEmployee({ 00000001, "DONGKIL", "KIM", CareerLevel::CL2, 8765, 4321, 2000, 01, 01, CERTI::PRO, "DONGKIL KIM", "010-8765-4321", 20000101 }));
	EXPECT_FALSE(data_manager->addEmployee({ 00000000, "KILDONG", "HONG", CareerLevel::CL1, 1234, 5678, 1999, 12, 31, CERTI::ADV, "KILDONG HONG", "010-1234-5678", 19991231 }));
}

TEST(dataManagerTest, DelEmployeeTest_Num) {
	DataManager* data_manager = new DataManager();
	input_test_data(data_manager);

	EXPECT_TRUE(data_manager->delEmployee({ "employeeNum", "00000000" }, { Option::NONE, Option::NONE }));
	EXPECT_TRUE(data_manager->delEmployee({ "employeeNum", "00000001" }, { Option::NONE, Option::NONE }));

	auto it = data_manager->employeeInfoMap.find(100000000 + 0);
	EXPECT_TRUE(it == data_manager->employeeInfoMap.end());
	it = data_manager->employeeInfoMap.find(100000000 + 1);
	EXPECT_TRUE(it == data_manager->employeeInfoMap.end());

	it = data_manager->employeeInfoMap.find(100000000 + 2);
	EXPECT_FALSE(it == data_manager->employeeInfoMap.end());
	it = data_manager->employeeInfoMap.find(100000000 + 3);
	EXPECT_FALSE(it == data_manager->employeeInfoMap.end());
	it = data_manager->employeeInfoMap.find(100000000 + 4);
	EXPECT_FALSE(it == data_manager->employeeInfoMap.end());
}
TEST(dataManagerTest, DelEmployeeTest_Name_Full) {
	DataManager* data_manager = new DataManager();
	input_test_data(data_manager);

	EXPECT_TRUE(data_manager->delEmployee({ "name", "KILDONG HONG" }, { Option::NONE, Option::NONE }));

	auto it = data_manager->nameMap.find("KILDONG HONG");
	EXPECT_TRUE(it == data_manager->nameMap.end());

	it = data_manager->nameMap.find("DONGKIL KIM");
	EXPECT_FALSE(it == data_manager->nameMap.end());

}
TEST(dataManagerTest, DelEmployeeTest_Name_Given) {
	DataManager* data_manager = new DataManager();
	input_test_data(data_manager);


	EXPECT_TRUE(data_manager->delEmployee({ "name", "KILDONG" }, { Option::NONE, Option::FIRST_YEAR }));

	auto it = data_manager->givenNameMap.find("KILDONG");
	EXPECT_TRUE(it == data_manager->givenNameMap.end());

	it = data_manager->givenNameMap.find("DONGKIL");
	EXPECT_FALSE(it == data_manager->givenNameMap.end());

}
TEST(dataManagerTest, DelEmployeeTest_Name_Family) {
	DataManager* data_manager = new DataManager();
	input_test_data(data_manager);

	EXPECT_TRUE(data_manager->delEmployee({ "name", "HONG" }, { Option::NONE, Option::LAST_DAY }));

	auto it = data_manager->familyNameMap.find("HONG");
	EXPECT_TRUE(it == data_manager->familyNameMap.end());

	it = data_manager->familyNameMap.find("KIM");
	EXPECT_FALSE(it == data_manager->familyNameMap.end());

}
TEST(dataManagerTest, DelEmployeeTest_Cl) {
	DataManager* data_manager = new DataManager();
	input_test_data(data_manager);

	EXPECT_TRUE(data_manager->delEmployee({ "cl", "CL1" }, { Option::NONE, Option::NONE }));

	auto it = data_manager->clMap.find(CareerLevel::CL1);
	EXPECT_TRUE(it == data_manager->clMap.end());

	it = data_manager->clMap.find(CareerLevel::CL2);
	EXPECT_FALSE(it == data_manager->clMap.end());

}
TEST(dataManagerTest, DelEmployeeTest_PhoneNum) {
	DataManager* data_manager = new DataManager();
	input_test_data(data_manager);

	EXPECT_TRUE(data_manager->delEmployee({ "phoneNum", "010-1234-5678" }, { Option::NONE, Option::NONE }));

	auto it = data_manager->phoneNumMap.find("010-1234-5678");
	EXPECT_TRUE(it == data_manager->phoneNumMap.end());

	it = data_manager->phoneNumMap.find("010-8765-4321");
	EXPECT_FALSE(it == data_manager->phoneNumMap.end());

}
TEST(dataManagerTest, DelEmployeeTest_PhoneNumMid) {
	DataManager* data_manager = new DataManager();
	input_test_data(data_manager);


	EXPECT_TRUE(data_manager->delEmployee({ "phoneNum", "1234" }, { Option::NONE, Option::MIDDLE_MONTH }));

	auto it = data_manager->phoneNumMidMap.find(1234);
	EXPECT_TRUE(it == data_manager->phoneNumMidMap.end());

	it = data_manager->phoneNumMidMap.find(8765);
	EXPECT_FALSE(it == data_manager->phoneNumMidMap.end());

}
TEST(dataManagerTest, DelEmployeeTest_PhoneNumEnd) {
	DataManager* data_manager = new DataManager();
	input_test_data(data_manager);


	EXPECT_TRUE(data_manager->delEmployee({ "phoneNum", "5678" }, { Option::NONE, Option::LAST_DAY }));

	auto it = data_manager->phoneNumEndMap.find(5678);
	EXPECT_TRUE(it == data_manager->phoneNumEndMap.end());

	it = data_manager->phoneNumEndMap.find(4321);
	EXPECT_FALSE(it == data_manager->phoneNumEndMap.end());

}
TEST(dataManagerTest, DelEmployeeTest_Birth) {
	DataManager* data_manager = new DataManager();
	input_test_data(data_manager);

	EXPECT_TRUE(data_manager->delEmployee({ "birthday", "19991231" }, { Option::NONE, Option::NONE }));

	auto it = data_manager->birthMap.find(19991231);
	EXPECT_TRUE(it == data_manager->birthMap.end());

	it = data_manager->birthMap.find(20000101);
	EXPECT_FALSE(it == data_manager->birthMap.end());
}
TEST(dataManagerTest, DelEmployeeTest_BirthYear) {
	DataManager* data_manager = new DataManager();
	input_test_data(data_manager);


	EXPECT_TRUE(data_manager->delEmployee({ "birthday", "1999" }, { Option::NONE, Option::FIRST_YEAR }));

	auto it = data_manager->birthYearMap.find(1999);
	EXPECT_TRUE(it == data_manager->birthYearMap.end());

	it = data_manager->birthYearMap.find(2000);
	EXPECT_FALSE(it == data_manager->birthYearMap.end());
}
TEST(dataManagerTest, DelEmployeeTest_BirthMonth) {
	DataManager* data_manager = new DataManager();
	input_test_data(data_manager);

	EXPECT_TRUE(data_manager->delEmployee({ "birthday", "12" }, { Option::NONE, Option::MIDDLE_MONTH }));

	auto it = data_manager->birthMonthMap.find(12);
	EXPECT_TRUE(it == data_manager->birthMonthMap.end());

	it = data_manager->birthMonthMap.find(01);
	EXPECT_FALSE(it == data_manager->birthMonthMap.end());
}
TEST(dataManagerTest, DelEmployeeTest_BirthDay) {
	DataManager* data_manager = new DataManager();
	input_test_data(data_manager);

	EXPECT_TRUE(data_manager->delEmployee({ "birthday", "31" }, { Option::NONE, Option::LAST_DAY }));

	auto it = data_manager->birthDayMap.find(31);
	EXPECT_TRUE(it == data_manager->birthDayMap.end());

	it = data_manager->birthDayMap.find(01);
	EXPECT_FALSE(it == data_manager->birthDayMap.end());
}
TEST(dataManagerTest, DelEmployeeTest_Certi) {
	DataManager* data_manager = new DataManager();
	input_test_data(data_manager);

	EXPECT_TRUE(data_manager->delEmployee({ "certi", "ADV" }, { Option::NONE, Option::NONE }));

	auto it = data_manager->certiMap.find(CERTI::ADV);
	EXPECT_TRUE(it == data_manager->certiMap.end());

	it = data_manager->certiMap.find(CERTI::PRO);
	EXPECT_FALSE(it == data_manager->certiMap.end());
}


TEST(dataManagerTest, SchEmployeeTest_Num) {
	DataManager* data_manager = new DataManager();
	input_test_data(data_manager);

	EXPECT_TRUE(data_manager->schEmployee({ "employeeNum", "00000000" }, { Option::NONE, Option::NONE }));
	EXPECT_TRUE(data_manager->schEmployee({ "employeeNum", "00000001" }, { Option::NONE, Option::NONE }));
	EXPECT_TRUE(data_manager->schEmployee({ "employeeNum", "00000006" }, { Option::NONE, Option::NONE }));
}
TEST(dataManagerTest, SchEmployeeTest_Name_Full) {
	DataManager* data_manager = new DataManager();
	input_test_data(data_manager);

	EXPECT_TRUE(data_manager->schEmployee({ "name", "KILDONG HONG" }, { Option::NONE, Option::NONE }));
	EXPECT_TRUE(data_manager->schEmployee({ "name", "DONGKIL KIM" }, { Option::NONE, Option::NONE }));
	EXPECT_TRUE(data_manager->schEmployee({ "name", "AAAAAAA AAAA" }, { Option::NONE, Option::NONE }));

}
TEST(dataManagerTest, SchEmployeeTest_Cl) {
	DataManager* data_manager = new DataManager();
	input_test_data(data_manager);

	EXPECT_TRUE(data_manager->schEmployee({ "cl", "CL1" }, { Option::NONE, Option::NONE }));
	EXPECT_TRUE(data_manager->schEmployee({ "cl", "CL2" }, { Option::NONE, Option::NONE }));
	EXPECT_TRUE(data_manager->schEmployee({ "cl", "CL3" }, { Option::NONE, Option::NONE }));

}
TEST(dataManagerTest, SchEmployeeTest_Phone) {
	DataManager* data_manager = new DataManager();
	input_test_data(data_manager);

	EXPECT_TRUE(data_manager->schEmployee({ "phoneNum", "010-1234-5678" }, { Option::NONE, Option::NONE }));
	EXPECT_TRUE(data_manager->schEmployee({ "phoneNum", "010-8765-4321" }, { Option::NONE, Option::NONE }));
	EXPECT_TRUE(data_manager->schEmployee({ "phoneNum", "010-0000-0000" }, { Option::NONE, Option::NONE }));

}
TEST(dataManagerTest, SchEmployeeTest_Birth) {
	DataManager* data_manager = new DataManager();
	input_test_data(data_manager);

	EXPECT_TRUE(data_manager->schEmployee({ "birthday", "19991231" }, { Option::NONE, Option::NONE }));
	EXPECT_TRUE(data_manager->schEmployee({ "birthday", "20000101" }, { Option::NONE, Option::NONE }));
	EXPECT_TRUE(data_manager->schEmployee({ "birthday", "20010615" }, { Option::NONE, Option::NONE }));

}
TEST(dataManagerTest, SchEmployeeTest_Certi) {
	DataManager* data_manager = new DataManager();
	input_test_data(data_manager);

	EXPECT_TRUE(data_manager->schEmployee({ "certi", "ADV" }, { Option::NONE, Option::NONE }));
	EXPECT_TRUE(data_manager->schEmployee({ "certi", "PRO" }, { Option::NONE, Option::NONE }));
	EXPECT_TRUE(data_manager->schEmployee({ "certi", "EX" }, { Option::NONE, Option::NONE }));

}


TEST(dataManagerTest, ModEmployeeTest_Num) {
	DataManager* data_manager = new DataManager();
	input_test_data(data_manager);

	EXPECT_TRUE(data_manager->modEmployee({ "employeeNum", "00000000" , "name", "DONGKIL KIM" }, { Option::NONE, Option::NONE }));
}
TEST(dataManagerTest, ModEmployeeTest_Name_Full) {
	DataManager* data_manager = new DataManager();
	input_test_data(data_manager);

	EXPECT_TRUE(data_manager->modEmployee({ "name", "KILDONG HONG", "cl", "CL2" }, { Option::NONE, Option::NONE }));
	EXPECT_TRUE(data_manager->modEmployee({ "name", "DONGKIL KIM", "cl", "CL1" }, { Option::NONE, Option::NONE }));
	EXPECT_TRUE(data_manager->modEmployee({ "name", "AAAAAAA AAAA", "cl", "CL3" }, { Option::NONE, Option::NONE }));
}
TEST(dataManagerTest, ModEmployeeTest_Cl) {
	DataManager* data_manager = new DataManager();
	input_test_data(data_manager);

	EXPECT_TRUE(data_manager->modEmployee({ "cl", "CL1", "phoneNum", "010-8765-4321" }, { Option::NONE, Option::NONE }));
	EXPECT_TRUE(data_manager->modEmployee({ "cl", "CL2", "phoneNum", "010-1234-5678" }, { Option::NONE, Option::NONE }));
	EXPECT_TRUE(data_manager->modEmployee({ "cl", "CL3", "phoneNum", "010-0000-0000" }, { Option::NONE, Option::NONE }));
}
TEST(dataManagerTest, ModEmployeeTest_Phone) {
	DataManager* data_manager = new DataManager();
	input_test_data(data_manager);

	EXPECT_TRUE(data_manager->modEmployee({ "phoneNum", "010-1234-5678", "birthday", "20000101" }, { Option::NONE, Option::NONE }));
	EXPECT_TRUE(data_manager->modEmployee({ "phoneNum", "010-8765-4321", "birthday", "19991231" }, { Option::NONE, Option::NONE }));
	EXPECT_TRUE(data_manager->modEmployee({ "phoneNum", "010-0000-0000", "birthday", "20010615" }, { Option::NONE, Option::NONE }));
}
TEST(dataManagerTest, ModEmployeeTest_Birth) {
	DataManager* data_manager = new DataManager();
	input_test_data(data_manager);

	EXPECT_TRUE(data_manager->modEmployee({ "birthday", "19991231", "certi", "PRO" }, { Option::NONE, Option::NONE }));
	EXPECT_TRUE(data_manager->modEmployee({ "birthday", "20000101", "certi", "ADV" }, { Option::NONE, Option::NONE }));
	EXPECT_TRUE(data_manager->modEmployee({ "birthday", "20010615", "certi", "EX" }, { Option::NONE, Option::NONE }));
}
TEST(dataManagerTest, ModEmployeeTest_Certi) {
	DataManager* data_manager = new DataManager();
	input_test_data(data_manager);

	EXPECT_TRUE(data_manager->modEmployee({ "certi", "ADV", "birthday", "20000101" }, { Option::NONE, Option::NONE }));
	EXPECT_TRUE(data_manager->modEmployee({ "certi", "PRO", "birthday", "19991231" }, { Option::NONE, Option::NONE }));
	EXPECT_TRUE(data_manager->modEmployee({ "certi", "EX", "birthday", "20010615" }, { Option::NONE, Option::NONE }));
}

