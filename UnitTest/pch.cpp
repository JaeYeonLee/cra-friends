//
// pch.cpp
//

#include "pch.h"
#include "../FriendsProject/employeeinfo.cpp"
#include "../FriendsProject/employeeManagement.cpp"
#include "../FriendsProject/commandParser.cpp"
#include "../FriendsProject/dataManager.cpp"
#include "../FriendsProject/search.cpp"
#include "../FriendsProject/printer.cpp"

void input_test_data(DataManager* data_manager) { // test iuput data for cmd run
	data_manager->addEmployee({ 00000000, "KILDONG", "HONG", CareerLevel::CL1, 1234, 5678, 1999, 12, 31, CERTI::ADV, "KILDONG HONG", "010-1234-5678", 19991231 });
	data_manager->addEmployee({ 00000001, "DONGKIL", "KIM", CareerLevel::CL2, 8765, 4321, 2000, 01, 01, CERTI::PRO, "DONGKIL KIM", "010-8765-4321", 20000101 });
	data_manager->addEmployee({ 00000002, "KILDONG", "HONG", CareerLevel::CL1, 1234, 5678, 1999, 12, 31, CERTI::ADV, "KILDONG HONG", "010-1234-5678", 19991231 });
	data_manager->addEmployee({ 00000003, "DONGKIL", "KIM", CareerLevel::CL2, 8765, 4321, 2000, 01, 01, CERTI::PRO, "DONGKIL KIM", "010-8765-4321", 20000101 });
	data_manager->addEmployee({ 00000004, "KILDONG", "HONG", CareerLevel::CL1, 1234, 5678, 1999, 12, 31, CERTI::ADV, "KILDONG HONG", "010-1234-5678", 19991231 });
}