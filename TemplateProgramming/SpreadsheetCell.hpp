#pragma once
#include <utility>
#include <string>

template<class T>
class SpreadsheetCell
{
private:
	T m_content;
	
public:
	SpreadsheetCell(T t) : m_content{std::move(t)} {}
	const T& getContent() const { return m_content}
};

SpreadsheetCell(const char*)->SpreadsheetCell<std::string>;