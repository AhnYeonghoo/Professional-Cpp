#include <vector>
#include <format>
#include <utility>
#include <array>
#include <iostream>
#include <optional>

using namespace std;

struct Point { double m_x, m_y, m_z; };

optional<int> getData(bool giveIt)
{
	if (giveIt) return 42;
	return nullopt;
}
int mainVector()
{
	vector<int> myVector{ 11, 22 };
	myVector.push_back(33);
	myVector.push_back(44);

	cout << format("1st element: {}", myVector[0]) << endl;
	
	pair<double, int> myPair{ 1.23, 5 };
	cout << format("{} {}", myPair.first, myPair.second) << endl;

	optional<int> data1{ getData(true) };
	optional<int> data2{ getData(false) };
	
	cout << "data1.has_value = " << data1.has_value() << endl;
	if (data2) cout << "data2 has a value" << endl;

	cout << data1.value() << endl;
	cout << *data1 << endl;
	cout << data2.value_or(0) << endl;
	
	array values{ 11, 22, 33 };
	auto [x, y, z] {values};
	Point point;
	point.m_x = 1.0; point.m_y = 2.0; point.m_z = 3.0;
	auto [x1, y1, z1] {point};

	pair myPair2{ "Hello", 5 };
	auto [theString, theInt] {myPair2};
	cout << format("theString: {}", theString) << endl;
	cout << format("theInt: {}", theInt) << endl;

	return 0;
}