#include "pch.h"
#include "../FriendsProject/printer.cpp"
#include "../FriendsProject/dataManager.h"
#include "../FriendsProject/search.h"
#include <iostream>

Printer printer;
DataManager* data_manager;

extern void input_test_data(DataManager* data_manager);

TEST(PrintTest, StringFunctionTestwithInvalidData) {
	EXPECT_EQ(-1, printer.setResultData(CommandType::ADD, nullptr, Option::NONE));
	EXPECT_EQ("", printer.getResultString());

	EXPECT_EQ(0, printer.setResultData(CommandType::MOD, nullptr, Option::NONE));
	EXPECT_EQ("MOD,NONE\n", printer.getResultString());
	EXPECT_EQ(0, printer.setResultData(CommandType::MOD, nullptr, Option::PRINT));
	EXPECT_EQ("MOD,NONE\n", printer.getResultString());
}

TEST(PrintTest, StringFunctionTestwithValidData) {
	data_manager = new DataManager();
	input_test_data(data_manager);

	list<EmployeeInfo*> testList;
	testList.push_back(&data_manager->employeePool[0]);
	
	EXPECT_EQ(1, printer.setResultData(CommandType::DEL, &testList, Option::NONE));
	EXPECT_EQ("DEL,1\n", printer.getResultString());

	string printResult = "DEL,00000000,KILDONG HONG,CL1,010-1234-5678,19991231,ADV\n";
	EXPECT_EQ(1, printer.setResultData(CommandType::DEL, &testList, Option::PRINT));
	EXPECT_EQ(printResult, printer.getResultString());

	testList.push_back(&data_manager->employeePool[1]);
	testList.push_back(&data_manager->employeePool[2]);

	EXPECT_EQ(3, printer.setResultData(CommandType::SCH, &testList, Option::NONE));
	EXPECT_EQ("SCH,3\n", printer.getResultString());

	printResult = "SCH,00000000,KILDONG HONG,CL1,010-1234-5678,19991231,ADV\nSCH,00000001,DONGKIL KIM,CL2,010-8765-4321,20000101,PRO\nSCH,00000002,KILDONG HONG,CL1,010-1234-5678,19991231,ADV\n";
	EXPECT_EQ(3, printer.setResultData(CommandType::SCH, &testList, Option::PRINT));
	EXPECT_EQ(printResult, printer.getResultString());
}
TEST(PrintTest, DELwithoutOption) {
	data_manager = new DataManager();
	input_test_data(data_manager);
	
	list<EmployeeInfo*>* result = nullptr;
	//result =  data_manager->schEmployee({ "employeeNum", "00000000" }); 

	string resultString = "DEL,1\n";
	cout << resultString;
	printer.setResultData(CommandType::DEL, result, Option::NONE);

	if (result != nullptr)
		EXPECT_EQ(resultString, printer.getResultString());
	else {
		EXPECT_TRUE(false);
		cout << "failed to get employeeInfo\n";
	}
}

TEST(PrintTest, DELwithOption) {
	data_manager = new DataManager();
	input_test_data(data_manager);

	list<EmployeeInfo*>* result = nullptr;
	//result =  data_manager->schEmployee({ "employeeNum", "00000000" }); 

	string resultString = "DEL,00000000,KILDONG HONG,CL1,010-1234-5678,19991231,ADV\n";
	cout << resultString;

	printer.setResultData(CommandType::DEL, result, Option::PRINT);

	if (result != nullptr)
		EXPECT_EQ(resultString, printer.getResultString());
	else {
		EXPECT_TRUE(false);
		cout << "failed to get employeeInfo\n";
	}
}

TEST(PrintTest, DELwithOptionNoResult) {
	data_manager = new DataManager();
	input_test_data(data_manager);

	list<EmployeeInfo*>* result = nullptr;
	//result =  data_manager->schEmployee({ "employeeNum", "99999999" }); 

	string resultString = "DEL,NONE\n";
	cout << resultString;

	printer.setResultData(CommandType::DEL, result, Option::PRINT);

	if (result != nullptr)
		EXPECT_EQ(resultString, printer.getResultString());
	else {
		EXPECT_TRUE(false);
		cout << "failed to get employeeInfo\n";
	}
}

TEST(PrintTest, MODwithoutOption) {
	data_manager = new DataManager();
	input_test_data(data_manager);

	list<EmployeeInfo*>* result = nullptr;
	//result =  data_manager->schEmployee({ "cl", "1" }); 

	string resultString = "MOD,3\n";
	cout << resultString;

	printer.setResultData(CommandType::MOD, result, Option::NONE);

	if (result != nullptr)
		EXPECT_EQ(resultString, printer.getResultString());
	else {
		EXPECT_TRUE(false);
		cout << "failed to get employeeInfo\n";
	}
}

TEST(PrintTest, MODwithOption) {
	data_manager = new DataManager();
	input_test_data(data_manager);

	list<EmployeeInfo*>* result = nullptr;
	//result =  data_manager->schEmployee({ "cl", "1" }); 

	string resultString = "MOD,00000000,KILDONG HONG,CL1,010-1234-5678,19991231,ADV\nMOD,00000002,KILDONG HONG,CL1,010-1234-5678,19991231,ADV\nMOD,00000004,KILDONG HONG,CL1,010-1234-5678,19991231,ADV\n";
	cout << resultString;

	printer.setResultData(CommandType::MOD, result, Option::PRINT);

	if (result != nullptr)
		EXPECT_EQ(resultString, printer.getResultString());
	else {
		EXPECT_TRUE(false);
		cout << "failed to get employeeInfo\n";
	}
}

TEST(PrintTest, MODwithOptionNoResult) {
	data_manager = new DataManager();
	input_test_data(data_manager);

	list<EmployeeInfo*>* result = nullptr;
	//result =  data_manager->schEmployee({ "cl", "4" }); 

	string resultString = "MOD,NONE\n";
	cout << resultString;

	printer.setResultData(CommandType::MOD, result, Option::PRINT);

	if (result != nullptr)
		EXPECT_EQ(resultString, printer.getResultString());
	else {
		EXPECT_TRUE(false);
		cout << "failed to get employeeInfo\n";
	}
}

TEST(PrintTest, SCHwithoutOption) {
	data_manager = new DataManager();
	input_test_data(data_manager);

	list<EmployeeInfo*>* result = nullptr;
	//result =  data_manager->schEmployee({ "familyname", "KIM" }); 

	string resultString = "SCH,2\n";
	cout << resultString;

	printer.setResultData(CommandType::SCH, result, Option::NONE);

	if (result != nullptr)
		EXPECT_EQ(resultString, printer.getResultString());
	else {
		EXPECT_TRUE(false);
		cout << "failed to get employeeInfo\n";
	}
}

TEST(PrintTest, SCHwithOption) {
	data_manager = new DataManager();
	input_test_data(data_manager);

	list<EmployeeInfo*>* result = nullptr;
	//result =  data_manager->schEmployee({ "familyname", "KIM" }); 

	string resultString = "SCH,00000001,DONGKIL KIM,CL2,010-8765-4321,20000101,ADV\nSCH,00000001,DONGKIL KIM,CL2,010-8765-4321,20000101,ADV\n";
	cout << resultString;

	printer.setResultData(CommandType::SCH, result, Option::PRINT);

	if (result != nullptr)
		EXPECT_EQ(resultString, printer.getResultString());
	else {
		EXPECT_TRUE(false);
		cout << "failed to get employeeInfo\n";
	}
}

TEST(PrintTest, SCHwithoutOptionNoResult) {
	data_manager = new DataManager();
	input_test_data(data_manager);

	list<EmployeeInfo*>* result = nullptr;
	//result =  data_manager->schEmployee({ "familyname", "LEE" }); 

	string resultString = "SCH,NONE\n";
	cout << resultString;

	printer.setResultData(CommandType::SCH, result, Option::NONE);

	if (result != nullptr)
		EXPECT_EQ(resultString, printer.getResultString());
	else {
		EXPECT_TRUE(false);
		cout << "failed to get employeeInfo\n";
	}
}
