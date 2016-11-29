#pragma once
class Board
{
public:
	Board();
	~Board();

	Board * Piece [8][8];

	void move();

};

