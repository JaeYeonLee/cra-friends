#include "pch.h"
#include "../FriendsProject/CommandParser.h"
#include "../FriendsProject/employeeManagement.h"

TEST(CommandParserTest, parse_data) {
	EmployeeManagement* em = new EmployeeManagement();
	CommandParser* cp = new CommandParser();

	ASSERT_EQ(em->loadData("../FriendsProject/input_20_20.txt"), 40);
	EXPECT_EQ(cp->parseData(em->readLine[0]), CommandType::ADD);
	EXPECT_EQ(cp->parseData(em->readLine[21]), CommandType::MOD);
	EXPECT_EQ(cp->parseData(em->readLine[22]), CommandType::SCH);
	EXPECT_EQ(cp->parseData(em->readLine[23]), CommandType::DEL);
}

TEST(CommandParserTest, parse_add) {
	EmployeeManagement* em = new EmployeeManagement();
	CommandParser* cp = new CommandParser();
	EmployeeInfo* addInfo = new EmployeeInfo();

	ASSERT_EQ(em->loadData("../FriendsProject/input_20_20.txt"), 40);

	cp->parseData(em->readLine[0]);
	cp->parseAddCommand(addInfo);

	// ADD, , , ,15123099,VXIHXOTH JHOP,CL3,010-3112-2609,19771211,ADV
	EXPECT_EQ(addInfo->employeeNum, 15123099);
	EXPECT_EQ(addInfo->givenName, "VXIHXOTH");
	EXPECT_EQ(addInfo->familyName, "JHOP");
	EXPECT_EQ(addInfo->cl, CareerLevel::CL3);
	EXPECT_EQ(addInfo->phoneNumMid, 3112);
	EXPECT_EQ(addInfo->phoneNumEnd, 2609);
	EXPECT_EQ(addInfo->birthYear, 1977);
	EXPECT_EQ(addInfo->birthMonth, 12);
	EXPECT_EQ(addInfo->birthDay, 11);
	EXPECT_EQ(addInfo->certi, CERTI::ADV);
}

TEST(CommandParserTest, parse_mod) {
	EmployeeManagement* em = new EmployeeManagement();
	CommandParser* cp = new CommandParser();
	KeyInfo* keyInfo = new KeyInfo();

	ASSERT_EQ(em->loadData("../FriendsProject/input_20_20.txt"), 40);

	cp->parseData(em->readLine[21]);
	cp->parseModifyCommand(keyInfo);

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

	ASSERT_EQ(em->loadData("../FriendsProject/input_20_20.txt"), 40);

	cp->parseData(em->readLine[22]);
	cp->parseSearchCommand(keyInfo);

	// SCH, , , ,employeeNum,79110836
	EXPECT_EQ(keyInfo->searchKey, "employeeNum");
	EXPECT_EQ(keyInfo->searchKeyword, "79110836");
}

TEST(CommandParserTest, parse_sch) {
	EmployeeManagement* em = new EmployeeManagement();
	CommandParser* cp = new CommandParser();
	KeyInfo* keyInfo = new KeyInfo();

	ASSERT_EQ(em->loadData("../FriendsProject/input_20_20.txt"), 40);

	cp->parseData(em->readLine[23]);
	cp->parseDeleteCommand(keyInfo);

	// DEL, , , ,employeeNum,18115040
	EXPECT_EQ(keyInfo->searchKey, "employeeNum");
	EXPECT_EQ(keyInfo->searchKeyword, "18115040");
}