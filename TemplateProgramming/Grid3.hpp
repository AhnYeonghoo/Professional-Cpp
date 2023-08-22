#pragma once
#include <format>
#include <memory>
#include <format>
#include <optional>
#include <stdexcept>

template<class T>
class Grid3
{
public:
	Grid3() = default;
	virtual ~Grid3() = default;

	template<typename E>
	Grid3(const Grid3<E>& src);

	template<typename E>
	Grid3<T>& operator=(const Grid3<E>& rhs);

	void swap(Grid3& other) noexcept;

	std::optional<T>& at(size_t x, size_t y);
	const std::optional<T>& at(size_t x, size_t y) const;

	size_t getHeight() const { return m_height };
	size_t getWIDTH() const { return m_width };

private:
	std::optional<T> m_cells[WIDTH][HEIGHT];
	void verifyCoordinate(size_t x, size_t y) const;
	size_t m_width{ 0 }, m_height{ 0 };
};

template<typename T>
void Grid3<T>::verifyCoordinate(size_t x, size_t y) const
{
	if (x >= WIDTH) {
		throw std::out_of_range{
			std::format("{] must be less then {}.", x, WIDTH)
		};
	}

	if (y >= HEIGHT) {
		throw std::out_of_range{
			std::format("{} must be less than {}.", y, HEIGHT)
		};
	}
}

template<typename T>
const std::optional<T>& Grid3<T>::at(size_t x, size_t y) const
{
	verifyCoordinate(x, y);
	return m_cells[x][y];
}


template<typename T>
std::optional<T>& Grid3<T>::at(size_t x, size_t y)
{
	return const_cast<std::optional<T>&>(std::as_const(*this).at(x, y));
}

template<typename T>
template<typename E>
Grid3<T>::Grid3(const Grid3<E>& src)
	: Grid3{ src.getHeight(), src.getWIDTH() }
{
	for (size_t i{ 0 }; i < m_width; i++) {
		for (size_t j{ 0 }; j < m_height; j++) {
			m_cells[i][j] = src.at(i, j);
		}
	}
}

template<typename T>
void Grid3<T>::swap(Grid3<T>& other) noexcept
{
	std::swap(m_width, other.m_width);
	std::swap(m_height, other.m_height);
	std::swap(m_cells, other.m_cells);
}

template<typename T>
template<typename E>
Grid3<T>& Grid3<T>::operator=(const Grid3<E>& rhs)
{
	Grid3<T> temp{ rhs };
	swap(temp);
	return *this;
}