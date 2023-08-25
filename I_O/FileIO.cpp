#include <fstream>
#include <iostream>
#include <format>
using namespace std;

int mainFileIO(int argc, char* argv[])
{
	ofstream outFile{ "text.txt", ios_base::trunc };
	if (!outFile.good()) {
		cerr << "Error while opening output file!" << endl;
		return -1;
	}
	outFile << "There were " << argc << " arguments to this program." << endl;
	outFile << "They are: " << endl;
	for (int i{ 0 }; i < argc; i++) {
		outFile << argv[i] << endl;
	}

	ofstream fout { "test.out" };
	if (!fout) {
		cerr << "Error Opening test.out for wrting" << endl;
		return 1;
	}

	fout << "54321";

	streampos curPos{ fout.tellp() };
	if (5 == curPos) {
		cout << "Test passed: Currently at position 5" << endl;
	}
	else {
		cout << "Test failed: Not at position  5" << endl;
	}
	
	fout.seekp(2, ios_base::beg);
	
	fout << 0;
	fout.close();

	ifstream fin{ "test.out" };
	if (!fin) {
		cerr << "Error opening test.out for reading" << endl;
		return 1;
	}

	int testVal;
	fin >> testVal;
	if (!fin) {
		cerr << "Error reading from file." << endl;
		return 1;
	}

	const int expected{ 54021 };
	if (testVal == expected) {
		cout << format("Test paased: Value is {}.", expected) << endl;
	}
	else {
		cout << format("test failed: Value is not {} (it was {})", expected, testVal) << endl;
	}
	return 0;
}