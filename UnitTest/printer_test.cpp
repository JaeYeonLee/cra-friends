#include "pch.h"
#include <iostream>

//Printer printer;
//DataManager* data_manager;
//
//extern void input_test_data(DataManager* data_manager);
//
//TEST(PrintTest, DELwithoutOption) {
//	data_manager = new DataManager();
//	input_test_data(data_manager);
//	
//	list<EmployeeInfo*>* result = nullptr;
//	//result =  data_manager->schEmployee({ "employeeNum", "00000000" }); 
//
//	string resultString = "DEL,1";
//	cout << resultString + "\n";
//
//	if (result != nullptr)
//		EXPECT_EQ(resultString, printer.printResultwithoutOption(CommandType::DEL, result->size()));
//	else {
//		EXPECT_TRUE(false);
//		cout << "failed to get employeeInfo";
//	}
//}
//
//TEST(PrintTest, DELwithOption) {
//	data_manager = new DataManager();
//	input_test_data(data_manager);
//
//	list<EmployeeInfo*>* result = nullptr;
//	//result =  data_manager->schEmployee({ "employeeNum", "00000000" }); 
//
//	string resultString = "DEL,00000000,HONG KILDONG,CL1,010-1234-5678,19991231,ADV";
//	cout << resultString + "\n";
//
//	if (result != nullptr)
//		EXPECT_EQ(resultString, printer.printResultwithOption(CommandType::DEL, result));
//	else {
//		EXPECT_TRUE(false);
//		cout << "failed to get employeeInfo";
//	}
//}
//
//TEST(PrintTest, DELwithOptionNoResult) {
//	data_manager = new DataManager();
//	input_test_data(data_manager);
//
//	list<EmployeeInfo*>* result = nullptr;
//	//result =  data_manager->schEmployee({ "employeeNum", "99999999" }); 
//
//	string resultString = "DEL,NONE";
//	cout << resultString + "\n";
//
//	if (result != nullptr)
//		EXPECT_EQ(resultString, printer.printResultwithOption(CommandType::DEL, result));
//	else {
//		EXPECT_TRUE(false);
//		cout << "failed to get employeeInfo";
//	}
//}
//
//TEST(PrintTest, MODwithoutOption) {
//	data_manager = new DataManager();
//	input_test_data(data_manager);
//
//	list<EmployeeInfo*>* result = nullptr;
//	//result =  data_manager->schEmployee({ "cl", "1" }); 
//
//	string resultString = "MOD,3";
//	cout << resultString + "\n";
//
//	if (result != nullptr)
//		EXPECT_EQ(resultString, printer.printResultwithoutOption(CommandType::MOD, result->size()));
//	else {
//		EXPECT_TRUE(false);
//		cout << "failed to get employeeInfo";
//	}
//}
//
//TEST(PrintTest, MODwithOption) {
//	data_manager = new DataManager();
//	input_test_data(data_manager);
//
//	list<EmployeeInfo*>* result = nullptr;
//	//result =  data_manager->schEmployee({ "cl", "1" }); 
//
//	string resultString = "MOD,00000000,HONG KILDONG,CL1,010-1234-5678,19991231,ADV\n \
//							MOD,00000002,HONG KILDONG,CL1,010-1234-5678,19991231,ADV\n \
//							MOD,00000004,HONG KILDONG,CL1,010-1234-5678,19991231,ADV";
//	cout << resultString + "\n";
//
//	if (result != nullptr)
//		EXPECT_EQ(resultString, printer.printResultwithOption(CommandType::MOD, result));
//	else {
//		EXPECT_TRUE(false);
//		cout << "failed to get employeeInfo";
//	}
//}
//
//TEST(PrintTest, MODwithOptionNoResult) {
//	data_manager = new DataManager();
//	input_test_data(data_manager);
//
//	list<EmployeeInfo*>* result = nullptr;
//	//result =  data_manager->schEmployee({ "cl", "4" }); 
//
//	string resultString = "MOD,NONE";
//	cout << resultString + "\n";
//
//	if (result != nullptr)
//		EXPECT_EQ(resultString, printer.printResultwithOption(CommandType::MOD, result));
//	else {
//		EXPECT_TRUE(false);
//		cout << "failed to get employeeInfo";
//	}
//}
//
//TEST(PrintTest, SCHwithoutOption) {
//	data_manager = new DataManager();
//	input_test_data(data_manager);
//
//	list<EmployeeInfo*>* result = nullptr;
//	//result =  data_manager->schEmployee({ "familyname", "KIM" }); 
//
//	string resultString = "SCH,2";
//	cout << resultString + "\n";
//
//	if (result != nullptr)
//		EXPECT_EQ(resultString, printer.printResultwithoutOption(CommandType::SCH, result->size()));
//	else {
//		EXPECT_TRUE(false);
//		cout << "failed to get employeeInfo";
//	}
//}
//
//TEST(PrintTest, SCHwithOption) {
//	data_manager = new DataManager();
//	input_test_data(data_manager);
//
//	list<EmployeeInfo*>* result = nullptr;
//	//result =  data_manager->schEmployee({ "familyname", "KIM" }); 
//
//	string resultString = "SCH,00000001,KIM DONGKIL,CL2,010-8765-4321,20000101,ADV\n \
//							SCH,00000001,KIM DONGKIL,CL2,010-8765-4321,20000101,ADV";
//	cout << resultString + "\n";
//
//	if (result != nullptr)
//		EXPECT_EQ(resultString, printer.printResultwithOption(CommandType::SCH, result));
//	else {
//		EXPECT_TRUE(false);
//		cout << "failed to get employeeInfo";
//	}
//}
//
//TEST(PrintTest, SCHwithoutOptionNoResult) {
//	data_manager = new DataManager();
//	input_test_data(data_manager);
//
//	list<EmployeeInfo*>* result = nullptr;
//	//result =  data_manager->schEmployee({ "familyname", "LEE" }); 
//
//	string resultString = "SCH,NONE";
//	cout << resultString + "\n";
//
//	if (result != nullptr)
//		EXPECT_EQ(resultString, printer.printResultwithoutOption(CommandType::MOD, result->size()));
//	else {
//		EXPECT_TRUE(false);
//		cout << "failed to get employeeInfo";
//	}
//}
