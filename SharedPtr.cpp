#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <memory>

using namespace std;

void close(FILE* filePtr)
{
	if (filePtr == nullptr) { return; }
	fclose(filePtr);
	cout << "FIle Closed" << endl;
}

int mainSharedPtr()
{
	FILE* f{ fopen("data.txt", "w") };
	shared_ptr<FILE> filePtr{ f, close };
	if (filePtr == nullptr) {
		cerr << "Error Opening file." << endl;
	}
	else {
		cout << "File Opened" << endl;
	}

	return 0;
}