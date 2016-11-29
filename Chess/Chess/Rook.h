#pragma once
#include "Piece.h"
#include <string>

class Rook : public Piece
{
public:
	Rook();
	~Rook();

	enum Color
	{
		white, black
	};
	bool move();
	std::string getname();


};

