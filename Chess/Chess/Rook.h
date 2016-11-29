#pragma once
#include "Piece.h"
#include <string>

class Rook : public Piece
{
public:
	Rook();
	~Rook();

	Color c;
	/*enum Color
	{
		white, black
	};*/
	bool col;
	bool move();
	std::string geticon();
	std::string getname();


};

