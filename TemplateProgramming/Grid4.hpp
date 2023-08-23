#include <stdexcept>
#include <optional>
#include <vector>
#include <format>

template<class T, size_t WIDTH = 10, size_t HEIGHT = 10>
class Grid4
{
private:
	std::optional<T> m_cells[WIDTH][HEIGHT];
	void verifyCoordinate(size_t x, size_t y) const;

public:
	Grid4() = default;
	virtual ~Grid4() = default;

	Grid4(const Grid4& src) = default;
	Grid4<T, WIDTH, HEIGHT>& operator=(const Grid4& rhs) = default;
	
	template<typename E, size_t WIDTH2, size_t HEIGHT2>
	Grid4(const Grid4<E, WIDTH2, HEIGHT2>& src);

	template<typename E, size_t WIDTH2, size_t HEIGHT2>
	Grid4& operator=(const Grid4<E, WIDTH2, HEIGHT2>& rhs);

	void swap(Grid4& other) noexcept;
	
	std::optional<T>& at(size_t x, size_t y);
	const std::optional<T>& at(size_t x, size_t y) const;

	size_t getHeight() const { return HEIGHT; }
	size_t getWidth() const { return WIDTH; }
};

template<typename T, size_t WIDTH, size_t HEIGHT>
const std::optional<T>& Grid4<T, WIDTH, HEIGHT>::at(size_t x, size_t y) const
{
	verifyCoordinate(x, y);
	return m_cells[x][y];
}

template<typename T, size_t WIDTH, size_t HEIGHT>
std::optional<T>& Grid4<T, WIDTH, HEIGHT>::at(size_t x, size_t y)
{
	return const_cast<std::optional<T>&>(std::as_const(*this).at(x, y));
}


template <typename T, size_t WIDTH, size_t HEIGHT>
void Grid4<T, WIDTH, HEIGHT>::verifyCoordinate(size_t x, size_t y) const
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
template<typename E, size_t WIDTH2, size_t HEIGHT2>
Grid4<T, WIDTH, HEIGHT>::Grid4(const Grid4<E, WIDTH2, HEIGHT2>& src)
{
	for (size_t i{ 0 }; i < WIDTH; i++) {
		for (size_t j{ 0 }; j < HEIGHT; j++) {
			if (i < WIDTH2 && j < HEIGHT2) {
				m_cells[i][j] = src.at(i, j);
			}
			else {
				m_cells[i][j].reset();
			}
		}
	}
}

template<typename T, size_t WIDTH, size_t HEIGHT>
void Grid4<T, WIDTH, HEIGHT>::swap(Grid4& other) noexcept
{
	std::swap(m_cells, other.m_cells);
}

template<typename T, size_t WIDTH, size_t HEIGHT>
template<typename E, size_t WIDTH2, size_t HEIGHT2>
Grid4<T, WIDTH, HEIGHT>& Grid4<T, WIDTH, HEIGHT>::operator=(
	const Grid4<E, WIDTH2, HEIGHT2>& rhs)
{
	Grid4<T, WIDTH, HEIGHT> temp{ rhs };
	swap(temp);
	return *this;
}