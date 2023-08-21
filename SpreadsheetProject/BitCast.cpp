#include <iostream>
#include <bit>

using namespace std;

int mainBitCast()
{
	float asFloat{ 1.23f };
	auto asUint{ bit_cast<unsigned int>(asFloat) };
	if (bit_cast<float>(asUint) == asFloat) { cout << "Roundtrip success" << endl; }
	return 0;
}