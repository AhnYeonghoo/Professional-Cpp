#pragma once
#include "SpreadsheetCell2.hpp"
#include "DoubleSpreadsheetCell.hpp"

class StringSpreadsheetCell : public SpreadsheetCell2
{
public:
	StringSpreadsheetCell() = default; // 디폴트생성자
	StringSpreadsheetCell(const DoubleSpreadsheetCell& cell)
		: m_value{ cell.getString() } {}
	void set(std::string_view value) override { m_value = value; }
	std::string getString() const override { return m_value.value_or(""); }

private:
	std::optional<std::string> m_value;
};


//StringSpreadsheetCell operator+(const StringSpreadsheetCell& lhs,
//	const StringSpreadsheetCell& rhs)
//{
//	StringSpreadsheetCell newCell;
//	newCell.set(lhs.getString() + rhs.getString());
//	return newCell;
//}