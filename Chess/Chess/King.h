#pragma once
#include "Piece.h"
#include <string>

class King : public Piece
{
public:
	King();
	~King();

	enum Color
	{
		white, black
	};
	bool move();
	std::string getname();
	std::string geticon();
};

