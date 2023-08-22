#pragma once
#include <optional>
#include <format>
#include <memory>
#include <stdexcept>

template<class T, size_t WIDTH, size_t HEIGHT>
class Grid2
{
public:
	Grid2() = default; 
	virtual ~Grid2() = default;
	
	// 복제생성자와 대입연산자를 명시적으로 디폴트로 지정한다.
	Grid2(const Grid2& src) = default;
	Grid2& operator=(const Grid2& hrs) = default;
	
	std::optional<T>& at(size_t x, size_t y);
	const std::optional<T>& at(size_t x, size_t y) const;
	
	size_t getHeight() const { return HEIGHT; }
	size_t getWidth() const { return WIDTH; }
	
private:
	void verifyCoordinate(size_t x, size_t y) const;
	std::optional<T> m_cells[WIDTH][HEIGHT];
};

template <typename T, size_t WIDTH, size_t HEIGHT>
void Grid2<T, WIDTH, HEIGHT>::verifyCoordinate(size_t x, size_t y) const
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

template<typename T, size_t WIDTH, size_t HEIGHT>
const std::optional<T>& Grid2<T, WIDTH, HEIGHT>::at(size_t x, size_t y) const
{
	verifyCoordinate(x, y);
	return m_cells[x][y];
}

template<typename T, size_t WIDTH, size_t HEIGHT>
std::optional<T>& Grid2<T, WIDTH, HEIGHT>::at(size_t x, size_t y)
{
	return const_cast<std::optional<T>&>(std::as_const(*this).at(x, y));
}
