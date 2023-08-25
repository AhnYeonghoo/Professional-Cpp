#include <iostream>

using namespace std;

int main()
{
	cout << "abc";
	cout.flush();
	cout << "def";
	cout << endl;
	if (cout.good()) {
		cout << "All good" << endl;
	}

	cout.flush();
	if (cout.fail()) {
		cerr << "Unable to flush to standard out" << endl;
	}

	cout.flush();

	if (!cout) {
		cerr << "Unable to flush to standard out" << endl;
	}

	cout.exceptions(ios::failbit | ios::badbit | ios::eofbit);
	try {
		cout << "Hello World" << endl;
	}
	catch (const ios_base::failure& ex) {
		cerr << "Caught exception: " << ex.what()
			<< ", error code = " << ex.code() << endl;
	}

	cout.clear();

	return 0;
}