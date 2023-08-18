#include <cstddef>
#include <iostream>
#include <exception>
#include <utility>
#include <vector>
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
	Spreadsheet(Spreadsheet&& src) noexcept; // 이동생성자
	Spreadsheet& operator=(Spreadsheet&& rhs) noexcept; // 이동 대입 연산자
private:
	bool inRange(size_t value, size_t upper) const;
	size_t m_width{ 0 };
	size_t m_height{ 0 };
	SpreadsheetCell** m_cells{ nullptr };
};

// 비 맴버 함수
void swap(Spreadsheet& first, Spreadsheet& second) noexcept;