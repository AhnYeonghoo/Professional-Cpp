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
	inline double getValue() const
	{
		m_numAccesses++;
		return m_value;
	}

	void setValue(int) = delete; // int형 오버로딩 명시적 삭제

	void setString(std::string_view value);
	inline std::string getString() const
	{
		m_numAccesses;
		return doubleToString(m_value);
	}

	SpreadsheetCell& operator=(const SpreadsheetCell& rhs);

	// 셀 산술연산
	SpreadsheetCell add(const SpreadsheetCell& cell) const;
	SpreadsheetCell operator+(const SpreadsheetCell& cell) const;

	// 축약형 산술 연산자 오버로딩
	SpreadsheetCell& operator+=(const SpreadsheetCell& rhs);
	SpreadsheetCell& operator-=(const SpreadsheetCell& rhs);
	SpreadsheetCell& operator/=(const SpreadsheetCell& rhs);
	SpreadsheetCell& operator*=(const SpreadsheetCell& rhs);

	[[nodiscard]] bool operator==(double rhs) const;
	[[nodiscard]] std::partial_ordering operator<=>(double rhs) const
	{
		return getValue() <=> rhs;
	}
	[[nodiscard]] auto operator<=>(const SpreadsheetCell&) const = default;
	[[nodiscard]] bool operator==(const SpreadsheetCell&) const = default;



private:
	double m_value{ 0 };
	static std::string doubleToString(double value);
	static double stringToDouble(std::string_view value);
	mutable size_t m_numAccesses{ 0 };

public:
	class Cell;
	enum class Color { Red = 1, Green, Blue, Yellow };
	void setColor(Color color);
	Color getColor() const;

private:
	Color m_color{ Color::Red };
};

SpreadsheetCell operator+(const SpreadsheetCell& lhs,
	const SpreadsheetCell& rhs)
{
	return SpreadsheetCell{ lhs.getValue() + rhs.getValue() };
}

SpreadsheetCell operator-(const SpreadsheetCell& lhs,
	const SpreadsheetCell& rhs)
{
	return SpreadsheetCell{ lhs.getValue() - rhs.getValue() };
}

SpreadsheetCell operator*(const SpreadsheetCell& lhs,
	const SpreadsheetCell& rhs)
{
	return SpreadsheetCell{ lhs.getValue() * rhs.getValue() };
}

SpreadsheetCell operator/(const SpreadsheetCell& lhs,
	const SpreadsheetCell& rhs)
{
	if (rhs.getValue() == 0) {
		throw std::invalid_argument{ "Divide by zero" };
	}
	return SpreadsheetCell{ lhs.getValue() / rhs.getValue() };
}

bool operator==(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs)
{
	return (lhs.getValue() == rhs.getValue());
}

bool operator<(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs)
{
	return (lhs.getValue() < rhs.getValue());
}

bool operator>(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs)
{
	return !(lhs < rhs);
}

bool operator<=(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs)
{
	return (lhs.getValue() <= rhs.getValue());
}

bool operator>=(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs)
{
	return !(lhs <= rhs);
}