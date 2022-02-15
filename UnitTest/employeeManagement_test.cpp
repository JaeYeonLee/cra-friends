#include "pch.h"
#include "../FriendsProject/employeeManagement.h"

TEST(employeeManagementTest, load_data) {
	EmployeeManagement* em = new EmployeeManagement();

	EXPECT_EQ(em->loadData("../FriendsProject/not_exist_file.txt"), -1);
	EXPECT_EQ(em->loadData("../FriendsProject/input_20_20.txt"), 40);
}
