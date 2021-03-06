#include "pch.h"

TEST(dataManagerCMDTest, AddEmployeeTest_RedundancyTest) {
	DataManager* data_manager = new DataManager();

	EXPECT_EQ(0, data_manager->addEmployee({ 00000000, "KILDONG", "HONG", CareerLevel::CL1, 1234, 5678, 1999, 12, 31, CERTI::ADV, "KILDONG HONG", "010-1234-5678", 19991231 }));
	EXPECT_EQ(0, data_manager->addEmployee({ 00000001, "DONGKIL", "KIM", CareerLevel::CL2, 8765, 4321, 2000, 01, 01, CERTI::PRO, "DONGKIL KIM", "010-8765-4321", 20000101 }));
	EXPECT_EQ(-1, data_manager->addEmployee({ 00000000, "KILDONG", "HONG", CareerLevel::CL1, 1234, 5678, 1999, 12, 31, CERTI::ADV, "KILDONG HONG", "010-1234-5678", 19991231 }));
}

TEST(dataManagerCMDTest, DelEmployeeTest_Num) {
	Printer* p = new Printer();
	DataManager* data_manager = new DataManager(p);
	input_test_data(data_manager);

	EXPECT_EQ(0, data_manager->delEmployee({ "employeeNum", "00000000" }, { Option::NONE, Option::NONE }));
	EXPECT_EQ(0, data_manager->delEmployee({ "employeeNum", "00000001" }, { Option::NONE, Option::NONE }));

	auto it = data_manager->getIntHashMap(SearchKey::EMPLOYEENUM);

	auto iter = it->find(0);
	EXPECT_TRUE(iter == it->end());
	iter = it->find(1);
	EXPECT_TRUE(iter == it->end());

	iter = it->find(2);
	EXPECT_FALSE(iter == it->end());
	iter = it->find(3);
	EXPECT_FALSE(iter == it->end());
	iter = it->find(4);
	EXPECT_FALSE(iter == it->end());
}
TEST(dataManagerCMDTest, DelEmployeeTest_Name_Full) {
	Printer* p = new Printer();
	DataManager* data_manager = new DataManager(p);
	input_test_data(data_manager);

	EXPECT_EQ(0, data_manager->delEmployee({ "name", "KILDONG HONG" }, { Option::NONE, Option::NONE }));

	auto it = data_manager->getStringHashMap(SearchKey::NAME);

	auto iter = it->find("KILDONG HONG");
	EXPECT_TRUE(iter == it->end());

	iter = it->find("DONGKIL KIM");
	EXPECT_FALSE(iter == it->end());

}
TEST(dataManagerCMDTest, DelEmployeeTest_Name_First) {
	Printer* p = new Printer();
	DataManager* data_manager = new DataManager(p);
	input_test_data(data_manager);

	EXPECT_EQ(0, data_manager->delEmployee({ "name_First", "KILDONG" }, { Option::NONE, Option::FIRST_YEAR }));

	auto it = data_manager->getStringHashMap(SearchKey::NAME_FIRST);

	auto iter = it->find("KILDONG");
	EXPECT_TRUE(iter == it->end());

	iter = it->find("DONGKIL");
	EXPECT_FALSE(iter == it->end());
}
TEST(dataManagerCMDTest, DelEmployeeTest_Name_Last) {
	Printer* p = new Printer();
	DataManager* data_manager = new DataManager(p);
	input_test_data(data_manager);

	EXPECT_EQ(0, data_manager->delEmployee({ "name_Last", "HONG" }, { Option::NONE, Option::LAST_DAY }));

	auto it = data_manager->getStringHashMap(SearchKey::NAME_LAST);

	auto iter = it->find("HONG");
	EXPECT_TRUE(iter == it->end());

	iter = it->find("KIM");
	EXPECT_FALSE(iter == it->end());
}
TEST(dataManagerCMDTest, DelEmployeeTest_Cl) {
	Printer* p = new Printer();
	DataManager* data_manager = new DataManager(p);
	input_test_data(data_manager);

	EXPECT_EQ(0, data_manager->delEmployee({ "cl", "CL1" }, { Option::NONE, Option::NONE }));

	auto it = data_manager->getClHashMap();

	auto iter = it->find(CareerLevel::CL1);
	EXPECT_TRUE(iter == it->end());

	iter = it->find(CareerLevel::CL2);
	EXPECT_FALSE(iter == it->end());
}
TEST(dataManagerCMDTest, DelEmployeeTest_PhoneNum) {
	Printer* p = new Printer();
	DataManager* data_manager = new DataManager(p);
	input_test_data(data_manager);

	EXPECT_EQ(0, data_manager->delEmployee({ "phoneNum", "010-1234-5678" }, { Option::NONE, Option::NONE }));

	auto it = data_manager->getStringHashMap(SearchKey::PHONENUM);

	auto iter = it->find("010-1234-5678");
	EXPECT_TRUE(iter == it->end());

	iter = it->find("010-8765-4321");
	EXPECT_FALSE(iter == it->end());
}
TEST(dataManagerCMDTest, DelEmployeeTest_PhoneNumMid) {
	Printer* p = new Printer();
	DataManager* data_manager = new DataManager(p);
	input_test_data(data_manager);

	EXPECT_EQ(0, data_manager->delEmployee({ "phoneNum_Mid", "1234" }, { Option::NONE, Option::MIDDLE_MONTH }));

	auto it = data_manager->getIntHashMap(SearchKey::PHONENUM_MID);

	auto iter = it->find(1234);
	EXPECT_TRUE(iter == it->end());

	iter = it->find(8765);
	EXPECT_FALSE(iter == it->end());
}
TEST(dataManagerCMDTest, DelEmployeeTest_PhoneNumEnd) {
	Printer* p = new Printer();
	DataManager* data_manager = new DataManager(p);
	input_test_data(data_manager);

	EXPECT_EQ(0, data_manager->delEmployee({ "phoneNum_End", "5678" }, { Option::NONE, Option::LAST_DAY }));

	auto it = data_manager->getIntHashMap(SearchKey::PHONENUM_END);

	auto iter = it->find(5678);
	EXPECT_TRUE(iter == it->end());

	iter = it->find(4321);
	EXPECT_FALSE(iter == it->end());
}
TEST(dataManagerCMDTest, DelEmployeeTest_Birth) {
	Printer* p = new Printer();
	DataManager* data_manager = new DataManager(p);
	input_test_data(data_manager);

	EXPECT_EQ(0, data_manager->delEmployee({ "birthday", "19991231" }, { Option::NONE, Option::NONE }));

	auto it = data_manager->getIntHashMap(SearchKey::BIRTH);

	auto iter = it->find(19991231);
	EXPECT_TRUE(iter == it->end());

	iter = it->find(20000101);
	EXPECT_FALSE(iter == it->end());
}
TEST(dataManagerCMDTest, DelEmployeeTest_BirthYear) {
	Printer* p = new Printer();
	DataManager* data_manager = new DataManager(p);
	input_test_data(data_manager);

	EXPECT_EQ(0, data_manager->delEmployee({ "birthday_Year", "1999" }, { Option::NONE, Option::FIRST_YEAR }));

	auto it = data_manager->getIntHashMap(SearchKey::BIRTH_YEAR);

	auto iter = it->find(1999);
	EXPECT_TRUE(iter == it->end());

	iter = it->find(2000);
	EXPECT_FALSE(iter == it->end());
}
TEST(dataManagerCMDTest, DelEmployeeTest_BirthMonth) {
	Printer* p = new Printer();
	DataManager* data_manager = new DataManager(p);
	input_test_data(data_manager);

	EXPECT_EQ(0, data_manager->delEmployee({ "birthday_Month", "12" }, { Option::NONE, Option::MIDDLE_MONTH }));

	auto it = data_manager->getIntHashMap(SearchKey::BIRTH_MOHTH);

	auto iter = it->find(12);
	EXPECT_TRUE(iter == it->end());

	iter = it->find(1);
	EXPECT_FALSE(iter == it->end());
}
TEST(dataManagerCMDTest, DelEmployeeTest_BirthDay) {
	Printer* p = new Printer();
	DataManager* data_manager = new DataManager(p);
	input_test_data(data_manager);

	EXPECT_EQ(0, data_manager->delEmployee({ "birthday_Day", "31" }, { Option::NONE, Option::LAST_DAY }));

	auto it = data_manager->getIntHashMap(SearchKey::BIRTH_DAY);

	auto iter = it->find(31);
	EXPECT_TRUE(iter == it->end());

	iter = it->find(1);
	EXPECT_FALSE(iter == it->end());
}
TEST(dataManagerCMDTest, DelEmployeeTest_Certi) {
	Printer* p = new Printer();
	DataManager* data_manager = new DataManager(p);
	input_test_data(data_manager);

	EXPECT_EQ(0, data_manager->delEmployee({ "certi", "ADV" }, { Option::NONE, Option::NONE }));

	auto it = data_manager->getCertiHashMap();

	auto iter = it->find(CERTI::ADV);
	EXPECT_TRUE(iter == it->end());

	iter = it->find(CERTI::PRO);
	EXPECT_FALSE(iter == it->end());
}


TEST(dataManagerCMDTest, SchEmployeeTest_Num) {
	Printer* p = new Printer();
	DataManager* data_manager = new DataManager(p);
	input_test_data(data_manager);

	EXPECT_EQ(0, data_manager->schEmployee({ "employeeNum", "00000000" }, { Option::NONE, Option::NONE }));
	EXPECT_EQ(0, data_manager->schEmployee({ "employeeNum", "00000001" }, { Option::NONE, Option::NONE }));
}
TEST(dataManagerCMDTest, SchEmployeeTest_Name_Full) {
	Printer* p = new Printer();
	DataManager* data_manager = new DataManager(p);
	input_test_data(data_manager);

	EXPECT_EQ(0, data_manager->schEmployee({ "name", "KILDONG HONG" }, { Option::NONE, Option::NONE }));
	EXPECT_EQ(0, data_manager->schEmployee({ "name", "DONGKIL KIM" }, { Option::NONE, Option::NONE }));

}
TEST(dataManagerCMDTest, SchEmployeeTest_Cl) {
	Printer* p = new Printer();
	DataManager* data_manager = new DataManager(p);
	input_test_data(data_manager);

	EXPECT_EQ(0, data_manager->schEmployee({ "cl", "CL1" }, { Option::NONE, Option::NONE }));
	EXPECT_EQ(0, data_manager->schEmployee({ "cl", "CL2" }, { Option::NONE, Option::NONE }));

}
TEST(dataManagerCMDTest, SchEmployeeTest_Phone) {
	Printer* p = new Printer();
	DataManager* data_manager = new DataManager(p);
	input_test_data(data_manager);

	EXPECT_EQ(0, data_manager->schEmployee({ "phoneNum", "010-1234-5678" }, { Option::NONE, Option::NONE }));
	EXPECT_EQ(0, data_manager->schEmployee({ "phoneNum", "010-8765-4321" }, { Option::NONE, Option::NONE }));

}
TEST(dataManagerCMDTest, SchEmployeeTest_Birth) {
	Printer* p = new Printer();
	DataManager* data_manager = new DataManager(p);
	input_test_data(data_manager);

	EXPECT_EQ(0, data_manager->schEmployee({ "birthday", "19991231" }, { Option::NONE, Option::NONE }));
	EXPECT_EQ(0, data_manager->schEmployee({ "birthday", "20000101" }, { Option::NONE, Option::NONE }));

}
TEST(dataManagerCMDTest, SchEmployeeTest_Certi) {
	Printer* p = new Printer();
	DataManager* data_manager = new DataManager(p);
	input_test_data(data_manager);

	EXPECT_EQ(0, data_manager->schEmployee({ "certi", "ADV" }, { Option::NONE, Option::NONE }));
	EXPECT_EQ(0, data_manager->schEmployee({ "certi", "PRO" }, { Option::NONE, Option::NONE }));

}


TEST(dataManagerCMDTest, ModEmployeeTest_Num) {
	Printer* p = new Printer();
	DataManager* data_manager = new DataManager(p);
	input_test_data(data_manager);

	EXPECT_EQ(0, data_manager->modEmployee({ "employeeNum", "00000000" , "name", "DONGKIL KIM" }, { Option::NONE, Option::NONE }));
}
TEST(dataManagerCMDTest, ModEmployeeTest_Name_Full) {
	Printer* p = new Printer();
	DataManager* data_manager = new DataManager(p);
	input_test_data(data_manager);

	EXPECT_EQ(0, data_manager->modEmployee({ "name", "KILDONG HONG", "cl", "CL2" }, { Option::NONE, Option::NONE }));
	EXPECT_EQ(0, data_manager->modEmployee({ "name", "DONGKIL KIM", "cl", "CL1" }, { Option::NONE, Option::NONE }));
}
TEST(dataManagerCMDTest, ModEmployeeTest_Cl) {
	Printer* p = new Printer();
	DataManager* data_manager = new DataManager(p);
	input_test_data(data_manager);

	EXPECT_EQ(0, data_manager->modEmployee({ "cl", "CL1", "phoneNum", "010-8765-4321" }, { Option::NONE, Option::NONE }));
	EXPECT_EQ(0, data_manager->modEmployee({ "cl", "CL2", "phoneNum", "010-1234-5678" }, { Option::NONE, Option::NONE }));
}
TEST(dataManagerCMDTest, ModEmployeeTest_Phone) {
	Printer* p = new Printer();
	DataManager* data_manager = new DataManager(p);
	input_test_data(data_manager);

	EXPECT_EQ(0, data_manager->modEmployee({ "phoneNum", "010-1234-5678", "birthday", "20000101" }, { Option::NONE, Option::NONE }));
	EXPECT_EQ(0, data_manager->modEmployee({ "phoneNum", "010-8765-4321", "birthday", "19991231" }, { Option::NONE, Option::NONE }));
}
TEST(dataManagerCMDTest, ModEmployeeTest_Birth) {
	Printer* p = new Printer();
	DataManager* data_manager = new DataManager(p);
	input_test_data(data_manager);

	EXPECT_EQ(0, data_manager->modEmployee({ "birthday", "19991231", "certi", "PRO" }, { Option::NONE, Option::NONE }));
	EXPECT_EQ(0, data_manager->modEmployee({ "birthday", "20000101", "certi", "ADV" }, { Option::NONE, Option::NONE }));
}
TEST(dataManagerCMDTest, ModEmployeeTest_Certi) {
	Printer* p = new Printer();
	DataManager* data_manager = new DataManager(p);
	input_test_data(data_manager);

	EXPECT_EQ(0, data_manager->modEmployee({ "certi", "ADV", "birthday", "20000101" }, { Option::NONE, Option::NONE }));
	EXPECT_EQ(0, data_manager->modEmployee({ "certi", "PRO", "birthday", "19991231" }, { Option::NONE, Option::NONE }));
}


TEST(dataManagerCMDTest, DelEmployeeTest_PhoneNumMid_Sync) {
	Printer* p = new Printer();
	DataManager* data_manager = new DataManager(p);
	input_test_data(data_manager);
	auto InfoMap = data_manager->getEmployeeInfoMap();

	EXPECT_EQ(0, data_manager->delEmployee({ "phoneNum_Mid", "1234" }, { Option::NONE, Option::MIDDLE_MONTH }));
	auto iter_PhoneNumMid = data_manager->getIntHashMap(SearchKey::PHONENUM_MID);
	auto iter_targetPhoneNumMid = iter_PhoneNumMid->find(1234);
	EXPECT_TRUE(iter_targetPhoneNumMid == iter_PhoneNumMid->end());

	EXPECT_EQ(0, data_manager->schEmployee({ "phoneNum_End", "5678" }, { Option::NONE, Option::LAST_DAY }));
	auto iter_PhoneNumEnd = data_manager->getIntHashMap(SearchKey::PHONENUM_END);
	auto iter_targetPhoneNumMidt = iter_PhoneNumEnd->find(5678);
	EXPECT_TRUE(iter_targetPhoneNumMidt == iter_PhoneNumEnd->end());

}

TEST(dataManagerCMDTest, DelEmployeeTest_Name_Fist_Sync) {
	Printer* p = new Printer();
	DataManager* data_manager = new DataManager(p);
	input_test_data(data_manager);

	auto InfoMap = data_manager->getEmployeeInfoMap();

	EXPECT_EQ(0, data_manager->delEmployee({ "name_First", "KILDONG" }, { Option::NONE, Option::MIDDLE_MONTH }));

	auto iter_Name = data_manager->getStringHashMap(SearchKey::NAME_FIRST);
	auto iter_TargetName = iter_Name->find("KILDONG");
	EXPECT_TRUE(iter_TargetName == iter_Name->end());

	EXPECT_EQ(0, data_manager->schEmployee({ "phoneNum_End", "5678" }, { Option::NONE, Option::LAST_DAY }));
	auto iter_PhoneEnd = data_manager->getIntHashMap(SearchKey::PHONENUM_END);
	auto iter_TargetPhoneEnd = iter_PhoneEnd->find(5678);
	EXPECT_TRUE(iter_TargetPhoneEnd == iter_PhoneEnd->end());

}