#pragma once
#include <string>
#include <iostream>

class Muffin
{
private:
	std::string m_description;
	int m_size{ 0 };
	bool m_hasChocolateChips{ false };

public:
	virtual ~Muffin() = default;
	
	const std::string& getDescription() const { return m_description; }
	void setDescription(std::string description)
	{
		m_description = std::move(description);
	}

	int getSize() const { return m_size; }
	void setSize(int size) { m_size = size; }

	bool hasChocolateChips() const { return m_hasChocolateChips; }
	void setHasChocolateChips(bool hasChips)
	{
		m_hasChocolateChips = hasChips;
	}

	void output() const
	{
		printf("%s, Size is %d, %s\n", getDescription().data(), getSize(),
			(hasChocolateChips() ? "has chips" : "no chips"));
	}

};