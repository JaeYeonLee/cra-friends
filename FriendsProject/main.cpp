#include <iostream>
#include "employeeManagement.h"

using namespace std;

int main(int argc, char* argv[]) {
	string input_filename = "../FriendsProject/input_20_20.txt";
	string output_filename = "";

	if (1 != argc) {
		if (argc == 3) {
			input_filename = argv[1];
			output_filename = argv[2];
		}
		else {
			cout << "Wrong argument." << endl;
			cout << "usage: FriendProject.exe inputfile.txt outputfile.txt" << endl;
			return -1;

		}
	}

	EmployeeManagement* em = new EmployeeManagement();
	if (em->openFile(input_filename, output_filename) < 0) {
		cout << "Fail to open file. (filename=" << input_filename << ", " << output_filename << ")" << endl;
		return -1;
	}

	int data_size = em->loadData();
	if (data_size < 0) return -1;

	int result = 0;
	for (int i = 0; i < data_size; i++) {
		result = em->prepareCommand(i);
		if (result < 0) continue;

		result = em->runCommand();
		if (result < 0) continue;

		result = em->printResult();
		if (result < 0) continue;
	}

	return 0;
}