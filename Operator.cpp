#include <iostream>

using namespace std;

enum class PieceType
{
	King = 1,
	Queen,
	Rook = 10,
	Pawn,
};

enum class PieceType2 : unsigned long
{
	King = 1,
	Queen,
	Rook = 10,
	Pawn,
};

int main()
{
	int someInteger{ 256 };
	short someShort;
	long someLong;
	float someFloat;
	double someDouble;
	
	someInteger++;
	someInteger *= 2;
	someShort = static_cast<short>(someInteger);
	someLong = someShort * 10000;
	someFloat = someLong + 0.785f;
	someDouble = static_cast<double>(someFloat) / 100000;
	cout << someDouble << endl;

	int i = { 34 + (8 * 2) + ((21 / 7) % 2) };
	cout << i << endl;

	const int PieceTypeKing{ 0 };
	const int PieceTypeQueen{ 1 };
	const int PieceTypeRook{ 2 };
	const int PieceTypePawn{ 3 };
	
	int myPiece{ PieceTypeKing };

	PieceType piece{ PieceType::King };
	cout << static_cast<int>(PieceType::King) << endl;
	cout << static_cast<int>(piece) << endl;

	return 0;
}

