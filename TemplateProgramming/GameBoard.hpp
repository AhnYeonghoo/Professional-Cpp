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
	GameBoard(const GameBoard& src); // ���� ������
	virtual ~GameBoard() = default;
	GameBoard& operator=(const GameBoard& rhs); // ���� ������
	
	// �̵� �����ڿ� ���� �����ڸ� ��������� ����Ʈ�� �����Ѵ�.
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
