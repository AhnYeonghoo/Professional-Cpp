#include <iostream>
#include <cstdlib>

[[noreturn]] void forceProgramTermination()
{
	std::exit(1);
}

bool isDongLeAvailable()
{
	bool isAvailable{ false };
	return isAvailable;
}

bool isFeatureLicensed(int featureId)
{
	if (!isDongLeAvailable()) {
		forceProgramTermination();
	}
	else {
		bool isLicensed{ featureId == 42 };
		return isLicensed;
	}
}

int mainAttribute()
{
	bool isLicensed{ isFeatureLicensed(42) };
	return 0;
}