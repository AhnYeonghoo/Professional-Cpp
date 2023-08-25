#include <iostream>
#include <sstream>
#include "Muffin.hpp"
using namespace std;

Muffin createMuffin(istringstream& stream);

int mainStringStream()
{
	cout << "Enter token. "
		<< "Control+D (Unix) or Control+Z (Windows) followed by Enter to end."
		<< endl;
	ostringstream outStream;
	while (cin) {
		string nextToken;
		cout << "Next token: ";
		cin >> nextToken;
		if (!cin || nextToken == "done")  break;
		outStream << nextToken << "\t";
	}

	cout << "The end result is: " << outStream.str() << endl;
	return 0;
}

Muffin createMuffin(istringstream& stream)
{
	Muffin muffin;
	// 데이터가 다음과 같은 형식에 맞게 들어온다고 가정한다.
	// Description size, chips
	
	string description;
	int size;
	bool hasChips;

	stream >> description >> size >> boolalpha >> hasChips;
	if (stream) {
		muffin.setSize(size);
		muffin.setDescription(description);
		muffin.setHasChocolateChips(hasChips);
	}
	return muffin;
}