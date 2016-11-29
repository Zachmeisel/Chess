#pragma once
#include <iostream>
#include <string>

class Piece
{
public:
	Piece();
	~Piece();

	 enum Color
	{
		white, black
	};
	 Color c;
	virtual bool move()=0;

	//std::string getname();
	
	virtual std::string getname()=0;
	virtual std::string geticon() = 0;
	std::string name;
	
};

