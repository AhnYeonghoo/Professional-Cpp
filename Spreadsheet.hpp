#include <cstddef>
#include <iostream>
#include <exception>
#include <utility>
#include <vector>
#include <algorithm>
#include "SpreadsheetCell.hpp"
#include "SpreadsheetApplication.hpp"

class Spreadsheet
{
public:
	Spreadsheet(size_t width = 100, size_t height = 100);
	void setCellAt(size_t x, size_t y, const SpreadsheetCell& cell);
	SpreadsheetCell& getCellAt(size_t x, size_t y);
	const SpreadsheetCell& getCellAt(size_t x, size_t y) const;
	// Helper Method
	void verifyCoordinate(size_t x, size_t y) const;
	~Spreadsheet();
	Spreadsheet(const Spreadsheet& src); // Deep Copy
	Spreadsheet& operator=(const Spreadsheet& rhs);
	void swap(Spreadsheet& other) noexcept;
	Spreadsheet& operator=(Spreadsheet&& rhs) noexcept; // 이동 대입 연산자
	size_t getId() const;
	
private:
	bool inRange(size_t value, size_t upper) const;
	size_t m_width{ 0 };
	size_t m_height{ 0 };
	SpreadsheetCell** m_cells{ nullptr };
	static inline size_t ms_counter{ 0 };
	const size_t m_id{ 0 };
	static const size_t MaxHeight{ 100 };
	static const size_t MaxWidth{ 100 };
	//const SpreadsheetApplication& m_theApp;

public:
	class Cell;
};

// 비 맴버 함수
void swap(Spreadsheet& first, Spreadsheet& second) noexcept;

class Spreadsheet::Cell
{
public:
	Cell() = default;
	Cell(size_t initialValue);
private:
	size_t m_value;
};