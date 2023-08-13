#include <iostream>
#include <array>

using namespace std;

int mainforWhile()
{
	int i{ 0 };
	while (i < 5) {
		cout << "This is Silly" << endl;
		++i;
	}
	i = 100;
	
	do {
		cout << "This is do while" << endl;
		++i;
	} while (i < 5);

	for (int j{ 0 }; j < 5; j++) {
		cout << "This is For" << endl;
	}

	array<int, 4> arr{ 1, 2, 3, 4 };
	for (int i : arr) { cout << i << endl; }

	for (array arr2{ 1, 2, 3, 4 }; int i : arr) { cout << i << endl; }


	return 0;
}