#include <iostream>
#include <stdexcept>
#include <format>
#include <vector>

using namespace std;

double divideNumbers(double numerator, double denominator)
{
	if (denominator == 0) {
		throw std::invalid_argument("Denominator cannot be 0.");
	}
	return numerator / denominator;
}

void processVector(const vector <basic_string<char>>& vec) { return; }

int mainException()
{
	try {
		cout << divideNumbers(2.5, 0.5) << endl;
		cout << divideNumbers(2.3, 0) << endl;
		cout << divideNumbers(4.5, 2.5) << endl;
	}
	catch (const std::invalid_argument& exception) {
		cout << format("Exception caught: {}", exception.what()) << endl;
	}

	vector<basic_string<char>> myVector;
	processVector(myVector);

	return 0;
}