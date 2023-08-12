#include <iostream>
using namespace std;

enum class Mode { Default, Custom, Standard };

int mainFallthrough() {
	
	int value{ 42 };
	Mode mode{};
	switch (mode) {
		using enum Mode;
	case Custom:
		value = 84;
		[[fallthrough]];
	case Standard:
	case Default:
		break;
	}

	int i{ 11 };
	strong_ordering result{ 1 <=> 0 };
	return 0;
	
}