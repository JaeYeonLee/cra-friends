#include "pch.h"
#include "../FriendsProject/employeeManagement.h"

TEST(employeeManagementTest, load_data) {
	EmployeeManagement* em = new EmployeeManagement();

	EXPECT_EQ(em->loadData("../FriendsProject/not_exist_file.txt"), -1);
	EXPECT_EQ(em->loadData("../FriendsProject/input_20_20.txt"), 40);
}

TEST(employeeManagementTest, prepare_command) {
	EmployeeManagement* em = new EmployeeManagement();

	int data_size = em->loadData("../FriendsProject/input_20_20.txt");
	ASSERT_EQ(data_size, 40);

	for (int i = 0; i < data_size; i++) {
		EXPECT_EQ(em->prepareCommand(i), 0);
	}
}
