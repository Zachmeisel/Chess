#pragma once
#include "Piece.h"
#include <string>

class Queen : public Piece
{
public:
	Queen();
	~Queen();

	enum Color
	{
		white, black
	};
	bool move();
	std::string getname();
	std::string geticon();

	
};

