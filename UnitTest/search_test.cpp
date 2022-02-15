#include "pch.h"
#include "../FriendsProject/search.h"


EmployeeInfo employees[1000];
SearchEngine searchEngine;
unordered_map<int, list<EmployeeInfo*>> hashTableInt;
unordered_map<string, list<EmployeeInfo*>> hashTableStr;
unordered_map<CERTI, list<EmployeeInfo*>> hashTableCerti;
TEST(SearchTest, SearchCareerLevel_NoResult) {
	EXPECT_EQ(nullptr, searchEngine.search(3, hashTableInt));
	EXPECT_EQ(nullptr, searchEngine.search(4, hashTableInt));
	
	hashTableInt[3].push_back(&employees[0]);

	EXPECT_EQ(nullptr, searchEngine.search(1, hashTableInt));
}

TEST(SearchTest, SearchCareerLevel_Result) {
	hashTableInt[3].push_back(&employees[0]);
	hashTableInt[3].push_back(&employees[1]);
	hashTableInt[3].push_back(&employees[2]);
	hashTableInt[4].push_back(&employees[3]);
	hashTableInt[4].push_back(&employees[4]);
	hashTableInt[2].push_back(&employees[5]);
	hashTableInt[2].push_back(&employees[6]);
	hashTableInt[2].push_back(&employees[7]);
	hashTableInt[2].push_back(&employees[8]);

	auto result = searchEngine.search(3, hashTableInt);
	EXPECT_NE(nullptr, result);
	if (result != nullptr) EXPECT_EQ(3, result->size());

	result = searchEngine.search(4, hashTableInt);
	EXPECT_NE(nullptr, result);
	if (result != nullptr) EXPECT_EQ(2, result->size());

	result = searchEngine.search(2, hashTableInt);
	EXPECT_NE(nullptr, result);
	if (result != nullptr) EXPECT_EQ(4, result->size());
}

TEST(SearchTest, SearchCerti_NoResult) {
	EXPECT_EQ(nullptr, searchEngine.search(CERTI::ADV, hashTableCerti));
	EXPECT_EQ(nullptr, searchEngine.search(CERTI::PRO, hashTableCerti));

	hashTableCerti[CERTI::ADV].push_back(&employees[0]);

	EXPECT_EQ(nullptr, searchEngine.search(CERTI::EX, hashTableCerti));
}

TEST(SearchTest, SearchCerti_Result) {
	hashTableCerti[CERTI::ADV].push_back(&employees[0]);
	hashTableCerti[CERTI::ADV].push_back(&employees[1]);
	hashTableCerti[CERTI::ADV].push_back(&employees[2]);
	hashTableCerti[CERTI::PRO].push_back(&employees[3]);
	hashTableCerti[CERTI::PRO].push_back(&employees[4]);
	hashTableCerti[CERTI::PRO].push_back(&employees[5]);
	hashTableCerti[CERTI::PRO].push_back(&employees[6]);
	hashTableCerti[CERTI::EX].push_back(&employees[7]);
	hashTableCerti[CERTI::EX].push_back(&employees[8]);

	auto result = searchEngine.search(CERTI::ADV, hashTableCerti);
	EXPECT_NE(nullptr, result);
	if (result != nullptr) EXPECT_EQ(3, result->size());

	result = searchEngine.search(CERTI::PRO, hashTableCerti);
	EXPECT_NE(nullptr, result);
	if (result != nullptr) EXPECT_EQ(4, result->size());

	result = searchEngine.search(CERTI::EX, hashTableCerti);
	EXPECT_NE(nullptr, result);
	if (result != nullptr) EXPECT_EQ(2, result->size());
}

TEST(SearchTest, SearchFullName_NoResult) {
	EXPECT_EQ(nullptr, searchEngine.search("Kim Samsung", hashTableStr));
	EXPECT_EQ(nullptr, searchEngine.search("Lee Jaeyeon", hashTableStr));

	hashTableStr["Kim Samsung"].push_back(&employees[0]);

	EXPECT_EQ(nullptr, searchEngine.search("Lee Jaeyeon", hashTableStr));
}

TEST(SearchTest, SearchFullName_Result) {
	hashTableStr["Kim Samsung"].push_back(&employees[0]);
	hashTableStr["Lee Jaeyeon"].push_back(&employees[1]);
	hashTableStr["Kim Samsung"].push_back(&employees[2]);
	hashTableStr["Choi King"].push_back(&employees[3]);

	auto result = searchEngine.search("Kim Samsung", hashTableStr);
	EXPECT_NE(nullptr, result);
	if (result != nullptr) EXPECT_EQ(2, result->size());

	result = searchEngine.search("Lee Jaeyeon", hashTableStr);
	EXPECT_NE(nullptr, result);
	if (result != nullptr) EXPECT_EQ(1, result->size());

	result = searchEngine.search("Choi King", hashTableStr);
	EXPECT_NE(nullptr, result);
	if (result != nullptr) EXPECT_EQ(1, result->size());
}

TEST(SearchTest, SearchGivenName_NoResult) {
	EXPECT_EQ(nullptr, searchEngine.search("Kim Samsung", hashTableStr));
	EXPECT_EQ(nullptr, searchEngine.search("Lee Jaeyeon", hashTableStr));

	hashTableStr["Kim Samsung"].push_back(&employees[0]);

	EXPECT_EQ(nullptr, searchEngine.search("Lee Jaeyeon", hashTableStr));

}

TEST(SearchTest, SearchGivenName_Result) {
	hashTableStr["Kim Samsung"].push_back(&employees[0]);
	hashTableStr["Lee Jaeyeon"].push_back(&employees[1]);
	hashTableStr["Kim Samsung"].push_back(&employees[2]);
	hashTableStr["Choi King"].push_back(&employees[3]);

	auto result = searchEngine.search("Kim Samsung", hashTableStr);
	EXPECT_NE(nullptr, result);
	if (result != nullptr) EXPECT_EQ(2, result->size());

	result = searchEngine.search("Lee Jaeyeon", hashTableStr);
	EXPECT_NE(nullptr, result);
	if (result != nullptr) EXPECT_EQ(1, result->size());

	result = searchEngine.search("Choi King", hashTableStr);
	EXPECT_NE(nullptr, result);
	if (result != nullptr) EXPECT_EQ(1, result->size());
}

TEST(SearchTest, SearchPhoneNumFull_NoResult) {
	EXPECT_EQ(nullptr, searchEngine.search(12345678, hashTableInt));

	hashTableInt[12345678].push_back(&employees[0]);

	EXPECT_EQ(nullptr, searchEngine.search(01020304, hashTableInt));
}

TEST(SearchTest, SearchPhoneNumFull_Result) {
	hashTableInt[12345678].push_back(&employees[0]);
	hashTableInt[00000000].push_back(&employees[1]);
	hashTableInt[99999999].push_back(&employees[2]);
	hashTableInt[12345678].push_back(&employees[3]);

	auto result = searchEngine.search(12345678, hashTableInt);
	EXPECT_NE(nullptr, result);
	if (result != nullptr) EXPECT_EQ(2, result->size());

	result = searchEngine.search(00000000, hashTableInt);
	EXPECT_NE(nullptr, result);
	if (result != nullptr) EXPECT_EQ(1, result->size());

	result = searchEngine.search(99999999, hashTableInt);
	EXPECT_NE(nullptr, result);
	if (result != nullptr) EXPECT_EQ(1, result->size());
}

TEST(SearchTest, SearchPhoneNumMiddle_NoResult) {
	EXPECT_EQ(nullptr, searchEngine.search(1234, hashTableInt));

	hashTableInt[1234].push_back(&employees[0]);

	EXPECT_EQ(nullptr, searchEngine.search(0000, hashTableInt));
}

TEST(SearchTest, SearchPhoneNumMiddle_Result) {
	hashTableInt[1234].push_back(&employees[0]);
	hashTableInt[0000].push_back(&employees[1]);
	hashTableInt[9999].push_back(&employees[2]);
	hashTableInt[0000].push_back(&employees[3]);

	auto result = searchEngine.search(1234, hashTableInt);
	EXPECT_NE(nullptr, result);
	if (result != nullptr) EXPECT_EQ(1, result->size());

	result = searchEngine.search(0000, hashTableInt);
	EXPECT_NE(nullptr, result);
	if (result != nullptr) EXPECT_EQ(2, result->size());

	result = searchEngine.search(9999, hashTableInt);
	EXPECT_NE(nullptr, result);
	if (result != nullptr) EXPECT_EQ(1, result->size());
}

TEST(SearchTest, SearchBirthFull_NoResult) {
	EXPECT_EQ(nullptr, searchEngine.search(19900101, hashTableInt));

	hashTableInt[19900101].push_back(&employees[0]);

	EXPECT_EQ(nullptr, searchEngine.search(20020202, hashTableInt));
}

TEST(SearchTest, SearchBirthFull_Result) {
	hashTableInt[19000101].push_back(&employees[0]);
	hashTableInt[20021231].push_back(&employees[1]);
	hashTableInt[20021231].push_back(&employees[2]);
	hashTableInt[19950505].push_back(&employees[3]);

	auto result = searchEngine.search(19900101, hashTableInt);
	EXPECT_NE(nullptr, result);
	if (result != nullptr) EXPECT_EQ(1, result->size());

	result = searchEngine.search(20021231, hashTableInt);
	EXPECT_NE(nullptr, result);
	if (result != nullptr) EXPECT_EQ(2, result->size());

	result = searchEngine.search(19950505, hashTableInt);
	EXPECT_NE(nullptr, result);
	if (result != nullptr) EXPECT_EQ(1, result->size());
}

TEST(SearchTest, SearchBirthDay_NoResult) {
	EXPECT_EQ(nullptr, searchEngine.search(01, hashTableInt));

	hashTableInt[01].push_back(&employees[0]);

	EXPECT_EQ(nullptr, searchEngine.search(31, hashTableInt));
}

TEST(SearchTest, SearchBirthDay_Result) {
	hashTableInt[01].push_back(&employees[0]);
	hashTableInt[20].push_back(&employees[1]);
	hashTableInt[20].push_back(&employees[2]);
	hashTableInt[31].push_back(&employees[3]);

	auto result = searchEngine.search(01, hashTableInt);
	EXPECT_NE(nullptr, result);
	if (result != nullptr) EXPECT_EQ(1, result->size());

	result = searchEngine.search(20, hashTableInt);
	EXPECT_NE(nullptr, result);
	if (result != nullptr) EXPECT_EQ(2, result->size());

	result = searchEngine.search(31, hashTableInt);
	EXPECT_NE(nullptr, result);
	if (result != nullptr) EXPECT_EQ(1, result->size());
}
