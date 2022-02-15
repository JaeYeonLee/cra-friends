#include "pch.h"
#include "../FriendsProject/CommandParser.h"


TEST(CommandParserTest, load_data) {
	CommandParser* cp = new CommandParser();

	EXPECT_EQ(cp->loadData("../FriendsProject/not_exist_file.txt"), -1);
	EXPECT_EQ(cp->loadData("../FriendsProject/input_20_20.txt"), 0);
	EXPECT_EQ(cp->getDataLineCount(), 41);
}

TEST(CommandParserTest, parse_data) {
	CommandParser* cp = new CommandParser();
	cp->loadData("../FriendsProject/input_20_20.txt");

	EXPECT_EQ(cp->parseData(0), CommandType::ADD);
	EXPECT_EQ(cp->parseData(21), CommandType::MOD);
	EXPECT_EQ(cp->parseData(22), CommandType::SCH);
	EXPECT_EQ(cp->parseData(23), CommandType::DEL);
	EXPECT_EQ(cp->parseData(40), CommandType::INVALID);
}

TEST(CommandParserTest, parse_add) {
	CommandParser* cp = new CommandParser();
	cp->loadData("../FriendsProject/input_20_20.txt");

	cp->parseData(0);

	EmployeeInfo* info = cp->parseAddCommand();

	// ADD, , , ,15123099,VXIHXOTH JHOP,CL3,010-3112-2609,19771211,ADV
	EXPECT_EQ(info->employeeNum, 15123099);
	EXPECT_EQ(info->givenName, "VXIHXOTH");
	EXPECT_EQ(info->familyName, "JHOP");
	EXPECT_EQ(info->cl, 3);
	EXPECT_EQ(info->phoneNumMid, 3112);
	EXPECT_EQ(info->phoneNumEnd, 2609);
	EXPECT_EQ(info->birthYear, 1977);
	EXPECT_EQ(info->birthMonth, 12);
	EXPECT_EQ(info->birthDay, 11);
	EXPECT_EQ(info->certi, ADV);
}

TEST(CommandParserTest, parse_mod) {
	CommandParser* cp = new CommandParser();
	cp->loadData("../FriendsProject/input_20_20.txt");

	cp->parseData(21);

	KeyInfo* keyInfo = cp->parseModifyCommand();

	// MOD,-p, , ,name,FB NTAWR,birthday,20050520
	EXPECT_EQ(keyInfo->searchKey, "name");
	EXPECT_EQ(keyInfo->searchKeyword, "FB NTAWR");
	EXPECT_EQ(keyInfo->modifyKey, "birthday");
	EXPECT_EQ(keyInfo->modifyKeyword, "20050520");
}


TEST(CommandParserTest, parse_del) {
	CommandParser* cp = new CommandParser();
	cp->loadData("../FriendsProject/input_20_20.txt");

	cp->parseData(22);

	KeyInfo* keyInfo = cp->parseSearchCommand();

	// SCH, , , ,employeeNum,79110836
	EXPECT_EQ(keyInfo->searchKey, "employeeNum");
	EXPECT_EQ(keyInfo->searchKeyword, "79110836");
}

TEST(CommandParserTest, parse_sch) {
	CommandParser* cp = new CommandParser();
	cp->loadData("../FriendsProject/input_20_20.txt");

	cp->parseData(23);

	KeyInfo* keyInfo = cp->parseDeleteCommand();

	// DEL, , , ,employeeNum,18115040
	EXPECT_EQ(keyInfo->searchKey, "employeeNum");
	EXPECT_EQ(keyInfo->searchKeyword, "18115040");
}