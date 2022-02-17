#include "pch.h"

using namespace std;

TEST(employeeManagementTest, open_file) {
	EmployeeManagement* em = new EmployeeManagement();

	EXPECT_EQ(em->openFile("../FriendsProject/not_exist_file.txt", ""), -1);
	EXPECT_EQ(em->openFile("", ""), -1);
	EXPECT_EQ(em->openFile("../FriendsProject/input_20_20.txt", ""), 0);
}

TEST(employeeManagementTest, prepare_command) {
	EmployeeManagement* em = new EmployeeManagement();

	ASSERT_EQ(em->openFile("../FriendsProject/input_20_20.txt", ""), 0);
	int data_size = em->loadData();
	ASSERT_EQ(data_size, 40);

	for (int i = 0; i < data_size; i++) {
		EXPECT_EQ(em->prepareCommand(i), 0);
	}
}
