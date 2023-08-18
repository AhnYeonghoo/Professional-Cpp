#include <initializer_list>
#include <stdexcept>
#include <iostream>
#include <vector>

class EvenSequence
{
public:
	EvenSequence(std::initializer_list<double> args)
	{
		// 만약 원소 개수가 짝수가 아니라면 예외를 던진다.
		if (args.size() % 2 != 0) {
			throw std::invalid_argument { "initializer should"
			"contain even number of elements" };
		}
		m_sequence.reserve(args.size());
		for (const auto& value : args) {
			m_sequence.push_back(value);
		}
	}

	void dump() const
	{
		for (const auto& value : m_sequence) {
			std::cout << value << ", ";
		}
		std::cout << std::endl;
	}
private:
	std::vector<double> m_sequence;
};

int mainEvenSequence()
{
	EvenSequence p1{ 1.0, 2.0, 3.0, 4.0, 5.0, 6.0 };
	p1.dump();
	
	try {
		EvenSequence p2{ 1.0, 2.0, 3.0 };
	}
	catch (const std::invalid_argument& e) {
		std::cout << e.what() << std::endl;
	}

	return 0;
}