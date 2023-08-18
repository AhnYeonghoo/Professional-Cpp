#pragma once;
#include <string>
#include <string_view>
#include <iostream>
#include <memory>
#include <charconv>

class SpreadsheetCell
{
public:
	SpreadsheetCell(double initialValue);
	explicit SpreadsheetCell(std::string_view initialValue);
	SpreadsheetCell() = default;
	~SpreadsheetCell();
	void setValue(double value);
	double getValue() const;

	void setString(std::string_view value);
	std::string getString() const;
	SpreadsheetCell& operator=(const SpreadsheetCell& rhs);

private:
	double m_value{ 0 };
	std::string doubleToString(double value) const;
	double stringToDouble(std::string_view value) const;
};