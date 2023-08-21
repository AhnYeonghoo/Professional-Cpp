#pragma once
#include <string>
#include <vector>

class Person
{
public:
	Person(std::string firstName, std::string lastName)
		: m_firstName{firstName}, m_lastName{lastName} {}
	const std::string& getFirstName() const { return m_firstName; }
	const std::string& getLastName() const { return m_lastName; }
private:
	std::string m_firstName;
	std::string m_lastName;
};

//export
//{
//	namespace DataModel
//	{
//		class Person {};
//		class Address {};
//		using Persons = std::vector<Person>;
//	}
//}