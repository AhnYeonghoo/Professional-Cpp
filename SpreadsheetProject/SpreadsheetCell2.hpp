#pragma once
#include <iostream>
#include <vector>
#include <charconv>
#include <memory>
#include <string>
#include <format>
#include <string_view>
#include <optional>

class SpreadsheetCell2
{
public:
	virtual ~SpreadsheetCell2() = default;
	virtual void set(std::string_view value) = 0;
	virtual std::string getString() const = 0; // 순수 가상 메서드
};