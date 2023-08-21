#include "GameBoard.hpp"
#include <format>
#include <iostream>

using namespace std;

GameBoard::GameBoard(size_t width, size_t height)
	: m_width{ width }, m_height{ height }
{
	m_cells.resize(m_width);
	for (auto& column : m_cells) {
		column.resize(m_height);
	}
}

GameBoard::GameBoard(const GameBoard& src)
	: GameBoard{src.m_width, src.m_height}
{
	for (size_t i{ 0 }; i < m_width; i++) {
		for (size_t j{ 0 }; j < m_height; j++) {
			if (src.m_cells[i][j]) {
				m_cells[i][j] = src.m_cells[i][j]->clone();
			}
		}
	}
}

void GameBoard::verifyCoordinate(size_t x, size_t y) const
{
	if (x >= m_width) {
		throw out_of_range{ format("{} must be less than {}. ", x, m_width) };
	}
	if (y >= m_height) {
		throw out_of_range{ format("{} must be less than {}.", y, m_height) };
	}
}

void GameBoard::swap(GameBoard& other) noexcept
{
	std::swap(m_width, other.m_width);
	std::swap(m_height, other.m_height);
	std::swap(m_cells, other.m_cells);
}

void swap(GameBoard& first, GameBoard& second) noexcept
{
	first.swap(second);
}

GameBoard& GameBoard::operator=(const GameBoard& rhs)
{
	GameBoard temp{ rhs };
	swap(temp);
	return *this;
}

const unique_ptr<GamePiece>& GameBoard::at(size_t x, size_t y) const
{
	verifyCoordinate(x, y);
	return m_cells[x][y];
}

unique_ptr<GamePiece>& GameBoard::at(size_t x, size_t y)
{
	return const_cast<unique_ptr<GamePiece>&>(as_const(*this).at(x, y));
}