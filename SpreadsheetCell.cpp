#include "SpreadsheetCell.hpp"

using namespace std;

SpreadsheetCell::SpreadsheetCell(double initialValue)
	: m_value{ initialValue } {}

SpreadsheetCell::SpreadsheetCell(string_view initialValue)
{
	setString(initialValue);
}

void SpreadsheetCell::setValue(double value)
{
	m_value = value;
}



void SpreadsheetCell::setString(string_view value)
{
	m_value = stringToDouble(value);
}


string SpreadsheetCell::doubleToString(double value) 
{
	return to_string(value);
}

double SpreadsheetCell::stringToDouble(string_view value)
{
	double number{ 0 };
	from_chars(value.data(), value.data() + value.size(), number);
	return number;
}

SpreadsheetCell::~SpreadsheetCell()
{
	cout << "Destructor called" << endl;
}

SpreadsheetCell& SpreadsheetCell::operator=(const SpreadsheetCell& rhs)
{
	if (this == &rhs) {
		return *this;
	}
	m_value = rhs.m_value;
	return *this;
}

void SpreadsheetCell::setColor(Color color)
{
	m_color = color;
}

SpreadsheetCell::Color SpreadsheetCell::getColor() const
{
	return m_color;
}

SpreadsheetCell SpreadsheetCell::add(const SpreadsheetCell& cell) const
{
	return SpreadsheetCell{ getValue() + cell.getValue() };
}

SpreadsheetCell SpreadsheetCell::operator+(const SpreadsheetCell& cell) const
{
	return SpreadsheetCell{ getValue() + cell.getValue() };
}

SpreadsheetCell& SpreadsheetCell::operator+=(const SpreadsheetCell& rhs)
{
	setValue(getValue() + rhs.getValue());
	return *this;
}

SpreadsheetCell& SpreadsheetCell::operator-=(const SpreadsheetCell& rhs)
{
	setValue(getValue() - rhs.getValue());
	return *this;
}

SpreadsheetCell& SpreadsheetCell::operator/=(const SpreadsheetCell& rhs)
{
	if (rhs.getValue() == 0) {
		throw invalid_argument{ "Divide by zero" };
	}
	setValue(getValue() / rhs.getValue());
	return *this;
}

SpreadsheetCell& SpreadsheetCell::operator*=(const SpreadsheetCell& rhs)
{
	setValue(getValue() * rhs.getValue());
	return *this;
}

bool SpreadsheetCell::operator==(double rhs) const
{
	return getValue() == rhs;
}
