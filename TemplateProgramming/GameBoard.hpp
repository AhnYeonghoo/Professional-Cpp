#pragma once
#include "GamePiece.hpp"
#include <vector>
#include <iostream>
#include <memory>

class GameBoard
{
public:
	static const size_t DefaultWidth{ 10 };
	static const size_t DefaultHeight{ 10 };
	GameBoard(const GameBoard& src); // 복사 생성자
	virtual ~GameBoard() = default;
	GameBoard& operator=(const GameBoard& rhs); // 대입 연산자
	
	// 이동 생성자와 대입 연산자를 명시적으로 디폴트로 지정한다.
	GameBoard(GameBoard&& src) = default;
	GameBoard& operator=(GameBoard&& src) = default;


	explicit GameBoard(size_t width = DefaultWidth, size_t height = DefaultHeight);
	std::unique_ptr<GamePiece>& at(size_t x, size_t y);
	const std::unique_ptr<GamePiece>& at(size_t x, size_t y) const;
	
	size_t getHeight() const { return m_height; }
	size_t getWidth() const { return m_width; }

	void swap(GameBoard& other) noexcept;

private:
	void verifyCoordinate(size_t x, size_t y) const;
	
	std::vector<std::vector<std::unique_ptr<GamePiece>>> m_cells;
	size_t m_width{ 0 }, m_height{ 0 };
};

void swap(GameBoard& first, GameBoard& second) noexcept;
