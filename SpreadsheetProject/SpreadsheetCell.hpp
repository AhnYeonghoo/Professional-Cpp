#pragma once;
#include <string>
#include <string_view>
#include <compare>
#include <charconv>
#include <stdexcept>

class SpreadsheetCell
{
public:
	SpreadsheetCell() = default;
	SpreadsheetCell(double initialValue);
	SpreadsheetCell(std::string_view initialValue);
	
	void set(double value);
	void set(std::string_view value);

	double getValue() const;
	std::string getString() const;
	
	SpreadsheetCell& operator+=(const SpreadsheetCell& rhs);
	SpreadsheetCell& operator-=(const SpreadsheetCell& rhs);
	SpreadsheetCell& operator*=(const SpreadsheetCell& rhs);
	SpreadsheetCell& operator/=(const SpreadsheetCell& rhs);
	
	[[nodiscard]] auto operator<=>(const SpreadsheetCell&) const = default;
	[[nodiscard]] bool operator==(const SpreadsheetCell&) const = default;
	
	[[nodiscard]] bool operator==(double rhs) const;
	[[nodiscard]] std::partial_ordering operator<=>(double rhs) const;

private:
	static std::string doubleToString(double value);
	static double stringToDouble(std::string_view value);
	
	double m_value{ 0 };
};

//SpreadsheetCell operator+(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs)
//{
//	return SpreadsheetCell{ lhs.getValue() + rhs.getValue() };
//}
//
//SpreadsheetCell operator-(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs)
//{
//	return SpreadsheetCell{ lhs.getValue() - rhs.getValue() };
//
//}
//
//SpreadsheetCell operator*(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs)
//{
//	return SpreadsheetCell{ lhs.getValue() * rhs.getValue() };
//
//}
//
//SpreadsheetCell operator/(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs)
//{
//	if (rhs.getValue() == 0) {
//		throw std::invalid_argument{ "Divide by zero" };
//	}
//
//	return SpreadsheetCell{ lhs.getValue() / rhs.getValue() };
//}