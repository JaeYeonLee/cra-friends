#include "pch.h"

TEST(CommandParserTest, parse_data) {
	EmployeeManagement* em = new EmployeeManagement();
	CommandParser* cp = new CommandParser();

	ASSERT_EQ(em->openFile("../FriendsProject/input_20_20.txt", ""), 0);
	ASSERT_EQ(em->loadData(), 40);
	EXPECT_EQ(cp->parseData(em->readLine[0]), CommandType::ADD);
	EXPECT_EQ(cp->parseData(em->readLine[21]), CommandType::MOD);
	EXPECT_EQ(cp->parseData(em->readLine[22]), CommandType::SCH);
	EXPECT_EQ(cp->parseData(em->readLine[23]), CommandType::DEL);
}

TEST(CommandParserTest, parse_add) {
	EmployeeManagement* em = new EmployeeManagement();
	CommandParser* cp = new CommandParser();
	EmployeeInfo* addInfo = new EmployeeInfo();
	OptionInfo* optionInfo = new OptionInfo();

	ASSERT_EQ(em->openFile("../FriendsProject/input_20_20.txt", ""), 0);
	ASSERT_EQ(em->loadData(), 40);

	cp->parseData(em->readLine[0]);
	cp->parseAddCommand(addInfo);

	// ADD, , , ,15123099,VXIHXOTH JHOP,CL3,010-3112-2609,19771211,ADV
	EXPECT_EQ(addInfo->employeeNum, 15123099);
	EXPECT_EQ(addInfo->name_First, "VXIHXOTH");
	EXPECT_EQ(addInfo->name_Last, "JHOP");
	EXPECT_EQ(addInfo->cl, CareerLevel::CL3);
	EXPECT_EQ(addInfo->phoneNum_Mid, 3112);
	EXPECT_EQ(addInfo->phoneNum_End, 2609);
	EXPECT_EQ(addInfo->birthday_Year, 1977);
	EXPECT_EQ(addInfo->birthday_Month, 12);
	EXPECT_EQ(addInfo->birthday_Day, 11);
	EXPECT_EQ(addInfo->certi, CERTI::ADV);
	EXPECT_EQ(addInfo->name, "VXIHXOTH JHOP");
	EXPECT_EQ(addInfo->phoneNum, "010-3112-2609");
	EXPECT_EQ(addInfo->birthday, 19771211);
}

TEST(CommandParserTest, parse_mod) {
	EmployeeManagement* em = new EmployeeManagement();
	CommandParser* cp = new CommandParser();
	KeyInfo* keyInfo = new KeyInfo();
	OptionInfo* optionInfo = new OptionInfo();

	ASSERT_EQ(em->openFile("../FriendsProject/input_20_20.txt", ""), 0);
	ASSERT_EQ(em->loadData(), 40);

	cp->parseData(em->readLine[21]);
	cp->parseOption(optionInfo);
	cp->parseModifyCommand(keyInfo, optionInfo);

	// MOD,-p, , ,name,FB NTAWR,birthday,20050520
	EXPECT_EQ(keyInfo->searchKey, "name");
	EXPECT_EQ(keyInfo->searchKeyword, "FB NTAWR");
	EXPECT_EQ(keyInfo->modifyKey, "birthday");
	EXPECT_EQ(keyInfo->modifyKeyword, "20050520");
}

TEST(CommandParserTest, parse_del) {
	EmployeeManagement* em = new EmployeeManagement();
	CommandParser* cp = new CommandParser();
	KeyInfo* keyInfo = new KeyInfo();
	OptionInfo* optionInfo = new OptionInfo();

	ASSERT_EQ(em->openFile("../FriendsProject/input_20_20.txt", ""), 0);
	ASSERT_EQ(em->loadData(), 40);

	cp->parseData(em->readLine[22]);
	cp->parseOption(optionInfo);
	cp->parseSearchCommand(keyInfo, optionInfo);

	// SCH, , , ,employeeNum,79110836
	EXPECT_EQ(keyInfo->searchKey, "employeeNum");
	EXPECT_EQ(keyInfo->searchKeyword, "79110836");
}

TEST(CommandParserTest, parse_sch) {
	EmployeeManagement* em = new EmployeeManagement();
	CommandParser* cp = new CommandParser();
	KeyInfo* keyInfo = new KeyInfo();
	OptionInfo* optionInfo = new OptionInfo();

	ASSERT_EQ(em->openFile("../FriendsProject/input_20_20.txt", ""), 0);
	ASSERT_EQ(em->loadData(), 40);

	cp->parseData(em->readLine[23]);
	cp->parseOption(optionInfo);
	cp->parseDeleteCommand(keyInfo, optionInfo);

	// DEL, , , ,employeeNum,18115040
	EXPECT_EQ(keyInfo->searchKey, "employeeNum");
	EXPECT_EQ(keyInfo->searchKeyword, "18115040");
}


TEST(CommandParserTest, parse_option) {
	EmployeeManagement* em = new EmployeeManagement();
	CommandParser* cp = new CommandParser();
	KeyInfo* keyInfo = new KeyInfo();
	OptionInfo* optionInfo = new OptionInfo();

	ASSERT_EQ(em->openFile("../FriendsProject/input_20_20.txt", ""), 0);
	ASSERT_EQ(em->loadData(), 40);

	cp->parseData(em->readLine[20]);
	cp->parseOption(optionInfo);
	cp->parseSearchCommand(keyInfo, optionInfo);

	// SCH,-p,-d, ,birthday,04
	EXPECT_EQ(keyInfo->searchKey, "birthday_Day");
	EXPECT_EQ(keyInfo->searchKeyword, "04");

	cp->parseData(em->readLine[24]);
	cp->parseOption(optionInfo);
	cp->parseDeleteCommand(keyInfo, optionInfo);

	// DEL,-p,-l, ,name,MPOSXU
	EXPECT_EQ(keyInfo->searchKey, "name_Last");
	EXPECT_EQ(keyInfo->searchKeyword, "MPOSXU");

	cp->parseData(em->readLine[28]);
	cp->parseOption(optionInfo);
	cp->parseSearchCommand(keyInfo, optionInfo);

	// SCH, ,-m, ,birthday,09
	EXPECT_EQ(keyInfo->searchKey, "birthday_Month");
	EXPECT_EQ(keyInfo->searchKeyword, "09");

	cp->parseData(em->readLine[31]);
	cp->parseOption(optionInfo);
	cp->parseSearchCommand(keyInfo, optionInfo);

	// SCH,-p,-y, ,birthday,2003
	EXPECT_EQ(keyInfo->searchKey, "birthday_Year");
	EXPECT_EQ(keyInfo->searchKeyword, "2003");

	cp->parseData(em->readLine[33]);
	cp->parseOption(optionInfo);
	cp->parseSearchCommand(keyInfo, optionInfo);

	// SCH,-p,-m, ,phoneNum,3112
	EXPECT_EQ(keyInfo->searchKey, "phoneNum_Mid");
	EXPECT_EQ(keyInfo->searchKeyword, "3112");

	cp->parseData(em->readLine[34]);
	cp->parseOption(optionInfo);
	cp->parseSearchCommand(keyInfo, optionInfo);

	// SCH,-p,-l, ,phoneNum,4605
	EXPECT_EQ(keyInfo->searchKey, "phoneNum_End");
	EXPECT_EQ(keyInfo->searchKeyword, "4605");

	cp->parseData(em->readLine[37]);
	cp->parseOption(optionInfo);
	cp->parseSearchCommand(keyInfo, optionInfo);

	// SCH, ,-f, ,name,LDEXRI
	EXPECT_EQ(keyInfo->searchKey, "name_First");
	EXPECT_EQ(keyInfo->searchKeyword, "LDEXRI");
}

TEST(CommandParserTest, parse_addmodule) {
	EmployeeManagement* em = new EmployeeManagement();
	CommandParser* cp = new CommandParser();
	EmployeeInfo* addInfo = new EmployeeInfo();
	OptionInfo* optionInfo = new OptionInfo();
	DataManager* dm = new DataManager();

	ASSERT_EQ(em->openFile("../FriendsProject/input_20_20.txt", ""), 0);
	ASSERT_EQ(em->loadData(), 40);

	cp->parseData(em->readLine[0]);
	cp->parseAddCommand(addInfo);
	dm->addEmployee(*addInfo);

	// ADD, , , ,15123099,VXIHXOTH JHOP,CL3,010-3112-2609,19771211,ADV
	auto iter = dm->getIntHashMap(SearchKey::EMPLOYEENUM);
	auto it = iter->find(15123099);
	ASSERT_TRUE(it != iter->end());
	EmployeeInfo* employee = &dm->employeePool[0];
	
	EXPECT_EQ(employee->employeeNum, 15123099);
	EXPECT_EQ(employee->name_First, "VXIHXOTH");
	EXPECT_EQ(employee->name_Last, "JHOP");
	EXPECT_EQ(employee->cl, CareerLevel::CL3);
	EXPECT_EQ(employee->phoneNum_Mid, 3112);
	EXPECT_EQ(employee->phoneNum_End, 2609);
	EXPECT_EQ(employee->birthday_Year, 1977);
	EXPECT_EQ(employee->birthday_Month, 12);
	EXPECT_EQ(employee->birthday_Day, 11);
	EXPECT_EQ(employee->certi, CERTI::ADV);
	EXPECT_EQ(employee->name, "VXIHXOTH JHOP");
	EXPECT_EQ(employee->phoneNum, "010-3112-2609");
	EXPECT_EQ(employee->birthday, 19771211);
}
