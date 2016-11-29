#pragma once
#include "Piece.h"
#include <string>

class Pawn : public Piece
{
public:
	Pawn();
	~Pawn();

	enum Color
	{
		white, black
	};
	bool move();
	std::string getname();
	std::string geticon();
};

