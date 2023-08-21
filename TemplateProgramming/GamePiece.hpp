#pragma once
#include <memory>

class GamePiece
{
public:
	virtual ~GamePiece() = default;
	virtual std::unique_ptr<GamePiece> clone() const = 0;
};