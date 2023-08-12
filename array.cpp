#include <iostream>
#include <array>
#include <format>

int mainArray() 
{
	std::array<int, 3> arr{ 9, 8, 7 };
	std::cout << std::format("array size: {}", arr.size()) << std::endl;
	std::cout << std::format("2nd element: {}", arr.at(1)) << std::endl;
	return 0;

}