#pragma once
#include <string>
#include <vector>
#include <optional>
#include <iostream>
#include <format>
#include <stdexcept>
#include <algorithm>
#include "Grid4.hpp"

// 템플릿 특수화
template<>
class Grid4<const char*>
{
public:
	explicit Grid4(size_t width = DefaultWidth, size_t height = DefaultHeight);
	virtual ~Grid4() = default;

	Grid4(const Grid4& src) = default;
	Grid4& operator=(const Grid4& rhs) = default;

	Grid4(Grid4&& src) = default;
	Grid4& operator=(Grid4&& rhs) = default;

	std::optional<std::string>& at(size_t x, size_t y);
	const std::optional<std::string>& at(size_t x, size_t y) const;


	
	size_t getHeight() const { return m_height; }
	size_t getWidth() const { return m_width; }

	static const size_t DefaultHeight{ 10 };
	static const size_t DefaultWidth{ 10 };

private:
	void verifyCoordinate(size_t x, size_t y) const;
	
	std::vector<std::vector<std::optional<std::string>>> m_cells;
	size_t m_height{ 0 }, m_width{ 0 };
};

Grid4<const char*>::Grid4(size_t width, size_t height)
	: m_width{ width }, m_height{height}
{
	m_cells.resize(m_width);
	for (auto& column : m_cells) {
		column.resize(m_height);
	}
}

void Grid4<const char*>::verifyCoordinate(size_t x, size_t y) const
{
	if (x >= m_width) {
		throw std::out_of_range{
			std::format("{} must be less than {}.", x, m_width)
		};
	}

	if (y >= m_height) {
		throw std::out_of_range{
			std::format("{} must be less than {}.", y, m_height)
		};
	}
}

const std::optional<std::string>& Grid4<const char*>::at(size_t x, size_t y) const
{
	verifyCoordinate(x, y);
	return m_cells[x][y];
}

std::optional<std::string>& Grid4<const char*>::at(size_t x, size_t y)
{
	return const_cast<std::optional<std::string>&>(
		std::as_const(*this).at(x, y));
}

template<class T>
class GameBoard2 : public Grid4<T>
{
public:
	explicit GameBoard2(size_t width = Grid4<T>::DefaultWidth,
		size_t height = Grid4<T>::DefaultHeight);
	void move(size_t xSrc, size_t ySrc, size_t xDest, size_t yDest);
};

template<typename T>
GameBoard2<T>::GameBoard2(size_t width, size_t height)
	: Grid4<T> {width, height}
{
}

template<typename T>
void GameBoard2<T>::move(size_t xSrc, size_t ySrc, size_t xDest, size_t yDest)
{
	Grid4<T>::at(xDest, yDest) = std::move(Grid4<T>::at(xSrc, ySrc));
	Grid4<T>::at(xSrc, ySrc).reset();
}

static const size_t NOT_FOUND{ static_cast<size_t>(-1) };
// 함수 템플릿
template<typename T>
size_t Find(const T& value, const T* arr, size_t size)
{
	for (size_t i{ 0 }; i < size; i++) {
		if (arr[i] == value) return i;
	}
	return NOT_FOUND;
}


// 함수 템플릿 오버로딩
size_t Find(const char* value, const char** arr, size_t size)
{
	for (size_t i{ 0 }; i < size; i++) {
		if (strcmp(arr[i], value) == 0) {
			return i;
		}
	}

	return NOT_FOUND;
}

template<typename T, size_t N>
size_t Find2(const T& value, const T(&arr)[N])
{
	return Find(value, arr, N);
}




// 클래스 템플릿의 프렌드 함수 템플릿
template<typename T>
Grid4<T> operator+(const Grid4<T>& lhs, const Grid4<T>& rhs)
{
	size_t minWidth{ std::min(lhs.getWidth(), rhs.getWidth) };
	size_t minHeight{ std::min(lhs.getHeight(), rhs.getHeight()) };

	Grid4<T> result{ minWidth, minHeight };
	for (size_t y{ 0 }; y < minHeight; y++) {
		for (size_t x{ 0 }; x < minWidth; x++) {
			const auto& leftElement{ lhs.m_cells[x][y] };
			const auto& rightElement{ rhs.m_cells[x][y] };
			if (leftElement.has_value() && rightElement.has_value()) {
				result.at(x, y) = leftElement.value() + rightElement.value();
			}
		}
		return result;
	}
}

template<typename T1, typename T2>
auto add(const T1& t1, const T2& t2) -> decltype(t1 + t2)
{
	return t1 + t2;
}