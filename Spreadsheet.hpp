#include <cstddef>
#include <iostream>
#include <exception>
#include <utility>
#include "SpreadsheetCell.hpp"

class Spreadsheet
{
public:
	Spreadsheet(size_t width, size_t height);
	void setCellAt(size_t x, size_t y, const SpreadsheetCell& cell);
	SpreadsheetCell& getCellAt(size_t x, size_t y);
	// Helper Method
	void verifyCoordinate(size_t x, size_t y) const;
	~Spreadsheet();
	Spreadsheet(const Spreadsheet& src); // Deep Copy
	Spreadsheet& operator=(const Spreadsheet& rhs);
	void swap(Spreadsheet& other) noexcept;
private:
	bool inRange(size_t value, size_t upper) const;
	size_t m_width{ 0 };
	size_t m_height{ 0 };
	SpreadsheetCell** m_cells{ nullptr };
};

// ºñ ¸É¹ö ÇÔ¼ö
void swap(Spreadsheet& first, Spreadsheet& second) noexcept;