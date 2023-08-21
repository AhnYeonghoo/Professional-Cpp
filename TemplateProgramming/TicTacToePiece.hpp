#pragma once
#include "GamePiece.hpp"

class TicTacToePiece : public GamePiece
{
public:
	std::unique_ptr<GamePiece> clone() const override
	{
		return std::make_unique<TicTacToePiece>(*this);
	}
};