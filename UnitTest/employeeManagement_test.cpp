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

TEST(employeeManagementTest, run_command) {
	EmployeeManagement* em = new EmployeeManagement();

	ASSERT_EQ(em->openFile("../FriendsProject/input_20_20.txt", ""), 0);
	int data_size = em->loadData();
	ASSERT_EQ(data_size, 40);

	for (int i = 0; i < data_size; i++) {
		EXPECT_EQ(em->prepareCommand(i), 0);
		EXPECT_EQ(em->runCommand(), 0);
	}
}

vector<string> split(string text, char div) {
	vector<string> result;
	text.push_back(div);

	int startpos = 0;
	int findpos = 0;

	while (1) {
		findpos = (int)text.find(div, startpos);
		if (findpos == -1) break;

		result.push_back(text.substr(startpos, ((size_t)findpos - startpos)));
		startpos = findpos + 1;
	}

	return result;
}

TEST(employeeManagementTest, compare_result) {
	EmployeeManagement* em = new EmployeeManagement();
	vector<string> compareLine;

	FILE* fcomp = new FILE();
	freopen_s(&fcomp, "../FriendsProject/output_20_20.txt", "r", stdin);
	ASSERT_NE(nullptr, fcomp);

	if (fcomp != nullptr) {
		char readBuffer[512];
		while (!(feof(fcomp))) {
			fgets(readBuffer, 512, fcomp);
			if (readBuffer[0] != '\0')
				compareLine.push_back(readBuffer);

			readBuffer[0] = '\0';
		}
		fclose(fcomp);
	}

	ASSERT_EQ(em->openFile("../FriendsProject/input_20_20.txt", ""), 0);
	int data_size = em->loadData();
	ASSERT_EQ(data_size, 40);

	string result = "";
	int print_count = 0;
	for (int i = 0; i < data_size; i++) {
		EXPECT_EQ(em->prepareCommand(i), 0);
		EXPECT_EQ(em->runCommand(), 0);
		result = em->debugResult();

		vector<string> result_split = split(result, '\n');
		for (int j = 0; j < result_split.size(); j++) {
			if (result_split[j] != "") {
				EXPECT_EQ(result_split[j], compareLine[print_count].substr(0, compareLine[print_count].length() - 1));
				print_count++;
			}
		}
	}
}


