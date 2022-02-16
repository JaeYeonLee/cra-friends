#include "pch.h"
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

	EXPECT_EQ(1, data_manager->delEmployee({ "employeeNum", "00000000" }));
	EXPECT_EQ(1, data_manager->delEmployee({ "employeeNum", "00000001" }));
	EXPECT_EQ(0, data_manager->delEmployee({ "employeeNum", "00000000" }));
}
TEST(dataManagerTest, DelEmployeeTest_Name_Full) {
	DataManager* data_manager = new DataManager();
	input_test_data(data_manager);

	EXPECT_EQ(3, data_manager->delEmployee({ "name", "KILDONG HONG" }));
	EXPECT_EQ(2, data_manager->delEmployee({ "name", "DONGKIL KIM" }));
	EXPECT_EQ(0, data_manager->delEmployee({ "name", "KILDONG HONG" }));
}
TEST(dataManagerTest, DelEmployeeTest_Name_Given) {
	DataManager* data_manager = new DataManager();
	input_test_data(data_manager);

	EXPECT_EQ(3, data_manager->delEmployee({ "givenName", "KILDONG" }));
	EXPECT_EQ(2, data_manager->delEmployee({ "givenName", "DONGKIL" }));
	EXPECT_EQ(0, data_manager->delEmployee({ "givenName", "KILDONG" }));
}
TEST(dataManagerTest, DelEmployeeTest_Name_Family) {
	DataManager* data_manager = new DataManager();
	input_test_data(data_manager);

	EXPECT_EQ(3, data_manager->delEmployee({ "familyName", "HONG" }));
	EXPECT_EQ(2, data_manager->delEmployee({ "familyName", "KIM" }));
	EXPECT_EQ(0, data_manager->delEmployee({ "familyName", "HONG" }));
}
TEST(dataManagerTest, DelEmployeeTest_Cl) {
	DataManager* data_manager = new DataManager();
	input_test_data(data_manager);

	EXPECT_EQ(3, data_manager->delEmployee({ "cl", "1" }));
	EXPECT_EQ(2, data_manager->delEmployee({ "cl", "2" }));
	EXPECT_EQ(0, data_manager->delEmployee({ "cl", "1" }));
}
TEST(dataManagerTest, DelEmployeeTest_PhoneNum) {
	DataManager* data_manager = new DataManager();
	input_test_data(data_manager);

	EXPECT_EQ(3, data_manager->delEmployee({ "phoneNum", "010-1234-5678" }));
	EXPECT_EQ(2, data_manager->delEmployee({ "phoneNum", "010-8765-4321" }));
	EXPECT_EQ(0, data_manager->delEmployee({ "phoneNum", "010-1234-5678" }));
}
TEST(dataManagerTest, DelEmployeeTest_PhoneNumMid) {
	DataManager* data_manager = new DataManager();
	input_test_data(data_manager);

	EXPECT_EQ(3, data_manager->delEmployee({ "phoneNumMid", "1234" }));
	EXPECT_EQ(2, data_manager->delEmployee({ "phoneNumMid", "8765" }));
	EXPECT_EQ(0, data_manager->delEmployee({ "phoneNumMid", "1234" }));
}
TEST(dataManagerTest, DelEmployeeTest_PhoneNumEnd) {
	DataManager* data_manager = new DataManager();
	input_test_data(data_manager);

	EXPECT_EQ(3, data_manager->delEmployee({ "phoneNumEnd", "5678" }));
	EXPECT_EQ(2, data_manager->delEmployee({ "phoneNumEnd", "4321" }));
	EXPECT_EQ(0, data_manager->delEmployee({ "phoneNumEnd", "5678" }));
}
TEST(dataManagerTest, DelEmployeeTest_Birth) {
	DataManager* data_manager = new DataManager();
	input_test_data(data_manager);

	EXPECT_EQ(3, data_manager->delEmployee({ "birthday", "19991231" }));
	EXPECT_EQ(2, data_manager->delEmployee({ "birthday", "20000101" }));
	EXPECT_EQ(0, data_manager->delEmployee({ "birthday", "19991231" }));
}
TEST(dataManagerTest, DelEmployeeTest_BirthYear) {
	DataManager* data_manager = new DataManager();
	input_test_data(data_manager);

	EXPECT_EQ(3, data_manager->delEmployee({ "birthdayYear", "1999" }));
	EXPECT_EQ(2, data_manager->delEmployee({ "birthdayYear", "2000" }));
	EXPECT_EQ(0, data_manager->delEmployee({ "birthdayYear", "1999" }));
}
TEST(dataManagerTest, DelEmployeeTest_BirthMonth) {
	DataManager* data_manager = new DataManager();
	input_test_data(data_manager);

	EXPECT_EQ(3, data_manager->delEmployee({ "birthdayMonth", "12" }));
	EXPECT_EQ(2, data_manager->delEmployee({ "birthdayMonth", "01" }));
	EXPECT_EQ(0, data_manager->delEmployee({ "birthdayMonth", "12" }));
}
TEST(dataManagerTest, DelEmployeeTest_BirthDay) {
	DataManager* data_manager = new DataManager();
	input_test_data(data_manager);

	EXPECT_EQ(3, data_manager->delEmployee({ "birthdayDay", "31" }));
	EXPECT_EQ(2, data_manager->delEmployee({ "birthdayDay", "01" }));
	EXPECT_EQ(0, data_manager->delEmployee({ "birthdayDay", "31" }));
}
TEST(dataManagerTest, DelEmployeeTest_Certi) {
	DataManager* data_manager = new DataManager();
	input_test_data(data_manager);

	EXPECT_EQ(3, data_manager->delEmployee({ "certi", "ADV" }));
	EXPECT_EQ(2, data_manager->delEmployee({ "certi", "PRO" }));
	EXPECT_EQ(0, data_manager->delEmployee({ "certi", "ADV" }));
}


TEST(dataManagerTest, SchEmployeeTest_Num) {
	DataManager* data_manager = new DataManager();
	input_test_data(data_manager);

	EXPECT_EQ(1, data_manager->schEmployee({ "employeeNum", "00000000" }, { Option::NONE, Option::PRINT }));
	EXPECT_EQ(1, data_manager->schEmployee({ "employeeNum", "00000001" }, { Option::NONE, Option::PRINT }));
	EXPECT_EQ(0, data_manager->schEmployee({ "employeeNum", "00000006" }, { Option::NONE, Option::NONE }));
}
TEST(dataManagerTest, SchEmployeeTest_Name_Full) {
	DataManager* data_manager = new DataManager();
	input_test_data(data_manager);

	EXPECT_EQ(3, data_manager->schEmployee({ "name", "KILDONG HONG" }, { Option::NONE, Option::PRINT }));
	EXPECT_EQ(2, data_manager->schEmployee({ "name", "DONGKIL KIM" }, { Option::NONE, Option::PRINT }));
	EXPECT_EQ(0, data_manager->schEmployee({ "name", "AAAAAAA AAAA" }, { Option::NONE, Option::NONE }));
}
TEST(dataManagerTest, SchEmployeeTest_Cl) {
	DataManager* data_manager = new DataManager();
	input_test_data(data_manager);

	EXPECT_EQ(3, data_manager->schEmployee({ "cl", "1" }, { Option::NONE, Option::PRINT }));
	EXPECT_EQ(2, data_manager->schEmployee({ "cl", "2" }, { Option::NONE, Option::PRINT }));
	EXPECT_EQ(0, data_manager->schEmployee({ "cl", "3" }, { Option::NONE, Option::NONE }));
}
TEST(dataManagerTest, SchEmployeeTest_Phone) {
	DataManager* data_manager = new DataManager();
	input_test_data(data_manager);

	EXPECT_EQ(3, data_manager->schEmployee({ "phoneNum", "010-1234-5678" }, { Option::NONE, Option::PRINT }));
	EXPECT_EQ(2, data_manager->schEmployee({ "phoneNum", "010-8765-4321" }, { Option::NONE, Option::PRINT }));
	EXPECT_EQ(0, data_manager->schEmployee({ "phoneNum", "010-0000-0000" }, { Option::NONE, Option::NONE }));
}
TEST(dataManagerTest, SchEmployeeTest_Birth) {
	DataManager* data_manager = new DataManager();
	input_test_data(data_manager);

	EXPECT_EQ(3, data_manager->schEmployee({ "birthday", "19991231" }, { Option::NONE, Option::PRINT }));
	EXPECT_EQ(2, data_manager->schEmployee({ "birthday", "20000101" }, { Option::NONE, Option::PRINT }));
	EXPECT_EQ(0, data_manager->schEmployee({ "birthday", "20010615" }, { Option::NONE, Option::NONE }));
}
TEST(dataManagerTest, SchEmployeeTest_Certi) {
	DataManager* data_manager = new DataManager();
	input_test_data(data_manager);

	EXPECT_EQ(3, data_manager->schEmployee({ "certi", "ADV" }, { Option::NONE, Option::PRINT }));
	EXPECT_EQ(2, data_manager->schEmployee({ "certi", "PRO" }, { Option::NONE, Option::PRINT }));
	EXPECT_EQ(0, data_manager->schEmployee({ "certi", "EX" }, { Option::NONE, Option::NONE }));
}


TEST(dataManagerTest, ModEmployeeTest_Num) {
	DataManager* data_manager = new DataManager();
	input_test_data(data_manager);

	EXPECT_EQ(1, data_manager->modEmployee({ "employeeNum", "00000000" , "name", "DONGKIL KIM" }));
	EXPECT_EQ(1, data_manager->modEmployee({ "employeeNum", "00000001" , "name", "KILDONG HONG" }));
	EXPECT_EQ(0, data_manager->modEmployee({ "employeeNum", "00000006" , "name", "KILDONG HONG" }));
}
TEST(dataManagerTest, ModEmployeeTest_Name_Full) {
	DataManager* data_manager = new DataManager();
	input_test_data(data_manager);

	EXPECT_EQ(3, data_manager->modEmployee({ "name", "KILDONG HONG", "cl", "2" }));
	EXPECT_EQ(2, data_manager->modEmployee({ "name", "DONGKIL KIM", "cl", "1" }));
	EXPECT_EQ(0, data_manager->modEmployee({ "name", "AAAAAAA AAAA", "cl", "3" }));
}
TEST(dataManagerTest, ModEmployeeTest_Cl) {
	DataManager* data_manager = new DataManager();
	input_test_data(data_manager);

	EXPECT_EQ(3, data_manager->modEmployee({ "cl", "1", "phoneNum", "010-8765-4321" }));
	EXPECT_EQ(2, data_manager->modEmployee({ "cl", "2", "phoneNum", "010-1234-5678" }));
	EXPECT_EQ(0, data_manager->modEmployee({ "cl", "3", "phoneNum", "010-0000-0000" }));
}
TEST(dataManagerTest, ModEmployeeTest_Phone) {
	DataManager* data_manager = new DataManager();
	input_test_data(data_manager);

	EXPECT_EQ(3, data_manager->modEmployee({ "phoneNum", "010-1234-5678", "birthday", "20000101" }));
	EXPECT_EQ(2, data_manager->modEmployee({ "phoneNum", "010-8765-4321", "birthday", "19991231" }));
	EXPECT_EQ(0, data_manager->modEmployee({ "phoneNum", "010-0000-0000", "birthday", "20010615" }));
}
TEST(dataManagerTest, ModEmployeeTest_Birth) {
	DataManager* data_manager = new DataManager();
	input_test_data(data_manager);

	EXPECT_EQ(3, data_manager->modEmployee({ "birthday", "19991231", "certi", "PRO" }));
	EXPECT_EQ(2, data_manager->modEmployee({ "birthday", "20000101", "certi", "ADV" }));
	EXPECT_EQ(0, data_manager->modEmployee({ "birthday", "20010615", "certi", "EX" }));
}
TEST(dataManagerTest, ModEmployeeTest_Certi) {
	DataManager* data_manager = new DataManager();
	input_test_data(data_manager);

	EXPECT_EQ(3, data_manager->modEmployee({ "certi", "ADV", "birthday", "20000101" }));
	EXPECT_EQ(2, data_manager->modEmployee({ "certi", "PRO", "birthday", "19991231" }));
	EXPECT_EQ(0, data_manager->modEmployee({ "certi", "EX", "birthday", "20010615" }));
}

