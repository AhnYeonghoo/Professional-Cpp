#pragma once
#include <vector>
#include <optional>
#include <iostream>
#include <format>
#include <iostream>
#include <memory>

template<class T>
class Grid
{
public:
	explicit Grid(size_t width = DefaultWidth, size_t height = DefaultHeight);
	virtual ~Grid() = default;

	Grid(const Grid& src) = default;
	Grid& operator=(const Grid& rhs) = default;
	
	Grid(Grid&& src) = default;
	Grid& operator=(Grid&& rhs) = default;

	std::optional<T>& at(size_t x, size_t y);
	const std::optional<T>& at(size_t x, size_t y) const;

	void swap(Grid<T>& other) noexcept;
	
	size_t getHeight() const { return m_height; }
	size_t getWidth() const { return m_width; }

	static const size_t DefaultWidth{ 10 };
	static const size_t DefaultHeight{ 10 };

	std::unique_ptr<Grid<T>> clone() const
	{
		return std::make_unique<T>(*this);
	}

private:
	void verifyCoordinate(size_t x, size_t y) const;
	std::vector<std::vector<std::optional<T>>> m_cells;
	size_t m_width{ 0 }, m_height{ 0 };
};

template<typename T>
Grid<T>::Grid(size_t width, size_t height)
	: m_width{ width }, m_height{ height }
{
	m_cells.resize(m_width);
	for (auto& column : m_cells) {
		column.resize(m_height);
	}
}

template<typename T>
void Grid<T>::swap(Grid<T>& other) noexcept
{
	std::swap(m_width, other.m_width);
	std::swap(m_height, other.m_height);
	std::swap(m_cells, other.m_cells);
}

template<typename T>
void swap(Grid<T>& first, Grid<T>& second) noexcept
{
	first.swap(second);
}

template<typename T>
void Grid<T>::verifyCoordinate(size_t x, size_t y) const
{
	if (x >= m_width) {
		throw std::out_of_range{
			std::format("{} must be less than {}. ", x ,m_width) };
	}
	if (y >= m_height) {
		throw std::out_of_range{
			std::format("{} must be less than {}.", y, m_height) };
	}
}

template<typename T>
const std::optional<T>& Grid<T>::at(size_t x, size_t y) const
{
	verifyCoordinate(x, y);
	return m_cells[x][y];
}

template<typename T>
std::optional<T>& Grid<T>::at(size_t x, size_t y)
{
	return const_cast<std::optional<T>&>(std::as_const(*this).at(x, y));
}

