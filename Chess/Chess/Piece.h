#pragma once
#include <iostream>;
#include <string>;

class Piece
{
public:
	Piece();
	~Piece();

	virtual enum Color
	{
		white, black
	};
	virtual bool move();

	//std::string getname();
	
	virtual std::string getname()=0;
	std::string name;
	
};

