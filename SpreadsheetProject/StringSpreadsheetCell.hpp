#pragma once;
#include "SpreadsheetCell2.hpp"

class StringSpreadsheetCell : public SpreadsheetCell2
{
public:
	void set(std::string_view value) override { m_value = value; }
	std::string getString() const override { return m_value.value_or(""); }

private:
	std::optional<std::string> m_value;
};

