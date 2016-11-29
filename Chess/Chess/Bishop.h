#pragma once
#include "Piece.h"
#include <string>

class Bishop : public Piece
{
public:
	Bishop();
	~Bishop();

	enum Color
	{
		white, black
	};
	bool move();
	std::string getname();
	std::string geticon();
};

